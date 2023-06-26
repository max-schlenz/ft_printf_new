/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:13:31 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 09:00:22 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ptr_to_hex_len(unsigned long ul_ptr_addr)
{
	int	ptr_addr_len;

	ptr_addr_len = 0;
	while (ul_ptr_addr != 0)
	{
		ul_ptr_addr /= 16;
		ptr_addr_len ++;
	}
	return (ptr_addr_len - 1);
}

static char	*ptr_to_hex(unsigned long ul_ptr_addr, bool lowercase)
{
	char			*ptr_addr;
	size_t			len_ptr_addr;
	unsigned long	remainder;
	int				i;

	i = 0;
	len_ptr_addr = ptr_to_hex_len(ul_ptr_addr);
	ptr_addr = ft_calloc(len_ptr_addr + 2, sizeof(char));
	while (ul_ptr_addr != 0)
	{
		remainder = ul_ptr_addr % 16;
		if (remainder > 9)
			ptr_addr[len_ptr_addr] = 55 + remainder;
		else
			ptr_addr[len_ptr_addr] = 48 + remainder;
		if (lowercase)
			ptr_addr[len_ptr_addr] = ft_tolower(ptr_addr[len_ptr_addr]);
		ul_ptr_addr /= 16;
		len_ptr_addr--;
	}
	return (ptr_addr);
}

void	mod_ptr(t_data *data)
{
	unsigned long	arg;
	char			*str;

	putchar_count('0', data);
	putchar_count('x', data);
	arg = (unsigned long)va_arg(data->args, void *);
	if (arg)
	{
		str = ptr_to_hex(arg, 1);
		if (str)
		{
			putstr_count(str, data);
			free(str);
		}
	}
	else
		putchar_count('0', data);
}
