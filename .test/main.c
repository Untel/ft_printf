/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:41:54 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/30 18:58:46 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include "test.h"

#define PRINT(x, ...) (printf("======================================================\nft_printf(\"%s\", %s)\n------------------------------------------------------\n", x, #__VA_ARGS__) && ft_printf(x, __VA_ARGS__) && printf("\t\tVS\t\t") && printf(x, __VA_ARGS__) && printf("\n------------------------------------------------------\n"))

int main(int ac, char **av)
{
    (void)av;
    (void)ac;

    PRINT("Hi \'%d\' you", 42);
    PRINT("Hi \'%5d\' you", 42);
    PRINT("Hi \'%05d\' you", 42);
    PRINT("Hi \'% 05d\' you", 42);
    PRINT("Hi \'% 0*d\' you", 5, 42);
    // PRINT("Hi \'%-5s\' you", "yo");
    PRINT("Hi \'%05s\' you", "yo");
    PRINT("Hi \'%.10s\' you", "yo");
    PRINT("Hi \'%.s\' you", "yo");

	PRINT("Hi \'%.5d\' you", 42);
    PRINT("Hi \'%.*d\' you", 5, 42);
    PRINT("Hi \'%+5d\' you", 42);
    PRINT("Hi \'%+5d\' you", -42);
    PRINT("Hi \'%5d\' you", -42);
    PRINT("Hi \'%.6d\' you", -42);
    PRINT("Hi \'%06d\' you", -42);
    PRINT("Hi \'%.1d\' you", -42);
    PRINT("Hi \'%+6.d\' you", 42);
    PRINT("Hi \'%+09.4d\' you", 42);
    // PRINT("Bonjour %d", 42);
    // PRINT("%d yo", 42);
}