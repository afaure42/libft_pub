/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:54:02 by afaure            #+#    #+#             */
/*   Updated: 2020/11/22 20:23:51 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t nsize)
{
	void	*ret;

	if (!(ret = malloc(nmemb * nsize)))
		return (NULL);
	ft_memset(ret, 0, nmemb * nsize);
	return (ret);
}
