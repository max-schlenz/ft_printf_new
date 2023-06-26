/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:29 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 08:17:35 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_string(t_data *data)
{
	char	*arg;

	arg = va_arg(data->args, char *);
	if (arg)
		putstr_count(arg, data);
	else
		putstr_count("(null)", data);
}
