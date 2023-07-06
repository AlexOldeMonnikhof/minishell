/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:22:38 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/06 13:35:33 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	leaks(void)
{
	system("leaks -s test");
}

int	main(void)
{
	t_token 	*head;
	t_cmd_table	*cmd_table;
	char		*text;
	
	head = NULL;
	cmd_table = NULL;
	text = "ls -la -l -w -c | cat -a | wc -l -w > outfile";
	atexit(leaks);
	tokenize_string(text, &head);
	print_tokenize_string(text, &head);
	cmd_table = parse_tokens(&head);
	print_cmd_table(&head, cmd_table);
	free_func_cmd_table(cmd_table, &head);
	free_func_token(&head);
}
