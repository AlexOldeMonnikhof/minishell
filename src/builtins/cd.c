/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:24 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/11 20:14:17 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/env_init.h"

#include <errno.h>
#include <unistd.h>
#include <string.h>

//not implementing error code

char	*get_home(t_env **env_head, t_cmd_table *cmd_table)
{
	size_t	i;
	char	*ret;
	t_env	*iter;

	i = 0;
	ret = NULL;
	iter = *env_head;
	while (iter)
	{
		if (ft_strncmp(iter->variable, "HOME", 5) == 0)
			break ;
		iter = iter->next;
	}
	if (!iter)
	{
		write(STDERR_FILENO, "cd: HOME not set\n", 17);
		cmd_table->latest_exit_code = 1;
	}
	else if (iter->variable)
		ret = iter->value;
	return (ret);
}

//uses envp from seperate int main -> no other envp yet

static char	*find_right_path(char *arg, t_env **env_head, t_cmd_table *cmd_tab)
{
	char	*path;

	path = NULL;
	if (arg == NULL)
		path = get_home(env_head, cmd_tab);
	else if (ft_strncmp(arg, "~", sizeof(arg)) == 0)
		path = cmd_tab->home;
	else
		path = arg;
	return (path);
}

//does not return error code but prints the error

void	cd(char *arg, t_env **env_head, t_cmd_table *cmd_table)
{
	char	*path;

	path = find_right_path(arg, env_head, cmd_table);
	if (!path)
		return ;
	if (chdir(path))
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		cmd_table->latest_exit_code = 1;
	}
	else
		cmd_table->latest_exit_code = 0;
}

// int main(int argc, char **argv, char **envp)
// {
// 	cd(NULL, envp);
// }