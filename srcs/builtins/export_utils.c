/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:02:43 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/27 14:29:32 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	strclen(char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		if (ft_isalnum(str[i]) == 0 || ft_isalpha(str[0]) == 0)
		{
			write(2, "export: not a valid identifier\n", 32);
			return (-1);
		}
		i++;
	}
	return (i);
}

void	free_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
