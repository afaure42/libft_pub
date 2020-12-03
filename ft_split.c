/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaure <afaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:16:07 by afaure            #+#    #+#             */
/*   Updated: 2020/12/02 11:27:34 by afaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	splits_count(char const *str, char c, size_t size)
{
	size_t i;
	size_t splits;

	splits = 0;
	i = 0;
	while (str[i] == c)
		i++;
	if (str[i])
	{
		while (i < size + 1)
		{
			if (str[i] == c || !str[i])
			{
				while (str[i] && str[i] == c)
					i++;
				splits++;
			}
			i++;
		}
	}
	return (splits);
}

static int		fill(char **dst, char const *str, char c, size_t size)
{
	size_t i;
	size_t beginning;

	i = 0;
	while (str[i] == c)
		i++;
	beginning = i;
	if (str[i])
	{
		while (i < size + 1)
		{
			if (!str[i] || str[i] == c)
			{
				if (!(*dst = malloc((i - beginning + 1) * sizeof(char))))
					return (0);
				ft_strlcpy(*dst++, str + beginning, i - beginning + 1);
				while (str[i] && str[i] == c)
					i++;
				beginning = i;
			}
			i++;
		}
	}
	*dst = NULL;
	return (1);
}

static void		ft_free(char ***tab)
{
	char **temp;

	while (tab)
	{
		temp = *tab;
		free(*tab);
		*tab = temp + 1;
	}
	*tab = NULL;
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	splits;
	size_t	s_size;

	s_size = ft_strlen(s);
	splits = splits_count(s, c, s_size);
	if (!s_size)
	{
		if (!(ret = malloc(1 * sizeof(char*))))
			return (NULL);
		*ret = NULL;
		return (ret);
	}
	if (!(ret = malloc((splits + 1) * sizeof(char *))))
		return (NULL);
	if (!fill(ret, s, c, s_size))
		ft_free(&ret);
	return (ret);
}
