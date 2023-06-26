/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:11:41 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 12:51:39 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	padding(const char* fmt, int *i, t_data *data)
{
	while (ft_isdigit(fmt[*i]))
	{
		data->width = data->width * 10 + (fmt[*i] - '0');
		(*i)++;
	}
}
