/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:23:04 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/29 19:25:41 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef	struct	s_modifiers
{
	int			padding;
	int			margin;
	int			show_sign;
}				t_modifiers;

int ft_parseint(const char *str, ...);
int ft_printf(const char *str, ...);
#endif
