#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vdf.h"

struct dsa_vdf_value_list
{
	size_t count;
	struct dsa_vdf *children;
};

struct dsa_vdf
{
	char *key;
	enum dsa_vdf_value_type type;
	union
	{
		int as_int;
		float as_float;
		char *as_str;
		struct dsa_vdf_value_list as_list;
	} value;
};


static inline int dsa_vdf_isspace(char c) {
	return c == '\t'
			|| c == '\n'
			|| c == '\r'
			|| c == ' ';
}

static inline int dsa_vdf_isctrl(char c) {
	return c == '"'
			|| c == '{'
			|| c == '}';
}

static inline char dsa_vdf_read_char(const char *ptr, const char *max_ptr)
{
	if (ptr >= max_ptr)
		return 0;

	return *ptr;
}

static inline const char *dsa_vdf_skip_spaces(const char *s, const char *max_ptr) {
	while (dsa_vdf_isspace(dsa_vdf_read_char(s, max_ptr)))
		s++;
	return s;
}

static inline char *dsa_vdf_strdup(const char *str) {
	size_t size = strlen(str) + 1;
	char *s = malloc(size);
	return memcpy(s, str, size);
}

static size_t read_tok_string(const char **ptr, const char *max_ptr, char *tok)
{
	const char *p = *ptr;
	int is_quoted;
	int is_esc;
	size_t tok_len = 0;

	p = dsa_vdf_skip_spaces(p, max_ptr);

	is_quoted = -1;
	is_esc = 0;
	for (; p < max_ptr; p++)
	{
		char c;

		c = dsa_vdf_read_char(p, max_ptr);
		if (!c)
			break;

		if (is_quoted < 0)
		{
			is_quoted = c == '"';
			if (is_quoted)
				continue;
		}

		if (c == '\\' && !is_esc)
		{
			is_esc = 1;
			continue;
		}

		if (c == '"' && is_quoted && !is_esc)
		{
			is_quoted = 0;
			p++;
			break;
		}

		if ((dsa_vdf_isctrl(c) || dsa_vdf_isspace(c)) && !is_quoted && !is_esc)
			break;

		if (c == 't' && is_esc)
			c = '\t';

		if (c == 'n' && is_esc)
			c = '\n';

		if (tok)
			*tok++ = c;
		tok_len++;
		is_esc = 0;
	}

	if (is_quoted)
		return SIZE_MAX;

	if (tok)
	{
		*tok = '\0';
		*ptr = p;
	}

	return tok_len;
}

static struct dsa_vdf *read_vdf(const char **ptr, const char *max_ptr, struct dsa_vdf *parent_vdf);

static int read_tok_list(const char **ptr, const char *max_ptr, struct dsa_vdf *vdf)
{
	const char *p = *ptr;
	int result;
	char c;

	p = dsa_vdf_skip_spaces(p, max_ptr);

	c = dsa_vdf_read_char(p, max_ptr);
	if (c != '{')
		return -1;
	p++;

	dsa_vdf_set_list(vdf);

	while (1)
	{
		p = dsa_vdf_skip_spaces(p, max_ptr);

		c = *p;
		if (c == '}')
			break;

		result = !!read_vdf(&p, max_ptr, vdf);
		if (!result)
			break;
	}

	if (c != '}')
	{
		dsa_vdf_unset(vdf);
		return -1;
	}

	*ptr = ++p;
	return 0;
}

static struct dsa_vdf *read_vdf(const char **ptr, const char *max_ptr, struct dsa_vdf *parent_vdf)
{
	const char *p = *ptr;
	size_t tok_len;
	char *tok_str;
	int result;
	struct dsa_vdf *vdf;

	tok_len = read_tok_string(&p, max_ptr, NULL);
	if (tok_len == SIZE_MAX)
		goto failed;

	tok_str = calloc(1, tok_len + 1);
	if (!tok_str)
		goto failed;

	read_tok_string(&p, max_ptr, tok_str);

	if (!parent_vdf)
		vdf = dsa_vdf_create_root(tok_str);
	else
		vdf = dsa_vdf_list_open_entry(parent_vdf, tok_str);

	free(tok_str);

	result = read_tok_list(&p, max_ptr, vdf);
	if (result < 0)
	{
		tok_len = read_tok_string(&p, max_ptr, NULL);
		if (tok_len == SIZE_MAX)
			goto failed;

		tok_str = calloc(1, tok_len + 1);
		if (!tok_str)
			goto failed;

		read_tok_string(&p, max_ptr, tok_str);
		dsa_vdf_set_str(vdf, tok_str);
		free(tok_str);
	}

