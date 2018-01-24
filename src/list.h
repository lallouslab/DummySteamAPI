#ifndef LIST_H
#define LIST_H 1

#include <stdatomic.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct list_elem
{
	struct list_elem *prev;
	struct list_elem *next;
	size_t data_size;
	char data[];
};

struct list
{
	atomic_uint locked;
	struct list_elem *head;
	struct list_elem *tail;
};

static inline int list_init(struct list *l) {
	atomic_store(&l->locked, 0);
	l->head = NULL;
	l->tail = NULL;

	return 0;
}

static inline int list_trylock(struct list *l) {
	unsigned int expected = 0;

	return atomic_compare_exchange_weak(&l->locked, &expected, 1) ? 0 : -1;
}

static inline int list_lock(struct list *l) {
	while (list_trylock(l) < 0);

	return 0;
}

static inline int list_unlock(struct list *l) {
	atomic_store(&l->locked, 0);

	return 0;
}

static inline struct list_elem *list_head(struct list *l) {
	return l->head;
}

static inline struct list_elem *list_tail(struct list *l) {
	return l->tail;
}

static inline struct list_elem *list_prev(struct list_elem *elem) {
	if (!elem)
		return NULL;

	return elem->prev;
}

static inline struct list_elem *list_next(struct list_elem *elem) {
	if (!elem)
		return NULL;

	return elem->next;
}

static inline void *list_get_data(struct list_elem *elem) {
	return (void *)elem->data;
}

static inline int list_push(struct list *l, void *data, size_t data_size) {
	struct list_elem *elem;

	elem = malloc(sizeof(*elem) + data_size);
	if (!elem)
		return -1;

	elem->prev = l->tail;
	elem->next = NULL;
	elem->data_size = data_size;
	memcpy(elem->data, data, data_size);

	if (l->tail)
		l->tail->next = elem;
	else
		l->head = elem;

	l->tail = elem;

	return 0;
}

static int list_remove(struct list *l, struct list_elem *elem) {
	if (!elem)
		return -1;

	if (elem->prev)
		elem->prev->next = elem->next;

	if (elem->next)
		elem->next->prev = elem->prev;

	if (elem == l->head)
		l->head = elem->next;

	if (elem == l->tail)
		l->tail = elem->prev;

	free(elem);

	return 0;
}

static inline int list_pop(struct list *l) {
	list_remove(l, l->tail);

	return 0;
}

static inline int list_clear(struct list *l) {
	while (l->tail)
		list_pop(l);

	return 0;
}

#endif /* LIST_H */
