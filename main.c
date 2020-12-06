/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:55:26 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/12/06 12:53:00 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libasm.h"

int		ft_strlen_test(char *src)
{
	int 	ret1;
	int 	ret2;

	ret1 = ft_strlen(src);
	ret2 = strlen(src);
	if (ret1 == ret2)
		printf("Test_str = "YELLOW"["RESET"%s"YELLOW"]"RESET" " GREEN " ... \
		OK!!!\n" RESET, src);
	else
		printf("Test_str = "YELLOW"["RESET"%s"YELLOW"]"RESET" " RED " ... KO!\
		!!\n" RESET, src);
	return (0);
}

int		ft_strcpy_test(char *src)
{
	char	dest1[512];
	char	dest2[512];

	bzero(dest1, 512);
	bzero(dest2, 512);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	if (!strcmp(dest1, dest2))
		printf("Test_str = "YELLOW"["RESET"%s"YELLOW"]"RESET" " GREEN " ... \
		OK!!!\n" RESET, src);
	else
		printf("Test_str = "YELLOW"["RESET"%s"YELLOW"]"RESET" " RED " ... KO!\
		!!\n" RESET, src);
	return (0);
}

int			main(void)
{	
	char *ch1 = "Hello, it',jl sdafads blls me!";
	char *ch2 = "\t \n\n gsgfdd \ewrtert";
	char *ch3 = "";
	char *ch4 = "      ";
	char *ch5 = "321V DEDFS 3ndm 12312		sdsfasv EPWQKEVMALSD><V/m23.3/1\
	rm!><DVSA>KBNVADFKNF!$K#!L:NR@#gv3 2 $";
	
	printf(YELLOW "STRLEN test start: \n" RESET);
	ft_strlen_test(ch1);
	ft_strlen_test(ch2);
	ft_strlen_test(ch3);
	ft_strlen_test(ch4);
	ft_strlen_test(ch5);

	printf(YELLOW "STRCPY test start: \n" RESET);
	ft_strcpy_test(ch1);
	ft_strcpy_test(ch2);
	ft_strcpy_test(ch3);
	ft_strcpy_test(ch4);
	ft_strcpy_test(ch5);

	
	return (0);
}

