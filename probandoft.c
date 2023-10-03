#include "libft.h"
#include <stdio.h>

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*substring;
	int		i;
	int		j;

	if (s1 ==  NULL)
		return(ft_strdup(s2));
	substring = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
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

int	main(void)
{
	char	*s1 = NULL;
	char	s2[]="Dani";

	printf("%s\n", ft_strjoin2(s1, s2));
	return (1);
}