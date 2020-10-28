/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itieu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:48:20 by itieu             #+#    #+#             */
/*   Updated: 2020/10/28 19:32:51 by itieu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if ((base[0] == '\0' || base[1]) == '\0')
				return (0);
			if (base[i] == '+' || base[i] == '-')
				return (0);
			if (base[i] < 32 || base[i] > 126)
				return (0);
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_length;
	int final_nbr[100];
	int i;

	base_length = 0;
	i = 0;
	if (ft_check_base(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		while (base[base_length])
			base_length++;
		while (nbr)
		{
			final_nbr[i] = nbr % base_length;
			nbr = nbr / base_length;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[final_nbr[i]]);
	}
}
