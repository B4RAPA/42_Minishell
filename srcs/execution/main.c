/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:12:26 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/27 16:03:01 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	g_exit_status;

static void		init(t_shell *mini, char **argv, char **envp);
static t_token	*init_token(void);
static void		minishell(t_shell *mini);
static void		reset_mini(t_shell *mini, int count);

int	main(int argc, char **argv, char **envp)
{
	t_shell				mini;
	t_token				*token;

	if (argc > 1)
		return (1);
	init(&mini, argv, envp);
	while (mini.exit < 0)
	{
		mini.cfd = 0;
		token = init_token();
		if (!token)
			return (-1);
		mini.token = parse(token, &mini);
		if (check_input(mini.token) == 0 && mini.token->str)
			minishell(&mini);
		free_token(mini.token);
		restore_signals();
	}
	free_env(&mini);
	rl_clear_history();
	exit(mini.exit);
}

static void	init(t_shell *mini, char **argv, char **envp)
{
	int	i;

	handle_signals(mini);
	mini->cmd = argv;
	mini->head = NULL;
	mini->env = NULL;
	get_env(mini, envp);
	mini->exit = -1;
	mini->in = dup(0);
	mini->out = dup(1);
	mini->exit_status = 0;
	g_exit_status = -100;
	mini->pipe = 0;
	mini->sco = 0;
	i = -1;
	while (++i < 256)
		mini->fdhd[i] = 0;
	reset_fds(mini);
	i = -1;
	while (++i < 256)
	{
		mini->fds[i][0] = -1;
		mini->fds[i][1] = -1;
	}
}

static t_token	*init_token(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->prev = NULL;
	token->next = NULL;
	token->str = NULL;
	token->type = 0;
	return (token);
}

static void	minishell(t_shell *mini)
{
	t_token	*token;
	int		count;

	token = find_cmd(mini->token, 0);
	if (heredoc_handle(mini, mini->token, 1, &token) == -1
		|| inout_handle(mini, mini->token, 1) == -1)
		return ;
	mini->flag = 1;
	count = 0;
	while (mini->exit < 0 && token)
	{
		if (check_token(mini, token, &count) == -1)
			exit (130);
		token = find_cmd(token, 1);
	}
	reset_mini(mini, count);
}

static void	reset_mini(t_shell *mini, int count)
{
	int		i;

	i = 0;
	if (count > 0)
	{
		while (i < count && mini->pids[i] > 0)
		{
			waitpid(mini->pids[i], &mini->exit_status, 0);
			i++;
		}
		if (WIFEXITED(mini->exit_status))
			mini->exit_status = WEXITSTATUS(mini->exit_status);
		else if (WIFSIGNALED(mini->exit_status))
			mini->exit_status = 128 + WTERMSIG(mini->exit_status);
	}
	dup2(mini->in, STDIN_FILENO);
	dup2(mini->out, STDOUT_FILENO);
	reset_fds(mini);
}
