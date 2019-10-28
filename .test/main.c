/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:41:54 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/28 21:51:44 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include "test.h"

#define PRINT(x, ...) (printf("ft_print(%s) =>\t\t", x#__VA_ARGS__) && ft_printf(x, __VA_ARGS__) && printf("\tVS\t") && printf(x, __VA_ARGS__) && printf("\n"))

int main(int ac, char **av)
{
    (void)av;
    (void)ac;
    int (*print)(const char *, ...);
    print = (ac == 1 ? ft_printf : printf);
    printf(ac == 1 ? "==== PRINTF ====\n" : "== FT_PRINTF ==\n");
 
    PRINT("Hi %d", 42);
    PRINT("Bonjour %d", 42);
    PRINT("Yop %d", 42);
}