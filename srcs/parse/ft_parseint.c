/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:32:41 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/06 22:15:48 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t
	ft_get_sized_int(va_list args, t_modifiers mods)
{
	int64_t val;

	if (mods.size == HH)
		val = (int64_t)va_arg(args, char);
	else if (mods.size == H)
		val = (int64_t)va_arg(args, short int);
	else if (mods.size == N)
		val = (int64_t)va_arg(args, int);
	else if (mods.size == L)
		val = (int64_t)va_arg(args, long int);
	else if (mods.size == LL)
		val = (int64_t)va_arg(args, int64_t);
	else
		val = 0;
	return (val);
}

uint64_t
	ft_get_sized_uint(va_list args, t_modifiers mods)
{
	uint64_t val;

	if (mods.size == HH)
		val = (uint64_t)va_arg(args, unsigned char);
	else if (mods.size == H)
		val = (uint64_t)va_arg(args, unsigned short int);
	else if (mods.size == N)
		val = (uint64_t)va_arg(args, unsigned int);
	else if (mods.size == L)
		val = (uint64_t)va_arg(args, unsigned long int);
	else if (mods.size == LL)
		val = (uint64_t)va_arg(args, uint64_t);
	else
		val = 0;
	return (val);
}

char
	*ft_apply_int_precision(char *res, t_modifiers mods)
{
	char *tmp;

	if (ft_strlen(res) == 1 && *res == '0')
		res = ft_then_free(res, ft_strdup(""));
	if (mods.precision > 0)
	{
		res = ft_then_free(res, ft_fill(res, mods.precision, '0', 0));
	}
	if (mods.sign)
		res = ft_then_free(res, ft_add_sign(mods.sign, res));
	res = ft_then_free(res, ft_fill(res, mods.padding, ' ', mods.align_left));
	return (res);
}

char
	*ft_apply_int_flags(char *res, t_modifiers mods)
{
	if (!(res = ft_strdup(res)))
		return (NULL);
	if (mods.precision != -1)
		return (ft_apply_int_precision(res, mods));
	else
	{
		if (mods.sign && mods.padchar == ' ')
			res = ft_then_free(res, ft_add_sign(mods.sign, res));
		else if (mods.sign)
			mods.padding--;
		res = ft_then_free(res,
			ft_fill(res, (mods.padding), mods.padchar, mods.align_left));
		if (mods.sign && mods.padchar == '0')
			res = ft_then_free(res, ft_add_sign(mods.sign, res));
	}
	return (res);
}

size_t
	ft_parse_int(char buff[BUFFER_SIZE],
	t_modifiers mods, va_list args, char conv)
{
	char	*res;
	char	*tmp;
	size_t	len;

	// printf("Conv = %c, size = %d\n", conv, mods.size);
	if (conv != 'u')
		res = ft_llitoa(ft_get_sized_int(args, mods));
	else
		res = ft_lluitoa(ft_get_sized_uint(args, mods));
	if (*res == '-')
	{
		res = ft_then_free(res, ft_strdup(res + 1));
		mods.sign = '-';
	}
	res = ft_then_free(res, ft_apply_int_flags(res, mods));
	len = ft_strcpy(buff, res);
	ft_memdel(&res);
	return (len);
}
