/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:16:38 by abarrio-          #+#    #+#             */
/*   Updated: 2023/09/28 16:44:51 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*aux2;
	char			*aux;
	int				nb;
	unsigned int	start;
	size_t			len;

	
	if (buff && ft_memchr(buff, '\n', ft_strlen(buff)))
	{
		aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!aux)
			return (NULL);
		aux = ft_getline(buff);
		start = ft_strlen(ft_getline(buff));
		len = ((ft_strlen(buff) - 1) - start);
		buff = ft_substr(buff, start + 1, len);
		return (aux);
	}
	else
	{
		aux2 = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!aux2)
			return (NULL);
		nb = read(fd, aux2, BUFFER_SIZE);
		if (nb == -1)
			return (NULL);
		if (nb == 0 )
		{
			if (!ft_memchr(buff, '\n', ft_strlen(buff) && buff != NULL))
			{
				printf("uwu: %s\n", buff);
				aux2 = ft_strdup(buff);
				free(buff);
				return (aux2);
			}
			return (NULL);
		}
		aux2[nb] = '\0';
		if (buff)
			aux = ft_strjoin(buff, aux2);
		else
			aux = ft_strdup(aux2);
		while (!ft_memchr(aux, '\n', ft_strlen(aux)) && nb == BUFFER_SIZE)
		{
			nb = read(fd, aux2, BUFFER_SIZE);
			if (nb == -1)
				return (NULL);
			aux2[nb] = '\0';
			aux = ft_strjoin(aux, aux2);
		}
		start = ft_strlen(ft_getline(aux));
		len = ((ft_strlen(aux) - 1) - start);
		buff = ft_substr(aux, start + 1, len);
		aux = ft_getline(aux);
	}
	return (aux);
}

/*
	- Funcion guarde todo lo que lea hasta encontarr un \n. Cuando
	lo encuentre, devuelve todo lo que ha leido y se lo añade a buff
	- Cuando tengo todo en buff, busco un \n.
		> Si hay \n, extraigo la primera linea y actualizo buff sin esa linea
		> Si no hay \n, ha leido todo y todo buff es la linea
*/