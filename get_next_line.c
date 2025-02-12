#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int ft_strlen(const char *str)
{
    int i = 0;
    while (str && str[i])
        i++;
    return (i);
}
void ft_bzero(void *s, int n)
{
    unsigned char *ptr = s;
    while (n--)
        *ptr++ = 0;
    
}
char *ft_strchr(const char *str, int c)
{
    while (*str)
    {
        if (*str == (char)c)
            return (char *)str;
        str++;
    }
    return NULL;
}

void    move_buffer(char *buffer)
{
    int i = 0;
    int j = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] != '\n')
        i++;
    while (buffer[i])
        buffer[j++] = buffer[i++];
    while (buffer[j])
        buffer[j++] = 0;
}
char    *join_buffer_to_line(char *buffer, char *line)
{
    int i = 0;
    int j = 0;
    int new_len = ft_strlen(buffer) + ft_strlen(line) + 2;
    char *res = malloc(new_len);
    if (!res)
        return NULL;
    while (line[i])
    {
        res[i] = line[i];
        i++;
    }
    free(line);
    while (buffer[j])
    {
        res[i] = buffer[j];
        if (buffer[j] == '\n')
            break;
        i++;
        j++;
    }
    res[i + 1] = '\n';
    return res;
}
char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    char *n;

    line = malloc(1);
    if (!line)
        return NULL;
    line[0] = '\0';
    while (1)
    {
        n = ft_strchr(buffer, '\n');
        line = join_buffer_to_line(buffer, line);
        if (!line || n)
            break;
        ft_bzero(buffer, BUFFER_SIZE + 1);
        if (read(fd, buffer, BUFFER_SIZE) <= 0)
            break;
    }
    move_buffer(buffer);
    if (ft_strlen(line) == 0)
    {
        free(line);
        return NULL;
    }
    return line;
}

// int main()
// {
// 	int bs = BUFFER_SIZE;
// 	printf("buffer size is %d\n", bs);
// 	char	*line;
// 	int		fd;

// 	fd = open("test", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		printf("----------\n");
// 		free(line);
// 	}
// 	return 0;
// }