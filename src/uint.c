/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:27 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/30 10:37:11 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_uint(t_data *data)
{
	unsigned int	arg;
	char			*str;

	arg = va_arg(data->args, unsigned int);
	str = ft_uitoa(arg);
	putstr_count(str, data, true);
	if (str)
		free(str);
}
