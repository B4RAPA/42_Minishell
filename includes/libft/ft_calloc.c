/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:24:58 by lfabel            #+#    #+#             */
/*   Updated: 2024/06/16 14:16:05 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)//num = anzahl && size = laenge
{
	void	*ptr;

	ptr = (char *) malloc (num * size);
	if (!ptr)
		return (ptr);
	ft_bzero (ptr, size * num);
	return (ptr);
}
