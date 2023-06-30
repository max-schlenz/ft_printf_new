/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:33:31 by mschlenz          #+#    #+#             */
/*   Updated: 2023/06/28 10:36:14 by mschlenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

# define PRNT printf("here\n");

typedef struct s_data
{
	unsigned int	count_chars;
	va_list			args;
	bool			left_allign;
	bool			right_allign;
	bool			zero_pad;
	bool			precision;
	bool			hash;
	int				width_prec;
	int				width;
}	t_data;

void	printStruct(t_data *data);

int		ft_printf(const char *fmt, ...);
void	mod_char(t_data *data);
void	mod_string(t_data *data);
void	mod_int(t_data *data);
void	mod_uint(t_data *data);
void	mod_ptr(t_data *data);
void	mod_hex(t_data *data, bool uppercase);

char	*ft_uitoa(unsigned int n);
void	putchar_count(char c, t_data *data);
void	putstr_count(char *str, t_data *data);

void	padding(const char* fmt, int *i, t_data *data);
void	padding_prec(const char* fmt, int *i, t_data *data);
long	ft_atol(const char *str);

// int		print_hex(va_list args, int lowercase);
// int		print_char(va_list args);
// int		print_str(va_list args);
// int		print_int(va_list args);
// int		print_uint(va_list args);
// int		print_ptr(va_list args);

// int		print_zpad(va_list args, int len_pad, char fmt);
// int		print_prec(va_list args, int len_pad, char fmt);
// int		print_sharp(va_list args, char fmt);
// int		print_space(va_list args, int len_pad, char fmt);
// int		print_plus(va_list args, char fmt);
// int		print_minus(va_list args, int len_pad, char fmt);

// int		uint_to_hex_len(unsigned int hex);

// int		print_char(va_list args);
// int		print_string(va_list args);
// int		print_pointer(va_list args);
// int		print_int(va_list args);
// int		print_uint(va_list args);
// int		print_hex(va_list args, size_t lcase);
// size_t	ft_strlen(const char *c);
// int		ft_tolower(int c);
// void	ft_putchar_fd(char c, int fd);
// void	ft_putstr_fd(char *s, int fd);
// char	*ft_itoa(int n);

#endif