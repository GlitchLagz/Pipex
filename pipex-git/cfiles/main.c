/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:46:55 by tpawson           #+#    #+#             */
/*   Updated: 2023/05/26 14:24:31 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"
// env is the enviromental varible that is 
// retrived from main and inputed to excve
//
// env are varibles that store info about 
// the enviroment in which a program is running,
// they are universal and not specific to the c language.
int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		para_error();
	if (argc == 5)
	{
		if (pipe(fd) < 0)
		{
			perror("Pipe Malfuntion: ");
			exit(1);
		}
		pid = fork();
		if (pid < 0)
		{
			perror("Fork Malfunction: ");
			exit(1);
		}
		if (pid == 0)
			ft_child(argv, env, fd);
		ft_par(argv, env, fd);
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}
