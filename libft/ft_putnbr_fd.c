/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:26:21 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/28 18:40:05 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static	void	iter_putnbr(long long nbr, int fd)
{
	char	nbr_to_c;

	if (nbr == 0)
		return ;
	nbr_to_c = nbr % 10 + '0';
	iter_putnbr(nbr / 10, fd);
	write(fd, &nbr_to_c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nbr;

	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (long long)n * (-1);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else
		nbr = n;
	iter_putnbr(nbr, fd);
}
