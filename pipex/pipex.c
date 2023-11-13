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

//Para el segundo archivo va en el siguiente orden
//Si no hay archivo, que lo cree. Si si lo hay, entonces lo abrimos para lectura y escritura y truncamos la info
//para borrar todo lo que haya y asi poder meter la informacion nuestra

int main(int argc, char **argv, char **envp)
{
    int first_file;
    int second_file;

    first_file = open(argv[1], O_RDONLY);
    second_file = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (first_file == -1 || second_file == -1)
        return (-1);
    pipex(first_file, second_file, argv, envp);
    return (0);
}
