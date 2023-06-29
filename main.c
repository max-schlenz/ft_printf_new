#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include "src/libft/inc/libft.h"
#include <limits.h>
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

	// printf("|%05s|\n", "42");
	// ft_printf("|%05s|\n", "42");

	// printf("|%5.5d|\n", 1);    // prints: |     |
	// ft_printf("|%5.5d|\n", 1);    // prints: |     |

	// printf("|%050s|\n", "hello");  
	// ft_printf("|%050s|\n", "hello");    

	// printf("|%.5d|\n", 420000);    // prints: |00042|
	// ft_printf("|%.5d|\n", 420000);    // prints: |00042|

	// printf("|%5.0d|\n", 0);    // prints: |     |
	// ft_printf("|%5.0d|\n", 0);    // prints: |     |

	// printf("|%05.0d|\n", 0);   // prints: |     |
	// ft_printf("|%05.0d|\n", 0);   // prints: |     |

	// printf("|%05.0d|\n", 0);   // prints: |     |
	// ft_printf("|%05.0d|\n", 0);   // prints: |     |

	// printf("%#x\n", 42);
	// ft_printf("%#x\n", 42);
	
	// printf("%#X\n", 42);
	// ft_printf("%#X\n", 42);
	
	// printf("%#X\n", 255);
	// ft_printf("%#X\n", 255);	

	// printf("%X\n", 42);
	// ft_printf("%X\n", 42);

	// printf("|%5s|\n", "100000");
	// ft_printf("|%5s|\n", "100000");

	// printf("| %c %c %c |\n", '0', 0, '1');
	// ft_printf("| %c %c %c |\n", '0', 0, '1');

	// printf("| %-1c> %-2c> %-3c> |\n", 0, 0, 1);
	// ft_printf("| %-1c> %-2c> %-3c> |\n", 0, 0, 1);

	// printf("%d:\n", printf("| %c %c %c |\n", '0', 0, '1'));
	// printf("%d:\n", ft_printf("| %c %c %c |\n", '0', 0, '1'));

	// printf("%d:\n", printf(" %-20p ", 1));
	// printf("%d:\n", ft_printf(" %-20p ", 1));

	// printf("|%d:|\n", printf(" %-2x \n", -1));
	// printf("|%d:|\n", ft_printf(" %-2x \n", -1));

	// printf(">%d<\n", printf("| %-10X |\n", 0));
	// printf(">%d<\n", ft_printf("| %-10X |\n", 0));

	// printf("%d\n", printf(" %x ", 0));
	// printf("%d\n", ft_printf(" %x ", 0));

	// printf("%d\n", printf(" %x ", 1));
	// printf("%d\n", ft_printf(" %x ", 1));

	// printf("%d\n", printf(" %04d ", -14));
	// printf("%d\n", ft_printf(" %04d ", -14));

	// printf("%d\n", printf(" %d ", -11));
	// printf("%d\n", ft_printf(" %d ", -11));

	// printf("%d\n", printf(" %d ", INT_MIN));
	// printf("%d\n", ft_printf(" %d ", INT_MIN));

	// printf("%d\n", printf(" %04d ", -14));
	// printf("%d\n", ft_printf(" %04d ", -14));

	// printf("%d\n", printf("%1s", ""));
	// printf("%d\n", ft_printf("%1s", ""));

	// printf("%d\n", printf(" %.s ", "-"));
	// printf("%d\n", ft_printf(" %.s ", "-"));

	// printf("%d\n", printf(" %01d ", -9));
	// printf("%d\n", ft_printf(" %01d ", -9));

	// printf("%d\n", printf(" %.2s %.1s ", "", "-"));
	// printf("%d\n", ft_printf(" %.2s %.1s ", "", "-"));

	// printf("%d\n", printf(" %.1s ", "-"));
	// printf("%d\n", ft_printf(" %.1s ", "-"));

	// printf("%d\n", printf(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""));
	// printf("%d\n", ft_printf(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""));

	printf("%d\n", printf(" %.1s ", " - "));
	printf("%d\n", ft_printf(" %.1s ", " - "));

}
