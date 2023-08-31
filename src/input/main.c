/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:10:05 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/31 00:09:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/token.h"
#include "../../inc/parser.h"
#include "../../inc/execute.h"
#include "../../inc/signals.h"

void	leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **envp)
{
	char		*input_string;
	t_token		*token_head;
	t_cmd_table	*cmd_table;

	argc = 0;
	argv = NULL;
	token_head = NULL;
	cmd_table = malloc(sizeof(t_cmd_table));
	cmd_table->env = env_to_linkedlist(envp);
	cmd_table->latest_exit_code = 0;
	while (1)
	{
		sign_init();
		input_string = get_line();
		if (!input_string)
			continue ;
		if (!tokenize_string(input_string, &token_head, cmd_table))
		{
			init_cmd_table(cmd_table, &token_head);
			execute(cmd_table);
			free_func_cmd_table(cmd_table, &token_head);
		}
		free_func_token(&token_head);
	}
	return (0);
}
