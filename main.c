/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:55:26 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/12/13 11:43:51 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int			ft_strdup_test(char *str)
{
	char	*str1;
	char	*str2;

	str1 = ft_strdup(str);
	str2 = strdup(str);
	if (!strcmp(str1, str2))
		printf(YELLOW "%s" GREEN "[OK] " RESET "\n", str);
	else
		printf(YELLOW "%s" RED "[KO] " RESET "", str);
	free(str1);
	free(str2);
	return (1);
}

void		test_part_1(void)
{
	printf("\n*********** "BLUE"STRLEN"RESET" test start: \n\n");
	ft_strlen_test(CH1);
	ft_strlen_test(CH2);
	ft_strlen_test(CH3);
	ft_strlen_test(CH4);
	ft_strlen_test(CH5);
	printf("\n*********** "BLUE"STRCPY"RESET" test start: \n\n");
	ft_strcpy_test(CH1);
	ft_strcpy_test(CH2);
	ft_strcpy_test(CH3);
	ft_strcpy_test(CH4);
	ft_strcpy_test(CH5);
	printf("\n*********** "BLUE"STRCMP"RESET" test start: \n\n");
	ft_strcmp_test("Hello\05 dsf", "Hello\200 dsf");
	ft_strcmp_test("dsaf dsafm/43r43 fw sda", "dsaf dsafm/43r43 fw sda");
	ft_strcmp_test("", "");
	ft_strcmp_test("  ", " safasd");
}

void		test_part_2(void)
{
	printf("\n*********** "BLUE"WRITE"RESET" test start: \n\n");
	ft_write(1, NULL, -1);
	printf("[ERROR %10d]\n", errno);
	ft_write_test("");
	printf("[ERROR %10d]\n", errno);
	ft_write(-1, "sdaf", 4);
	printf("[ERROR %10d]\n", errno);
	ft_write(-1, NULL, 1);
	ft_write_test(CH1);
	ft_write_test(CH2);
	ft_write_test(CH3);
	ft_write_test(CH4);
	ft_write_test(CH5);
}

void		test_part_3(void)
{
	printf("\n*********** "BLUE"READ"RESET" test start: \n\n");
	ft_write(1, NULL, -1);
	printf("[ERROR %10d]\n", errno);
	ft_write_test("");
	printf("[ERROR %10d]\n", errno);
	ft_write(-1, "sdaf", 4);
	printf("[ERROR %10d]\n", errno);
	ft_write(-1, NULL, 1);
	ft_read_test(CH1);
	ft_read_test(CH2);
	ft_read_test(CH3);
	ft_read_test(CH4);
	ft_read_test(CH5);
	printf("\n*********** "BLUE"STRDUP"RESET" test start: \n\n");
	ft_strdup_test(CH1);
	ft_strdup_test(CH2);
	ft_strdup_test(CH3);
	ft_strdup_test(CH4);
	ft_strdup_test(CH5);
}

int			main(void)
{
	test_part_1();
	test_part_2();
	test_part_3();
	return (0);
}
