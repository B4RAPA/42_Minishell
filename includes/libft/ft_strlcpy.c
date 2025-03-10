/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:05:23 by lfabel            #+#    #+#             */
/*   Updated: 2024/06/17 10:20:04 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *des, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	if (!des && !src && !size)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (++i < size - 1 && src[i])
	{
		des[i] = src[i];
	}
	des[i] = '\0';
	return (ft_strlen(src));
}
