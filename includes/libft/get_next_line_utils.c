/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:51:33 by lfabel            #+#    #+#             */
/*   Updated: 2025/01/24 11:13:29 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strle(char *s)
{
	size_t	i;
	char	delim;

	delim = '\0';
	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != delim)
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char			cc;
	unsigned int	i;

	i = 0;
	cc = (char ) c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (cc == '\0' && cc == s[i])
		return ((char *) &s[i]);
	return (0);
}

char	*ft_strndup_gnl(char *input, size_t n)

{
	char	*output;
	size_t	i;

	i = 0;
	output = malloc(sizeof(char) * (n + 1));
	if (!output)
		return (NULL);
	while (i < n)
	{
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strnjoin_gnl(char *s1, char *s2, size_t n)

{
	char	*output;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return (s1);
	output = (char *) malloc (ft_strle(s1) + n + 1);
	if (!output)
		return (NULL);
	while (s1 && s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && j < n)
		output[i++] = s2[j++];
	output[i] = '\0';
	if (s1)
		free (s1);
	return (output);
}

void	*ft_memmove_gnl(void *des, const void *src, size_t num)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)des;
	i = -1;
	if (!des && !src)
		return (0);
	if (des == src)
		return (des);
	if (d > s)
	{
		while (num-- > 0)
			d[num] = s[num];
	}
	else
	{
		while (++i < num)
			d[i] = s[i];
	}
	return (des);
}
