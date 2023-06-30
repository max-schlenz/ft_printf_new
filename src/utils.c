/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:22 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/30 10:49:05 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	putchar_count(char c, t_data *data)
{
	write(STDOUT_FILENO, &c, 1);
	data->count_chars++;
}

void putstr_count(char *str, t_data *data, bool is_numeric)
{
    int len = ft_strlen(str);
    int pad = 0;

	bool	is_neg = false;
	
	// char *tmp;

	if (str[0] == '-')
	{
		is_neg = true;
		str = str + 1;
		// free(str);
		// str = tmp;
		len--;
		data->width--;
	}

    if (data->width > len)
        pad = data->width - len;

	if (!data->right_allign && is_neg)
		putchar_count('-', data);
	else if ((data->right_allign && is_neg) && (data->width >= 0 || data->width_prec > 0))
		putchar_count('-', data);

    if (data->right_allign && pad > 0)
    {
        while (pad--)
        {
            if (data->zero_pad && is_numeric)
                putchar_count('0', data);
            else
                putchar_count(' ', data);
        }
    }

    // if (data->precision && data->width_prec > len)
    // {
    //     int precision_pad = data->width_prec - len;
    //     while (precision_pad--)
    //         putchar_count('0', data);
    // }

	if (data->precision && len > data->width_prec)
        len = data->width_prec;

    while (len--)
        putchar_count(*str++, data);

    if (data->left_allign && pad > 0)
    {
        while (pad--)
            putchar_count(' ', data);
    }
}

void	printStruct(t_data *data)
{
	printf("DATA: \n");
	printf("count_chars: %u\n", data->count_chars);
	printf("left_allign: %s\n", data->left_allign ? "true" : "false");
	printf("right_allign: %s\n", data->right_allign ? "true" : "false");
	printf("zero_pad: %s\n", data->zero_pad ? "true" : "false");
	printf("precision: %s\n", data->precision ? "true" : "false");
	printf("hash: %s\n", data->hash ? "true" : "false");
	printf("width_prec: %d\n", data->width_prec);
	printf("width: %d\n", data->width);
	printf("\n");
}

long	ft_atol(const char *str)
{
	int			i;
	long long	r;
	int			is_neg;

	i = 0;
	r = 0;
	is_neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
		|| str[i] == '\f' || str[i] == '\r')
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg = -1;
	i++;
	}
	while (ft_isdigit(str[i]))
		r = r * 10 + str[i++] - '0';
	if (!ft_isdigit(str[0]) || !ft_isdigit(str[i - 1]) || str[i] != '\0' \
		|| r > INT_MAX || r < INT_MIN)
		return (-2147483649);
	return (r * is_neg);
}