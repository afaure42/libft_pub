/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:43:57 by afaure            #+#    #+#             */
/*   Updated: 2020/11/28 16:03:34 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rev(char *str)
{
	size_t	i;
	size_t	len;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	long	temp;
	char	*ret;
	int		i;

	i = 0;
	temp = n;
	temp = temp < 0 ? -temp : temp;
	if (!(ret = malloc(13 * sizeof(char))))
		return (NULL);
	while (temp > 9)
	{
		ret[i++] = (temp % 10) + '0';
		temp = temp / 10;
	}
	ret[i++] = temp + '0';
	if (n < 0)
		ret[i++] = '-';
	ret[i] = '\0';
	return (ft_rev(ret));
}
