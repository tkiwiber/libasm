/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:28:27 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/12/13 11:44:53 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define BUFF 32768
# define CH1 "Hello, it',jl sdafads blls me!"
# define CH2 "\t \n\n gsgfdd \ewrtert"
# define CH3 ""
# define CH4 "      "
# define CH5 "Sed ut perspiciatis, unde omnis iste natus error sit volupt."

size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);

int			ft_strlen_test(char *str);
int			ft_strcpy_test(char *str);
int			ft_strcmp_test(char *s1, char *s2);
int			ft_write_test(char *str);
int			ft_read_test(char *str);
int			ft_strdup_test(char *str);

#endif
