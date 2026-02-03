#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_list
{
	int					number;
	int					index;
	struct s_list		*next;
}				t_list;

t_list	*create_node_list(t_list *node, int *i, char *str);
void	add_last_node(t_list *begin_node, t_list *node_to_add);

t_list	*parse_args_to_list(char **argv);
t_list	*parse_1arg_to_list(char *str);
int		go_to_next_num(char *str, int *i);

int		str_len(char *str);
int		ft_atoi(char *str, int *begin);

void	print_list(t_list *node);

# endif