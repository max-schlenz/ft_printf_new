/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:11:41 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 14:17:25 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	padding_prec(const char* fmt, int *i, t_data *data)
{
	data->width_prec = 0;
	while (ft_isdigit(fmt[*i]))
	{
		data->width_prec = data->width * 10 + (fmt[*i] - '0');
		(*i)++;
	}
}

void	padding(const char* fmt, int *i, t_data *data)
{
	data->width = 0;
	while (ft_isdigit(fmt[*i]))
	{
		data->width = data->width * 10 + (fmt[*i] - '0');
		(*i)++;
	}
}
