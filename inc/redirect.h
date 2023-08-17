/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:30:25 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/17 18:09:42 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "parser.h"

# define READ 0
# define WRITE 1

int 	redirect_input(t_redirect *redirect_arr, int redirect_count);
int 	redirect_output(t_redirect *redirect_arr, int redirect_count);
void	redirect_child(t_cmd_table *cmd_table, int fd[2], int rd, int cmd_index);
void	redirect_single_child(t_cmd_table *cmd_table);

#endif