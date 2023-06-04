/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:33:55 by tpawson           #+#    #+#             */
/*   Updated: 2023/05/23 05:17:56 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include	<stdlib.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<string.h>
# include	<sys/wait.h>
# include	<sys/types.h>

int		ft_strlen(const char *s);
int		para_error(void);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnstr(const char *hs, const char *n, size_t len);
char	*ft_path(char *cmd, char **env);
char	*ft_pathpos(char *cmd, char **env);
void	ft_cmd(char *argv, char **env);
void	ft_child(char **argv, char **env, int *fd);
void	ft_par(char **argv, char **env, int *fd);
int		main(int argc, char **argv, char **env);

#endif
