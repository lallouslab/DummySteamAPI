#ifndef VDF_VDF_H
#define VDF_VDF_H 1

#include <stdarg.h>

enum dsa_vdf_value_type
{
	DSA_VDF_VALUE_TYPE_INVAL = 0,
	DSA_VDF_VALUE_TYPE_INT,
	DSA_VDF_VALUE_TYPE_FLOAT,
	DSA_VDF_VALUE_TYPE_STR,
	DSA_VDF_VALUE_TYPE_LIST
};

struct dsa_vdf;

extern struct dsa_vdf *dsa_vdf_parse(const char *data, size_t size);
extern struct dsa_vdf *dsa_vdf_create_root(const char *key);
extern struct dsa_vdf *dsa_vdf_get_name(struct dsa_vdf *vdf, const char **name);
extern struct dsa_vdf *dsa_vdf_get_type(struct dsa_vdf *vdf, enum dsa_vdf_value_type *type);
extern struct dsa_vdf *dsa_vdf_get_int(struct dsa_vdf *vdf, int *val);
extern struct dsa_vdf *dsa_vdf_get_float(struct dsa_vdf *vdf, float *val);
extern struct dsa_vdf *dsa_vdf_get_str(struct dsa_vdf *vdf, const char **val);
extern struct dsa_vdf *dsa_vdf_mutate(struct dsa_vdf *vdf, enum dsa_vdf_value_type tgt_type);
extern struct dsa_vdf *dsa_vdf_mutate_as_inval(struct dsa_vdf *vdf);
extern struct dsa_vdf *dsa_vdf_mutate_as_int(struct dsa_vdf *vdf);
extern struct dsa_vdf *dsa_vdf_mutate_as_float(struct dsa_vdf *vdf);
extern struct dsa_vdf *dsa_vdf_mutate_as_str(struct dsa_vdf *vdf);
extern struct dsa_vdf *dsa_vdf_mutate_as_list(struct dsa_vdf *vdf);
extern struct dsa_vdf *dsa_vdf_unset(struct dsa_vdf *vdf);
extern struct dsa_vdf *dsa_vdf_set_int(struct dsa_vdf *vdf, int val);
extern struct dsa_vdf *dsa_vdf_set_float(struct dsa_vdf *vdf, float val);
extern struct dsa_vdf *dsa_vdf_set_str(struct dsa_vdf *vdf, const char *val);
extern struct dsa_vdf *dsa_vdf_set_list(struct dsa_vdf *vdf);
extern struct dsa_vdf *dsa_vdf_list_get_entry(struct dsa_vdf *vdf, const char *key);
extern struct dsa_vdf *dsa_vdf_list_get_entry_count(struct dsa_vdf *vdf, size_t *count);
extern struct dsa_vdf *dsa_vdf_list_get_entry_by_idx(struct dsa_vdf *vdf, size_t idx);
extern struct dsa_vdf *dsa_vdf_list_create_entry(struct dsa_vdf *vdf, const char *key);
extern struct dsa_vdf *dsa_vdf_list_open_entry(struct dsa_vdf *vdf, const char *key);
extern struct dsa_vdf *dsa_vdf_vget_path(struct dsa_vdf *vdf, va_list ap);
extern struct dsa_vdf *dsa_vdf_get_path(struct dsa_vdf *vdf, ...);
extern struct dsa_vdf *dsa_vdf_vcreate_path(struct dsa_vdf *vdf, va_list ap);
extern struct dsa_vdf *dsa_vdf_create_path(struct dsa_vdf *vdf, ...);
extern struct dsa_vdf *dsa_vdf_vopen_path(struct dsa_vdf *vdf, va_list ap);
extern struct dsa_vdf *dsa_vdf_open_path(struct dsa_vdf *vdf, ...);
extern char *dsa_vdf_serialize(struct dsa_vdf *vdf, size_t *size);
extern struct dsa_vdf *dsa_vdf_destroy(struct dsa_vdf *vdf);
extern struct dsa_vdf *dsa_vdf_destroy_root(struct dsa_vdf *vdf);

#endif /* VDF_VDF_H */
