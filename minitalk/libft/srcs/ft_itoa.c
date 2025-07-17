/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:53:39 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/19 14:41:12 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

static int	pow(int p);
static char	*make_str(int n, int *max_pow);
static void	ft_nbr_str(int n, char *buf, int max_pow);

char	*ft_itoa(int n)
{
	char	*ret;
	int		max_pow;

	ret = make_str(n, &max_pow);
	if (ret == NULL)
		return (NULL);
	ft_nbr_str(n, ret, max_pow);
	return (ret);
}

static void	ft_nbr_str(int n, char *buf, int max_pow)
{
	size_t	i;

	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (max_pow > 0)
	{
		if (n < 0)
		{
			if (i == 0)
				buf[i++] = '-';
			buf[i] = -((n / pow(max_pow - 1)) % 10) + '0';
		}
		else
		{
			buf[i] = (n / pow(max_pow - 1)) % 10 + '0';
		}
		i++;
		max_pow--;
	}
	buf[i] = '\0';
	return ;
}

static int	pow(int p)
{
	int	ret;

	ret = 1;
	while (p > 0)
	{
		ret *= 10;
		p--;
	}
	return (ret);
}

static char	*make_str(int n, int *max_pow)
{
	char	*ret;
	int		temp;

	*max_pow = 0;
	temp = n;
	while (temp != 0)
	{
		(*max_pow)++;
		temp /= 10;
	}
	if (n <= 0)
		ret = malloc(*max_pow + 2);
	else
		ret = malloc(*max_pow + 1);
	return (ret);
}
