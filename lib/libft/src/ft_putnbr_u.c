/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:29:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/18 00:55:56 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u(int n)
{
	int	count;

	count = 0;
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
		count++;
	}
	else
	{
		count += ft_putnbr_u(n / 10);
		count += ft_putnbr_u(n % 10);
	}
	return (count);
}
