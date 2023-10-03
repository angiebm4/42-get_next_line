/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:59:10 by abarrio-          #+#    #+#             */
/*   Updated: 2023/10/03 18:15:19 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		size;
	char	*memory;
	int		i;

	if (!src)
		return (NULL);
	size = ft_strlen(src);
	memory = (char *)malloc((size + 1) * sizeof(char));
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		memory[i] = src[i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*substring;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	substring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i <= ft_strlen(s1) && s1[i] != '\0')
	{
		substring[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < (ft_strlen(s1) + ft_strlen(s2)) && s2[j] != '\0')
	{
		substring[i] = s2[j];
		i++;
		j++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if ((start + len) > (unsigned long)ft_strlen(s))
		len = (unsigned long)ft_strlen(s) - start;
	if (!s)
		return (ft_free(s));
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_free(s));
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (ft_free(s));
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	free(s);
	return (substring);
}
