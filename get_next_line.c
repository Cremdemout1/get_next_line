/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_try.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:15:08 by yohan             #+#    #+#             */
/*   Updated: 2024/01/16 13:04:19 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *buf_fix(char *buffer, int newline)
{
    int i;

    i = 0;
    while (buffer[newline])
    {
       if (buffer[newline] == '\n')
       {
            while (buffer[i])
            {
                buffer[i] = buffer[newline];
                i++;
                newline++;
            }
        newline++;
       }
    buffer[i] = '\0';
    }
    return (buffer);
}

char *splitBufferBeforeAndAfterNL(char *buffer, char newline)
{
    char *before_Newline;

    before_Newline = ft_calloc(BUFFER_SIZE + 1, 1);
    if (before_Newline == NULL)
        return (NULL);

    int i;

    i = 0;
    while (buffer[i] && buffer[i] != newline)
    {
        before_Newline[i] = buffer[i];
        i++;
    }
    before_Newline[i] = '\0';
    buf_fix(buffer, i);
    return (before_Newline);
}

char *join_Line(char *result, char *buffer)
{
    
    if (!buffer)
        return (result);
    if (!ft_strchr(buffer, '\n'))
        result = ft_strjoin(result, buffer);
    if (ft_strchr(buffer, '\n'))
    {
        char *before_Newline = splitBufferBeforeAndAfterNL(buffer, '\n');
        result = ft_strjoin(result, before_Newline);
        free(before_Newline);
    }
    return (result);
}

char *ft_read_line(char *result, char *buffer, int fd)
{
    if (read (fd, 0, 0) < 0)
        return ("NULL");
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

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];

    char *result;
    
    result = ft_calloc (BUFFER_SIZE + 1, 4);
    if (result == NULL)
        return (NULL);
        
    if (ft_strlen(buffer) > 0) // check if buffer is not empty
        result = ft_strjoin(result, buffer);
        
    result = ft_read_line(result, buffer, fd);
    
    return (result);
}

int main (void)
{
    char *line;
    int fd = open("file2.txt", O_RDONLY);
    line = get_next_line(fd);
    printf ("|1|%s\n", line);
    free (line);
    
    line = get_next_line(fd);
    printf ("|2|%s\n", line);
    free(line);
    
    line = get_next_line(fd);
    printf ("|3|%s\n", line);
    free (line);
    
    line = get_next_line(fd);
    printf ("|4|%s\n", line);
    free (line);
    
    line = get_next_line(fd);
    printf ("|5|%s\n", line);
    free (line);
    
    line = get_next_line(fd);
    printf ("|6|%s\n", line);
    free (line);

    return (0);
}