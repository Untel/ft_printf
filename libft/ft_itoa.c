/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:08:30 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/20 19:49:15 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	int		length;
	int		nt;
	char	*str;

	if (n < 0 && n == -2147483648)
		return (ft_strdup("-2147483648"));
	nt = (n < 0 ? -n : n);
	length = (n < 0 ? 2 : 1);
	while ((nt /= 10) != 0)
		length++;
	nt = (n < 0 ? -n : n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	str += length;
	*str = 0;
	*--str = (nt % 10) + '0';
	while ((nt /= 10))
		*--str = (nt % 10) + '0';
	if (n < 0)
		*--str = '-';
	return (str);
}
