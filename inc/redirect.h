/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:30:25 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/12 17:27:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "parser.h"

# define READ 0
# define WRITE 1

int		redirect_input(t_redirect *red, int redirect_count);
int 	redirect_output(t_redirect *red, int red_count);
int 	redirect_child(t_cmd_table *cmd_table, int cmd_i);
void 	redirect_single_child(t_cmd_table *cmd_table);

#endif