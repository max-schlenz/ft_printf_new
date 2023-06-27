/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:34 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/27 11:25:25 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void mod_int(t_data *data)
{
    int arg = va_arg(data->args, int);
    char *str;

    if (arg == 0 && data->precision && data->width_prec == 0)
        str = ft_strdup("");
    else
        str = ft_itoa(arg);

    if (str)
    {
        putstr_count(str, data);
        free(str);
    }
}
