/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:02:26 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 08:19:21 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modifier(char mod, t_data *data)
{
	if (mod == 'c')
		mod_char(data);
	else if (mod == 's')
		mod_string(data);
	else if (mod == 'p')
		mod_ptr(data);
	else if (mod == 'd' || mod == 'i')
		mod_int(data);
	else if (mod == 'u')
		mod_uint(data);
	else if (mod == 'X')
		mod_hex(data, true);
	else if (mod == 'x')
		mod_hex(data, false);
	else if (mod == '%')
		putchar_count('%', data);
}

int	ft_printf(const char *fmt, ...)
{
	t_data	data;
	int		i;

	i = 0;
	ft_memset(&data, 0, sizeof(data));
	va_start(data.args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			modifier(fmt[i + 1], &data);
			i += 2;
		}
		else
			putchar_count(fmt[i++], &data);
	}
	va_end(data.args);
	return (data.count_chars);
}
