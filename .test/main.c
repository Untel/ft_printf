/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:41:54 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/05 17:42:21 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	run_int_tests()
{
	PRINT("Hi \'%d\' you", 42);
    PRINT("Hi \'%5d\' you", 42);
    PRINT("Hi \'%05d\' you", 42);
    PRINT("Hi \'% 05d\' you", 42);
    PRINT("Hi \'% 0*d\' you", 5, 42);
    // PRINT("Hi \'%*.*d\' you", -5, -5, 42);
    PRINT("Hi \'%*d\' you", -5, 42);
    PRINT("Hi \'%*d\' you", -5, 42);
    PRINT("Hi \'%*u\' you", -5, -42);
    PRINT("Hi \'%04d\' you", -42);
    PRINT("Hi \'%-04d\' you", -42);
    PRINT("Hi \'%-010.6d\' you", -42);
    // PRINT("Hi \'%*.*d\' you", 5, 5, 42);
    // PRINT("Hi \'%d\' you", INT32_MAX + 3);
    // PRINT("Hi \'%u\' you", 3);
    // PRINT("Hi \'%u\' you", 333343);
    // PRINT("Hi \'%u\' you", INT32_MAX);
	// PRINT("Hi \'%.5d\' you", 42);
    // PRINT("Hi \'%.*d\' you", 5, 42);
    // PRINT("Hi \'%+5d\' you", 42);
    // PRINT("Hi \'%+5d\' you", -42);
    // PRINT("Hi \'%5d\' you", -42);
    // PRINT("Hi \'%.6d\' you", -42);
    // PRINT("Hi \'%06d\' you", -42);
    // PRINT("Hi \'%.1d\' you", -42);
    // PRINT("Hi \'%+6.d\' you", 42);
    // PRINT("Hi \'%+09.4d\' you", 42);
    // PRINT("Hi \'%+9.4d\' you", 42);
    // PRINT("Hi \'%9.4d\' you", 42);
    // PRINT("Hi \'% 9.4d\' you", 42);
    // PRINT("Hi \'%+04d\' you", 42);
    // PRINT("Hi \'%.0d\' you", 0);
    // PRINT("Hi \'%.0d\' you", 4);
    // PRINT("Hi \'%.032d\' you", 4);
}

int	run_string_tests()
{
    PRINT("Hi \'%-5s\' you", "yo");
    PRINT("Hi \'%05s\' you", "-yo");
    PRINT("Hi \'%9.6s\' you", "Bonjour a tous");
    PRINT("Hi \'%9.6s\' you", "-Bonjour a tous");
    PRINT("Hi \'%6.9s\' you", "Bonjour a tous");
    PRINT("Hi \'%s\' you", "yo");
    PRINT("Hi \'%.10s\' you", "yo");
    PRINT("Hi \'%.s\' you", "yo");
    PRINT("Hi \'%5.1s\' you", "yo");
    PRINT("Hi \'%*s\' you", -5, "yo");
    PRINT("Hi \'% s\' you", "yo");
    PRINT("Hi \'%+s\' you", "yo");
    PRINT("Hi \'%020s\' you", "-Bonjour a tous");
}
int	run_char_tests()
{
    PRINT("Hi \'%c\' you", 'k');
    PRINT("Hi \'%c\' you", '\0');
    PRINT("Hi \'%05c\' you", '\0');
    PRINT("Hi \'%05c\' you", 'c');
    PRINT("Hi \'%.5c\' you", 'c');
    PRINT("Hi \'%5.9c\' you", 'c');
    PRINT("Hi \'%+05.9c\' you", 'c');
    PRINT("Hi \'%-05.9c\' you", 'c');
    PRINT("Hi \'% 5.9c\' you", 'c');
    PRINT("Hi \'%.0c\' you", 'c');
    PRINT("Hi \'%5.*c\' you", -5, 'c');
    PRINT("Hi \'%-5.c\' you", 'c');
    PRINT("Hi \'%0*.c\' you", -5, 'c');
    PRINT("Hi \'%0*.c\' you", 5, 'c');
}

