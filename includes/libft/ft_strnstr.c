/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:37:37 by lfabel            #+#    #+#             */
/*   Updated: 2025/02/06 13:58:31 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (little[0] == 0)
		return ((char *) big);
	while (big[i + k] && (i + k) < len)
	{
		if (big[i + k] == little[k])
			k++;
		else
		{
			i += 1;
			k = 0;
		}
		if (little[k] == '\0')
			return ((char *) big + i);
	}
	return (NULL);
}
