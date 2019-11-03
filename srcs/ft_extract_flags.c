/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:17:59 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/03 22:29:39 by adda-sil         ###   ########.fr       */
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
	ft_handle_size(const char *str, t_modifiers *mods)
{
	size_t ret;

	ret = 1;
	if (*str == 'l')
		if (str[1] == 'l' && ret++)
			mods->size = LL;
		else
			mods->size = L;
	else
		if (str[1] == 'h' && ret++)
			mods->size = HH;
		else
			mods->size = H;

	return (ret);
}

static size_t
	ft_handle_padding_size(const char *str, t_modifiers *mods, va_list args)
{
	int s;
	if (*str == '*')
	{
		s = va_arg(args, int);
		if (s >= 0)
			mods->padding = (size_t)s;
		else
		{
			mods->align_left = 1;
			mods->padding = (size_t)(s * -1);
		}
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
		mods->precision = 0;
		return (1);
	}
		
	mods->precision = ft_atoi(str);
	return (1 + ft_strlen(ft_itoa(mods->precision)));
}

static size_t
	ft_handle_special_cases(char conv, t_modifiers *mods, va_list args)
{
	if (conv != 'f' && mods->precision != -1)
	{
		mods->padding = mods->precision != -2 ? mods->precision : mods->padding;
		mods->align_left = 0;
	}
}

int
	ft_extract_flags(const char *str, t_list **lst, va_list args)
{
	int			i;
	t_modifiers mods;

	mods = (t_modifiers){ .padding = 0, .padchar = ' ', .sign = 0, .align_left = 0, .precision = -1, .alt = 0, .size = N };
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
		else if (str[i] == '#')
			(mods.alt = 1) && i++;
		else if (str[i] == 'l' || str[i] == 'h')
			i += ft_handle_size(&str[i], &mods);			
		else
			break;
	// ft_handle_special_cases(str[i], &mods, args);
	ft_convert(str[i], mods, lst, args);
	return (i + 1);
}