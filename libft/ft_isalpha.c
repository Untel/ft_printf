/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:32:42 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/10 17:32:44 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_islower(unsigned char c)
{
	return (c >= 'a' && c <= 'z');
}

int		ft_isupper(unsigned char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		ft_isalpha(unsigned char c)
{
	return (ft_islower(c)
		|| ft_isupper(c));
}
