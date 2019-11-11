/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:07:39 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/11 01:55:24 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_parse_string(char buff[BUFFER_SIZE], t_modifiers mods, va_list args)
{
	char	*res;
	size_t	len;

	res = (char *)va_arg(args, char *);
	res = NULLABLE_STR(res);
	if (mods.precision == -1)
		res = ft_strdup(res);
	else
		res = ft_substr(res, 0, DEFINED_VALUE(mods.precision));
	if (!res || !(res = ft_then_free(res,
		ft_fill(res, mods.padding, mods.padchar, mods.align_left))))
		return (-1);
	len = ft_strcpy(buff, res);
	ft_memdel((void **)&res);
	return (len);
}

char* wchar_to_char(const wchar_t* pwchar)
{
	int currentCharIndex = 0;

	char currentChar = pwchar[currentCharIndex];
	while (currentChar != '\0')
	{
		currentCharIndex++;
		currentChar = pwchar[currentCharIndex];
	}
	const int charCount = currentCharIndex + 1;
	char* filePathC = (char*)malloc(sizeof(char) * charCount);

	for (int i = 0; i < charCount; i++)
	{
		char character = pwchar[i];
        *filePathC = character;
        filePathC += sizeof(char);
    }
    filePathC += '\0';

    filePathC -= (sizeof(char) * charCount);

    return filePathC;
}

wchar_t
	ft_get_sized_char(va_list args, t_modifiers mods)
{
	wchar_t val;

	if (mods.size <= N)
		val = (wchar_t)va_arg(args, int);
	else
		val = (wchar_t)va_arg(args, wchar_t);
	return (val);
}

int
	ft_parse_char(char buff[BUFFER_SIZE],
		t_modifiers mods, va_list args, char conv)
{
	wchar_t	c;
	char	*res;
	char	b[999];
	wchar_t	ws[2];
	int		len;

	c = ft_is_conv("cC", conv) ? ft_get_sized_char(args, mods) : '%';
	if (mods.size <= N || c <= 128)
	{
		res = ft_fill_c(c, mods.padding, mods.padchar, mods.align_left);
		len = mods.padding > 1 ? mods.padding : 1;
	}
	else
	{
		ws[0] = c;
		ws[1] = 0;
		ft_strcat(b, ft_nbrbase((int)c, "0123456789ABCDEF", 16));
		write(1, "Hey: '", 6);
		wchar_t n = 0xA9;
		write(1, &n, 21);
		write(1, "'\n", sizeof(char) * 2);
		res = ft_fill((char *)b, mods.padding, mods.padchar, mods.align_left);
		len = mods.padding > 0 ? mods.padding - 1 : 0;
		len += 4;
	}
	ft_memcpy(buff, res, len);
	ft_memdel((void **)&res);
	return (len);
}
