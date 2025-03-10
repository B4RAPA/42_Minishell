/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:02:45 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/18 12:35:44 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reset_std(t_shell *mini)
{
	dup2(mini->in, 0);
	dup2(mini->out, 1);
}

void	close_fds(t_shell *mini)
{
	close(mini->fdin);
	close(mini->fdout);
	close(mini->pipein);
	close(mini->pipeout);
}

void	reset_fds(t_shell *mini)
{
	char	*temp;

	mini->fdin = 0;
	mini->fdout = 0;
	mini->pipein = STDIN_FILENO;
	mini->pipeout = STDOUT_FILENO;
	temp = NULL;
	mini->count = 0;
	while (mini->sco >= 0)
	{
		if (mini->fdhd[mini->sco])
		{
			temp = herdocfile(mini);
			close(mini->fdhd[mini->sco]);
			unlink(temp);
			free(temp);
		}
		mini->fdhd[mini->sco] = 0;
		mini->sco--;
	}
}