	*ptr = p;
	return vdf;

failed:
	if (!parent_vdf)
		dsa_vdf_destroy_root(vdf);
	else
		dsa_vdf_destroy(vdf);
	return NULL;
}

struct dsa_vdf *dsa_vdf_parse(const char *data, size_t size)
{
	const char *max_ptr = &data[size];

	if (!data || !size)
		return NULL;

	return read_vdf(&data, max_ptr, NULL);
}

struct dsa_vdf *dsa_vdf_create_root(const char *key)
{
	struct dsa_vdf *vdf;

	vdf = calloc(1, sizeof(*vdf));
	if (!vdf)
		return NULL;

	vdf->key = dsa_vdf_strdup(key);
	vdf->type = DSA_VDF_VALUE_TYPE_INVAL;
	return vdf;
}

struct dsa_vdf *dsa_vdf_get_name(struct dsa_vdf *vdf, const char **name)
{
	if (!vdf)
		return NULL;

	if (!vdf->key)
		return NULL;

	*name = vdf->key;
	return vdf;
}

struct dsa_vdf *dsa_vdf_get_type(struct dsa_vdf *vdf, enum dsa_vdf_value_type *type)
{
	if (!vdf)
		return NULL;

	*type = vdf->type;
	return vdf;
}

struct dsa_vdf *dsa_vdf_get_int(struct dsa_vdf *vdf, int *val)
{
	if (!vdf)
		return NULL;

	if (vdf->type != DSA_VDF_VALUE_TYPE_INT)
		return NULL;

	if (val)
		*val = vdf->value.as_int;
	return vdf;
}

struct dsa_vdf *dsa_vdf_get_float(struct dsa_vdf *vdf, float *val)
{
	if (!vdf)
		return NULL;

	if (vdf->type != DSA_VDF_VALUE_TYPE_FLOAT)
		return NULL;

	if (val)
		*val = vdf->value.as_float;
	return vdf;
}

struct dsa_vdf *dsa_vdf_get_str(struct dsa_vdf *vdf, const char **val)
{
	if (!vdf)
		return NULL;

	if (vdf->type != DSA_VDF_VALUE_TYPE_STR)
		return NULL;

	if (val)
		*val = vdf->value.as_str;
	return vdf;
}

struct dsa_vdf *dsa_vdf_mutate(struct dsa_vdf *vdf, enum dsa_vdf_value_type tgt_type)
{
	if (!vdf)
		return NULL;

	if (tgt_type == vdf->type)
		return vdf;

	switch (tgt_type)
	{
		case DSA_VDF_VALUE_TYPE_INVAL:
			dsa_vdf_unset(vdf);
			break;

		case DSA_VDF_VALUE_TYPE_INT:
		{
			int val;

			if (vdf->type == DSA_VDF_VALUE_TYPE_INVAL)
				val = 0;
			else if (vdf->type == DSA_VDF_VALUE_TYPE_FLOAT)
				val = (int)vdf->value.as_float;
			else if (vdf->type == DSA_VDF_VALUE_TYPE_STR)
				val = strtol(vdf->value.as_str, NULL, 0);
			else
				return NULL;

			dsa_vdf_set_int(vdf, val);
			break;
		}
			
		case DSA_VDF_VALUE_TYPE_FLOAT:
		{
			float val;

			if (vdf->type == DSA_VDF_VALUE_TYPE_INVAL)
				val = 0.f;
			else if (vdf->type == DSA_VDF_VALUE_TYPE_INT)
				val = (float)vdf->value.as_int;
			else if (vdf->type == DSA_VDF_VALUE_TYPE_STR)
				val = strtof(vdf->value.as_str, NULL);
			else
				return NULL;

			dsa_vdf_set_float(vdf, val);
			break;
		}

		case DSA_VDF_VALUE_TYPE_STR:
		{
			char buf[32];

			if (vdf->type == DSA_VDF_VALUE_TYPE_INVAL)
				buf[0] = '\0';
			else if (vdf->type == DSA_VDF_VALUE_TYPE_INT)
				snprintf(buf, sizeof(buf), "%d", vdf->value.as_int);
			else if (vdf->type == DSA_VDF_VALUE_TYPE_FLOAT)
				snprintf(buf, sizeof(buf), "%f", vdf->value.as_float);
			else
				return NULL;

			dsa_vdf_set_str(vdf, buf);
			break;
		}

		case DSA_VDF_VALUE_TYPE_LIST:
			if (vdf->type == DSA_VDF_VALUE_TYPE_INVAL)
				dsa_vdf_set_list(vdf);
			else
				return NULL;

			break;
	}

