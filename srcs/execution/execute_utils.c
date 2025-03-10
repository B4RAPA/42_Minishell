/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:56:37 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/26 14:25:21 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	ftt_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ftt_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ftt_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

char	**tok_to_str(t_token *start)
{
	char	**command;
	int		i;
	t_token	*token;

	if (!start)
		return (NULL);
	token = start;
	i = 0;
	while (token && token->type < PIPE)
	{
		i++;
		token = token->next;
	}
	command = (char **)malloc((i + 1) * sizeof(char *));
	token = start;
	i = 0;
	while (token && token->type < PIPE)
	{
		command[i] = ft_strdup(token->str);
		token = token->next;
		i++;
	}
	command[i] = NULL;
	return (command);
}

char	*herdocfile(t_shell *mini)
{
	char	*i;
	char	*temp;
	char	*y;

	i = ft_itoa(mini->sco);
	y = ft_strjoin("hdocttemp", ft_strrchr(ttyname(STDOUT_FILENO), '/') + 1);
	temp = ft_strjoin(y, i);
	free(i);
	free(y);
	return (temp);
}

int	herdoc_file(t_shell *mini, t_token *s, t_token **cmd)
{
	char	*temp;

	mini->sco++;
	temp = herdocfile(mini);
	mini->fdhd[mini->sco] = open(temp, O_CREAT | O_RDWR | O_TRUNC, 0644);
	free(temp);
	if (mini->fdhd[mini->sco] == -1)
		return (-1);
	if (!ft_strncmp(s->str, "<<", 2) && !s->next->next && !s->prev)
		*cmd = s;
	return (0);
}
