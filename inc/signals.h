/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:05:39 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/29 18:09:17 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <stdbool.h>

bool	sig_check(void);
void	sign_interrupt(int signum);
void	sign_init(void);
void	sign_child(void);
void	sign_delim(void);
void	ctrl_d();

#endif