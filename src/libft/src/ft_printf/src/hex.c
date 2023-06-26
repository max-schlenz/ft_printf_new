/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:19:14 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 08:19:15 by mschlenz         ###   ########.fr       */
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

void	mod_hex(t_data *data, bool uppercase)
{
	unsigned int	to_hex;
	char			*str;

	to_hex = (unsigned int)va_arg(data->args, int);
	if (!to_hex)
		putchar_count('0', data);
	str = uint_to_hex(to_hex, uppercase);
	if (str)
	{
		putstr_count(str, data);
		free(str);
	}
}
