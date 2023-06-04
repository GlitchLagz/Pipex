/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:28:23 by tpawson           #+#    #+#             */
/*   Updated: 2023/05/26 11:02:03 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char	*hs, const char	*n, size_t	len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (n[i] == '\0')
		return ((char *)hs);
	while (hs[i] != '\0')
	{
		k = 0;
		while (hs[i + k] == n[k] && (i + k) < len)
		{
			if (hs[i + k] == '\0' && n[k] == '\0')
				return ((char *)&hs[i]);
			k++;
		}
		if (n[k] == '\0')
			return ((char *)hs + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int			k;
	int			i;
	char		*res;

	i = -1;
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	k = -1;
	while (s2[++k])
		res[i++] = s2[k];
	res[i] = '\0';
	return (res);
}
