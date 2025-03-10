/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:37:10 by lfabel            #+#    #+#             */
/*   Updated: 2024/06/17 13:03:54 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long int nbr);

char	*ft_itoa(int i)
{
	long int	nbr;
	char		*result;
	int			len;
	int			n;

	nbr = i;
	len = int_len(nbr);
	result = malloc (sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	result[0] = '0';
	n = len - 1;
	while (nbr != 0)
	{
		result[n] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		n--;
	}
	if (i < 0)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

static int	int_len(long int nbr)
{
	int	n;

	n = 0;
	if (nbr < 0)
	{
		n++;
		nbr = -nbr;
	}
	if (nbr == 0)
		n++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		n++;
	}
	return (n);
}
