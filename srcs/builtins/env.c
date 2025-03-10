/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:43:32 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/18 16:51:58 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_list *env)
{
	t_list	*en;
	int		i;
	char	*str;

	if (!env)
		return (1);
	en = env;
	while (en && en->value)
	{
		i = 0;
		str = en->value;
		while (str[i])
		{
			if (ft_strncmp(&str[i], "=", 1) == 0)
				printf(" %s\n", en->value);
			i++;
		}
		en = en->next;
	}
	return (0);
}
