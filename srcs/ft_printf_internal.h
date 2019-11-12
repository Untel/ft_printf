/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:23:04 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/12 19:05:39 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H
# include "ft_printf.h"
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <locale.h>
# include <wchar.h>
# define NULLABLE_STR(x) (x ? x : "(NULL)")
# define DEFAULT_VALUE(x, v) (x != -1 ? x : v)
# define DEFINED_VALUE(x) (x != -2 ? x : 0)
# define OUTPUT_FD 1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define B BUFFER_SIZE

typedef enum	e_argsize
{
	H, HH, N, L, LL
}				t_argsize;
typedef	struct	s_modifiers
{
	size_t		padding;
	char		padchar;
	char		sep;
	int			align_left;
	int			precision;
	int			alt;
	t_argsize	size;
	char		sign;
	int			trail;
}				t_modifiers;
void			*ft_then_free(void *ptr, void *res);
int				ft_convert(char conv, t_modifiers mods, t_list **lst, va_list args);
int				ft_extract_flags(const char *str, va_list args, t_modifiers *mods);
int				ft_is_conv(char *str, char c);
char			*ft_nbrbase(uintptr_t nbr, char *base, unsigned int base_size);
char			*ft_fill(char *str, size_t count, char c, int align_left);
char			*ft_fill_c(char cc, size_t count, char c, int align_left);
char			*ft_add_sign(char sign, char *str);
int				ft_parse_int(char *buff,
	t_modifiers mods, va_list args, char conv);
int				ft_parse_char(char *buff,
	t_modifiers mods, va_list args, char conv);
int				ft_parse_string(char *buff,
	t_modifiers mods, va_list args);
int				ft_parse_base(char *buff,
	t_modifiers mods, va_list args, char conv);
int				ft_parse_float(char *buff,
	t_modifiers mods, va_list args, char conv);
int64_t			ft_get_sized_int(va_list args, t_modifiers mods);
uint64_t		ft_get_sized_uint(va_list args, t_modifiers mods);
int				ft_printf(const char *str, ...);
int				ft_sprintf(char *buffer, const char *str, ...);
int				ft_split_to_list(const char *str, t_list **lst, va_list args);
char			*ft_stringify_exp(char conv, long double arg,
	size_t dig, t_modifiers mods);
char			*ft_stringify_float(long double val, size_t dig, t_modifiers mods);
#endif

