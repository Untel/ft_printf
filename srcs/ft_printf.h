/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:23:04 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/05 18:50:24 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# define NULLABLE_STR(x) (x ? x : "(NULL)")
# define DEFAULT_VALUE(x, v) (x != -1 ? x : v)
# define DEFINED_VALUE(x) (x != -2 ? x : 0)
# define OUTPUT_FD 1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

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
char	*ft_nbrbase(uintptr_t nbr, char *base, unsigned int base_size);

char	*ft_fill_padding(char *str, t_modifiers mods, char conv);
char	*ft_fill(char *str, size_t count, char c, int align_left);

size_t	ft_parse_int(char buff[BUFFER_SIZE],
	t_modifiers mods, va_list args, char conv);
size_t	ft_parse_char(char buff[BUFFER_SIZE],
	t_modifiers mods, va_list args);
size_t	ft_parse_string(char buff[BUFFER_SIZE],
	t_modifiers mods, va_list args);
size_t	ft_parse_base(char buff[BUFFER_SIZE],
	t_modifiers mods, va_list args, char conv);
size_t	ft_parse_float(char buff[BUFFER_SIZE],
	t_modifiers mods, va_list args, char conv);
// char	*ft_parse_address(t_modifiers mods, va_list args);
int		ft_printf(const char *str, ...);
int		ft_sprintf(char *buffer, const char *str, ...);
#endif

