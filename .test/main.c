/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:41:54 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/29 16:31:39 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include "test.h"

#define PRINT(x, ...) (printf("\t-----\nft_printf(%s, %s)\n", x, #__VA_ARGS__) && printf("'") && ft_printf(x, __VA_ARGS__) && printf("'") && printf("\t\tVS\t\t") && printf("'") && printf(x, __VA_ARGS__) && printf("'") && printf("\n"))

int main(int ac, char **av)
{
    (void)av;
    (void)ac;
 
    PRINT("Hi %d", 42);
    PRINT("Bonjour %d", 42);
    PRINT("Yop %d", 42);
}