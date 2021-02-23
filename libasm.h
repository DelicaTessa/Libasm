/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 13:24:30 by tclement      #+#    #+#                 */
/*   Updated: 2021/02/22 11:24:25 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>

extern  size_t  ft_strlen(const char *s);
extern  char    *ft_strcpy(char *dst, char *src);
extern  char    *ft_strdup(const char *s1);
extern  int     ft_strcmp(const char* s1, const char *s2);
extern  ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
extern  ssize_t ft_read(int fildes, void *buf, size_t nbyte);

#endif