/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:22 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/27 11:20:39 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_count(char c, t_data *data)
{
	write(STDOUT_FILENO, &c, 1);
	data->count_chars++;
}

void putstr_count(char *str, t_data *data)
{
    int len = ft_strlen(str);
    int pad = 0;

    if (data->width > len)
        pad = data->width - len;

    if (data->right_allign && pad > 0)
    {
        while (pad--)
        {
            if (data->zero_pad)
                putchar_count('0', data);
            else
                putchar_count(' ', data);
        }
    }

    // Write the precision zero padding
    if (data->precision && data->width_prec > len)
    {
        int precision_pad = data->width_prec - len;
        while (precision_pad--)
            putchar_count('0', data);
    }

    // Write the string itself
    while (*str)
        putchar_count(*str++, data);

    if (data->left_allign && pad > 0)
    {
        while (pad--)
            putchar_count(' ', data);
    }
}