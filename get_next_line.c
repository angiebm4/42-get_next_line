/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:33:34 by abarrio-          #+#    #+#             */
/*   Updated: 2023/10/03 18:10:09 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char *buff)
{
	free(buff);
	buff = NULL;
	return (NULL);
}

char	*ft_read(int fd, char *buff)
{
	char	*aux;
	int		nb;
	char	*auxbuff;

	nb = 1;
	aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!aux)
		return (ft_free(buff));
	while (nb > 0 && (!ft_strchr(buff, '\n') || !ft_strchr(buff, '\0')))
	{
		nb = read(fd, aux, BUFFER_SIZE);
		if (nb == -1)
		{
			free(aux);
			return (ft_free(buff));
		}
		aux[nb] = '\0';
		if (aux[0] == '\0')
		{
			free(aux);
			return (buff);
		}
		auxbuff = ft_strdup(buff);
		free(buff);
		buff = ft_strjoin(auxbuff, aux);
		free(auxbuff);
		if (!buff)
		{	
			free(aux);
			return (ft_free(buff));
		}
	}
	free(aux);
	return (buff);
}

char	*ft_getline(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (ft_free(buff));
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*readnotprint = NULL;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	readnotprint = ft_read(fd, readnotprint);
	if (!readnotprint)
		return (NULL);
	line = ft_getline(readnotprint);
	if (!line)
		return (NULL);
	readnotprint = ft_substr(readnotprint, ft_strlen(line), (ft_strlen(readnotprint)
				- ft_strlen(line)));
	return (line);
}
