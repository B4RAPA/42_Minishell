/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:43:26 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/27 14:09:25 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_echo(char *str);

int	ft_echo(t_token *token)
{
	if (!token || !token->next)
	{
		write (1, "\n", 1);
		return (0);
	}
	if (ft_strcmp(token->str, "echo") == 0)
		token = token->next;
	token = skip_args(token);
	if (token == NULL)
		return (0);
	while (token && token->str && token->type < 3)
	{
		print_echo(token->str);
		if (!token->next)
			break ;
		token = token->next;
		if (token && token->type < 3)
			write(1, " ", 2);
	}
	while (token->prev->prev)
		token = token->prev;
	if (token->str && (ft_strncmp(token->str, "-n", 1) != 0))
		printf ("\n");
	return (0);
}

void	print_echo(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

t_token	*skip_args(t_token *token)
{
	char	*str;
	int		i;

	while (token && token->str && token->type < 3)
	{
		i = 0;
		str = token->str;
		if (token->str && (ft_strncmp(token->str, "-n", 1) == 0))
		{
			i = 1;
			while (str[i] && str[i] == 'n')
				i++;
			if (!str[i])
			{
				if (token->next)
					token = token->next;
				else
					return (NULL);
				continue ;
			}
		}
		break ;
	}
	return (token);
}
