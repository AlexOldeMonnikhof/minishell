/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:54:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/17 15:31:59 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	init_cmd_table(t_cmd_table *cmd_table, t_token **head)
{
	cmd_table->cmd_count = count_cmd(head); 
	cmd_table->cmd_arr = malloc(count_cmd(head) * sizeof(t_command));
	fill_cmd_arr(cmd_table, head);
}

void	fill_cmd_arr(t_cmd_table *cmd_table, t_token **head)
{
	int	arg_n;
	int	i;

	i = 0;
	arg_n = 0;
	while (i != cmd_table->cmd_count)
	{
		arg_n = num_of_arguments(head, i);
		cmd_table->cmd_arr[i].num_of_arguments = arg_n;
		cmd_table->cmd_arr[i].single_cmd = single_command(head, arg_n, i);
		cmd_table->cmd_arr[i].input_file = NULL;
		cmd_table->cmd_arr[i].output_file = NULL;
		i++;
	}
}

char	**single_command(t_token **head, int num_of_arguments, int i)
{
	t_token	*iterate;
	char	**cmd;
	int		j;

	iterate = get_cmd_location(head, i);
	j = 0;
	cmd = malloc((num_of_arguments + 1) * sizeof(char *));
	while (iterate != NULL && iterate->type != PIPE)
	{
		if (iterate->type == WORD)
		{
			cmd[j] = ft_strdup(iterate->text);
			j++;
		}
		iterate = iterate->next;
	}
	cmd[j] = NULL;
	return (cmd);
}
