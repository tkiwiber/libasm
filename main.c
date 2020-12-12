/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:55:26 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/12/12 21:10:14 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libasm.h"

#define		BUFF 32768
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

int		ft_strdup_test(char *str)
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

int			main(void)
{	
	char *ch1 = "Hello, it',jl sdafads blls me!";
	char *ch2 = "\t \n\n gsgfdd \ewrtert";
	char *ch3 = "";
	char *ch4 = "      ";
	char *ch5 = "Sed ut perspiciatis, unde omnis iste natus error sit volupta\
	tem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae\
	ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, \
	explicabo. Nemo enim ipsam voluptatem, quia voluptas sit, aspernatur aut \
	odit aut fugit, sed quia consequuntur magni dolores eos, qui ratione volu\
	ptatem sequi nesciunt, neque porro quisquam est, qui dolorem ipsum, quia \
	dolor sit, amet, consectetur, adipisci velit, sed quia non numquam eius m\
	odi tempora incidunt, ut labore et dolore magnam aliquam quaerat voluptat\
	em. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis \
	suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis aute\
	m vel eum iure reprehenderit, qui in ea voluptate velit esse, quam nihil \
	molestiae consequatur, vel illum, qui dolorem eum fugiat, quo voluptas nu\
	lla pariatur? At vero eos et accusamus et iusto odio dignissimos ducimus,\
	 qui blanditiis praesentium voluptatum deleniti atque corrupti, quos dolo\
	 res et quas molestias excepturi sint, obcaecati cupiditate non provident.";
	
	printf("\n*********** "BLUE"STRLEN"RESET" test start: \n\n");
	ft_strlen_test(ch1);
	ft_strlen_test(ch2);
	ft_strlen_test(ch3);
	ft_strlen_test(ch4);
	ft_strlen_test(ch5);

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
	ft_strcmp_test("  ", " safasd");
	//ft_strcmp_test("\xff\x80", "\xff\x00");

	printf("\n*********** "BLUE"WRITE"RESET" test start: \n\n");
	
	ft_write(1, NULL, -1);
	printf("[ERROR %10d]\n", errno);	ft_write_test("");
	printf("[ERROR %10d]\n", errno);	ft_write(-1, "sdaf", 4);
	printf("[ERROR %10d]\n", errno);	ft_write(-1, NULL, 1);

	ft_write_test(ch1);
	ft_write_test(ch2);
	ft_write_test(ch3);
	ft_write_test(ch4);
	ft_write_test(ch5);

	printf("\n*********** "BLUE"READ"RESET" test start: \n\n");
	
	ft_write(1, NULL, -1);
	printf("[ERROR %10d]\n", errno);	ft_write_test("");
	printf("[ERROR %10d]\n", errno);	ft_write(-1, "sdaf", 4);
	printf("[ERROR %10d]\n", errno);	ft_write(-1, NULL, 1);

	ft_read_test(ch1);
	ft_read_test(ch2);
	ft_read_test(ch3);
	ft_read_test(ch4);
	ft_read_test(ch5);

	printf("\n*********** "BLUE"STRDUP"RESET" test start: \n\n");

	ft_strdup_test(ch1);
	ft_strdup_test(ch2);
	ft_strdup_test(ch3);
	ft_strdup_test(ch4);
	ft_strdup_test(ch5);
	//strdup(NULL);
	//ft_strdup_test(NULL);

	return (0);
}
