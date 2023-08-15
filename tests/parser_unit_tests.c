/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_unit_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:52:47 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/15 17:39:55 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

// void	test_num_of_arguments(void)
// {
// 	t_token *head;

// 	head = NULL;
// 	tokenize_string("ls | cat -c | jo jo jo > outfile < infile", &head);
// 	assert(num_of_arguments(&head, 0) == 1);
// 	assert(num_of_arguments(&head, 1) == 2);
// 	assert(num_of_arguments(&head, 2) == 3);
// 	free_func_token(&head);
// 	tokenize_string("< infile > oufile ls | > outfile cat -c | < infile jo jo jo > outfile < infile", &head);
// 	assert(num_of_arguments(&head, 0) == 1);
// 	assert(num_of_arguments(&head, 1) == 2);
// 	assert(num_of_arguments(&head, 2) == 3);
// 	free_func_token(&head);
// }

void	print_cmd_table(t_token **head, t_cmd_table *cmd_table)
{
	int			i;

	i = 0;
	printf("\ncommand table:\n");
	while (i != count_cmd(head))
	{
		printf("command: %d\n", i);
		print_double_array(cmd_table->cmd_arr[i].single_cmd);
		printf("total redirections: %d\n", cmd_table->cmd_arr[i].redirect_count);
		if (cmd_table->cmd_arr[i].redirect_arr)
			print_redirect(cmd_table->cmd_arr[i].redirect_arr, cmd_table->cmd_arr[i].redirect_count);
		i++;
	}
}

void	print_redirect(t_redirect *redirect_arr, unsigned int redirect_count)
{
	int	i;

	i = 0;
	while (i < redirect_count)
	{
		printf("redirect: %d, file name: %s, type: %s\n", i, redirect_arr[i].file_name, type_text(redirect_arr[i].type));
		i++;
	}
}

void	print_double_array(char **command)
{
	int i;
	
	i = 0;
	while (command[i] != NULL)
	{
		printf("%s, ", command[i]);
		i++;
	}
	printf("%s\n", command[i]);
}

// void	test_get_cmd_location(void)
// {
// 	t_token	*head;
// 	t_token	*iterate;

// 	head = NULL;
// 	// tokenize_string("< infile > outfile cat | < infile wc -w | sws swa > outfile", &head);
// 	// iterate = get_cmd_location(&head, 1);
// 	// assert(ft_strncmp(iterate->text, "wc", 2) == 0);
// 	// iterate = get_cmd_location(&head, 0);
// 	// assert(ft_strncmp(iterate->text, "cat", 3) == 0);
// 	// iterate = get_cmd_location(&head, 2);
// 	// assert(ft_strncmp(iterate->text, "sws", 3) == 0);
// 	// free_func_token(&head);
// 	tokenize_string("< infile > outfile cat | < infile wc -w | sws swa > outfile", &head);
// 	iterate = get_cmd_location(&head, 1);
// 	assert(ft_strncmp(iterate->text, "<", 1) == 0);
// 	iterate = get_cmd_location(&head, 0);
// 	assert(ft_strncmp(iterate->text, "<", 1) == 0);
// 	iterate = get_cmd_location(&head, 2);
// 	assert(ft_strncmp(iterate->text, "sws", 3) == 0);
// 	free_func_token(&head);
// 	tokenize_string("cat Makefile | wc > out | ls | pwd > out2", &head);
// 	iterate = get_cmd_location(&head, 2);
// 	assert(ft_strncmp(iterate->text, "ls", 2) == 0);
// 	free_func_token(&head);
// }

// void	test_count_redirect(void)
// {
// 	t_token	*head;
// 	t_token	*iterate;

// 	tokenize_string("cat Makefile | wc | ls | pwd > out2", &head);
// 	iterate = get_cmd_location(&head, 0);
// 	assert(count_redirect(iterate) == 0);
// 	iterate = get_cmd_location(&head, 1);
// 	assert(count_redirect(iterate) == 0);
// 	iterate = get_cmd_location(&head, 2);
// 	assert(count_redirect(iterate) == 0);
// 	iterate = get_cmd_location(&head, 3);
// 	assert(count_redirect(iterate) == 1);
// 	free_func_token(&head);
// }
