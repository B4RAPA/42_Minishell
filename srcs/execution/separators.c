/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:59:14 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/27 11:46:49 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	parent_handler(t_shell *mini, int pid, int *count, int *pipefd);

int	pipe_command(int *pipefd)
{
	if (pipe(pipefd) < 0)
	{
		write(2, "Pipe Error\n", 11);
		return (1);
	}
	return (0);
}

int	fork_command(t_shell *mini, int *count, int *pipefd)
{
	pid_t	pid;
	int		index;

	index = *count;
	if (mini->fds[index][0] == -2 || mini->fds[index][1] == -2)
	{
		*count += 1;
		return (-1);
	}
	pid = fork();
	if (pid == 0)
	{
		redirect_process(mini, index, pipefd);
		return (0);
	}
	else
	{
		parent_handler(mini, pid, count, pipefd);
		return (1);
	}
}

void	redirect_process(t_shell *mini, int index, int *pipefd)
{
	if (mini->fds[index][0] != -1)
	{
		dup2(mini->fds[index][0], STDIN_FILENO);
		close(mini->fds[index][0]);
		mini->fds[index][0] = -1;
	}
	if (mini->fds[index][1] != -1)
	{
		dup2(mini->fds[index][1], STDOUT_FILENO);
		close(mini->fds[index][1]);
		mini->fds[index][1] = -1;
	}
	else if (*pipefd != -100 && pipefd[1] != -1)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		mini->pipeout = pipefd[1];
	}
}

static void	parent_handler(t_shell *mini, int pid, int *count, int *pipefd)
{
	mini->pids[(*count)++] = pid;
	mini->count = *count;
	close(mini->pipein);
	if (pipefd[0] != -1)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		mini->pipein = STDIN_FILENO;
		close(pipefd[0]);
		mini->pipeout = STDOUT_FILENO;
	}
}
