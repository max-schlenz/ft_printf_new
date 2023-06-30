/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:34 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/30 10:48:53 by mschlenz         ###   ########.fr       */
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
			// printf("%d\n", ft_strlen(str));
				// data->width_prec-- ;
			
		}
		int len = ft_strlen(str);
       	if (data->precision && data->width_prec >= len)
		{
            int precision_pad;
            if (is_neg)
                precision_pad = data->width_prec - len + 1;
            else
                precision_pad = data->width_prec - len;
            
            while (precision_pad--)
                putchar_count('0', data);
        }
        putstr_count(str, data, true);
        free(str);
    }
}
