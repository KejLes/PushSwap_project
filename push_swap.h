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
int	str_len(char *str);
int	ft_atoi(char *str, int *begin);
t_list	*parse_to_list(char *str);
void	print_list(t_list *node);

# endif