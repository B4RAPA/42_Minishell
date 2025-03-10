/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:43:56 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/17 11:13:57 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(t_shell *mini)
{
	t_list	*cur;
	t_list	*prev;
	char	*name;

	name = mini->token->next->str;
	cur = mini->env;
	prev = NULL;
	while (cur)
	{
		if (ft_strncmp(cur->value, name, ft_strlen(name)) == 0 && \
			cur->value[ft_strlen(name)] == '=')
		{
			if (prev)
				prev->next = cur->next;
			else
				mini->env = cur;
			free (cur->value);
			free (cur);
			return (0);
		}
		prev = cur;
		cur = cur->next;
	}
	return (0);
}
