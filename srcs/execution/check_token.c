/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:06:27 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/27 14:11:35 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	init_vars(int *pid, int *pipefd);
static void	command_handle(t_shell *mini, t_token *token);

int	check_token(t_shell *mini, t_token *token, int *count)
{
	t_token	*next;
	int		pipefd[2];
	int		pid;

	next = next_pipe(token);
	init_vars(&pid, pipefd);
	if (token && token->type == CMD && !mini->pipe && is_builtin(token, mini))
		return (0);
	if (is_type(next, PIPE))
		pipe_command(pipefd);
	pid = fork_command(mini, count, pipefd);
	if (pid == 0)
	{
		set_child_signals();
		command_handle(mini, token);
	}
	return (0);
}

static void	command_handle(t_shell *mini, t_token *token)
{
	char	*temp;

	if (find_heredoc(token))
	{
		temp = herdocfile(mini);
		inredir(mini, token->next, temp);
		unlink(temp);
		free(temp);
	}
	if (!is_builtin(token, mini))
		execute_cmd(mini, token);
	free_env(mini);
	free_token(mini->token);
	dup2(mini->in, STDIN_FILENO);
	exit(mini->exit_status);
}

static void	init_vars(int *pid, int *pipefd)
{
	*pid = 0;
	pipefd[0] = -1;
	pipefd[1] = -1;
	g_exit_status = -100;
	silence_signals();
}

int	handle_status(const char *name, t_list *env, char *result, int start)
{
	char	*value;

	value = expansion(name, env);
	if (value)
	{
		while (*value)
		{
			result[start] = *value++;
			start++;
		}
		return (start);
	}
	return (start);
}
