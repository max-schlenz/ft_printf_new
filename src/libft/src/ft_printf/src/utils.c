/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:22 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 08:14:04 by mschlenz         ###   ########.fr       */
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

	i = 0;
	while (str && *str)
		putchar_count(*str++, data);
}
