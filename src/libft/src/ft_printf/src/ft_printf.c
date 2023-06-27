/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:02:26 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/27 08:31:08 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	modifier_bonus(char mod, const char* fmt, int *i, t_data *data)
{
	if (fmt[*i] == '-')
	{
		(*i)++;
		padding(fmt, i, data);
		data->left_allign = true;
	}
	else if (fmt[*i] == '#')
	{
		(*i)++;
		data->hash = true;
	}
	else if (fmt[*i] == '0')
	{
		(*i)++;
		padding(fmt, i, data);
		data->zero_pad = true;
		data->right_allign = true;
	}
	else if (ft_isdigit(fmt[*i]))
	{		
		padding(fmt, i, data);
		data->right_allign = true;
	}
	if (fmt[*i] == '.')
	{
		(*i)++;
		padding_prec(fmt, i, data);
		data->zero_pad = true;
		data->right_allign = true;
	}
}

void	modifier(char mod, t_data *data)
{
	// printf("mod: %c\n", mod);
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
			i ++;
			modifier_bonus(fmt[i], fmt, &i, &data);
			modifier(fmt[i], &data);
			i ++;
		}
		else
			putchar_count(fmt[i++], &data);
	}
	va_end(data.args);
	return (data.count_chars);
}
