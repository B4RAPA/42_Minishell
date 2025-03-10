/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:41:01 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/18 16:56:03 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_child_signals(void)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = sigint_heredoc;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = sigquit2;
	sa.sa_flags = 0;
	sigaction(SIGQUIT, &sa, NULL);
}

void	handle_signals(t_shell *mini)
{
	struct sigaction	sa;

	(void)mini;
	(void)signal;
	sa.sa_handler = sigint;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		write(2, "failed to SIGINT", 17);
	}
	sa.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
	{
		write(2, "failed to sigquit", 18);
	}
}

void	silence_signals(void)
{
	struct sigaction	sa;

	(void)signal;
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		write(2, "failed to SIGINT", 17);
	}
	sa.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
	{
		write(2, "failed to sigquit", 18);
	}
}
