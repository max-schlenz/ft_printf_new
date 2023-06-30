/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:15:38 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/26 08:16:08 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_req_chars(unsigned int n)
{
	unsigned int	r;

	r = 1;
	while (n > 9)
	{
		n = n / 10;
		r++;
	}
	return (r);
}

static void	create_string(char *str, unsigned int n, int i)
{
	if (n)
	{
		while (n != 0)
		{
			if (n > 0)
				str[i - 1] = n % 10 + '0';
			else
				str[i - 1] = n % 10 * (-1) + '0';
			n /= 10;
			i--;
		}
	}
	else
		str[0] = '0';
}

char	*ft_uitoa(unsigned int n)
{
	char				*str;
	int					digit_count;
	int					i;
	unsigned int		is_neg;

	is_neg = 0;
	if (n < 0)
	{
			n *= -1;
			is_neg = 1;
	}
	digit_count = calc_req_chars(n);
	i = digit_count + is_neg;
	str = ft_calloc((digit_count + is_neg + 1), sizeof(char));
	if (!str)
		return (0);
	create_string(str, n, i);
	if (is_neg)
		str[0] = '-';
	str[digit_count + is_neg] = '\0';
	return (str);
}
