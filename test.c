/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 21:16:13 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/12/12 21:16:31 by tkiwiber         ###   ########.fr       */
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
		printf("Test_str [%lu] = "YELLOW"[%s]"RESET" " GREEN " ... \
		OK!!!\n" RESET, ft_strlen(src), src);
	else
		printf("Test_str [%lu]= "YELLOW"[%s]"RESET" " RED " ... KO!\
		!!\n" RESET, ft_strlen(src), src);
	return (0);
}

int		ft_strcpy_test(char *src)
{
	char	dest1[BUFF];
	char	dest2[BUFF];

	bzero(dest1, BUFF);
	bzero(dest2, BUFF);
	strcpy(dest1, src);
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
	char	buf[BUFF];
	int		ret;

	bzero(buf, BUFF);
	if (pipe(ft_write_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_write_pipe[0], F_SETFL, O_NONBLOCK);
	ft_write(ft_write_pipe[1], str, strlen(str));
	ret = read(ft_write_pipe[0], buf, BUFF);
	buf[ret] = '\0';
	if (!strcmp(buf, str))
		printf(YELLOW "%s" GREEN "[OK] " RESET "\n", str);
	else
		printf(YELLOW "%s" RED "[KO] " RESET "", str);
	close(ft_write_pipe[1]);
	close(ft_write_pipe[0]);
	return (0);
}

int		ft_read_test(char *str)
{
	int		ft_write_pipe[2];
	char	buf[BUFF];
	int		ret;

	bzero(buf, BUFF);
	if (pipe(ft_write_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_write_pipe[0], F_SETFL, O_NONBLOCK);
	write(ft_write_pipe[1], str, strlen(str));
	ret = ft_read(ft_write_pipe[0], buf, BUFF);
	buf[ret] = '\0';
	if (!strcmp(buf, str))
		printf(YELLOW "%s" GREEN "[OK] " RESET "\n", str);
	else
		printf(YELLOW "%s" RED "[KO] " RESET "", str);
	close(ft_write_pipe[1]);
	close(ft_write_pipe[0]);
	return (0);
}