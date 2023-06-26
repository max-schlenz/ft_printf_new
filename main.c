#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include "src/libft/inc/libft.h"

int main()
{
	// char *str = "hello";
	// printf(" (%d)\n", printf("%s", str));
	// printf(" (%d)\n", ft_printf("%s", str));

	// int i = 42;
	// printf(" (%d)\n", printf("%d", i));
	// printf(" (%d)\n", ft_printf("%d", i));

	// unsigned int ui = (unsigned int) __INT_MAX__ + 10;
	// printf(" (%d)\n", printf("%u", ui));
	// printf(" (%d)\n", ft_printf("%u", ui));
	
	// void *ptr = ft_calloc(1, sizeof(void));
	// printf(" (%d)\n", printf("%p", ptr));
	// printf(" (%d)\n", ft_printf("%p", ptr));
	// free(ptr);

	// int i_hex = 42;
	// printf(" (%d)\n", printf("%x", i_hex));
	// printf(" (%d)\n", ft_printf("%x", i_hex));

	// printf(" (%d)\n", printf(" %c %c %c ", '0', 0, '1'));
	// printf(" (%d)\n", ft_printf(" %c %c %c ", '0', 0, '1'));

	// // printf(" (%d)\n", printf("%c%c ", '0', '4'));
	// // printf(" (%d)\n", ft_printf("%c%c ", '0', '4'));

	// printf(" (%d)\n", printf(" %c %c %c ", '0', 0, '1'));
	// printf(" (%d)\n", ft_printf(" %c %c %c ", '0', 0, '1'));

	// // printf(" (%d)\n", printf(" %c %c %c ", '2', '1', 0));
	// // printf(" (%d)\n", ft_printf(" %c %c %c ", '2', '1', 0));
	
	// // printf(" (%d)\n", printf(" %c %c %c ", 0, '1', '2'));
	// // printf(" (%d)\n", ft_printf(" %c %c %c ", 0, '1', '2'));

	// printf("|%-25s|\n", "text");
	// ft_printf("|%-25s|\n", "text");

	// printf("|%25d|\n", 42);
	// ft_printf("|%25d|\n", 42);

	// printf("|%05d|\n", 42);
	// ft_printf("|%05d|\n", 42);

	printf("|%5d|\n", 42);
	ft_printf("|%05d|\n", 42);

}