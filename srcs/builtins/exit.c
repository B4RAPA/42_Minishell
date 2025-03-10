/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:27:09 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/14 13:28:01 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_exit(t_shell *mini)
{
	t_token	*token;
	int		exit_code;

	token = mini->token;
	if (!token->next)
		exit_code = 0;
	else if (is_number(token->next->str) != 0)
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		exit_code = 2;
	}
	else if (token->next && token->next->next)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		mini->exit_status = 123;
		exit_code = -1;
		return ;
	}
	else
		exit_code = ft_atoi(token->next->str);
	mini->exit = exit_code;
}
