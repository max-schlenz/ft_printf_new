/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:29 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 14:11:10 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_string(t_data *data)
{
	char	*arg;

	arg = va_arg(data->args, char *);
	data->zero_pad = false;
	if (arg)
		putstr_count(arg, data);
	else
		putstr_count("(null)", data);
}
