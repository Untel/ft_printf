/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:23:04 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/02 17:41:17 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# include <stdlib.h>

typedef	struct	s_modifiers
{
	size_t		padding;
	char		padchar;
	int			align_left;
	int			precision;
	char		sign;
}				t_modifiers;
void	*ft_then_free(void *ptr, void *res);
char	*ft_char_to_str(char c);
int		ft_convert(char conv, t_modifiers mods, t_list **lst, va_list args);
int		ft_extract_flags(const char *str, t_list **lst, va_list args);
int		ft_printf(const char *str, ...);
char	*ft_fill_padding(char *str, t_modifiers mods, char conv);
char	*ft_nbrbase(int nbr, char *base, unsigned int base_size);
#endif
