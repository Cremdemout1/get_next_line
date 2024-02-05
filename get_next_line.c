/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3rd_rep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:13:59 by yohan             #+#    #+#             */
/*   Updated: 2024/02/05 16:49:36 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *static_fix(char *line)
{
    char *temp;
    int i;

    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    temp = ft_substr(line, i + 1, ft_strlen(line) - i);
    if (*temp == '\0')
    {
        free (temp);
        return (NULL);
    }
    line[i + 1] = '\0';
    return (temp);
}

char *read_file(int fd, char *buffer, char *held)
{
    char *temp;
    int readed;

    readed = 1;
    while (readed != '\0')
    {
        readed = read (fd, buffer, BUFFER_SIZE);
        if (readed < 0)
            return (NULL);
        if (readed == 0)
            break;
        buffer[readed] = '\0';

        if (held == NULL)
            held = malloc (1);
        temp = held;
        held = ft_strjoin(temp, buffer);
        free (temp);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    return (held);
}

char *get_next_line(int fd)
{
    static char *held;
    char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
        
    buffer = malloc (sizeof (char) * BUFFER_SIZE);
    if (buffer == NULL)
        return (NULL); 
    line = read_file (fd, buffer, held);
    free (buffer);
    if (line == NULL)
    {
        free (held);
        held = NULL;
        return (NULL);
    }
    held = static_fix(line);
    return (line);
}

int main (void)
{
    int fd;
    char *line;
    int i;

    fd = open ("lines.txt", O_RDONLY);
    i = 1;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf ("|%d| %s", i, line);
        i++;
        free (line);
    }
    return (0);
}