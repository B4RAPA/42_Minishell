/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:08:03 by lfabel            #+#    #+#             */
/*   Updated: 2024/07/08 13:32:09 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int character)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	while (str[i])
	{
		if (str[i] == (char ) character)
			s = (char *) &str[i];
		i++;
	}
	if (str[i] == (char ) character)
		s = (char *) &str[i];
	return (s);
}