	return vdf;
}

struct dsa_vdf *dsa_vdf_mutate_as_inval(struct dsa_vdf *vdf)
{
	return dsa_vdf_mutate(vdf, DSA_VDF_VALUE_TYPE_INVAL);
}

struct dsa_vdf *dsa_vdf_mutate_as_int(struct dsa_vdf *vdf)
{
	return dsa_vdf_mutate(vdf, DSA_VDF_VALUE_TYPE_INT);
}

struct dsa_vdf *dsa_vdf_mutate_as_float(struct dsa_vdf *vdf)
{
	return dsa_vdf_mutate(vdf, DSA_VDF_VALUE_TYPE_FLOAT);
}

struct dsa_vdf *dsa_vdf_mutate_as_str(struct dsa_vdf *vdf)
{
	return dsa_vdf_mutate(vdf, DSA_VDF_VALUE_TYPE_STR);
}

struct dsa_vdf *dsa_vdf_mutate_as_list(struct dsa_vdf *vdf)
{
	return dsa_vdf_mutate(vdf, DSA_VDF_VALUE_TYPE_LIST);
}

struct dsa_vdf *dsa_vdf_unset(struct dsa_vdf *vdf)
{
	if (!vdf)
		return NULL;

	if (vdf->type == DSA_VDF_VALUE_TYPE_LIST)
	{
		while (vdf->value.as_list.count > 0)
			dsa_vdf_destroy(&vdf->value.as_list.children[--vdf->value.as_list.count]);

		free(vdf->value.as_list.children);
	}
	else if (vdf->type == DSA_VDF_VALUE_TYPE_STR)
		free(vdf->value.as_str);

	vdf->type = DSA_VDF_VALUE_TYPE_INVAL;
	return vdf;
}

struct dsa_vdf *dsa_vdf_set_int(struct dsa_vdf *vdf, int val)
{
	if (!vdf)
		return NULL;

	dsa_vdf_unset(vdf);

	vdf->type = DSA_VDF_VALUE_TYPE_INT;
	vdf->value.as_int = val;
	return vdf;
}

struct dsa_vdf *dsa_vdf_set_float(struct dsa_vdf *vdf, float val)
{
	if (!vdf)
		return NULL;

	dsa_vdf_unset(vdf);

	vdf->type = DSA_VDF_VALUE_TYPE_FLOAT;
	vdf->value.as_float = val;
	return vdf;
}

struct dsa_vdf *dsa_vdf_set_str(struct dsa_vdf *vdf, const char *val)
{
	if (!vdf)
		return NULL;

	dsa_vdf_unset(vdf);

	vdf->type = DSA_VDF_VALUE_TYPE_STR;
	vdf->value.as_str = dsa_vdf_strdup(val);
	return vdf;
}

struct dsa_vdf *dsa_vdf_set_list(struct dsa_vdf *vdf)
{
	if (!vdf)
		return NULL;

	dsa_vdf_unset(vdf);

	vdf->type = DSA_VDF_VALUE_TYPE_LIST;
	vdf->value.as_list.count = 0;
	vdf->value.as_list.children = NULL;
	return vdf;
}

struct dsa_vdf *dsa_vdf_list_get_entry(struct dsa_vdf *vdf, const char *key)
{
	struct dsa_vdf *entry = NULL;

	if (!vdf)
		return NULL;

	if (vdf->type != DSA_VDF_VALUE_TYPE_LIST)
		return NULL;

	for (size_t i = 0; i < vdf->value.as_list.count; i++)
	{
		struct dsa_vdf *child = &vdf->value.as_list.children[i];

		if (!child->key)
			continue;

		if (strcmp(child->key, key) == 0)
		{
			entry = child;
			break;
		}
	}

	return entry;
}

struct dsa_vdf *dsa_vdf_list_get_entry_count(struct dsa_vdf *vdf, size_t *count)
{
	if (!vdf)
		return NULL;

	if (vdf->type != DSA_VDF_VALUE_TYPE_LIST)
		return NULL;

	*count = vdf->value.as_list.count;
	return vdf;
}

struct dsa_vdf *dsa_vdf_list_get_entry_by_idx(struct dsa_vdf *vdf, size_t idx)
{
	struct dsa_vdf *entry;

