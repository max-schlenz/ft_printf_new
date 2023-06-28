/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:34 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/28 10:42:12 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

void mod_int(t_data *data)
{
    int arg = va_arg(data->args, int);
    
	char *tmp = NULL;
	char *str;
	bool is_neg = false;

	if (arg == INT_MIN)
		arg = arg;
	else if (arg < 0)
	{
		arg *= -1;
		is_neg = true;
	}

	// printStruct(data);
	
    if (arg == 0 && data->precision && data->width_prec == 0)
        str = ft_strdup("");
    else
        str = ft_itoa(arg);

    if (str)
    {
		if (is_neg)
		{
			tmp = ft_strjoin("-", str);
			free(str);
			str = tmp;
		}
        putstr_count(str, data);
        free(str);
    }
}
