/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:30:12 by idvinov           #+#    #+#             */
/*   Updated: 2025/02/27 14:54:46 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_builtins(char *str, t_shell *mini);
static int	check_first(t_token *token);

int	is_type(t_token *token, int type)
{
	if (token && token->type == type)
		return (1);
	return (0);
}

int	is_builtin(t_token *token, t_shell *mini)
{
	int	res;
	int	temp;

	res = 1;
	temp = -100;
	redirect_process(mini, mini->count, &temp);
	if (check_builtins(token->str, mini) == -1)
		return (1);
	if (ft_strncmp(token->str, "cd", 2) == 0)
		mini->exit_status = ft_cd(token, mini);
	else if (ft_strncmp(token->str, "echo", 4) == 0)
		mini->exit_status = ft_echo(token);
	else if (ft_strncmp(token->str, "pwd", 3) == 0)
		mini->exit_status = ft_pwd();
	else if (ft_strncmp(token->str, "exit", 4) == 0)
		ft_exit(mini);
	else if (ft_strncmp(token->str, "env", 3) == 0)
		mini->exit_status = ft_env(mini->env);
	else if (ft_strncmp(token->str, "unset", 6) == 0)
		mini->exit_status = ft_unset(mini);
	else if (ft_strncmp(token->str, "export", 7) == 0)
		mini->exit_status = ft_export(mini);
	else
		res = 0;
	return (res);
}

int	check_input(t_token *token)
{
	if (check_first(token) == 1)
		return (1);
	while (token)
	{
		if (token->type == PIPE && (!token->next || token->next->type == PIPE))
			ft_putendl_fd("bash: parse error near '|'", STDERR);
		else if (token->type == 6 && (!token->next || token->next->type >= 3))
			ft_putendl_fd("bash: error near unexpected token `newline'", 2);
		else if ((token->type == 5 || token->type == TRUNC) && \
				(!token->next || token->next->type >= 3))
			ft_putendl_fd("bash: error near unexpected token `newline'", 2);
		else if (token->type == HEREDOC && !token->next)
			ft_putendl_fd("bash: error near unexpected token `newline'", 2);
		else
		{
			token = token->next;
			continue ;
		}
		return (1);
	}
	return (0);
}

static int	check_builtins(char *str, t_shell *mini)
{
	if ((ft_strncmp(str, "unset", 6) == 0))
	{
		if (!mini->token || mini->token->next == NULL)
			return (-1);
	}
	if ((ft_strncmp(str, "env", 3) == 0) && (mini->token->next \
			&& mini->token->next->type < 3))
	{
		write(2, "env: '", 6);
		write(2, mini->token->next->str, ft_strlen(mini->token->next->str));
		write(2, "': No such file or directory\n", 29);
		mini->exit_status = 127;
		return (-1);
	}
	return (0);
}

static int	check_first(t_token *token)
{
	if (token->prev == NULL && token->type == PIPE)
		ft_putendl_fd("bash: parse error near '|'", STDERR);
	else
		return (0);
	return (1);
}