	if (!vdf)
		return NULL;

	if (vdf->type != DSA_VDF_VALUE_TYPE_LIST)
		return NULL;

	if (idx >= vdf->value.as_list.count)
		return NULL;

	entry = &vdf->value.as_list.children[idx];
	if (!entry->key)
		return NULL;

	return entry;
}

struct dsa_vdf *dsa_vdf_list_create_entry(struct dsa_vdf *vdf, const char *key)
{
	struct dsa_vdf *entry = NULL;

	if (!vdf)
		return NULL;

	if (vdf->type != DSA_VDF_VALUE_TYPE_LIST)
		return NULL;

	for (size_t i = 0; i < vdf->value.as_list.count; i++)
	{
		struct dsa_vdf *child = &vdf->value.as_list.children[i];

		/* Recycle dead entries */
		if (!child->key)
		{
			entry = child;
			continue;
		}

		/* Duplicates are not allowed */
		if (strcmp(child->key, key) == 0)
			return NULL;
	}

	if (!entry)
	{
		struct dsa_vdf *children = realloc(vdf->value.as_list.children, (vdf->value.as_list.count + 1) * sizeof(vdf->value.as_list.children[0]));
		if (!children)
			return NULL;

		vdf->value.as_list.children = children;
		entry = &vdf->value.as_list.children[vdf->value.as_list.count];
		vdf->value.as_list.count++;
	}

	entry->key = dsa_vdf_strdup(key);
	entry->type = DSA_VDF_VALUE_TYPE_INVAL;
	return entry;
}

struct dsa_vdf *dsa_vdf_list_open_entry(struct dsa_vdf *vdf, const char *key)
{
	struct dsa_vdf *entry = NULL;

	if (!vdf)
		return NULL;

	if (vdf->type != DSA_VDF_VALUE_TYPE_LIST)
		return NULL;

	entry = dsa_vdf_list_get_entry(vdf, key);
	if (entry)
		return entry;

	return dsa_vdf_list_create_entry(vdf, key);
}

struct dsa_vdf *dsa_vdf_vget_path(struct dsa_vdf *vdf, va_list ap)
{
	struct dsa_vdf *entry = vdf;
	const char *elem;

	if (!vdf)
		return NULL;

	while ((elem = va_arg(ap, const char *)))
	{
		entry = dsa_vdf_list_get_entry(entry, elem);
		if (!entry)
			return NULL;
	}

	return entry;
}

struct dsa_vdf *dsa_vdf_get_path(struct dsa_vdf *vdf, ...)
{
	va_list ap;
	struct dsa_vdf *entry;

	va_start(ap, vdf);
	entry = dsa_vdf_vget_path(vdf, ap);
	va_end(ap);
	return entry;
}

struct dsa_vdf *dsa_vdf_vcreate_path(struct dsa_vdf *vdf, va_list ap)
{
	struct dsa_vdf *entry = vdf;
	struct dsa_vdf *last_created = NULL;
	const char *elem;

	if (!vdf)
		return NULL;

	while ((elem = va_arg(ap, const char *)))
	{
		struct dsa_vdf *e;

		e = dsa_vdf_list_get_entry(entry, elem);
		if (!e)
			e = last_created = dsa_vdf_set_list(dsa_vdf_list_create_entry(entry, elem));
		if (!e)
			return NULL;
		entry = e;
	}

	/* The last component of the path must be created by this function */
	if (entry != last_created)
		return NULL;

	dsa_vdf_unset(entry);
	return entry;
}

struct dsa_vdf *dsa_vdf_create_path(struct dsa_vdf *vdf, ...)
{
	va_list ap;
	struct dsa_vdf *entry;

	va_start(ap, vdf);
	entry = dsa_vdf_vcreate_path(vdf, ap);
	va_end(ap);
	return entry;
}

struct dsa_vdf *dsa_vdf_vopen_path(struct dsa_vdf *vdf, va_list ap)
{
	struct dsa_vdf *entry = NULL;
	va_list ap_bak;

	if (!vdf)
		return NULL;

	va_copy(ap_bak, ap);

	entry = dsa_vdf_vget_path(vdf, ap);
	if (entry)
		return entry;

	return dsa_vdf_vcreate_path(vdf, ap_bak);
}

struct dsa_vdf *dsa_vdf_open_path(struct dsa_vdf *vdf, ...)
{
	va_list ap;
	struct dsa_vdf *entry;

