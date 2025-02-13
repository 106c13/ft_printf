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
#include <stdio.h>

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

void	print_flag(t_arg *arg, char *str, int *count)
{
	if (arg->flag[1] && *str != '-')
	{
		ft_cputchar('+', count);
		arg->flag[1] = 0;
	}
	else if (arg->flag[2] && *str != '-')
	{
		ft_cputchar(' ', count);
		arg->flag[2] = 0;
	}
	else if (*str == '-')
	{
		ft_cputchar('-', count);
		ft_memcpy(str, (str + 1), ft_strlen(str));
		(arg->width)--;
		arg->flag[2] = 0;
		arg->flag[1] = 0;
	}
}
