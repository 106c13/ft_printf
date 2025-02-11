/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:10:39 by haaghaja          #+#    #+#             */
/*   Updated: 2025/02/11 16:11:00 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, t_arg *arg, int *count)
{
	if (arg->flag[0])
	{
		ft_cputchar(c, count);
		print_surplus(arg->width - 1, ' ', count);
	}
	else
	{
		print_surplus(arg->width - 1, ' ', count);
		ft_cputchar(c, count);
	}
}

void	print_string(char *str, t_arg *arg, int *count)
{
	int	dup;

	if (!str)
	{
		ft_cputstr("(null)", count);
		return ;
	}
	dup = 0;
	if ((unsigned int)arg->prec < ft_strlen(str) && arg->prec >= 0)
	{
		str = ft_strdup(str);
		str[arg->prec] = '\0';
		dup = 1;
	}
	if (!arg->flag[0])
		print_surplus(arg->width - ft_strlen(str), ' ', count);
	ft_cputstr(str, count);
	if (arg->flag[0])
		print_surplus(arg->width - ft_strlen(str), ' ', count);
	if (dup)
		free(str);
}
