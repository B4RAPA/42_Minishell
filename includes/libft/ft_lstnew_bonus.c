/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:12:07 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/25 10:29:41 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *value)
{
	t_list	*out;

	out = malloc(sizeof(t_list));
	if (!out)
		return (0);
	out->value = ft_strdup(value);
	out->next = NULL;
	return (out);
}
