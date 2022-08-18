/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:30:47 by mthiry            #+#    #+#             */
/*   Updated: 2022/01/04 17:26:38 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (dst == 0 && src == 0)
		return (0);
	while (n)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char	*s1)
{
	void	*dest;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + 1;
	dest = malloc (size * sizeof (char));
	if (!dest)
		return (NULL);
	return ((char *) ft_memcpy(dest, s1, size));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	len;
	char	*result;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *) malloc (len + 1 * sizeof(char));
	if (!result)
		return (0);
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free((char *)s1);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = (char)c;
	i = ft_strlen(s) + 1;
	while (i)
	{
		if (*s == c)
			return ((char *)s);
		s++;
		i--;
	}
	return (0);
}