int	run_hex_tests()
{
    PRINT("Hi \'%x\' you", 15);
    PRINT("Hi \'%x\' you", -15);
    PRINT("Hi \'%X\' you", INT64_MAX);
    PRINT("Hi \'%x\' you", INT64_MAX + 1);
	PRINT("Hi \'%X\' you", INT64_MIN);
    PRINT("Hi \'%x\' you", INT64_MIN - 1);
    PRINT("Hi \'%X\' you", INT32_MAX);
    PRINT("Hi \'%X\' you", 750);
    PRINT("Hi \'%#x\' you", 750);
    PRINT("Hi \'%#10.7x\' you", 750);
    PRINT("Hi \'%-5X\' you", 750);
    PRINT("Hi \'%-10.3X\' you", 75000);
}
int	run_pointer_tests()
{
	char *init = "BONJOUR A TOUS";
	char *uninit;

    PRINT("Hi \'%p\' you", init);
    PRINT("Hi \'%.5p\' you", init);
    PRINT("Hi \'%.10p\' you", init);
    PRINT("Hi \'%p\' you", uninit);
    PRINT("Hi \'%-10.3p\' you", uninit);
    PRINT("Hi \'%#-10.3p\' you", uninit);
    PRINT("Hi \'%p\' you", INT64_MAX);
    PRINT("Hi \'%llx\' you", INT64_MAX);
    PRINT("Hi \'%lx\' you", INT64_MAX);
    PRINT("Hi \'%hx\' you", INT64_MAX);
    // PRINT("Hi \'%020p\' you", init);
    // PRINT("Hi \'%020p\' you", uninit);
    // PRINT("Hi \'%25.20p\' you", init);
    // PRINT("Hi \'%25.20p\' you", uninit);
    // PRINT("Hi \'%14.5p\' you", init);
    // PRINT("Hi \'%14.5p\' you", uninit);
}

int	run_float_tests()
{
    PRINT("Hi \'%f\' you", 3.999);
    PRINT("Hi \'%.f\' you", 3.999);
    PRINT("Hi \'%.f\' you", 3.123);
    PRINT("Hi \'%.3f\' you", 3.999);
    PRINT("Hi \'%.3f\' you", -3.999);
    PRINT("Hi \'%.3e\' you", -31.1);
    PRINT("Hi \'%.4e\' you", -31.991);
    PRINT("Hi \'%.10f\' you", 3.999);
    PRINT("Hi \'%.20g\' you", 3.999);
    PRINT("Hi \'%.15g\' you", 3.999999999999999);
    PRINT("Hi \'%.15f\' you", 3.999999999999999);
    PRINT("Hi \'%.15f\' you", 3.999999999999999);
    PRINT("Hi \'%020f\' you", -127.32435);
    PRINT("Hi \'%.f\' you", -127.32435);
}

int	run_other_tests()
{
    PRINT("Hi \'%s\' %s %d you %s", "how", "are", 42, "doing?");
}

int	run_exp_tests()
{
    PRINT("Hi \'%e\' you", 3.999);
}

int main(int ac, char **av)
{
    (void)ac;
	memset(g_flush1, 0, BUFFER_SIZE);
	memset(g_flush2, 0, BUFFER_SIZE);
	while (*++av)
		if (strcmp(*av, "int") == 0)
			HEADER(*av, run_int_tests);
		else if (strcmp(*av, "char") == 0)
			HEADER(*av, run_char_tests);
		else if (strcmp(*av, "string") == 0)
			HEADER(*av, run_string_tests);
		else if (strcmp(*av, "pointer") == 0)
			HEADER(*av, run_pointer_tests);
		else if (strcmp(*av, "hex") == 0)
			HEADER(*av, run_hex_tests);
		else if (strcmp(*av, "float") == 0)
			HEADER(*av, run_float_tests);
		else if (strcmp(*av, "exp") == 0)
			HEADER(*av, run_float_tests);
		else if (strcmp(*av, "other") == 0)
			HEADER(*av, run_other_tests);

	printf("\e[0;36mTotal\e[0m: %*s%d/%d\n\e[0m", 49, g_okcount == g_total ? "\e[0;32m" : "\e[0;31m", g_okcount, g_total);
	printf("======================================================\n");
	system("leaks a.out");
}