/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:34 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 08:18:47 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_int(t_data *data)
{
	int		arg;
	char	*str;

	arg = va_arg(data->args, int);
	str = ft_itoa(arg);
	if (str)
	{
		putstr_count(str, data);
		free(str);
	}
}
