/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:34:34 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/18 15:38:44 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	free_token(t_token *token)
{
	t_token	*tmp;

	while (token && token->prev)
		token = token->prev;
	while (token)
	{
		tmp = token->next;
		if (token->str)
			free(token->str);
		if (token)
			free (token);
		token = tmp;
	}
}

void	free_env(t_shell *mini)
{
	t_list	*tmp;
	t_list	*token;

	mini->env = mini->head;
	token = mini->env;
	while (token)
	{
		tmp = token->next;
		free(token->value);
		free(token);
		token = tmp;
	}
}

void	delete_token(t_shell *mini, t_token *token)
{
	if (!token)
		return ;
	if (token->str)
		free(token->str);
	if (token->prev == NULL)
		mini->token = token->next;
	else
		token->prev->next = token->next;
	if (token->next != NULL)
		token->next->prev = token->prev;
	free(token);
}

void	free_env_array(char **env_array)
{
	int	i;

	i = 0;
	if (!env_array)
		return ;
	while (env_array[i])
		free(env_array[i++]);
	free(env_array);
}
