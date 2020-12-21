/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 22:42:54 by gmarva            #+#    #+#             */
/*   Updated: 2020/11/29 22:42:56 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main()
{
	char s[]="123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678";
	char s1[10000];
	char *s2;

	printf("\n");

	// ft_strlen
	printf(FBLUE BWHITE"=====TEST ft_strlen:====="NONEL);
	// Try ft_strlen with an empty string
	printf(FGREEN W"Original  = "NONE);
    printf("%ld\n", strlen(""));
	printf("My        = ");
    printf("%ld\n", ft_strlen(""));
	// Try ft_strlen with a very long string
	printf(FGREEN W"Original  = "NONE);
    printf("%ld\n", strlen(s));
	printf("My        = ");
    printf("%ld\n", ft_strlen(s));
	
	// ft_strcpy
	printf(FBLUE BWHITE"=====TEST ft_strcpy:====="NONEL);
	// Try ft_strcpy with an empty string
	printf(FGREEN W"Original  = "NONE);
    printf("%s\n", strcpy(s1, ""));
	printf("My        = ");
    printf("%s\n", ft_strcpy(s1, ""));
	// Try ft_strcpy with a very long string
	printf(FGREEN W"Original  = "NONE);
    printf("%s\n", strcpy(s1, s));
	printf("My        = ");
    printf("%s\n", ft_strcpy(s1, s));

	// ft_strcmp
	printf(FBLUE BWHITE"=====TEST ft_strcmp:====="NONEL);
	// Try ft_strcmp with 2 empty strings
	printf(FGREEN W"Original  = "NONE);
    printf("%d\n", strcmp("", ""));
	printf("My        = ");
    printf("%d\n", ft_strcmp("", ""));
	// Try ft_strcmp with 1 empty string as first argument
	printf(FGREEN W"Original  = "NONE);
    printf("%d\n", strcmp("", s));
	printf("My        = ");
    printf("%d\n", ft_strcmp("", s));
	// Try ft_strcmp with 1 empty string as second argument
	printf(FGREEN W"Original  = "NONE);
    printf("%d\n", strcmp(s, ""));
	printf("My        = ");
    printf("%d\n", ft_strcmp(s, ""));
	// Try ft_strcmp with multiple strings, equal or not, think about switching them
	printf(FGREEN W"Original  = "NONE);
    printf("%d\n", strcmp(s, s));
	printf("My        = ");
    printf("%d\n", ft_strcmp(s, s));

	// ft_write
	// Try ft_write with the stdout
	printf(FBLUE BWHITE"=====TEST ft_write:====="NONEL);
	printf(FGREEN W"Original  = "NONEL);
	errno = 0;
	printf(" %ld, %d\n", write(1, s, strlen(s)), errno);
	printf("My        = \n");
	errno = 0;
	printf(" %ld, %d\n", ft_write(1, s, strlen(s)), errno);
	// Try ft_write with an open file descriptor
	int fd = open("file", O_WRONLY);
	printf(FGREEN W"Original  = \n"NONE);
	errno = 0;
	//printf("%ld, %d\n", write(fd, s, strlen(s)), errno);
	printf("My        = \n");
	errno = 0;
	printf("%ld, %d\n", ft_write(fd, s, strlen(s)), errno);
	close(fd);
	// Try ft_write with a wrong file descriptor
	printf(FGREEN W"Original  = \n"NONE);
	errno = 0;
	printf("%ld, %d\n", write(-1, s, strlen(s)), errno);
	printf("My        = \n");
	errno = 0;
	printf("%ld, %d\n", ft_write(-1, s, strlen(s)), errno);
	printf(FGREEN W"Original  = \n"NONE);
	errno = 0;
	printf("%ld, %d\n", write(0, NULL, strlen(s)), errno);
	printf("My        = \n");
	errno = 0;
	printf("%ld, %d\n", ft_write(0, NULL, strlen(s)), errno);
	printf(FGREEN W"Original  = \n"NONE);
	errno = 0;
	printf("%ld, %d\n", write(0, s, -1), errno);
	printf("My        = \n");
	errno = 0;
	printf("%ld, %d\n", ft_write(0, s, -1), errno);
	printf("\n");

	// ft_read
	char s10[5];
	printf(FBLUE BWHITE"=====TEST ft_read:====="NONEL);
	// Try ft_read with the stdin
	printf(FGREEN W"Original  = "NONEL);
	errno = 0;
	printf("%ld, %s, %d\n", read(0, s10, 100), s10, errno);
	printf("My        = \n");
	errno = 0;
	printf("%ld, %s, %d\n", ft_read(0, s10, 100), s10, errno);
	// Try ft_read with an open file descriptor
	printf(FGREEN W"Original  = \n"NONE);
	char *s11;
	s11 = malloc(5);
	fd = open("file", O_RDONLY);
	errno = 0;
	printf("%ld, %s, %d\n", read(fd, s11, 5), s11, errno);
	close(fd);
	printf("My        = \n");
	fd = open("file", O_RDONLY);
	errno = 0;
	printf("%ld, %s, %d\n", ft_read(fd, s11, 5), s11, errno);
	close(fd);
	// Try ft_read with a wrong file descriptor
	printf(FGREEN W"Original  = \n"NONE);
	errno = 0;
	printf("%ld, %s, %d\n", read(-1, s1, 10), s1, errno);
	printf("My        = \n");
	errno = 0;
	printf("%ld, %s, %d\n", ft_read(-1, s1, 10), s1, errno);
	fd = open("file", O_RDONLY);
	printf(FGREEN W"Original  = \n"NONE);
	fd = open("file", O_RDONLY);
	errno = 0;
	printf("%ld, %s, %d\n", read(fd, NULL, 100), s1, errno);
	close(fd);
	printf("My        = \n");
	fd = open("file", O_RDONLY);
	errno = 0;
	printf("%ld, %s, %d\n", ft_read(fd, NULL, 100), s1, errno);
	close(fd);
	printf(FGREEN W"Original  = \n"NONE);
	fd = open("file", O_RDONLY);
	errno = 0;
	printf("%ld, %s, %d\n", read(fd, s1, -1), s1, errno);
	close(fd);
	printf("My        = \n");
	fd = open("file", O_RDONLY);
	errno = 0;
	printf("%ld, %s, %d\n", ft_read(fd, s1, -1), s1, errno);
	close(fd);
	printf("\n");
	
	// ft_strdup
	printf(FBLUE BWHITE"=====TEST ft_strdup:====="NONEL);
	// Try ft_strdup with an empty string
	s2 = strdup("");
	printf(FGREEN W"Original  = "NONE);
	printf("%s, len = %ld\n", s2, strlen(s2));
	free(s2);
	s2 = ft_strdup("");
	printf("My        = ");
	printf("%s, len = %ld\n", s2, ft_strlen(s2));
	free(s2);
	// Try ft_strdup with a very long string
	s2 = strdup(s);
	printf(FGREEN W"Original  = "NONE);
	printf("%s, len = %ld\n", s2, strlen(s2));
	free(s2);
	s2 = ft_strdup(s);
	printf("My        = ");
	printf("%s, len = %ld\n", s2, ft_strlen(s2));
	free(s2);
	char str[]= "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. In massa tempor nec feugiat. Viverra vitae congue eu consequat ac felis donec et odio. Iaculis nunc sed augue lacus. Lacus laoreet non curabitur gravida arcu ac. Sit amet aliquam id diam maecenas ultricies. Consequat interdum varius sit amet mattis vulputate enim nulla. Lorem sed risus ultricies tristique nulla aliquet. Non nisi est sit amet. Sollicitudin aliquam ultrices sagittis orci a. Eget lorem dolor sed viverra ipsum nunc. Elit ut aliquam purus sit amet luctus venenatis. Nulla pellentesque dignissim enim sit amet venenatis urna. Tellus orci ac auctor augue. Est placerat in egestas erat imperdiet sed euismod.\
Commodo viverra maecenas accumsan lacus vel facilisis volutpat est. Sit amet massa vitae tortor condimentum lacinia quis vel eros. In nibh mauris cursus mattis. Lectus urna duis convallis convallis tellus id interdum. Blandit massa enim nec dui nunc mattis enim ut. Ullamcorper a lacus vestibulum sed arcu non odio. Convallis aenean et tortor at risus viverra adipiscing at. Sed egestas egestas fringilla phasellus. Lacus laoreet non curabitur gravida arcu ac tortor dignissim convallis. Id cursus metus aliquam eleifend. Fringilla phasellus faucibus scelerisque eleifend donec pretium. Arcu bibendum at varius vel pharetra vel.\
Volutpat diam ut venenatis tellus in metus vulputate eu scelerisque. Fermentum leo vel orci porta non pulvinar neque laoreet suspendisse. Viverra vitae congue eu consequat ac felis donec. Rhoncus mattis rhoncus urna neque viverra justo. Elementum integer enim neque volutpat ac tincidunt vitae semper quis. Viverra vitae congue eu consequat. Augue mauris augue neque gravida in fermentum. Diam vulputate ut pharetra sit amet aliquam. Amet est placerat in egestas erat imperdiet. Venenatis tellus in metus vulputate eu. Sed risus ultricies tristique nulla aliquet enim. Iaculis eu non diam phasellus vestibulum lorem sed risus.\
Porta lorem mollis aliquam ut porttitor leo a. Nam libero justo laoreet sit amet. Nunc sed id semper risus in hendrerit. Ut diam quam nulla porttitor massa id neque aliquam. Nunc vel risus commodo viverra maecenas. Porta non pulvinar neque laoreet suspendisse. Integer malesuada nunc vel risus commodo. Odio facilisis mauris sit amet. Nunc sed velit dignissim sodales ut eu sem integer vitae. Habitant morbi tristique senectus et netus et malesuada fames. Risus at ultrices mi tempus imperdiet nulla malesuada pellentesque elit. Pellentesque eu tincidunt tortor aliquam nulla. Ultrices vitae auctor eu augue. Tellus rutrum tellus pellentesque eu. Non pulvinar neque laoreet suspendisse interdum. Ultrices mi tempus imperdiet nulla malesuada pellentesque elit. Ullamcorper malesuada proin libero nunc consequat interdum varius sit. Et sollicitudin ac orci phasellus egestas tellus rutrum tellus. Sollicitudin nibh sit amet commodo nulla facilisi nullam vehicula ipsum.\
Pretium lectus quam id leo in vitae turpis. Eros donec ac odio tempor orci dapibus. Purus gravida quis blandit turpis cursus in hac. Tincidunt dui ut ornare lectus sit amet est placerat in. Mi quis hendrerit dolor magna. Pulvinar sapien et ligula ullamcorper malesuada proin libero nunc consequat. Aliquam eleifend mi in nulla posuere. Facilisi morbi tempus iaculis urna id volutpat lacus laoreet. Fames ac turpis egestas integer eget aliquet nibh. Mus mauris vitae ultricies leo integer.\
Quam id leo in vitae turpis. Vitae elementum curabitur vitae nunc. Donec pretium vulputate sapien nec sagittis aliquam malesuada bibendum arcu. Tellus cras adipiscing enim eu turpis egestas pretium aenean. Pretium lectus quam id leo in vitae turpis. Diam maecenas ultricies mi eget. Nisi porta lorem mollis aliquam ut porttitor leo a diam. Facilisi cras fermentum odio eu. Pulvinar etiam non quam lacus suspendisse faucibus interdum posuere lorem. Amet consectetur adipiscing elit pellentesque habitant. Sed nisi lacus sed viverra tellus in hac habitasse. Malesuada fames ac turpis egestas integer eget aliquet. Eu ultrices vitae auctor eu augue ut lectus. Sed felis eget velit aliquet sagittis id consectetur. Nascetur ridiculus mus mauris vitae ultricies leo. Interdum velit laoreet id donec ultrices tincidunt arcu non.\
Facilisis gravida neque convallis a cras semper auctor neque vitae. Pellentesque habitant morbi tristique senectus et netus. Nullam non nisi est sit. Eget dolor morbi non arcu risus quis varius quam quisque. Elit duis tristique sollicitudin nibh sit amet commodo nulla. Nunc mattis enim ut tellus. Faucibus interdum posuere lorem ipsum dolor sit. Augue eget arcu dictum varius duis at consectetur. Leo vel fringilla est ullamcorper eget nulla facilisi etiam dignissim. Risus quis varius quam quisque id diam vel quam elementum. Faucibus nisl tincidunt eget nullam. Sit amet dictum sit amet justo donec enim. Aliquam faucibus purus in massa tempor nec feugiat. In est ante in nibh mauris cursus. Sed sed risus pretium quam vulputate dignissim. Amet justo donec enim diam vulputate ut pharetra. Cursus turpis massa tincidunt dui ut ornare lectus sit amet. Cras sed felis eget velit. Enim nunc faucibus a pellentesque sit amet porttitor eget.\
Viverra orci sagittis eu volutpat odio. Consequat semper viverra nam libero justo. Venenatis cras sed felis eget. Nibh cras pulvinar mattis nunc sed blandit libero volutpat. Sagittis eu volutpat odio facilisis mauris. Nisl nunc mi ipsum faucibus vitae aliquet nec ullamcorper. Amet venenatis urna cursus eget. Id volutpat lacus laoreet non. Mauris ultrices eros in cursus turpis. Accumsan lacus vel facilisis volutpat. Tempor orci dapibus ultrices in iaculis nunc sed augue. Sit amet nulla facilisi morbi tempus iaculis urna id. Ornare arcu dui vivamus arcu felis bibendum ut tristique et. Mauris rhoncus aenean vel elit scelerisque. Ante metus dictum at tempor commodo. Tellus cras adipiscing enim eu. Scelerisque felis imperdiet proin fermentum leo vel orci porta non. Interdum velit laoreet id donec ultrices tincidunt arcu non sodales.\
Donec massa sapien faucibus et. Elit duis tristique sollicitudin nibh sit. Tempor nec feugiat nisl pretium fusce id velit ut. Volutpat est velit egestas dui id ornare. Condimentum id venenatis a condimentum vitae. In hac habitasse platea dictumst quisque sagittis. Nunc eget lorem dolor sed viverra ipsum nunc aliquet bibendum. Lectus nulla at volutpat diam ut venenatis tellus in metus. Arcu ac tortor dignissim convallis aenean et tortor at risus. Malesuada fames ac turpis egestas sed tempus urna et pharetra. Amet dictum sit amet justo. Ac tincidunt vitae semper quis lectus. Ac felis donec et odio pellentesque diam volutpat commodo sed. Ultricies lacus sed turpis tincidunt id aliquet risus feugiat. Id volutpat lacus laoreet non curabitur gravida arcu ac. Facilisi nullam vehicula ipsum a arcu cursus vitae. Orci phasellus egestas tellus rutrum tellus pellentesque eu tincidunt. Eget est lorem ipsum dolor sit. Egestas sed tempus urna et pharetra. Tellus orci ac auctor augue.\
Pulvinar elementum integer enim neque volutpat. Ac ut consequat semper viverra nam. Faucibus interdum posuere lorem ipsum. Malesuada proin libero nunc consequat interdum varius. Egestas egestas fringilla phasellus faucibus scelerisque eleifend donec. Pellentesque pulvinar pellentesque habitant morbi tristique senectus et netus. Tortor consequat id porta nibh venenatis cras sed. Placerat orci nulla pellentesque dignissim enim sit. Ac tincidunt vitae semper quis. Leo a diam sollicitudin tempor id eu nisl nunc mi. Ultrices neque ornare aenean euismod elementum nisi quis. Nunc sed augue lacus viverra. Ac ut consequat semper viverra nam. Quisque sagittis purus sit amet volutpat consequat. Mi bibendum neque egestas congue quisque egestas. Mi in nulla posuere sollicitudin aliquam.\
Eu augue ut lectus arcu bibendum at varius vel. Ut consequat semper viverra nam libero justo laoreet. Tortor consequat id porta nibh venenatis cras sed felis eget. Nisl vel pretium lectus quam id leo in vitae. Ut tristique et egestas quis ipsum suspendisse ultrices gravida. Turpis cursus in hac habitasse platea. Eget felis eget nunc lobortis mattis aliquam faucibus purus in. Ornare massa eget egestas purus viverra accumsan. Nunc vel risus commodo viverra maecenas accumsan lacus vel. Turpis in eu mi bibendum neque egestas. Platea dictumst vestibulum rhoncus est pellentesque. Diam quam nulla porttitor massa id neque aliquam. Condimentum mattis pellentesque id nibh tortor. Venenatis lectus magna fringilla urna. Quam adipiscing vitae proin sagittis nisl rhoncus mattis rhoncus. Diam in arcu cursus euismod quis viverra. Urna condimentum mattis pellentesque id nibh tortor id aliquet. Aliquet sagittis id consectetur purus.\
Posuere ac ut consequat semper. Et odio pellentesque diam volutpat commodo sed. Nulla at volutpat diam ut venenatis. Mauris vitae ultricies leo integer malesuada nunc vel. Felis imperdiet proin fermentum leo vel orci. Sed elementum tempus egestas sed sed. Erat pellentesque adipiscing commodo elit at imperdiet dui accumsan sit. Ipsum faucibus vitae aliquet nec ullamcorper sit amet risus nullam. Sem fringilla ut morbi tincidunt. Quis hendrerit dolor magna eget est lorem ipsum dolor. Cursus sit amet dictum sit amet. Odio aenean sed adipiscing diam donec adipiscing. Sodales neque sodales ut etiam sit amet nisl purus in. Nunc consequat interdum varius sit amet mattis.\
Purus faucibus ornare suspendisse sed nisi lacus sed. Purus viverra accumsan in nisl nisi. Risus quis varius quam quisque id diam vel quam. Porta non pulvinar neque laoreet suspendisse interdum consectetur. Purus gravida quis blandit turpis cursus in. Diam maecenas sed enim ut sem. Euismod lacinia at quis risus sed vulputate odio ut. Tellus in metus vulputate eu scelerisque felis. Consectetur adipiscing elit pellentesque habitant morbi tristique senectus. Pharetra diam sit amet nisl. Lacus suspendisse faucibus interdum posuere lorem. Lectus mauris ultrices eros in cursus. Vitae aliquet nec ullamcorper sit amet risus nullam. Massa tempor nec feugiat nisl pretium fusce id velit. Facilisi nullam vehicula ipsum a arcu cursus. Nibh tellus molestie nunc non blandit massa enim nec dui.\
Pellentesque id nibh tortor id aliquet lectus proin nibh nisl. Nunc sed augue lacus viverra vitae. Interdum velit laoreet id donec. Odio tempor orci dapibus ultrices. Fames ac turpis egestas sed. Mi bibendum neque egestas congue quisque egestas diam in. Eu sem integer vitae justo eget magna fermentum. Odio morbi quis commodo odio. Tristique magna sit amet purus gravida quis blandit. Blandit massa enim nec dui nunc mattis enim. Lectus proin nibh nisl condimentum id venenatis a.\
Scelerisque eleifend donec pretium vulputate sapien nec. Aliquam purus sit amet luctus venenatis. Adipiscing elit duis tristique sollicitudin nibh sit amet commodo nulla. Neque viverra justo nec ultrices dui sapien. Phasellus vestibulum lorem sed risus. Praesent tristique magna sit amet purus gravida quis. Egestas erat imperdiet sed euismod nisi porta. Etiam erat velit scelerisque in dictum non. Nec dui nunc mattis enim. Faucibus interdum posuere lorem ipsum dolor sit amet consectetur adipiscing. Eget arcu dictum varius duis at consectetur lorem donec.\
A cras semper auctor neque vitae tempus quam. Arcu felis bibendum ut tristique et. Dolor sit amet consectetur adipiscing. Vulputate ut pharetra sit amet aliquam id diam maecenas ultricies. Odio tempor orci dapibus ultrices in. Porta lorem mollis aliquam ut porttitor leo a diam sollicitudin. Pharetra vel turpis nunc eget. Pulvinar pellentesque habitant morbi tristique senectus et netus et malesuada. Pharetra convallis posuere morbi leo urna molestie at elementum. Nunc sed augue lacus viverra vitae congue eu consequat ac. At in tellus integer feugiat scelerisque varius. Dui id ornare arcu odio ut. Vulputate mi sit amet mauris commodo quis imperdiet. Dictum fusce ut placerat orci nulla pellentesque dignissim enim. Et tortor consequat id porta. Ac orci phasellus egestas tellus rutrum tellus pellentesque. Lectus arcu bibendum at varius vel pharetra vel turpis nunc. Et magnis dis parturient montes nascetur. Eu sem integer vitae justo eget magna. Nunc scelerisque viverra mauris in aliquam sem.\
Vel elit scelerisque mauris pellentesque. Suspendisse interdum consectetur libero id faucibus nisl. Viverra orci sagittis eu volutpat odio facilisis mauris sit amet. Ac felis donec et odio pellentesque diam volutpat commodo sed. At tempor commodo ullamcorper a lacus vestibulum sed arcu. Orci a scelerisque purus semper. Nisl purus in mollis nunc sed id. Mauris vitae ultricies leo integer malesuada nunc vel risus. Eget egestas purus viverra accumsan in. Ante metus dictum at tempor commodo. Dolor sit amet consectetur adipiscing elit.\
Non enim praesent elementum facilisis. Ac tincidunt vitae semper quis lectus nulla at. Vulputate odio ut enim blandit volutpat maecenas volutpat blandit aliquam. Vitae turpis massa sed elementum tempus egestas sed. Non consectetur a erat nam at lectus urna duis convallis. Mauris sit amet massa vitae tortor. Suspendisse ultrices gravida dictum fusce. Semper quis lectus nulla at volutpat. Posuere lorem ipsum dolor sit amet consectetur. Id consectetur purus ut faucibus pulvinar elementum integer enim. Hendrerit gravida rutrum quisque non. Laoreet id donec ultrices tincidunt. Habitant morbi tristique senectus et netus et. Nisl vel pretium lectus quam id. Volutpat odio facilisis mauris sit amet massa vitae tortor. Vitae purus faucibus ornare suspendisse sed nisi.\
Maecenas sed enim ut sem. Cras fermentum odio eu feugiat pretium nibh ipsum consequat nisl. Sed risus ultricies tristique nulla aliquet enim tortor at auctor. Duis at tellus at urna condimentum. Auctor urna nunc id cursus. Enim nec dui nunc mattis enim ut tellus elementum sagittis. In fermentum et sollicitudin ac orci. Congue eu consequat ac felis donec. Hac habitasse platea dictumst vestibulum rhoncus est. Gravida arcu ac tortor dignissim convallis aenean et. Justo nec ultrices dui sapien eget. Pretium nibh ipsum consequat nisl vel pretium lectus quam id. Faucibus purus in massa tempor nec feugiat nisl pretium. Risus viverra adipiscing at in. Amet consectetur adipiscing elit ut aliquam purus sit amet luctus. Porta nibh venenatis cras sed felis eget velit. Mi eget mauris pharetra et ultrices.\
Sed risus ultricies tristique nulla aliquet. Vivamus arcu felis bibendum ut tristique et. Sapien eget mi proin sed libero. Mauris ultrices eros in cursus turpis massa. Elementum sagittis vitae et leo duis ut. Tempor id eu nisl nunc mi ipsum. Lorem mollis aliquam ut porttitor leo a diam sollicitudin. Eget nunc lobortis mattis aliquam faucibus purus in massa tempor. Imperdiet massa tincidunt nunc pulvinar sapien et. Feugiat in ante metus dictum at.";
	s2 = strdup(str);
	printf(FGREEN W"Original  = \n"NONE);
	printf("%s\n"FRED BWHITE"len = "NONE"%ld\n\n", s2, strlen(s2));
	free(s2);
	s2 = ft_strdup(str);
	printf(FBLACK BWHITE"My        = \n"NONE);
	printf("%s\n"FRED BWHITE"len = "NONE"%ld\n", s2, ft_strlen(s2));
	free(s2);
	printf("\n");
	
	return (0);
}
