/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:25 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/27 12:47:38 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_char(t_data *data)
{
	char	arg;
	char	str[2];

	data->zero_pad = false;
	arg = va_arg(data->args, int);
	if (!arg)
	{
		data->width--;
		putchar_count(arg, data);
		// data->count_chars++;
	}
	
	str[0] = arg;
	str[1] = '\0';

	// if (str[0])
		putstr_count(str, data);
	// else
}

