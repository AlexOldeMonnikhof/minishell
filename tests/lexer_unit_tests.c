/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_unit_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:03:11 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/13 17:23:33 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char *type_text(t_type type)
{
	if (type == PIPE)
		return ("PIPE");
	else if (type == REDIRECT)
		return ("REDIRECT");
	else if (type == IO_FILE)
		return ("IO_FILE");
	else
		return ("WORD");
}

void print_tokenize_string(char *text, t_token **head)
{
	t_token		*iterate;
	
	iterate = *head;
	printf("input: %s\n", text);
	printf("Amount of commands: %d\n", count_cmd(head));
	while (iterate != NULL)
	{
		printf("%s, %s\n", iterate->text, type_text(iterate->type));
		iterate = iterate->next;
	}
}

void	test_count_cmd(void)
{
	t_token *head;

	head = NULL;
	tokenize_string("< infile ls -la | cat -a | wc -l -w > outfile", &head);
	assert(count_cmd(&head) == 3);
	free_func_token(&head);
}
