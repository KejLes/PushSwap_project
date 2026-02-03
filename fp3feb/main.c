/* Voy a hacer las estructuras y a cambiarlas según las órdenes */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list	*stack_A;
	// t_list	*stack_B;

	printf("argc: %d\n", argc);
	if (argc == 1)
		return(write(1, "Error\n", 6));
	else if (argc == 2)
	{
		if ((stack_A = parse_1arg_to_list(argv[1])) == NULL)
			return(write(1, "Error\n", 7));
		print_list(stack_A);							// BORRAR
	}
	else if (argc > 2)
	{
		if ((stack_A = parse_args_to_list(argv)) == NULL)
			return(write(1, "Error\n", 7));
		print_list(stack_A);							// BORRAR
	}
}

t_list	*parse_args_to_list(char **argv)
{
	t_list	*first_node;
	t_list	*aux_node;		// Auxiliar node
	int	i;
	// int j;

	i = 1;
	// j = 0;
	first_node = NULL;
	aux_node = NULL;
	while(argv[i])
	{
		// while(argv[i][j])
		// {
		// 	if(go_to_next_num(argv[i], &j))
		// 	{
		// 		if((first_node = create_node_list(first_node, &j, argv[i])) == NULL)
		// 			return (NULL);
		// 	}
		// 	else
		// 		return (NULL);
		// }
		if ((aux_node = parse_1arg_to_list(argv[i])) == NULL)
			return (NULL);
		add_node(first_node, aux_node);
		// j = 0;
		i++;
	}
	return (first_node);
}

void	add_last_node(t_list *begin_node, t_list *node_to_add)
{
	t_list	*current_node;

	current_node = begin_node;
	while(current_node != NULL)
		current_node = current_node->next;
	current_node = node_to_add;
}

void	print_list(t_list *node)
{
	printf("Lista creada:\n");
	while (node != NULL)
	{
		printf("%d\n", node->number);
		node = node->next;
	}
}

//	Cuenta los espacios entre números y chequea que solo haya números
t_list	*parse_1arg_to_list(char *str)
{
	t_list *first_node;
	int	i;
	int	number;

	i = 0;
	first_node = NULL;
	while(str[i])
	{
		if(go_to_next_num(str, &i))
		{
			
			if((first_node = create_node(first_node)) == NULL)		//Cambiar la función para que el ft_atoi esté aquí
				return (NULL);
			
		}
		else
			return (NULL);
	}
	return (first_node);
}
//	Va hasta el siguiente número
int	go_to_next_num(char *str, int *i)
{
	if(str[*i] < '0' && str[*i] > '9')
		return (0);
	else if(str[*i] == ' ' || str[*i] == '\t')	// Comprueba espacios y tabulaciones y avanza hasta el siguiente número
	{
		while(str[*i] == ' ' || str[*i] == '\t')
			(*i)++;
	}
	return(1);
}

void	*ft_atoi_parse(char *str, int *begin, t_list *node)
{
	double num;

	num = 0;
	while(str[*begin] >= '0' && str[*begin] <= '9')
	{
		num = num * 10 + str[*begin] - '0';
		(*begin)++;
	}
	if (num > INT_MAX)
		return (NULL);	
}

int	str_len(char *str)
{
	int	len;
	
	len = 0;
	while (str[len])
		len++;
	return (len);
}

t_list	*create_node(t_list *node)
{
	t_list *new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	return (new_node);
}

