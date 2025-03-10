/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:12:59 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/17 09:08:42 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	*ft_free(char **str, int count);
static char	**loop(char **dest, const char *s, char c, size_t i);

static void	ft_vars(int *j, int *start, int *s_quotes, int *d_quotes)
{
	*j = 0;
	*start = -1;
	*d_quotes = 0;
	*s_quotes = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	size_t	i;

	i = -1;
	dest = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	dest = loop(dest, s, c, i);
	if (!dest)
		return (NULL);
	return (dest);
}

static char	**loop(char **dest, const char *s, char c, size_t i)
{
	int		start;
	int		j;
	int		s_quotes;
	int		d_quotes;

	ft_vars(&j, &start, &s_quotes, &d_quotes);
	while (++i <= ft_strlen(s))
	{
		if (s[i] == '\'' && !d_quotes)
			s_quotes = !s_quotes;
		else if (s[i] == '\"' && !s_quotes)
			d_quotes = !d_quotes;
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0 \
				&& !s_quotes && !d_quotes)
		{
			dest[j] = fill_word(s, start, i);
			if (!dest[j])
				return (ft_free(dest, j));
			start = -1;
			j++;
		}
	}
	return (dest);
}

static void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
