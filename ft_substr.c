/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:27:34 by afaure            #+#    #+#             */
/*   Updated: 2020/11/28 23:30:03 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	total_len;
	char	*ret;

	i = 0;
	if (start >= ft_strlen(s))
	{
		if (!(ret = malloc(1 * sizeof(char))))
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	while (s[i + start] && i < len)
		i++;
	if (!(ret = malloc((i + 1) * sizeof(char))))
		return (NULL);
	total_len = i;
	i = 0;
	while (i < total_len)
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
