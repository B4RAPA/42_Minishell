/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:54:44 by lfabel            #+#    #+#             */
/*   Updated: 2024/06/17 11:30:42 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *ptr, int value, size_t num )
{
	size_t			i;
	unsigned char	*src;
	unsigned char	c;

	src = (unsigned char *) ptr;
	c = (unsigned char )value;
	i = -1;
	while (num > ++i)
	{
		if (src[i] == c)
			return ((void *)&src[i]);
	}
	return (NULL);
}
