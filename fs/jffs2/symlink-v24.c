/*
 * JFFS2 -- Journalling Flash File System, Version 2.
 *
 * Copyright (C) 2001, 2002 Red Hat, Inc.
 *
 * Created by David Woodhouse <dwmw2@infradead.org>
 *
 * For licensing information, see the file 'LICENCE' in this directory.
 *
 * $Id: symlink-v24.c,v 1.19 2005/11/07 11:14:42 gleixner Exp $
 *
 */


#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include "nodelist.h"

int jffs2_readlink(struct dentry *dentry, char *buffer, int buflen);
int jffs2_follow_link(struct dentry *dentry, struct nameidata *nd);

struct inode_operations jffs2_symlink_inode_operations =
{
	.readlink =	jffs2_readlink,
	.follow_link =	jffs2_follow_link,
	.setattr =	jffs2_setattr
};

int jffs2_readlink(struct dentry *dentry, char *buffer, int buflen)
{
	struct jffs2_inode_info *f = JFFS2_INODE_INFO(dentry->d_inode);

	if (!f->target) {
		printk(KERN_ERR "jffs2_readlink(): can't find symlink taerget\n");
		return -EIO;
	}

	return vfs_readlink(dentry, buffer, buflen, (char *)f->target);
}

int jffs2_follow_link(struct dentry *dentry, struct nameidata *nd)
{
	struct jffs2_inode_info *f = JFFS2_INODE_INFO(dentry->d_inode);

	if (!f->target) {
		printk(KERN_ERR "jffs2_follow_link(): can't find symlink taerget\n");
		return -EIO;
	}

	return vfs_follow_link(nd, (char *)f->target);
}
