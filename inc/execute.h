/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:07:18 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/06 19:10:14 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>


void	execute_with_child(int (*fd)[2], int cmd_index);
void	execute_multiple_cmd();
void	execute_single_cmd();
void	execute_commands(void);
void	execute(void);

#endif