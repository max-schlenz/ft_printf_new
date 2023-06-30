/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:19:14 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/30 10:36:48 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uint_to_hex_len(unsigned int hex)
{
	int	hex_len;

	hex_len = 0;
	while (hex != 0)
	{
		hex /= 16;
		hex_len ++;
	}
	return (hex_len - 1);
}

static char	*uint_to_hex(unsigned int hex, bool uppercase)
{
	char			*str_hex;
	int				len_hex;
	unsigned int	remainder;
	int				i;

	i = 0;
	len_hex = uint_to_hex_len(hex);
	// printf(">>%d\n", len_hex);
	if (len_hex < 0)
		return NULL;
	str_hex = ft_calloc(len_hex + 2, sizeof(char));
	while (hex != 0)
	{
		remainder = hex % 16;
		if (remainder > 9)
			str_hex[len_hex] = 55 + remainder;
		else
			str_hex[len_hex] = 48 + remainder;
		if (!uppercase)
			str_hex[len_hex] = ft_tolower(str_hex[len_hex]);
		hex /= 16;
		len_hex--;
	}
	return (str_hex);
}

void mod_hex(t_data *data, bool uppercase)
{
    unsigned int to_hex = (unsigned int)va_arg(data->args, int);
    char *str = NULL;
    char *prefix = NULL;

    if (data->hash)
    {
        prefix = uppercase ? "0X" : "0x";
    }

    str = uint_to_hex(to_hex, uppercase);
    if (str)
    {
        // If the # flag is present, concatenate the prefix and the number
        if (prefix)
        {
            char *temp = str;
            str = ft_strjoin(prefix, str);  // Assume ft_strjoin allocates a new string
            free(temp);
        }

        putstr_count(str, data, false);
        free(str);
    }
    else if (!to_hex)
    {
        // If the number is 0, output 0 with putstr_count to handle padding and field width
        putstr_count("0", data, false);
    }
}


// void	mod_hex(t_data *data, bool uppercase)
// {
// 	unsigned int	to_hex;
// 	char			*str;

// 	if (data->hash)
// 	{
// 		putchar_count('0', data);
// 		if (uppercase)
// 			putchar_count('X', data);
// 		else
// 			putchar_count('x', data);
// 	}
// 	to_hex = (unsigned int)va_arg(data->args, int);
// 	if (!to_hex)
// 	{
// 		putchar_count('0', data);
// 	}
// 	str = uint_to_hex(to_hex, uppercase);
// 	if (str)
// 	{
// 		putstr_count(str, data);
// 		free(str);
// 	}
// }
