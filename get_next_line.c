/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_try.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:15:08 by yohan             #+#    #+#             */
/*   Updated: 2024/01/12 07:36:29 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *clear_after_NewLine(char *buffer, char newline)
{
    if (buffer == NULL)
        return (NULL);
    int i;

    i = 0;
    while (buffer[i] && buffer[i] != newline)
        i++;
    if (buffer[i] == newline)
        i++;
    
    buffer[i] = '\0';
    /* while (buffer[i] && buffer[i] != '\0')
    {
        buffer[i] = '\0';
        i++;
    } */
    return (buffer);
}

char *join_Line(char *result, char *addition)
{
    if (!addition)
        return (result);
    if (ft_strchr(addition, '\n'))
        addition = clear_after_NewLine(addition, '\n');

    result = ft_strjoin(result, addition); 
    return (result);
}

char *read_Until_NewLine(char *result, char *buffer, int fd)
{
    int bytes_Read;
    
    bytes_Read = read (fd, buffer, BUFFER_SIZE);
    if (bytes_Read <= 0)
        return (NULL);
        
    while (bytes_Read > 0)
    {
        result = join_Line(result, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
        bytes_Read = read (fd, buffer, BUFFER_SIZE);
    }
    
    return (result);
}

char *ft_read_line(char *result, char *buffer, int fd)
{
    if (read (fd, 0, 0) < 0)
        return ("NULL");
        
    result = read_Until_NewLine(result, buffer, fd);
    free (buffer);
    return (result);
}

char *get_next_line(int fd)
{
    char *result;
    result = ft_calloc (BUFFER_SIZE + 1, 4);
    if (result == NULL)
        return (NULL);
    char *buffer;
    buffer = ft_calloc (BUFFER_SIZE + 1, 4);
    if (buffer == NULL)
        return (NULL);
    result = ft_read_line(result, buffer, fd);
    return (result);
}

int main (void)
{
    char *line;
    int fd = open("file2.txt", O_RDONLY);
    line = get_next_line(fd);
    printf ("|1|%s", line);
    free (line);
    
    line = get_next_line(fd);
    printf ("|2|%s", line);
    free(line);
    
    line = get_next_line(fd);
    printf ("|3|%s", line);
    free (line);
    
    line = get_next_line(fd);
    printf ("|4|%s", line);
    free (line);
    
    line = get_next_line(fd);
    printf ("|5|%s", line);
    free (line);
    
    return (0);
}