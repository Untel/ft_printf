/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:17:59 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/30 18:43:08 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converters: "cspdiuxX%"
 * Modifiers: "-0.*"
 * Converters_bonus: "nfge"
 * Modifiers_bonus: "l ll h hh ’# +"
 */

#include "ft_printf.h"

static size_t
	ft_handle_padding_zero(t_modifiers *mods)
{
	mods->padchar = '0';
	return (1);
}

static size_t
	ft_handle_padding_size(const char *str, t_modifiers *mods, va_list args)
{
	if (*str == '*')
	{
		mods->padding = va_arg(args, int);
		return (1);
	}
	mods->padding = ft_atoi(str);
	return (ft_strlen(ft_itoa(mods->padding)));
}

static size_t
	ft_handle_jusitfy_side(t_modifiers *mods)
{
	mods->align_left = 1;
	mods->padchar = ' ';
	return (1);
}

static size_t
	ft_handle_precision_size(const char *str, t_modifiers *mods, va_list args)
{
	str += 1;
	if (*str == '*')
	{
		mods->precision = (int)va_arg(args, int);
		return (2);
	}
	if (!ft_isdigit(*str))
	{
		mods->precision = -2;
		return (1);
	}
		
	mods->precision = ft_atoi(str);
	return (1 + ft_strlen(ft_itoa(mods->padding)));
}

static size_t
	ft_handle_special_cases(char conv, t_modifiers *mods, va_list args)
{
	if (conv != 'f' && mods->precision != -1)
	{
		mods->padding = mods->precision != -2 ? mods->precision : 0;
		mods->align_left = 0;
		mods->padchar = '0';
	}
}

int
	ft_extract_flags(const char *str, t_list **lst, va_list args)
{
	int			i;
	t_modifiers mods;

	mods = (t_modifiers){ .padding = 0, .padchar = ' ', .sign = '\0', .align_left = 0, .precision = -1 };
	i = 0;
	while (str[i])
		if (str[i] == '0')
			i += ft_handle_padding_zero(&mods);
		else if (ft_isdigit(str[i]) || str[i] == '*')
			i += ft_handle_padding_size(&str[i], &mods, args);
		else if (str[i] == '.')
			i += ft_handle_precision_size(&str[i], &mods, args);
		else if (str[i] == '-')
			i += ft_handle_jusitfy_side(&mods);
		else if (str[i] == '+' || str[i] == ' ')
			mods.sign = str[i++];
		else
			break;
	ft_handle_special_cases(str[i], &mods, args);	
	ft_convert(str[i], mods, lst, args);
	return (i + 1);
}