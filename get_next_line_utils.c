/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:17:11 by yohan             #+#    #+#             */
/*   Updated: 2024/01/11 12:39:14 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

int    ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

	size_t	ft_strlcat(char *dest, const char *src, size_t sizeofbuf)
	{
		size_t	i;
		int		j;
		int		k;

		i = 0;
		j = 0;
		k = 0;
		while (dest[i])
			i++;
	while (src[j])
	j++;
	if (sizeofbuf <= i)
	j += sizeofbuf;
	else
	j += i;
	while (src[k] && i + 1 < sizeofbuf)
	{
	dest[i] = src[k];
	i++;
	k++;
	}
	dest[i] = '\0';
	return (j);
	}

size_t	ft_strlcpy(char *dest, const char *src, size_t i)
{
	size_t	j;
	size_t	len;

	j = 0;
	len = 0;
	while (src[len])
		len++;
	if (i > 0)
	{
		while (src[j] && j < (i - 1))
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*full;

	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	
	full = (char *)malloc(((i + j + 1)) * sizeof(char));
	
	if (full == NULL)
		return (NULL);
		
	ft_strlcpy(full, s1, i + 1);
	ft_strlcat(full, s2, i + j + 1);
	return (full);
}

char	*ft_strchr(const char *s, int c)
{
    int	i;

    i = 0;
    while (s[i] != (char)c && s[i] != '\0')
        s++;
    if (s[i] == (char)c)
       return ((char *)s);
    return (0);
} 

char	*ft_substr(char *s, int start, int len)
{
	int	j;
	char	*str;

	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (start < ft_strlen(s) && j < len)
	{
		str[j++] = s[start++];
	}
	str[j] = '\0';
	return (str);
}
