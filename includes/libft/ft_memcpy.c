/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:18:35 by lfabel            #+#    #+#             */
/*   Updated: 2024/06/17 10:33:36 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;

	i = -1;
	if (!src && !dest)
		return (0);
	while (++i < count)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	return (dest);
}
