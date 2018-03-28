#ifndef OS_OS_H
#define OS_OS_H 1

struct dsa_os_mutex;

extern const char *dsa_os_get_home_dir(void);
extern const char *dsa_os_get_steam_dir(void);
extern struct dsa_os_mutex *dsa_os_mutex_create(void);
extern void dsa_os_mutex_destroy(struct dsa_os_mutex *mtx);
extern int dsa_os_mutex_lock(struct dsa_os_mutex *mtx);
extern int dsa_os_mutex_trylock(struct dsa_os_mutex *mtx);
extern int dsa_os_mutex_unlock(struct dsa_os_mutex *mtx);
extern int dsa_os_mkdir(const char *path);

#endif /* OS_OS_H */
