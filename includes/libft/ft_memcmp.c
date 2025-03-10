/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:09:41 by lfabel            #+#    #+#             */
/*   Updated: 2024/06/17 11:23:55 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( const void *ptr1, const void *ptr2, size_t num )
{
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;

	i = -1;
	s1 = (unsigned char *) ptr1;
	s2 = (unsigned char *) ptr2;
	while (++i < num)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
