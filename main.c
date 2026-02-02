/* Voy a hacer las estructuras y a cambiarlas según las órdenes */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list	*first_node;

	printf("argc: %d\n", argc);
	if (argc == 1)
		return(write(1, "Error\n", 6));
	else if (argc == 2)
	{
		if ((first_node = parse_to_list(argv[1])) == NULL)
			return(write(1, "Error2\n", 7));
		print_list(first_node);
	}
	// else	//parsear más de un argumento;
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
t_list	*parse_to_list(char *str)
{
	t_list *first_node;
	int	i;

	i = 0;
	first_node = NULL;
	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')	// Si el carácter no es número, return -1
		{
			if((first_node = create_node_list(first_node, &i, str)) == NULL)
				return (NULL);
		}
		else if(str[i] == ' ' || str[i] == '\t')	// Comprueba espacios y tabulaciones y avanza hasta el siguiente número
		{
			while(str[i] == ' ' || str[i] == '\t')
				i++;
		}
	}
	return (first_node);
}

int	ft_atoi(char *str, int *begin)
{
	double num;

	num = 0;
	while(str[*begin] >= '0' && str[*begin] <= '9')
	{
		num = num * 10 + str[*begin] - '0';
		(*begin)++;
	}
	if (num > INT_MAX)
		return(-1);
	return ((int)num);
}

int	str_len(char *str)
{
	int	len;
	
	len = 0;
	while (str[len])
		len++;
	return (len);
}

t_list	*create_node_list(t_list *node, int *i, char *str)
{
	t_list *new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->number = ft_atoi(str, i);
	new_node->next = NULL;
	if(node == NULL)
		return (new_node);
	else
	{
		t_list *current;

		current = node;
		while(current->next != NULL)
			current = current->next;
		current->next = new_node;
		return (node);
	}
}
