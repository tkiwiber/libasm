/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:55:26 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/12/05 21:48:55 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libasm.h"

void		hello(void);

int			main(void)
{	
	char *ch1 = "Hello, it',jl sdafads blls me!\n";
	
	hello();
	if (strlen(ch1) != ft_strlen(ch1))
		printf("KO\n");
	
	printf("%p %c\n", ch1, *ch1);
	printf("%p %c\n", ch1 + 1, *(ch1 + 1));

	printf("ft len: %ld\n", strlen(ch1));
	printf("std len: %ld\n", ft_strlen(ch1));

	
	return (0);
}

