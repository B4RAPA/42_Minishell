/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:35:53 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/17 09:08:34 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*loop(int start, int end, const char *s, char *word);

static void	ft_vars(int *i, int *k, int *s_quotes, int *d_quotes)
{
	*k = 0;
	*i = 0;
	*d_quotes = 0;
	*s_quotes = 0;
}

static void	ft_vars2(int *i, int *s_quotes, int *d_quotes)
{
	*i = 0;
	*s_quotes = 0;
	*d_quotes = 0;
}

int	word_count(const char *s, char c)
{
	int	i;
	int	k;
	int	count;
	int	s_quotes;
	int	d_quotes;

	ft_vars(&i, &k, &s_quotes, &d_quotes);
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'' && !d_quotes)
			s_quotes = !s_quotes;
		if (s[i] == '\"' && !s_quotes)
			d_quotes = !d_quotes;
		if (s[i] != c && k == 0 && !s_quotes && !d_quotes)
		{
			k = 1;
			count++;
		}
		if (s[i] == c && !s_quotes && !d_quotes)
			k = 0;
		i++;
	}
	return (count);
}

char	*fill_word(const char *s, int start, int end)
{
	char	*word;

	if (start < 0 || end > (int)ft_strlen(s) || start >= end)
		return (NULL);
	word = malloc((end - start + 1) * sizeof(char));
	word = loop(start, end, s, word);
	if (!word)
		return (0);
	return (word);
}

static char	*loop(int start, int end, const char *s, char *word)
{
	int		i;
	int		s_quotes;
	int		d_quotes;

	ft_vars2(&i, &s_quotes, &d_quotes);
	while (start < end && s[start])
	{
		if (s[start] == '\'' && !d_quotes)
		{
			s_quotes = !s_quotes;
			start++;
			continue ;
		}
		else if (s[start] == '\"' && !s_quotes)
		{
			d_quotes = !d_quotes;
			start++;
			continue ;
		}
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}
