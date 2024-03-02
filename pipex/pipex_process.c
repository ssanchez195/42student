/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:37:43 by marvin            #+#    #+#             */
/*   Updated: 2023/11/11 10:37:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

void	child_proccess(char **environment, char **argv, int *aux_fileD)
{
	int	file_descript;

	file_descript = open(argv[1], O_RDONLY);
	if (file_descript == -1)
		exit(0);
	dup2(file_descript, STDIN_FILENO);
	dup2(aux_fileD[1], STDOUT_FILENO);
	close(aux_fileD[0]);
	launch_command(argv[2], environment);
}

void	parent_proccess(char **environment, char **argv, int *aux_fileD)
{
	int	file_descript;

	file_descript = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file_descript == -1)
		exit(0);
	dup2(file_descript, STDOUT_FILENO);
	dup2(aux_fileD[0], STDIN_FILENO);
	close(aux_fileD[1]);
	launch_command(argv[3], environment);
}

void	launch_command(char *command, char **environment)
{
	char	**find_cmd_var;
	char	*path;

	find_cmd_var = ft_split(command, ' ');
	path = find_command_path(find_cmd_var[0], environment);
	if (execve(path, find_cmd_var, environment) != 0)
	{
		ft_putendl_fd("pipex: command not found", 2),
		ft_putendl_fd(find_cmd_var[0], 2);
		free_info(find_cmd_var);
		exit(0);
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}
