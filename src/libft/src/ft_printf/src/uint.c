/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:27 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 08:16:27 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_uint(t_data *data)
{
	unsigned int	arg;
	char			*str;

	arg = va_arg(data->args, unsigned int);
	str = ft_uitoa(arg);
	putstr_count(str, data);
	if (str)
		free(str);
}
