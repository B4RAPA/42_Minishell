/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:16 by lfabel            #+#    #+#             */
/*   Updated: 2024/06/17 11:40:46 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *des, const void *src, size_t num)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)des;
	i = -1;
	if (!des && !src)
		return (0);
	if (des == src)
		return (des);
	if (d > s)
	{
		while (num-- > 0)
			d[num] = s[num];
	}
	else
	{
		while (++i < num)
			d[i] = s[i];
	}
	return (des);
}
