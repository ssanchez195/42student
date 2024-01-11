/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:35:05 by marvin            #+#    #+#             */
/*   Updated: 2023/11/20 17:35:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_LIB_H
# define PIPEX_LIB_H

# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

int		ft_strcmp(char *str1, char *str2);
char    *find_command_path(char *command, char **envp);
void    launch_command(char *command, char **environment);
void    free_info(char **info);
void    error_exit(void);
void    child_proccess(char **environment, char **argv, int *aux_fileD);
void    parent_proccess(char **environment, char **argv, int *aux_fileD);

#endif