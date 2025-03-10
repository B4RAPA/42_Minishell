/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:03:42 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/27 13:53:32 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	quotes(char	*line)
{
	int	i;
	int	open;

	open = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\\' && line[i + 1] != '\0')
			i++;
		else if ((open == 0) && line[i] == '\'')
			open = 1;
		else if (((open == -1) || (open == 0)) && line[i] == '\"')
			open = 2;
		else if ((open == 1) && line[i] == '\'')
			open = 0;
		else if ((open == 2) && line[i] == '\"')
			open = -1;
		i++;
	}
	return (open);
}

void	ft_lstadd_back2(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if ((*lst)->str == NULL)
	{
		free (*lst);
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_token	*ft_lstnew2(char *str)
{
	t_token	*out;

	out = malloc(sizeof(t_token));
	if (!out)
		return (0);
	out->str = ft_strdup(str);
	out->next = NULL;
	out->prev = NULL;
	return (out);
}

int	check_before(t_token *token)
{
	while (token)
	{
		if (!token->prev)
			return (1);
		token = token->prev;
		if (token->type == PIPE)
			return (3);
		if (token->type == CMD)
			return (0);
	}
	return (1);
}
