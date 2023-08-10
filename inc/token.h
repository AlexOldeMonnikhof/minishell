/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:42:15 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/10 16:28:31 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_token	t_token;

typedef enum s_type {
	WORD,
	REDIRECT,
	PIPE,
	INFILE,
	OUTFILE,
	APPEND,
}	t_type;

typedef struct s_token {
	t_type	type;
	char	*text;
	t_token	*next;
}	t_token;

void	tokenize_string(char *input_string, t_token **head);
int		assign_token(char *str, t_token **head);
void	create_token(t_type type, char *text, t_token **head);
void	create_io_file_tokens(t_token **head);
int		create_redirection_token(char *str, t_token **head);

int		count_cmd(t_token **head);
bool	ft_iswhitespace(char a);
void	ft_lstadd_back(t_token **head, t_token *new);
t_token	*ft_lstnew(t_type type, char *text);
void 	free_func_token(t_token **head);

#endif