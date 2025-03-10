/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idvinov <idvinov@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-27 12:53:56 by idvinov           #+#    #+#             */
/*   Updated: 2025-02-27 12:53:56 by idvinov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_in(t_shell *mini, t_token *temp, int *i, int j);
static void	ft_tr(t_shell *mini, t_token *temp, int *i, int j);
static void	ft_ap(t_shell *mini, t_token *t, int *i, int j);
static void	ft_s(t_shell *mini, int *j, t_token *temp);

int	inout_handle(t_shell *mini, t_token *start, int id)
{
	t_token	*temp;
	int		i;
	int		j;

	j = mini->cfd;
	i = 0;
	id = 0;
	temp = prev_pipe(start);
	while (temp)
	{
		ft_s(mini, &j, temp);
		if (i == -1)
			return (-1);
		if (is_type(temp, INPUT))
			ft_in(mini, temp, &i, j);
		else if (is_type(temp, TRUNC))
			ft_tr(mini, temp, &i, j);
		else if (is_type(temp, APPEND))
			ft_ap(mini, temp, &i, j);
		temp = temp->next;
	}
	if (i == -1)
		return (-1);
	return (0);
}

static void	ft_s(t_shell *mini, int *j, t_token *temp)
{
	if (temp->type == PIPE)
	{
		mini->cfd++;
		(*j)++;
		mini->pipe = 1;
	}
}

static void	ft_in(t_shell *mini, t_token *temp, int *i, int j)
{
	mini->fds[j][0] = open(temp->next->str, O_RDONLY);
	if (mini->fds[j][0] == -1)
	{
		perror(temp->next->str);
		mini->fds[j][0] = -2;
		*i = -1;
	}
}

static void	ft_tr(t_shell *mini, t_token *temp, int *i, int j)
{
	mini->fds[j][1] = open(temp->next->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (mini->fds[j][1] == -1)
	{
		perror(temp->next->str);
		mini->fds[j][1] = -2;
		*i = -1;
	}
}

static void	ft_ap(t_shell *mini, t_token *t, int *i, int j)
{
	mini->fds[j][1] = open(t->next->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (mini->fds[j][1] == -1)
	{
		perror(t->next->str);
		mini->fds[j][1] = -2;
		*i = -1;
	}
}
