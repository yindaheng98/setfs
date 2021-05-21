/*
  Big Brother File System
  Copyright (C) 2012 Joseph J. Pfeiffer, Jr., Ph.D. <pfeiffer@cs.nmsu.edu>

  This program can be distributed under the terms of the GNU GPLv3.
  See the file COPYING.

  This code is derived from function prototypes found /usr/include/fuse/fuse.h
  Copyright (C) 2001-2007  Miklos Szeredi <miklos@szeredi.hu>
  His code is licensed under the LGPLv2.
  A copy of that code is included in the file fuse.h
  
  The point of this FUSE filesystem is to provide an introduction to
  FUSE.  It was my first FUSE filesystem as I got to know the
  software; hopefully, the comments in this code will help people who
  follow later to get a gentler introduction.

  This might be called a no-op filesystem:  it doesn't impose
  filesystem semantics on top of any other existing structure.  It
  simply reports the requests that come in, and passes them to an
  underlying filesystem.  The information is saved in a logfile named
  bbfs.log, in the directory from which you run bbfs.
*/
#include "config.h"
#define FUSE_USE_VERSION 26

#include <fuse.h>
#include <stdio.h>
#ifdef HAVE_SYS_XATTR_H
#include <sys/xattr.h>
#endif

struct fuse_operations setfs_oper = {
    .getattr = NULL,
    .readlink = NULL,
    //.getdir = NULL,
    .mknod = NULL,
    .mkdir = NULL,
    .unlink = NULL,
    .rmdir = NULL,
    .symlink = NULL,
    .rename = NULL,
    .link = NULL,
    .chmod = NULL,
    .chown = NULL,
    .truncate = NULL,
    //.utime = NULL,
    .open = NULL,
    .read = NULL,
    .write = NULL,
    .statfs = NULL,
    .flush = NULL,
    .release = NULL,
    .fsync = NULL,

#ifdef HAVE_SYS_XATTR_H
    .setxattr = NULL,
    .getxattr = NULL,
    .listxattr = NULL,
    .removexattr = NULL,
#endif

    .opendir = NULL,
    .readdir = NULL,
    .releasedir = NULL,
    .fsyncdir = NULL,
    .init = NULL,
    .destroy = NULL,
    .access = NULL,
    .create = NULL,
    .ftruncate = NULL,
    .fgetattr = NULL,
    .lock = NULL,
    .utimens = NULL,
    .bmap = NULL};

int main(int argc, char *argv[])
{
    int fuse_stat;

    // turn over control to fuse
    fprintf(stderr, "about to call fuse_main\n");
    fuse_stat = fuse_main(argc, argv, &setfs_oper, NULL);
    fprintf(stderr, "fuse_main returned %d\n", fuse_stat);

    return fuse_stat;
}
