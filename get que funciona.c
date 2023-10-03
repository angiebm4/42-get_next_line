#include "get_next_line.h"
#include <stdio.h>

char	*ft_getline(char *text)
{
	char	*line;
	int		i;

	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
	{ 
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	*ft_free(char *aux, char *buff)
{
	free (aux);
	free (buff);
	buff = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*buff = NULL;
	char			*aux;
	int				nb;
	unsigned int	start;
	size_t			len;
	
	if (buff && ft_memchr(buff, '\n', ft_strlen(buff)))
	{
		aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!aux)
			return (ft_free(aux, buff));
		aux = ft_getline(buff);
		start = ft_strlen(ft_getline(buff));
		len = ((ft_strlen(buff) - 1) - start);
		buff = ft_substr(buff, start + 1, len);
		return (aux);
	}
	else
	{
		aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!aux)
			return (ft_free(aux, buff));
		nb = read(fd, aux, BUFFER_SIZE);
		if (nb == -1)
			return (ft_free(aux, buff));
		if (nb == 0)
		{
			if (buff != NULL)
			{
				aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
				if (!aux)
					return (ft_free(aux, buff));
				if (!buff[0])
					return (ft_free(aux, buff));
				aux = ft_strdup(buff);
				free(buff);
				buff = NULL;
				return(aux);
			}
			return (NULL);
		}
		aux[nb] = '\0';
		if (buff)
		{
			char* hola = ft_strdup(buff);
			buff = ft_strjoin(hola, aux);
			free(hola);
		}
		else
			buff = ft_strdup(aux);
		free(aux);
		while (!ft_memchr(buff, '\n', ft_strlen(buff)) && nb == BUFFER_SIZE)
		{
			aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
			if (!aux)
				return (ft_free(aux, buff));
			nb = read(fd, aux, BUFFER_SIZE);
			if (nb == -1)
				return (ft_free(aux, buff));
			aux[nb] = '\0';
			char* hola = ft_strdup(buff);
			buff = ft_strjoin(hola, aux);
		}
		aux = ft_getline(buff);
		start = ft_strlen(ft_getline(buff));
		len = ((ft_strlen(buff) - 1) - start);
		buff = ft_substr(buff, start + 1, len);
		return (aux);
	}
}