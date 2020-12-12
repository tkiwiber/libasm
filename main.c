/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:55:26 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/12/12 18:32:12 by tkiwiber         ###   ########.fr       */
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
		printf("Test_str = "YELLOW"[%s]"RESET" " GREEN " ... \
		OK!!!\n" RESET, src);
	else
		printf("Test_str = "YELLOW"[%s]"RESET" " RED " ... KO!\
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
		printf("Test_str = "YELLOW"[%s]"RESET" " GREEN " ... \
		OK!!!\n" RESET, src);
	else
		printf("Test_str = "YELLOW"[%s]"RESET" " RED " ... KO!\
		!!\n" RESET, src);
	return (0);
}

int		ft_strcmp_test(char *s1, char *s2)
{
	int 	ret1;
	int 	ret2;

	ret1 = ft_strcmp(s1, s2);
	ret2 = strcmp(s1, s2);
	if ((ret1 > 0 && ret2 > 0) || (ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 == 0))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	return (1);
}

int		ft_write_test(char *str)
{
	int		ft_write_pipe[2];
	char	buf[512];
	int		ret;

	bzero(buf, 512);
	if (pipe(ft_write_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_write_pipe[0], F_SETFL, O_NONBLOCK);
	ft_write(ft_write_pipe[1], str, strlen(str));
	ret = read(ft_write_pipe[0], buf, 512);
	buf[ret] = '\0';
	if (!strcmp(buf, str))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	close(ft_write_pipe[1]);
	close(ft_write_pipe[0]);
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
	
	printf("\n*********** "BLUE"STRCPY"RESET" test start: \n\n");
	ft_strcpy_test(ch1);
	ft_strcpy_test(ch2);
	ft_strcpy_test(ch3);
	ft_strcpy_test(ch4);
	ft_strcpy_test(ch5);

	printf("\n*********** "BLUE"STRCPY"RESET" test start: \n\n");
	ft_strcpy_test(ch1);
	ft_strcpy_test(ch2);
	ft_strcpy_test(ch3);
	ft_strcpy_test(ch4);
	ft_strcpy_test(ch5);

	printf("\n*********** "BLUE"STRCMP"RESET" test start: \n\n");
	ft_strcmp_test("Hello\05 dsf", "Hello\200 dsf");
	ft_strcmp_test("dsaf dsafm/43r43 fw sda", "dsaf dsafm/43r43 fw sda");
	ft_strcmp_test("", "");
	ft_strcmp_test("  ", "  ");
	ft_strcmp_test("\xff\x80", "\xff\x00");

	printf("\n*********** "BLUE"WRITE"RESET" test start: \n\n");
	
	ft_write(1, NULL, -1);
	printf("[ERROR %10d]\n", errno);	ft_write_test("");
	printf("[ERROR %10d]\n", errno);	ft_write(-1, "sdaf", 4);
	printf("[ERROR %10d]\n", errno);	ft_write(-1, NULL, 1);

	ft_write_test("test");
	ft_write_test("test allo");
	ft_write_test("test allo \0 what");
	return (0);
}
