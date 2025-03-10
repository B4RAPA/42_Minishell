/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:34:04 by lfabel            #+#    #+#             */
/*   Updated: 2024/06/17 14:12:27 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	borders2(const char *s1, const char *set);
static int	borders1(const char *s1, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*dest;
	size_t	len;

	i = borders1(s1, set);
	j = 0;
	k = borders2(s1, set);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	len = k - (i - 1);
	if (i >= ft_strlen(s1) || len <= 0)
		return (ft_strdup(""));
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (j < len)
	{
		dest[j] = s1[i + j];
		j++;
	}
	dest[len] = '\0';
	return (dest);
}

static int	borders1(const char *s1, const char *set)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	borders2(const char *s1, const char *set)
{
	size_t	k;
	size_t	j;

	j = 0;
	k = ft_strlen(s1) - 1;
	while (set[j])
	{
		if (s1[k] == set[j])
		{
			k--;
			j = 0;
		}
		else
			j++;
	}
	return (k);
}
