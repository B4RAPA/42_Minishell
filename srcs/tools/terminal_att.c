/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_att.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:31:16 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/05 13:19:31 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	disable_echoctl(struct termios *newt, struct termios *oldt)
{
	if (tcgetattr(STDIN_FILENO, oldt) == -1)
	{
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	}
	*newt = *oldt;
	newt->c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, newt) == -1)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
}

void	restore_terminal(struct termios *oldt)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, oldt) == -1)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
}

void	configure_terminal(void)
{
	struct termios	tios;

	tcgetattr(STDIN_FILENO, &tios);
	tios.c_cc[VQUIT] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &tios);
}

void	get_att(struct termios *oldt)
{
	if (tcgetattr(STDIN_FILENO, oldt) == -1)
	{
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	}
}

void	set_att(struct termios *oldt)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, oldt) == -1)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
}
