/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:14 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/18 16:56:31 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigint(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 130;
}

void	sigint2(int signal)
{
	(void)signal;
	g_exit_status = 130;
}

void	sigquit(int signal, t_shell *mini, t_token *token)
{
	(void)signal;
	(void)mini;
	write(2, "exit\n", 6);
	free_env(mini);
	free_token(token);
	g_exit_status = 130;
	exit (1);
}

void	sigquit2(int signal)
{
	(void)signal;
	write(2, "exit\n", 6);
	exit (1);
}

void	sigint_heredoc(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	g_exit_status = 130;
	exit (130);
}
