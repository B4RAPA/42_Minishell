/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idvinov <idvinov@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-27 13:13:49 by idvinov           #+#    #+#             */
/*   Updated: 2025-02-27 13:13:49 by idvinov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	outredir(t_shell *mini, t_token *token, int type)
{
	if (!token)
	{
		write(2, "bash: Missing Argument\n", 24);
		return (-1);
	}
	if (mini->fdout)
		close(mini->fdout);
	if (type == TRUNC)
		mini->fdout = open(token->str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == APPEND)
		mini->fdout = open(token->str, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (mini->fdout == -1)
	{
		write(2, "bash: ", 6);
		perror(token->str);
		return (-1);
	}
	dup2(mini->fdout, STDOUT_FILENO);
	close(mini->fdout);
	return (0);
}

int	inredir(t_shell *mini, t_token *token, char *fname)
{
	if (!fname && !token)
	{
		write(2, "bash: Missing Argument\n", 24);
		return (-1);
	}
	if (mini->fdin)
		close(mini->fdin);
	if (fname)
		mini->fdin = open(fname, O_RDONLY, 0644);
	else
		mini->fdin = open(token->str, O_RDONLY, 0644);
	if (mini->fdin == -1)
	{
		write(2, "bash: ", 6);
		perror(token->str);
		return (-1);
	}
	dup2(mini->fdin, STDIN_FILENO);
	close(mini->fdin);
	return (0);
}
