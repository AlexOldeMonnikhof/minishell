/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:33:22 by alex              #+#    #+#             */
/*   Updated: 2023/08/30 23:41:14 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/signals.h"

#include <unistd.h>
#include <stdlib.h>

void	sign_interrupt(int signum)
{
	write(STDERR_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sign_interrupt_delimiter(int signum)
{
	close(STDOUT_FILENO);
	write(STDERR_FILENO, "\n", 1);
	exit(0);
}

void	ctrl_d(void)
{
	write(STDERR_FILENO, "exit\n", 5);
	exit(0);
}
