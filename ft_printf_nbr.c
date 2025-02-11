/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:29:38 by haaghaja          #+#    #+#             */
/*   Updated: 2025/02/11 16:33:25 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(int num, t_arg *arg, int *count)
{
	char	*str;

	str = ft_itoa(num);
	if ((arg->flag[1] || arg->flag[2]) && num >= 0)
		arg->width--;
	if (arg->prec > 0)
		arg->width -= arg->prec - ft_strlen(str);
	if (!arg->flag[0] && !arg->flag[3])
		print_surplus(arg->width - ft_strlen(str), ' ', count);
	if (arg->prec > 0)
	{
		print_flag(arg, str, count);
		print_surplus(arg->prec - ft_strlen(str), '0', count);
		arg->prec = -2;
	}
	if (arg->prec != -2)
		print_flag(arg, str, count);
	if (arg->flag[3] && !arg->flag[0])
		print_surplus(arg->width - ft_strlen(str), '0', count);
	ft_cputstr(str, count);
	if (arg->flag[0])
		print_surplus(arg->width - ft_strlen(str), ' ', count);
	free(str);
}

void	print_hex(unsigned int num, t_arg *arg, int *count, int cap)
{
	char	*str;

	str = ft_dtoh((unsigned long)num, cap);
	if (!str)
		return ;
	if (arg->flag[4])
		arg->width -= 2;
	if ((unsigned int)arg->prec > ft_strlen(str) && arg->prec > 0)
		arg->width -= arg->prec - ft_strlen(str);
	if (!arg->flag[0] && !arg->flag[3])
		print_surplus(arg->width - ft_strlen(str), ' ', count);
	if (arg->flag[4] && num != 0 && !cap)
		ft_cputstr("0x", count);
	if (arg->flag[4] && num != 0 && cap)
		ft_cputstr("0X", count);
	if (!arg->flag[0] && arg->flag[3])
		print_surplus(arg->width - ft_strlen(str), '0', count);
	print_n_zeros(arg->prec - ft_strlen(str), count);
	if (!(arg->prec == 0 && num == 0))
		ft_cputstr(str, count);
	if (arg->flag[0])
		print_surplus(arg->width - ft_strlen(str), ' ', count);
	free(str);
}

void	print_pointer(void *ptr, t_arg *arg, int *count)
{
	char	*str;

	str = ft_dtoh((unsigned long)ptr, 0);
	if (!arg->flag[0])
		print_surplus(arg->width - ft_strlen(str), ' ', count);
	ft_cputstr("0x", count);
	arg->width -= 2;
	ft_cputstr(str, count);
	if (arg->flag[0])
		print_surplus(arg->width - ft_strlen(str), ' ', count);
	free(str);
}

void	print_unsigned(unsigned int num, t_arg *arg, int *count)
{
	char	*str;

	str = ft_utoa(num);
	if (arg->prec > 0)
		arg->width -= arg->prec - ft_strlen(str);
	print_surplus(arg->prec - ft_strlen(str), '0', count);
	if (arg->flag[3] && !arg->flag[0])
	{
		print_surplus(arg->width - ft_strlen(str), '0', count);
		ft_cputstr(str, count);
	}
	else if (!arg->flag[0])
	{
		print_surplus(arg->width - ft_strlen(str), ' ', count);
		ft_cputstr(str, count);
	}
	else if (arg->flag[0])
	{
		ft_cputstr(str, count);
		print_surplus(arg->width - ft_strlen(str), ' ', count);
	}
	free(str);
}
