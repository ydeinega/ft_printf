#include "libftprintf.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
	//Per cent
	// printf("%5%|\n");
	// ft_printf("%5%|\n");

	// printf("\n%05%|\n");
	// ft_printf("%05%|\n");
	
	// printf("\n%-5%|\n");
	// ft_printf("%-5%|\n");
	
	// printf("\n%.0%|\n");
	// ft_printf("%.0%|\n");

	// printf("\n%05.10%|\n");
	// ft_printf("%05.10%|\n");
	
	// printf("\n%   %|\n", "test");
	// ft_printf("%   %|\n", "test");



	//перепроверить работу ширины для х
	// printf("%#-08x|\n", 42);
	// ft_printf("%#-08x|\n", 42);

	// printf("\n%#08x|\n", 42);
	// ft_printf("%#08x|\n", 42);



	//пресижин 0 для 0 не выводит
	// printf("\n@moulitest:%#.x|%#.0x|\n", 0, 0);
	// ft_printf("@moulitest:%#.x|%#.0x|\n", 0, 0);
	
	// printf("\n@moulitest: %.x| %.0x|\n", 0, 0);
	// ft_printf("@moulitest: %.x| %.0x|\n", 0, 0);

	// printf("\n@moulitest: %#.x %#.0x\n", 42, 42);
	// ft_printf("@moulitest: %#.x %#.0x\n", 42, 42);

	// printf("\n@moulitest: %5.x| %5.0x|\n", 0, 0);
	// ft_printf("@moulitest: %5.x| %5.0x|\n", 0, 0);

	// printf("\n@moulitest:%.u|%.0u|\n", 0, 0);
	// ft_printf("@moulitest:%.u|%.0u|\n", 0, 0);

	// printf("\n@moulitest: %5.u| %5.0u|\n", 0, 0);
	// ft_printf("@moulitest: %5.u| %5.0u|\n", 0, 0);

	// printf("\n@moulitest:%#.O|%#.0O|\n", 0, 0);
	// ft_printf("@moulitest:%#.o|%#.0o|\n", 0, 0);

	// printf("\n@moulitest: %5.o| %5.0o|\n", 0, 0);
	// ft_printf("@moulitest: %5.o| %5.0o|\n", 0, 0);

	// printf("%s\n", ft_strjoin("0", ""));

	// printf("\n@moulitest: %5.d| %5.0d|\n", 0, 0);
	// ft_printf("@moulitest: %5.d| %5.0d|\n", 0, 0);


	// NULL for s and c
	// int a;
	// int b = 0;
	
	//ft_strdup(NULL);
	// a = printf("@moulitest: %10s\n", NULL);
	// b = ft_printf("@moulitest: %10s\n", NULL);
	// printf("a = %d, b = %d\n", a, b);
	// ft_printf("@moulitest: %s\n", NULL);

	//printf("%s %s", NULL, "@moulitest");
	//ft_printf("%s %s", NULL, "@moulitest");

	//printf("%.2c", NULL); 
	//ft_printf("%.2c", NULL);

	// 0 для c 
	int a;
	int b;

	// a = printf("@moulitest:%c|\n", 0);
	// b = ft_printf("@moulitest:%c|\n", 0);
	// printf("a = %d, b = %d\n", a, b);

	// printf("\n");
	// a = printf("@moulitest:%.2C|\n", 0);
	// b = ft_printf("@moulitest:%.2C|\n", 0);
	// printf("a = %d, b = %d\n", a, b);


	// printf("\n");
	// a = printf("@moulitest:%2c|\n", 0); 
	// b = ft_printf("@moulitest:%2c|\n", 0);
	// printf("a = %d, b = %d\n", a, b);

	// printf("\n");
	// a = printf("@moulitest:%-5c|\n", 0); 
	// b = ft_printf("@moulitest:%-5c|\n", 0);
	// printf("a = %d, b = %d\n", a, b);

	// printf("\n");
	// a = printf("@moulitest:%-5c|\n", 'a'); 
	// b = ft_printf("@moulitest:%-5c|\n", 'a');
	// printf("a = %d, b = %d\n", a, b);

	// printf("\n");
	// a = printf("@moulitest:%02c|\n", 0); 
	// b = ft_printf("@moulitest:%02c|\n", 0);
	// printf("a = %d, b = %d\n", a, b);

	
	// printf("\n");
	// a = printf("null %c and text\n", 0); 
	// b = ft_printf("null %c and text\n", 0);
	// printf("a = %d, b = %d\n", a, b);

	// printf("\n");
	// a = printf("% c|\n", 0);
	// b = ft_printf("% c|\n", 0);
	// printf("a = %d, b = %d\n", a, b);

	// printf("\n");
	// a = printf("%s\n", "hello");
	// b = ft_printf("%s\n", "hello");
	// printf("a = %d, b = %d\n", a, b);

	//#define CTEST
	#ifdef CTEST
	a = printf("{%*c}\n", -15, 0);
	b = ft_printf("{%*c}\n", -15, 0);
	printf("a = %d, b = %d\n", a, b);

	a = printf("{%-15c}\n", 0);
	b = ft_printf("{%-15c}\n", 0);
	printf("a = %d, b = %d\n", a, b);

	a = printf("{%*3d}\n", 0, 0);
	b = ft_printf("{%*3d}\n", 0, 0);
	printf("a = %d, b = %d\n", a, b);
	#endif


	//CONV p
	// int a;
	// int b;

	// a = printf("%p\n", 0);
	// b = ft_printf("%p\n", 0);
	// printf("a = %d, b = %d\n", a, b);

	// a = printf("{%05p}\n", 0);
	// b = ft_printf("{%05p}\n", 0);
	// printf("a = %d, b = %d\n", a, b);

	//#define NONVALID
	#ifdef NONVALID
	printf("\n");
	a = printf("{%10R}\n");
	b = ft_printf("{%10R}\n");
	printf("a = %d, b = %d\n", a, b);

	printf("\n");
	a = printf("{%-15Z}\n", 123);
	b = ft_printf("{%-15Z}\n", 123);
	printf("a = %d, b = %d\n", a, b);

	printf("\n");
	a = printf("{%05.Z}\n", 0);
	b = ft_printf("{%05.Znn}\n", 0);
	printf("a = %d, b = %d\n", a, b);


	printf("\n");//не реагирует на пресижн
	a = printf("{%.5Z}\n", 0);
	b = ft_printf("{%.5Z}\n", 0);
	printf("a = %d, b = %d\n", a, b);
	#endif

	//#define OTHER
	#ifdef OTHER
	setlocale(LC_ALL, "");
	printf("\n");
	a = printf("|%-2.0c|\n", 'a');
	b = ft_printf("|%-2.0c|\n", 'a');
	printf("a = %d, b = %d\n", a, b);

	printf("\n");
	a = printf("|%.0c|\n", 'a');
	b = ft_printf("|%.0c|\n", 'a');
	printf("a = %d, b = %d\n", a, b);

	printf("\n");
	a = printf("|%.0C|\n", L'Ю');
	b = ft_printf("|%.0C|\n", L'Ю');
	printf("a = %d, b = %d\n", a, b);
	#endif

	#define ASCII
	#ifdef ASCII
	//setlocale(LC_ALL, "");
	printf("sp\n");
	a = printf("|%5 |\n");
	b = ft_printf("|%5 |\n");
	printf("a = %d, b = %d\n", a, b);

	printf("!\n");
	a = printf("|%5!|\n");
	b = ft_printf("|%5!|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("\"\n");
	a = printf("|%5\"|\n");
	b = ft_printf("|%5\"|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("#\n");
	a = printf("|%5#|\n");
	b = ft_printf("|%5#|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("$\n");
	a = printf("|%5$|\n");
	b = ft_printf("|%5$|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("%%\n");
	a = printf("|%5%|\n");
	b = ft_printf("|%5%|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("&\n");
	a = printf("|%5&|\n");
	b = ft_printf("|%5&|\n");
	printf("a = %d, b = %d\n", a, b);

	printf(",\n");//не выводит
	a = printf("|%5,|\n");
	b = ft_printf("|%5,|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("(\n");
	a = printf("|%5(|\n");
	b = ft_printf("|%5(|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("(\n");//не выводит
	a = printf("|%5:|\n");
	b = ft_printf("|%5:|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("(\n");//не выводит
	a = printf("|%5;|\n");
	b = ft_printf("|%5;|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("(\n");//выводит
	a = printf("|%5?|\n");
	b = ft_printf("|%5?|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("(\n");//не выводит
	a = printf("|%5_|\n");
	b = ft_printf("|%5_|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("(\n");//выводит
	a = printf("|%05]|\n");
	b = ft_printf("|%05]|\n");
	printf("a = %d, b = %d\n", a, b);

	printf("(\n");//выводит
	a = printf("|%5Ю|\n");
	b = ft_printf("|%5Ю|\n");
	printf("a = %d, b = %d\n", a, b);

	// , ; : _
	#endif

	


}