#ifndef JOBSERVER_H
#define JOBSERVER_H 1

typedef void (*dsa_jobserver_callback_t)(void *arg);

extern int dsa_jobserver_init(void);
extern int dsa_jobserver_deinit(void);
extern int dsa_jobserver_schedule(dsa_jobserver_callback_t callback, void *arg, size_t arg_size);

#endif /* JOBSERVER_H */
