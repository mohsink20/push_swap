/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:37:25 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/22 15:37:26 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp != NULL && tmp->nxt != NULL)
	{
		if (tmp->i > tmp->nxt->i)
			return (0);
		tmp = tmp->nxt;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	struct s_data	d;
	char			**argm;
	int				i;

	d.b = NULL;
	if (argc == 2)
	{
		i = 0;
		argm = ft_split(argv[1], ' ');
		while (argm[i])
			i++;
		d.a = init_stack(&d, i, argm, 0);
		ft_free((void **)argm);
	}
	else
		d.a = init_stack(&d, argc - 1, argv, 1);
	if (argc > 1)
	{
		if (is_sorted(d.a) == 0)
			do_sort(&d);
		ps_lstclear(&d.a);
		if (is_sorted(d.a) == 0)
			ps_lstclear(&d.b);
	}
	return (0);
}
