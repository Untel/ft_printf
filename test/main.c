/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:41:54 by adda-sil          #+#    #+#             */
/*   Updated: 2019/11/14 01:41:03 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	run_int_tests()
{
	PRINT("Hi \'%d\' you", 42);
	PRINT("Hi \'%d\' you", INT32_MAX);
    PRINT("Hi \'%5d\' you", 42);
    PRINT("Hi \'%05d\' you", 42);
    PRINT("Hi \'% 05d\' you", 42);
    PRINT("Hi \'% 0*d\' you", 5, 42);
    PRINT("Hi \'%*.*d\' you", -5, -5, 42);
    PRINT("Hi \'%*d\' you", -5, 42);
    PRINT("Hi \'%*d\' you", -5, 42);
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
    PRINT("Hi \'%+9.4d\' you", 42);
    PRINT("Hi \'%9.4d\' you", 42);
    PRINT("Hi \'% 9.4d\' you", 42);
    PRINT("Hi \'%+04d\' you", 42);
    PRINT("Hi \'%.0d\' you", 0);
    PRINT("Hi \'%.0d\' you", 4);
    PRINT("Hi \'%.032d\' you", 4);
    PRINT("Hi \'%*.*d\' you", 5, 5, 42);
    PRINT("Hi \'%-010.6d\' you", -42);
    PRINT("Hi \'%-04d\' you", -42);
    PRINT("Hi \'%04d\' you", -42);
    PRINT("Hi \'%#d\' you", 0);
    PRINT("Hi \'%d\' you", 0);
    PRINT("Hi \'%lld\' you", INT64_MAX);
    PRINT("Hi \'%ld\' you", INT64_MAX);
	PRINT("Hi \'%hd\' you", INT64_MAX);
    PRINT("Hi \'%hhd\' you", INT64_MAX);
    PRINT("Hi \'%hd\' you", INT32_MIN - 6000);
    PRINT("Hi \'%hhd\' you", INT32_MIN - 6000);
    PRINT("Hi \'%lld\' you", INT64_MAX);
    PRINT("Hi \'%'d\' you", 1234567);
    PRINT("Hi \'%'d\' you", 1234567);
    PRINT("Hi \'%0d\' you", -579);
    PRINT("%d%d", 4, 2);	
	//TOFIX
    // PRINT("Hi \'%d\' you", INT32_MAX + 3);
}

int	run_uint_tests()
{
    PRINT("Hi \'%u\' you", 0);
    PRINT("Hi \'%u\' you", -4500);
    PRINT("Hi \'%u\' you", -200);
    PRINT("Hi \'%u\' you", INT64_MAX);
    PRINT("Hi \'%llu\' you", INT64_MAX);
    PRINT("Hi \'%lu\' you", INT64_MAX);
	PRINT("Hi \'%hu\' you", INT64_MAX);
    PRINT("Hi \'%hhu\' you", INT64_MAX);
    PRINT("Hi \'%hu\' you", INT32_MIN + 6000);
    PRINT("Hi \'%hhu\' you", INT32_MIN + 6000);
    PRINT("Hi \'%hu\' you", INT32_MIN - 6000);
    PRINT("Hi \'%hhu\' you", INT32_MIN - 6000);
    PRINT("Hi \'%'u\' you", INT32_MIN - 6000);
    PRINT("%llu", (unsigned long long)-12345612220);
	//TOFIX
    PRINT("Hi \'%d\' you", INT32_MAX + 3);
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
    PRINT("Hi \'%012s\' you", "-Bonjour a tous");
    PRINT("Hi \'%012.8s\' you", "-Bonjour a tous");
    PRINT("Hi \'%-012.8s\' you", "-Bonjour a tous");
    PRINT("Hi \'%12.8s\' you", "-Bonjour a tous");
    PRINT("Hi \'%12.8hhs\' you", "-Bonjour a tous");
    PRINT("Hi \'%12.8lls\' you", "-Bonjour a tous");
    PRINT("Hi \'%ls\' you", L"I will display À ♠");
    PRINT("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256);
    PRINT("test %-7C %007d%-10.2ls!!", 0xd777, 0x45, L"〻");
    PRINT("%05.2ls!!", L"〻");
    PRINT("%9.6ls %S", L"㪼#@$%^&*()_S", L"a");
    PRINT("I am hap%-8ls", L"py 😋");

}
int	run_char_tests()
{
    PRINT("Hi \'%05c\' you", '-');
    PRINT("Hi \'%5.*c\' you", -5, '-');
    PRINT("Hi \'%*c\' you", -5, '-');
    PRINT("Hi \'%c\' you", 'k');
    PRINT("Hi \'%c\' you", '\0');
    PRINT("Hi \'%05c\' you", '\0');
    PRINT("Hi \'%-5c\' you", '\0');
    PRINT("Hi \'%'5c\' you", '\0');
    PRINT("Hi \'%#5c\' you", '\0');
    PRINT("Hi \'%0.5c\' you", '\0');
    PRINT("Hi \'%#-5.4c\' you", '\0');
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
    PRINT("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
    PRINT("%05lc", 0x20AC);
    PRINT("%05c", 0x20AC);
    PRINT("%lc", 0x1e40);
    PRINT("%lc", 0x40501);
    PRINT("%C", 0x110000);
    PRINT("%lc", 0x10FFFF);
    PRINT("Hey %lc you", 0x11ffff);
    PRINT("%lc", 254);
    PRINT("%lc", 0xdfff);
    PRINT("%lc", 0xbffe);

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
    PRINT("Hi \'%llx\' you", INT64_MAX);
    PRINT("Hi \'%lx\' you", INT64_MAX);
    PRINT("%#X", 0);
    PRINT("%#o", 0);
    PRINT("%#X", 70);
    PRINT("%.0x", 0);
    PRINT("%.1x", 70000);
    PRINT("Hi \'%hx\' you", INT64_MAX);
    PRINT("t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1);
    PRINT("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
    PRINT("toto %##.0xet %#.X%###.1x", 0, 0, 0);
    PRINT("%0#10.0x %0#x", 12345, 0);
    PRINT("%0#############10.........000000x %0#x", 12345, 0);
    PRINT("%0#10.0x", 0);
    PRINT("coco et %-#-#--24O titi%#012o", 12, -874);
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
    PRINT("Hi \'%#-10.3hhp\' you", uninit);
    PRINT("Hi \'%p\' you", INT64_MAX);
    PRINT("Hi \'%llp\' you", INT64_MAX);
    PRINT("Hi \'%lp\' you", INT64_MAX);
    PRINT("Hi \'%hhp\' you", INT64_MIN);
    PRINT("Hi \'%hp\' you", INT64_MIN + 600);
    PRINT("Hi \'%hp\' you", INT64_MIN - 600);
    PRINT("Hi \'%020p\' you", init);
    PRINT("Hi \'%020p\' you", uninit);
    PRINT("Hi \'%25.20p\' you", init);
    PRINT("Hi \'%25.20p\' you", uninit);
    PRINT("Hi \'%14.5p\' you", init);
    PRINT("Hi \'%14.5p\' you", uninit);
}

int	run_float_tests()
{
    PRINT("Hi \'%f\' you", 3.999);
    PRINT("Hi \'%.f\' you", 3.999);
    PRINT("Hi \'%f\' you", 3.999);
    PRINT("Hi \'%.f\' you", 3.456);
    PRINT("Hi \'%.f\' you", 3.90000);
    PRINT("Hi \'%.f\' you", 3.123);
    PRINT("Hi \'%.3f\' you", 3.999);
    PRINT("Hi \'%.3f\' you", -3.999);
    PRINT("Hi \'%.10f\' you", 3.999);
    PRINT("Hi \'%.15f\' you", 3.999999999999999);
    PRINT("Hi \'%.15f\' you", 3.9999999999999999);
    PRINT("Hi \'%.16f\' you", 3.999999999999999);
    // PRINT("Hi \'%.18f\' you", 3.99999999999999999);
    PRINT("Hi \'%020f\' you", -127.32435);
    PRINT("Hi \'%.f\' you", -127.32435);
    PRINT("Hi \'%'.f\' you", -12744515451.32435);
    PRINT("Hi \'%'020f\' you", -15451.32435);
    PRINT("Hi \'%f\' you", 0.0042);
    PRINT("Hi \'%.1f\' you", 3.96);
    PRINT("Hi \'%.2f\' you", 3.96);
    PRINT("Hi \'%'10.3f\' you", 1233.96);
    PRINT("%f", -5.9999999);
	PRINT("%5.0f", -7.3);
	PRINT("%f", -0.00032);
	PRINT("%f", -0.00032);
	PRINT("%4.09f", -7.3);
	PRINT("%5.1f", -7.3);
	PRINT("%Lf", 1.99999949l);
}

int	run_exp_tests()
{
    PRINT("Hi \'%.4e\' you", -31.991);
    PRINT("Hi \'%.3e\' you", -31.1);
    PRINT("Hi \'%e\' you", 3.999);
    PRINT("Hi \'%e\' you", 151.32);
    PRINT("Hi \'%e\' you", -151.32);
    PRINT("Hi \'%e\' you", 0.000042);
}

int	run_gfloat_tests()
{
    PRINT("Hi \'%g\' you", 0.000042);
    PRINT("Hi \'%g\' you", 0.0042);
    PRINT("Hi \'%.5g\' you", 4200.042);
    PRINT("Hi \'%.4g\' you", 4200.042);
    PRINT("Hi \'%.6g\' you", 4200.042);
}


int	run_other_tests()
{
    PRINT("Hi %%n\'%s\' %s %d you %s", "how", "are", 42, "doing?");
    int n;
    int m;
    n = 0;
    m = 0;
	// TEST %n
    printf("Hi %n%%n\'%s\' %s %d you %s has %d\n", &n, "how", "are", 42, "doing?", n);
    ft_printf("Hi %n%%n\'%s\' %s %d you %s has %d\n", &m, "how", "are", 42, "doing?", m);
	printf(n == m ? "\e[0;32m" : "\e[0;31m");
    printf("Orig %%n = %d, Your %%n = %d\n", n, m);
	printf("\e[0m");

	//SANDBOX
    PRINT("Hello %d %", 1);
    PRINT("Hello %.*d %", -10, 1);
    PRINT("Hello %.*f %", -4, 123.456789);
    PRINT("|%%%%%%%|");
    PRINT("|%-5..-.10k|");
    PRINT("%@@@%10");
    PRINT("%✈️@@🗿@%-25⛱");
    PRINT("pC4IqXzMQ%0*xpi9U7", -6, 0);
    PRINT("pC4IqXzMQ%0*.-5xpi9U7", -6, 0);
	PRINT("eHEtK8hgt%7.0s%i%-x%0d", "8PkQQbbMw5Lx45nlSfnS9gYh85nMBuxPcjQHERVOmpgd2OS7IKX9AvvQfVfaBvMShJMHd16", 2147483647, 2147483647, 0);
	PRINT("cxCiLwP b%16.0u", 2147483647);
	PRINT("zTKIqO%.0x%-*.3X%c%*c8z1ufquH4m%-x", 0, -8, 2147483647, '\0', 0, 'r', 2147483647);
	n = printf("zTKIqO%.0x%-*.3X%c%*c8z1ufquH4m%-x\n", 0, -8, 2147483647, '\0', 0, 'r', 2147483647);
	m = ft_printf("zTKIqO%.0x%-*.3X%c%*c8z1ufquH4m%-x\n", 0, -8, 2147483647, '\0', 0, 'r', 2147483647);
	if (n == m)
		printf("\e[0;32m");
    printf("Orig %%n = %d, Your %%n = %d\n", n, m);
	printf("\e[0m");
	PRINT("ovjCxNv%*c%018xhG9NP%c%0xmbSroi%%", 6, 'Y', -102219787, 'u', -542704649);
	PRINT("pvIPqX0uI0%10s%-*.0s%0.3d0v", NULL, 3, "", -2147483647);
	PRINT("%0.5x", 0);
	PRINT("%%%%A nu%-11.3XEj2ny%%", -2147483647);
	PRINT("DU23Ql%.0ikOeIQ", 2147483647);
	PRINT("F31%19x", 2147483647);
	ft_printf("%s", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");
}

#include <locale.h>
int main(int ac, char **av, char **env)
{
    (void)ac;
	int show_leaks = 0;
	memset(g_flush1, 0, BUFFER_SIZE);
	memset(g_flush2, 0, BUFFER_SIZE);
	setlocale(LC_ALL, "en_US.UTF-8");
	while (*++av)
		if (strcmp(*av, "int") == 0)
			HEADER(*av, run_int_tests);
		else if (strcmp(*av, "uint") == 0)
			HEADER(*av, run_uint_tests);
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
			HEADER(*av, run_exp_tests);
		else if (strcmp(*av, "gfloat") == 0)
			HEADER(*av, run_gfloat_tests);
		else if (strcmp(*av, "other") == 0)
			HEADER(*av, run_other_tests);
		else if (strcmp(*av, "leaks") == 0)
			show_leaks = 1;
	printf("\e[0;36mTotal\e[0m: %*s%d/%d\n\e[0m", 49, g_okcount == g_total ? "\e[0;32m" : "\e[0;31m", g_okcount, g_total);
	printf("======================================================\n");
	if (show_leaks)
		system("leaks a.out");
    // char *str = ft_itoa_wrapper((uint64_t)(42), '\0', 0);
    // printf("%s\n", str);
	// printf("|len=%d\n", printf("%c", 0));
	// printf("|len=%d\n", printf("%05.3%"));
	// printf("Hi \'%20.*-5s\' you", 10, "bonjour");
    // printf("Hi \'%'f\' you\n", -12744515451.32435);
    // PRINT("Hi \'%#.18llf\' you", 0.0000000046);

	return (0);
}