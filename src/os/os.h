#ifndef OS_OS_H
#define OS_OS_H 1

struct dsa_os_thread;
struct dsa_os_mutex;
struct dsa_os_semaphore;

typedef void (*dsa_os_thread_entry_point_t)(void *arg);

extern const char *dsa_os_get_home_dir(void);
extern const char *dsa_os_get_steam_dir(void);
extern struct dsa_os_thread *dsa_os_thread_create(dsa_os_thread_entry_point_t ep, void *arg);
extern void dsa_os_thread_destroy(struct dsa_os_thread *thrd);
extern int dsa_os_thread_kill(struct dsa_os_thread *thrd);
extern int dsa_os_thread_wait(struct dsa_os_thread *thrd);
extern int dsa_os_thread_trywait(struct dsa_os_thread *thrd);
extern void dsa_os_thread_yield(void);
extern struct dsa_os_mutex *dsa_os_mutex_create(void);
extern void dsa_os_mutex_destroy(struct dsa_os_mutex *mtx);
extern int dsa_os_mutex_lock(struct dsa_os_mutex *mtx);
extern int dsa_os_mutex_trylock(struct dsa_os_mutex *mtx);
extern int dsa_os_mutex_unlock(struct dsa_os_mutex *mtx);
extern struct dsa_os_semaphore *dsa_os_semaphore_create(unsigned int val);
extern void dsa_os_semaphore_destroy(struct dsa_os_semaphore *sem);
extern int dsa_os_semaphore_signal(struct dsa_os_semaphore *sem);
extern int dsa_os_semaphore_wait(struct dsa_os_semaphore *sem);
extern int dsa_os_semaphore_trywait(struct dsa_os_semaphore *sem);
extern int dsa_os_mkdir(const char *path);

#endif /* OS_OS_H */
