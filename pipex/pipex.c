/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:37:35 by marvin            #+#    #+#             */
/*   Updated: 2023/11/11 10:37:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

void	free_info(char **info)
{
	int	i;

	i = 0;
	while (info[i])
		free(info[i++]);
	free(info);
}

char	*find_env(char **environment)
{
	int		i;
	int		j;
	char	*get_to_path;

	i = 0;
	while (environment[i])
	{
		j = 0;
		while (environment[i][j] && environment[i][j] != '=')
			j++;
		get_to_path = ft_substr(environment[i], 0, j);
		if (ft_strcmp(get_to_path, "PATH") == 0)
		{
			j++;
			free (get_to_path);
			return (environment[i] + j);
		}
		free(get_to_path);
		i++;
	}
	return (NULL);
}

char	*find_command_path(char *command, char **envp)
{
	int		i;
	char	*full_route;
	char	**command_name;
	char	**split_info;

	i = 0;
	command_name = ft_split(command, ' ');
	split_info = ft_split(find_env(envp), ':');
	while (split_info[i])
	{
		full_route = ft_strjoin(ft_strjoin(split_info[i], "/"), command_name[0]);
		if (access(full_route, X_OK) == 0)
			return (full_route);
		free(full_route);
		i++;
	}
	free(split_info);
    return (command);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t pid_num;
	int	files_pointer[2];

	if (argc != 5)
	{
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(-1);
	}
	if (pipe(files_pointer) == -1)
		exit(-1);
	pid_num = fork();
	if (pid_num == -1)
		exit(-1);
	if (pid_num == 0)
		child_proccess(envp, argv, files_pointer);
	parent_proccess(envp, argv, files_pointer);
	return (0);
}
