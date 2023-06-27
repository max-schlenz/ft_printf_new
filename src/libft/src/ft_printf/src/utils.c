/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:22 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/27 09:31:40 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_count(char c, t_data *data)
{
	write(STDOUT_FILENO, &c, 1);
	data->count_chars++;
}

void	putstr_count(char *str, t_data *data)
{
	int	i;
	int	len;
	int	pad;
	
	i = 0;
	len = ft_strlen(str);
	// if (str[0] <= 32)
	// 	len = 0;
	// printf("stlen: %d|\n", (int)str[0]);
	pad = 0;

	if (data->right_allign)
	{
		if (data->width > len)
			pad = data->width - len;
		while (i < pad)
		{
			if (data->zero_pad)
				putchar_count('0', data);
			else
				putchar_count(' ', data);
			i++;
		}
	}
	
	while (str && *str)
		putchar_count(*str++, data);

	if (data->left_allign)
	{
		if (data->width > len)
			pad = data->width - len;
		while (i < pad)
		{
			if (data->zero_pad)
				putchar_count('0', data);
			else
				putchar_count(' ', data);
			i++;
		}
	}
}