	va_start(ap, vdf);
	entry = dsa_vdf_vopen_path(vdf, ap);
	va_end(ap);
	return entry;
}

#define DSA_VDF_BUF_GROW 1024

static char *dsa_vdf_buf_append(char **buf, size_t *buf_size, size_t *i, const char *s)
{
	size_t s_len;

	s_len = strlen(s);
	while (*i + s_len > *buf_size)
	{
		char *b;

		b = realloc(*buf, *buf_size + DSA_VDF_BUF_GROW);
		if (!b)
		{
			free(*buf);
			*buf = NULL;
			return NULL;
		}

		*buf = b;
		*buf_size += DSA_VDF_BUF_GROW;
	}

	memcpy(&(*buf)[*i], s, s_len);
	*i += s_len;
	return *buf;
}

#undef DSA_VDF_BUF_GROW

static char *dsa_vdf_serialize_helper(struct dsa_vdf *vdf, size_t indent_lvl, char **buf, size_t *buf_size, size_t *i)
{
	static const char s_indent[] = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	char tmpb[32];
	const char *indent;

	/* Dead entry */
	if (!vdf->key)
		return *buf;

	if (indent_lvl > sizeof(s_indent) - 1)
		indent_lvl = sizeof(s_indent) - 1;

	indent = &s_indent[sizeof(s_indent) - 1 - indent_lvl];

	dsa_vdf_buf_append(buf, buf_size, i, indent);
	dsa_vdf_buf_append(buf, buf_size, i, "\"");
	dsa_vdf_buf_append(buf, buf_size, i, vdf->key);
	dsa_vdf_buf_append(buf, buf_size, i, "\"");

	switch (vdf->type)
	{
		case DSA_VDF_VALUE_TYPE_INVAL:
			dsa_vdf_buf_append(buf, buf_size, i, " \"(nil)\"");
			break;

		case DSA_VDF_VALUE_TYPE_INT:
			snprintf(tmpb, sizeof(tmpb), "%d", vdf->value.as_int);
			dsa_vdf_buf_append(buf, buf_size, i, " \"");
			dsa_vdf_buf_append(buf, buf_size, i, tmpb);
			dsa_vdf_buf_append(buf, buf_size, i, "\"");
			break;

		case DSA_VDF_VALUE_TYPE_FLOAT:
			snprintf(tmpb, sizeof(tmpb), "%f", vdf->value.as_float);
			dsa_vdf_buf_append(buf, buf_size, i, " \"");
			dsa_vdf_buf_append(buf, buf_size, i, tmpb);
			dsa_vdf_buf_append(buf, buf_size, i, "\"");
			break;

		case DSA_VDF_VALUE_TYPE_STR:
			dsa_vdf_buf_append(buf, buf_size, i, " \"");
			dsa_vdf_buf_append(buf, buf_size, i, vdf->value.as_str);
			dsa_vdf_buf_append(buf, buf_size, i, "\"");
			break;

		case DSA_VDF_VALUE_TYPE_LIST:
			dsa_vdf_buf_append(buf, buf_size, i, "\n");
			dsa_vdf_buf_append(buf, buf_size, i, indent);
			dsa_vdf_buf_append(buf, buf_size, i, "{\n");

			for (size_t j = 0; j < vdf->value.as_list.count; j++)
				dsa_vdf_serialize_helper(&vdf->value.as_list.children[j], indent_lvl + 1, buf, buf_size, i);

			dsa_vdf_buf_append(buf, buf_size, i, indent);
			dsa_vdf_buf_append(buf, buf_size, i, "}");
			break;
	}

	dsa_vdf_buf_append(buf, buf_size, i, "\n");
	return *buf;
}

char *dsa_vdf_serialize(struct dsa_vdf *vdf, size_t *size)
{
	char *buf = NULL;
	size_t buf_size = 0;

	if (!vdf)
		return NULL;

	*size = 0;

	return dsa_vdf_serialize_helper(vdf, 0, &buf, &buf_size, size);
}

struct dsa_vdf *dsa_vdf_destroy(struct dsa_vdf *vdf)
{
	if (!vdf)
		return NULL;

	dsa_vdf_unset(vdf);

	if (vdf->key)
		free(vdf->key);
	vdf->key = NULL;

	return NULL;
}

struct dsa_vdf *dsa_vdf_destroy_root(struct dsa_vdf *vdf)
{
	if (!vdf)
		return NULL;

	dsa_vdf_destroy(vdf);
	free(vdf);

	return NULL;
}
