/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_nav.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:58:06 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/18 10:12:37 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*find_cmd(t_token *token, int skip)
{
	if (token && skip)
		token = token->next;
	while (token && token->type != CMD)
	{
		token = token->next;
	}
	return (token);
}

t_token	*next_sep(t_token *start)
{
	t_token	*token;

	token = start;
	while (token && token->type < PIPE)
		token = token->next;
	return (token);
}

t_token	*next_pipe(t_token *start)
{
	t_token	*token;

	token = start;
	while (token && token->type != PIPE)
		token = token->next;
	return (token);
}

t_token	*prev_sep(t_token *start)
{
	t_token	*token;

	token = start;
	while (token && token->type < PIPE)
		token = token->prev;
	return (token);
}

t_token	*prev_pipe(t_token *start)
{
	t_token	*token;

	token = start;
	while (token && token->prev && token->type != PIPE)
		token = token->prev;
	if (token->type == PIPE)
		token = token->next;
	return (token);
}
