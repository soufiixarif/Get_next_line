/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:28:56 by sarif             #+#    #+#             */
/*   Updated: 2023/12/22 15:10:57 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_getline(char *reserve)
{
	int		i;
	char	*line;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (reserve[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (reserve[++i] && reserve[i] != '\n')
		line[i] = reserve[i];
	if (reserve[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update(char *reserve)
{
	char	*new_reserve;
	int		c;
	int		i;
	int		len;

	c = 0;
	i = 0;
	len = ft_strlen(reserve);
	while (reserve[c] && reserve[c] != '\n')
		c++;
	new_reserve = malloc(len - c);
	if (!new_reserve)
		return (free(reserve), reserve = NULL, NULL);
	if (reserve[c] == '\n')
		c++;
	while (reserve[c])
		new_reserve[i++] = reserve[c++];
	new_reserve[i] = '\0';
	free(reserve);
	reserve = NULL;
	return (new_reserve);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen((char *)s1);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (++i < len && s1[i])
		*(p + i) = s1[i];
	*(p + i) = 0;
	return (p);
}
