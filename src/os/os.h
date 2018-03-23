#ifndef OS_OS_H
#define OS_OS_H 1

extern int dsa_os_init(void);
extern int dsa_os_deinit(void);
extern const char *dsa_os_get_home_dir(void);
extern const char *dsa_os_get_steam_dir(void);
extern int dsa_os_mkdir(const char *path);

#endif /* OS_OS_H */
