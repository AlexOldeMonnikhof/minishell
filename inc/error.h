/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:45:36 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/18 16:49:40 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "parser.h"

int		export_error_check(char *arg);
int		syntax_error(char *token, t_cmd_table *cmd_table);
void	execve_error(char *cmd);

#endif