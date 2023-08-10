/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:36:53 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/08 15:39:50 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execve.h"
#include "../../libft/libft.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

char	*get_right_path(char **paths, char **cmd)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (paths[i])
	{
		ret = ft_strjoin_with_slash(paths[i], cmd[0]);
		if (access(ret, X_OK | F_OK) == 0)
			return (ret);
		free(ret);
		i++;
	}
	return (cmd[0]);
}

char	*get_paths(char **envp)
{
	int		i;
	char	*ret;

	i = 0;
	while (envp[i])
	{
		ret = ft_strnstr(envp[i], "PATH=", 5);
		if (ret)
			break ;
		i++;
	}
	return (ret);
}

void	ft_execve(char **cmd, char **envp)
{
	char *path = get_paths(envp);
	char **paths = ft_split(path + 5, ':');
	char *cmdpath = get_right_path(paths, cmd);
	execve(cmdpath, cmd, envp);
	free(cmdpath);
}
