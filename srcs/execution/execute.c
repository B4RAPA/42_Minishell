/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:30:05 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/18 16:12:08 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int		start_command(char *path, char **command, t_list *envp);
static int		prepare_command(char **command, t_shell *mini);
static int		exec_shell(char **command, t_list *envi, char *path);
static void		wait_child(int pid, int *status, char **env);

void	execute_cmd(t_shell *mini, t_token *token)
{
	char	**command;

	if (mini->flag == 0)
		return ;
	command = tok_to_str(token);
	if (command)
		mini->exit_status = prepare_command(command, mini);
	mini->pipein = -1;
	mini->pipeout = -1;
	mini->flag = 0;
	ft_free_arr(command);
}

static int	prepare_command(char **command, t_shell *mini)
{
	char	*path;
	t_list	*envi;
	int		i;

	i = 0;
	envi = mini->env;
	if (!envi)
		exit (EXIT_FAILURE);
	if (envi == NULL)
		return (start_command(command[0], command, envi));
	path = split_path(command[0], envi);
	i = exec_shell(command, envi, path);
	if (i)
		return (i);
	if (path == NULL)
	{
		free(path);
		if (ft_strcmp(mini->token->str, "<<") == 0)
			return (0);
		return (error_message(mini->token->str));
	}
	else
		i = start_command(path, command, envi);
	free(path);
	return (i);
}

static int	start_command(char *path, char **command, t_list *envp)
{
	int		status;
	int		pid;
	char	**env;

	status = SUCCESS;
	env = env_to_array(envp);
	pid = fork();
	if (pid == 0)
	{
		if (ft_strchr(path, '/') != NULL)
		{
			if (execve(path, command, env) == -1)
			{
				status = error_message(path);
				free_env_array(env);
				exit(status);
			}
		}
		status = error_message(path);
		free_env_array(env);
		exit(status);
	}
	else
		wait_child(pid, &status, env);
	return (status);
}

static void	wait_child(int pid, int *status, char **env)
{
	free_env_array(env);
	waitpid(pid, status, 0);
	if (WIFEXITED(*status))
		*status = WEXITSTATUS(*status);
	else if (WIFSIGNALED(*status))
		*status = 128 + WTERMSIG(*status);
	else
		*status = 1;
}

static int	exec_shell(char **command, t_list *envi, char *path)
{
	int	i;

	i = 0;
	if (!command[0])
		return (0);
	if (ft_strcmp("./minishell", command[0]) == 0)
	{
		silence_signals();
		i = start_command(command[0], command, envi);
		free(path);
		return (i);
	}
	return (i);
}
