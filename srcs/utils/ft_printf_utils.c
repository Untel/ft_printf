/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:55 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/08 14:22:56 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *
	ft_add_sign(char sign, char *str)
{
	char *res;

	if (!(res = malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	*res = sign;
	ft_strcpy(&res[1], str);
	return (res);
}

void
	*ft_then_free(void *ptr, void *res)
{
	ft_memdel(&ptr);
	return (res);
}

char
	*ft_char_to_str(char c)
{
	char *str;

	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

char
	*ft_fill_padding(char *str, t_modifiers mods, char conv)
{
	size_t	initial_len;
	size_t	len;
	char	*new_str;
	size_t	i;

	if (!((initial_len = ft_strlen(str)) < mods.padding))
		return (str);
	if (!(new_str = malloc(sizeof(char) * (mods.padding + 1))))
		return (NULL);
	i = 0;
	if (mods.padchar == '0' && ((*str == '-' || mods.sign)
		|| (conv == 'p' && *str == '0' && str[1] == 'x'
		&& (new_str[i++] = *str++))))
		new_str[i++] = *str++;
	len = ft_strlen(str);
	while (!mods.align_left && i < (mods.padding - len))
		new_str[i++] = mods.padchar;
	while (*str)
		new_str[i++] = *str++;
	while (mods.align_left && i < (mods.padding))
		new_str[i++] = ' ';
	free(str - initial_len);
	new_str[i] = 0;
	return (new_str);
}

char
	*ft_fill(char *str, size_t count, char c, int align_left)
{
	size_t	initial_len;
	size_t	i;
	char	*new_str;

	i = 0;
	if ((initial_len = ft_strlen(str)) >= count)
		return (ft_strdup(str));
	if (!(new_str = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	while (!align_left && i < (count - initial_len))
		new_str[i++] = c;
	while (*str)
		new_str[i++] = *str++;
	while (align_left && i < count)
		new_str[i++] = ' ';
	new_str[i] = 0;
	return (new_str);
}
