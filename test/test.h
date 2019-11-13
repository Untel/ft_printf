/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:22:15 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/13 23:13:56 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "ft_printf.h"
# include "ft_printf_internal.h"
# include <stdio.h>
# include "libft.h"
# include <unistd.h>
int		g_size1;
int		g_size2;
char 	g_flush1[BUFFER_SIZE];
char 	g_flush2[BUFFER_SIZE];
int		g_is_ok = 0;
int		g_okcount = 0;
int		g_total = 0;

#define PRINT(...) {\
	g_size1 = ft_sprintf(g_flush1, __VA_ARGS__);\
	g_size2 = sprintf(g_flush2, __VA_ARGS__);\
	g_is_ok = (!strcmp(g_flush1, g_flush2) && g_size1 == g_size2);\
	printf("------------------------------------------------------\n");\
	printf("ft_printf(%s)\n", #__VA_ARGS__);\
	printf("%s\"%s\" (%d)\n\e[0m", g_is_ok ? "\e[0;32m" : "\e[0;31mMine: ", g_flush1, g_size1);\
	if (g_is_ok == 0)\
		printf("\e[0;32mOrig: \"%s\" (%d)\n\e[0m", g_flush2, g_size2);\
	else\
		g_okcount++;\
	g_total++;\
}
#define HEADER(x, fn) (printf("\e[0;36m %*s \e[0m\n", ((printf("======================================================\n") + ft_strlen(x)) / 2), x) && printf("======================================================\n") && fn() && printf("\n======================================================\n"))
#endif