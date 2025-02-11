/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_align.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:49 by haaghaja          #+#    #+#             */
/*   Updated: 2025/02/11 16:08:30 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_surplus(int size, char pad, int *count)
{
	while (size > 0)
	{
		ft_cputchar(pad, count);
		size--;
	}
}

void	print_n_zeros(int n, int *count)
{
	while (n-- > 0)
		ft_cputchar('0', count);
}

void	print_negative_num(char *str, int *count, int width)
{
	ft_cputchar('-', count);
	print_surplus(width - ft_strlen(str), '0', count);
	str++;
	ft_cputstr(str, count);
}

void	print_flag(t_arg *arg, char *str, int *count)
{
	if (arg->flag[1] && *str != '-')
		ft_cputchar('+', count);
	else if (arg->flag[2] && *str != '-')
		ft_cputchar(' ', count);
	else if (*str == '-')
	{
		ft_cputchar('-', count);
		ft_memcpy(str, (str + 1), ft_strlen(str));
		(arg->width)--;
	}
}
