/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:22:38 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/03 18:06:55 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	leaks(void)
{
	system("leaks -s test");
}

int	main(void)
{
	t_token *head;
	
	head = NULL;
	// atexit (leaks);
	assert(ft_iswhitespace(' ') == true);
	assert(ft_iswhitespace('a') == false);
	test_num_of_arguments(&head);
	// print_tokenize_string("ls | cat -a | wc -l -w > outfile", &head);
}
