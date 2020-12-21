/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:06:39 by gmarva            #+#    #+#             */
/*   Updated: 2020/12/17 17:06:45 by gmarva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <fcntl.h>
# define FBLACK      "\033[30;"
# define FRED        "\033[31;"
# define FGREEN      "\033[32"
# define FYELLOW     "\033[33;"
# define FBLUE       "\033[34;"
# define FPURPLE     "\033[35;"
# define D_FGREEN    "\033[6;"
# define FWHITE      "\033[7;"
# define FCYAN       "\x1b[36m"
# define W       	"m"
# define BBLACK      "40m"
# define BRED        "41m"
# define BGREEN      "42m"
# define BYELLOW     "43m"
# define BBLUE       "44m"
# define BPURPLE     "45m"
# define D_BGREEN    "46m"
# define BWHITE      "47m"
# define NONEL        "\033[0m\n"
# define NONE        "\033[0m"

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *str);
size_t	ft_write(int fd, const void *buf, size_t count);
size_t	ft_read(int fd, const void *buf, size_t count);

#endif
