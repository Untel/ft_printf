/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:22:15 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/28 19:40:43 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <stdio.h>
# include "ft_printf.h"
# ifndef ORIGIN_PRINTF
#  define ORIGIN_PRINTF
#  define PRINT printf
# else
#  define PRINT ft_printf
# endif
#endif