/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:39:45 by dlucio            #+#    #+#             */
/*   Updated: 2020/05/21 19:39:48 by dlucio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int count;
	int array[10];

	if (n < 0)
	{
		n = n * (-1);
		ft_putchar_fd('-', fd);
	}
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar_fd('2', fd);
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	count = 0;
	while (n != 0)
	{
		array[count++] = n % 10 + '0';
		n = n / 10;
	}
	while (count != 0)
	{
		ft_putchar_fd(array[count-- - 1], fd);
	}
}
