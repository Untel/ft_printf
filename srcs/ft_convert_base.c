/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 01:33:08 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/02 15:45:05 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_nb_char_base(long int nbr, int base_size)
{
	if (nbr > 0)
		return (1 + (ft_nb_char_base(nbr / base_size, base_size)));
	else
		return (0);
}

char	*alloc_str(unsigned int nb, int base_size, char *base, int is_neg)
{
	char	*ptr;
	char	*save;
	int		len;

	len = nb > 0 ? (ft_nb_char_base(nb, base_size) + is_neg) : 1;
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (!ptr || ptr == NULL)
		return (0);
	save = ptr + len;
	*save-- = '\0';
	if (nb == 0)
		*save-- = base[nb % base_size];
	while (nb > 0)
	{
		*save-- = base[nb % base_size];
		nb = nb / base_size;
	}
	if (is_neg)
		*save-- = '-';
	return (ptr);
}

char	*ft_nbrbase(int nbr, char *base, unsigned int base_size)
{
	unsigned int	nb;
	int				is_neg;

	is_neg = 0;
	if (nbr < 0)
	{
		nb = (unsigned int)(nbr * -1);
		is_neg = 1;
	}
	else
		nb = (unsigned int)nbr;
	return (alloc_str(nb, base_size, base, is_neg));
}
