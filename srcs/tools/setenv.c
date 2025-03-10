/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:48:45 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/27 13:55:44 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shlvl(t_shell *mini);

int	get_env(t_shell *mini, char **envp)
{
	int		i;
	t_list	*new;
	char	**str;

	i = 0;
	str = envp;
	if (!str)
		error();
	else
	{
		while (str[i])
		{
			new = ft_lstnew(str[i]);
			if (!new)
			{
				ft_lstclear(&(mini->env), free_lst);
				break ;
			}
			ft_lstadd_back(&(mini->env), new);
			i++;
		}
	}
	shlvl(mini);
	return (0);
}

void	free_lst(void *value)
{
	free (value);
}

void	shlvl(t_shell *mini)
{
	int		i;
	char	*str;
	char	*level;

	i = 0;
	mini->head = mini->env;
	while (mini->env)
	{
		if (ft_strncmp(mini->env->value, "SHLVL", 5) == 0)
		{
			str = mini->env->value;
			while (str[i] != '=')
				i++;
			i = ft_atoi(&str[i + 1]) + 1;
			level = ft_itoa(i);
			str = ft_strjoin("SHLVL=", level);
			ft_strcpy(mini->env->value, str);
			free (level);
			free(str);
			mini->env = mini->head;
			return ;
		}
		mini->env = mini->env->next;
	}
	mini->env = mini->head;
}
