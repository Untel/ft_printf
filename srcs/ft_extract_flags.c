/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:17:59 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/29 21:21:16 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converters: "cspdiuxX%"
 * Modifiers: "-0.*"
 * Converters_bonus: "nfge"
 * Modifiers_bonus: "l ll h hh ’# +"
 */

#include "ft_printf.h"

const char *converters = "cspdiuxX%";
const char *modifiers = "-0.*123456789";

static size_t
	ft_handle_padding_zero(t_modifiers *mods)
{
	mods->padding = '0';
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
	ft_handle_precision_size(const char *str, t_modifiers *mods, va_list args)
{
	str += 1;
	if (*str == '*')
	{
		mods->precision = (int)va_arg(args, int);
		return (1);
	}
	mods->precision = ft_atoi(str);
	return (1 + ft_strlen(ft_itoa(mods->padding)));
}

static int
	ft_convert(char conv, t_modifiers mods, t_list **lst, va_list args)
{
	char *res = 0;
	(void)mods;

	if (conv == 'd')
		res = ft_itoa((int)va_arg(args, int));

	if (res)
		ft_lstadd_back(lst, ft_lstnew(res));
	return (1);
}

int
	ft_extract_flags(const char *str, t_list **lst, va_list args)
{
	int			i;
	t_modifiers mods;

	mods = (t_modifiers){ .padding = 0, .padchar = ' ', .show_sign = 0 };
	i = 0;
	while (str[i])
		if (str[i] == '0')
			i += ft_handle_padding_zero(&mods);
		else if (ft_isdigit(str[i]) || str[i] == '*')
			i += ft_handle_padding_size(&str[i], &mods, args);
		else if (str[i] == '.')
			i += ft_handle_precision_size(&str[i], &mods, args);
		else
			break;

	// if (ft_strchr(converters, str[i]))
	ft_convert(str[i], mods, lst, args);
	return (i + 1);
}