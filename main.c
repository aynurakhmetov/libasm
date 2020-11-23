#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp( const char * string1, const char * string2 );
char	*ft_strdup(const char *str);
size_t	ft_write(int fd,const void *buf, size_t count);
size_t	ft_read(int fd,const void *buf, size_t count);

int main()
{
	//TEST ft_strlen
	char *s;
	int i;

	s = "hello";
	i = 0;
	printf("TEST 1 ft_strlen 5 = %d\n", ft_strlen(s));


	//TEST ft_strcpy
	char s1[5];
	char *s2;
	s2 = "01234";
	ft_strcpy(s1, s2);
	printf("TEST 2 ft_strcpy %s\n", s1);

	//TEST ft_strcmp
	char *s3, *s4;
	int k, l;
	s3 = "";
	s4 = "";
	k = ft_strcmp(s3, s4);
	l = strcmp(s3, s4);
	printf("TEST 3 ft_strcmp = %d strcmp = %d\n", k, l);

	//TEST ft_strdup
	char *s5, *s6;
	s5 = "111121111111122211111111122111111111";
	s6 = ft_strdup(s5);
	printf("TEST 4 ft_strdup = %s\n", s6);

	//TEST ft_write
	char *str = "lfdgkjfgjfdkljgldjlkjdfgj";
	k = ft_write(-1, str, ft_strlen(str));
	printf("%d\n", k);
	
	//TEST ft_write
	char buf[1000];
	buf[999] = '\0';
	ft_read(0, buf, 100);
	printf("%s\n", buf);

	return (0);
}

