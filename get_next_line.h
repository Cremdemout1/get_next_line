/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:01:57 by yohan             #+#    #+#             */
/*   Updated: 2024/01/12 09:04:38 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXTLINE_H
#define NEXTLINE_H
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif
 
void	*ft_memcpy(void *dest, const void *src, size_t n);
void    ft_strcpy(char *dest, char *src);
int     ft_strlen(char *str);
size_t  ft_strlcat(char *dest, const char *src, size_t sizeofbuf);
size_t	ft_strlcpy(char *dest, const char *src, size_t i);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strchr(const char *s, int c);
char    *get_next_line(int fd);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_bzero(void *str, size_t nb);

#endif