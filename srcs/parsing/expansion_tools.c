/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:45:13 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/10 10:46:17 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	skip_dollar(char *str, char *result)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	result = malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		if (str[i] == '$')
			i++;
		else
		{
			result[k] = str[i];
			k++;
			i++;
		}
	}
	result[k] = '\0';
}
