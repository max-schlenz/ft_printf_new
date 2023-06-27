/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:34 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/27 08:37:32 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_int(t_data *data)
{
	int		i;
	int		arg;
	char	*str;

	i = 0;
	arg = va_arg(data->args, int);
	str = ft_itoa(arg);
	if (str)
	{
		if (data->precision)
		{
			while (i < data->width_prec)
			{
				putchar_count('0', data);
				i++;
			}
		}
		putstr_count(str, data);
		free(str);
	}
}
