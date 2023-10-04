/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:03:23 by abarrio-          #+#    #+#             */
/*   Updated: 2023/10/04 16:44:58 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>

void f(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	/*int		fd1;
	int 	fd2;
	char	*line;
	float second;

	// atexit(f);
	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("texto.txt", O_RDONLY);
	clock_t start = clock();
	line = get_next_line(fd1);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
	}
	second = ((float)clock() - start) / CLOCKS_PER_SEC;
	printf("%s\n%f\n", line, second);
	return (0);*/
	
	int		fd;

	fd = 0;
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	
	/*int		uwu;
	
	uwu = open("texto.txt", O_RDONLY);
	printf("PRIMERA VEZ ------\n\n");
	printf("%s\n\n",get_next_line(uwu));
	free(line);
	printf("SEGUNDA VEZ ------\n\n");
	printf("%s\n\n", get_next_line(uwu));
	printf("TERCERA VEZ ------\n\n");
	printf("%s\n\n", get_next_line(uwu));
	printf("CUARTA VEZ ------\n\n");
	printf("%s\n\n", get_next_line(uwu));
	close(uwu);*/
}
