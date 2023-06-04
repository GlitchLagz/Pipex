/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:48 by tpawson           #+#    #+#             */
/*   Updated: 2023/05/23 05:19:24 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

static size_t	wlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s++)
		len++;
	return (len);
}

static size_t	wcount(char const *s, char c)
{
	size_t	wc;
	size_t	i;

	wc = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		wc++;
	}
	if (i > 0 && s[i - 1] == c)
		wc--;
	return (wc);
}

static char	**str_free(char **s, size_t c)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (i < c)
		{
			if (s[i] != NULL)
				free(s[i]);
			i++;
		}
		free(s);
	}
	return (NULL);
}

static char	**ft_allocarr(char **res, const char *s, char c)
{
	size_t	j;
	size_t	i;

	j = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		res[j] = malloc(sizeof(char) * wlen(s, c) + 1);
		if (res[j] == NULL)
			return (str_free(res, j));
		i = 0;
		while (*s != c && *s)
			res[j][i++] = *s++;
		res[j][i] = '\0';
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (wcount(s, c) + 1));
	if (!res)
		return (NULL);
	ft_allocarr(res, s, c);
	return (res);
}
