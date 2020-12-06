/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:28:27 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/12/06 12:06:44 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
#define LIBASM_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"

size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dst, const char *src);

int         ft_strlen_test(char *str);
int	    	ft_strcpy_test(char *src);



#endif