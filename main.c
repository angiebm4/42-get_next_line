/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:03:23 by abarrio-          #+#    #+#             */
/*   Updated: 2023/10/03 18:30:22 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void f(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	int		uwu;
	char	*line;

	// atexit(f);
	uwu = open("texto.txt", O_RDONLY);
	printf("PRIMERA VEZ ------\n\n");
	printf("%s\n\n", line = get_next_line(uwu));
	free(line);
	// printf("SEGUNDA VEZ ------\n\n");
	// printf("%s\n\n", get_next_line(uwu));
	// printf("TERCERA VEZ ------\n\n");
	// printf("%s\n\n", get_next_line(uwu));
	// printf("CUARTA VEZ ------\n\n");
	// printf("%s\n\n", get_next_line(uwu));
	close(uwu);
}
