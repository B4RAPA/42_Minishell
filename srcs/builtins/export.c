/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:43:46 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/27 14:47:16 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	exists(t_list *env, char *name, t_shell *mini);
void		printf_export(t_shell *mini);
static int	line_shit(t_shell *mini, char *name);

int	check_existing(char *name, t_shell *mini)
{
	int		i;

	i = 1;
	if (!name[0])
		return (-1);
	if (ft_strrchr(name, '='))
	{
		if (line_shit(mini, name) == 1)
			return (1);
	}
	else
	{
		while (mini->env && name)
		{
			if (ft_strncmp(mini->env->value, name, ft_strlen(name)) == 0)
			{
				free(mini->env->value);
				mini->env->value = ft_strdup(name);
				return (1);
			}
			mini->env = mini->env->next;
		}
	}
	return (0);
}

int	ft_export(t_shell *mini)
{
	char	*name;
	t_list	*env;

	if (!mini->token->next || !(mini->token->next->type < 3))
	{
		printf_export(mini);
		return (0);
	}
	name = ft_strdup(mini->token->next->str);
	if (strclen(name, '=') == -1)
	{
		free(name);
		return (127);
	}
	env = mini->env;
	return (exists(env, name, mini));
}

static int	exists(t_list *env, char *name, t_shell *mini)
{
	int		i;
	t_list	*new;

	(void)env;
	i = check_existing(name, mini);
	mini->env = mini->head;
	if (i == 1)
	{
		free(name);
		return (0);
	}
	else if (name[0] && i != 1)
	{
		new = ft_lstnew(name);
		free(name);
		if (!new)
			return (1);
		ft_lstadd_back(&(mini->env), new);
	}
	return (0);
}

void	printf_export(t_shell *mini)
{
	t_list	*tmp;

	tmp = mini->env;
	while (tmp)
	{
		printf("declare -x %s\n", tmp->value);
		tmp = tmp->next;
	}
}

static int	line_shit(t_shell *mini, char *name)
{
	while (mini->env && ft_strncmp(name, mini->env->value, \
			strclen(name, '=')) != 0)
		mini->env = mini->env->next;
	if (mini->env && ft_strncmp(name, mini->env->value, \
		strclen(name, '=')) == 0 && ft_strncmp(name, mini->env->value, \
			strclen(mini->env->value, '=')) == 0)
	{
		free(mini->env->value);
		mini->env->value = ft_strdup(name);
		return (1);
	}
	return (0);
}
