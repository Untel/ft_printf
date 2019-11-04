/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:23:04 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/04 09:55:37 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# include <stdlib.h>

typedef enum	e_argsize
{
	N, L, LL, H, HH
}				t_argsize;
typedef	struct	s_modifiers
{
	size_t		padding;
	char		padchar;
	int			align_left;
	int			precision;
	int			alt;
	t_argsize	size;
	char		sign;
}				t_modifiers;
void	*ft_then_free(void *ptr, void *res);
char	*ft_char_to_str(char c);
int		ft_convert(char conv, t_modifiers mods, t_list **lst, va_list args);
int		ft_extract_flags(const char *str, t_list **lst, va_list args);
int		ft_printf(const char *str, ...);
char	*ft_nbrbase(uintptr_t nbr, char *base, unsigned int base_size);

char	*ft_fill_padding(char *str, t_modifiers mods, char conv);
char	*ft_fill(char *str, size_t count, char c, int align_left);

char	*ft_parse_int(t_modifiers mods, va_list args, char conv);
char	*ft_parse_char(t_modifiers mods, va_list args);
char	*ft_parse_string(t_modifiers mods, va_list args);
char	*ft_parse_base(t_modifiers mods, va_list args, char conv);
char	*ft_parse_float(t_modifiers mods, va_list args, char conv);
// char	*ft_parse_address(t_modifiers mods, va_list args);
#endif
