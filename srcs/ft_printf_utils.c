/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:20:55 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/30 18:36:32 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	*ft_then_free(void *ptr, void *res)
{
	free(ptr);
	return (res);
}

char
	*ft_char_to_str(char c)
{
	char str[2];

	str[0] = c;
	str[1] = 0;
	return (str);
}

char
	*ft_fill_padding(char *str, t_modifiers mods, char conv)
{
	size_t	initial_len;
	char	*new_str;
	size_t	i;
	size_t	n;

	if (!((initial_len = ft_strlen(str)) < mods.padding))
		return (ft_strdup(str));
	if (!(new_str = malloc(sizeof(char) * (mods.padding + 1))))
		return (NULL);
	i = 0;
	n = 0;
	new_str[mods.padding] = '\0';
	if (mods.padchar == '0' && ((*str == '-' || mods.sign)
		|| (conv == 'p' && *str == '0' && (new_str[i++] = *str++))))
		new_str[i++] = *str++;
	while (!mods.align_left && n++ < (mods.padding - initial_len))
		new_str[i++] = mods.padchar;
	while (*str)
		new_str[i++] = *str++;
	while (mods.align_left && n++ < mods.padding)
		new_str[i++] = ' ';
	free(str - initial_len);
	return (new_str);
}
