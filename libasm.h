#ifndef LIBASM_H
# define LIBASM_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp( const char *str1, const char *str2);
char	*ft_strdup(const char *str);
size_t	ft_write(int fd,const void *buf, size_t count);
size_t	ft_read(int fd,const void *buf, size_t count);

#endif