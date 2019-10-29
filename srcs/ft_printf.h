/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:23:04 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/29 20:34:46 by adda-sil         ###   ########.fr       */
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
	int			padding;
	int			precision;
	char		padchar;
	int			show_sign;
}				t_modifiers;

int		ft_extract_flags(const char *str, t_list **lst, va_list args);
int 	ft_parseint(const char *str, ...);
int		ft_printf(const char *str, ...);
#endif
