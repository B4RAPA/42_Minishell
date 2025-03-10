/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:09:16 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/27 13:52:23 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*iterater(char **str1, t_token *token, int i);

void	get_type(t_token *token)
{
	while (token && token->str)
	{
		if (ft_strcmp(token->str, " ") == 0)
			token->type = EMPTY;
		else if (ft_strcmp(token->str, "<<") == 0)
			token->type = HEREDOC;
		else if (ft_strcmp(token->str, "<") == 0)
			token->type = INPUT;
		else if (ft_strcmp(token->str, ">") == 0)
			token->type = TRUNC;
		else if (ft_strcmp(token->str, ">>") == 0)
			token->type = APPEND;
		else if (ft_strcmp(token->str, "|") == 0)
			token->type = PIPE;
		else if (token->prev && (token->prev->type == 0 \
				|| token->prev->type >= 4))
			token->type = ARG;
		else if (check_before(token) != 0)
			token->type = CMD;
		else
			token->type = ARG;
		token = token->next;
	}
}

int	connect(t_token *token)
{
	if (!token)
		return (-1);
	while (token)
	{
		token = token->next;
	}
	return (0);
}

char	*get_input(t_shell *mini, t_token *token)
{
	char	*input;

	input = NULL;
	input = readline("minishell > ");
	if (!input || input == NULL)
	{
		sigquit (SIGQUIT, mini, token);
	}
	if (input && *input)
		add_history(input);
	return (input);
}

t_token	*skip_space(t_token *token, char *str)
{
	char	**str1;
	int		i;

	i = 0;
	if (str == NULL)
		return (token);
	str1 = ft_split(str, ' ');
	if (!str1)
	{
		free(str);
		return (NULL);
	}
	free(str);
	token = iterater(str1, token, i);
	return (token);
}

t_token	*iterater(char **str1, t_token *token, int i)
{
	char	*temp;
	t_token	*new;

	while (str1[i])
	{
		if (str1[i][0] == '~')
		{
			temp = ft_strdup(ft_memmove(&str1[i][0], &str1[i][1],
						ft_strlen(str1[i]) - 0));
			free(str1[i]);
			str1[i] = ft_strjoin(getenv("HOME"), temp);
			free(temp);
		}
		new = ft_lstnew2(str1[i]);
		if (!new)
			break ;
		ft_lstadd_back2(&token, new);
		get_type(new);
		i++;
	}
	i = 0;
	while (str1[i])
		free(str1[i++]);
	free (str1);
	return (token);
}
