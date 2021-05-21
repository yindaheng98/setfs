#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([setfs], [1.0], [yindaheng98@163.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.y
PKG_CHECK_MODULES(FUSE, fuse)

# Checks for header files.
AC_CHECK_HEADERS([sys/xattr.h])
AC_CHECK_HEADERS([attr/xattr.h])
AC_CHECK_HEADERS([sys/extattr.h])
AC_CHECK_FUNCS([fallocate])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
