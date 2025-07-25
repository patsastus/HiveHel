/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:35:03 by nraatika          #+#    #+#             */
/*   Updated: 2025/07/25 14:47:16 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>
#include <stdio.h>

void	test_chars(void)
{
	const char	*tests[5] = {"|%c|\n", "|%2c|\n", "|%-2c|\n", "|%4c|\n", "|%-4c|\n"};
	int			i;
	int			cl;
	int			ft;
	
	ft_printf("\nTesting char with different widths and '-' flag\n");
	i = 0;
	while (i < 5)
	{
		cl = printf(tests[i], 'f');
		ft = ft_printf(tests[i], 'f');
		printf("Returns; %d | %d\n", cl, ft);
		i++;
	}
}

void	test_strs(void)
{
	const char	*tests[6] = {"|%s|\n", "|%2s|\n", "|%-2s|\n",  "|%7.2s|\n",  "|%-8.3s|\n", "|%6.8s|\n"};
	const char	*input[3] = {"", "testing", NULL};
	int			i;
	int			j;
	int			cl;
	int			ft;
	
	j = 0;
	while (j < 3)
	{
		i = 0;
		printf("\ntesting input string: ");
		printf("'%s'\n", input[j]);
		while (i < 6)
		{
			printf("format string:\n");
			ft_putendl_fd((char *)tests[i], 1);
			cl = printf(tests[i], input[j]);
			ft = ft_printf(tests[i], input[j]);
			printf("Returns; %d | %d\n", cl, ft);
			i++;
		}
		j++;
	}
}

static char	*add_flag(const char *s, char c);

void	test_hexes(void)
{
	char			*flags = "0-#";
	long			input[7] = {0, -11, 42, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN};
	char			*test_lo[7] = {"|%x|\n", "|%5x|\n", "|%3.5x|\n", "|%8.11x|\n", "|%11.8x|\n", "|%20.10x|\n", "|%10.20x|\n"};
	char			*test_hi[7] = {"|%X|\n", "|%5X|\n", "|%3.5X|\n", "|%8.11X|\n", "|%11.8X|\n", "|%20.10X|\n", "|%10.20X|\n"};
	int				i = 0;
	int 			j;
	int				k;
	int				ft;
	int				cl;
	char			*temp;

	printf("\nTesting hexadecimal outputs, at different widths/precision and different combos of flags %s\n", flags);
	while (i < 6)
	{
		ft_printf("Input: %d\n", input[i]);
		j = 0;
		while (j < 7)
		{
			k = 0;
			while ((size_t)k < ft_strlen(flags) + 1)
			{
				if (k == 0)
					temp = ft_strdup(test_lo[j]);
				else
					temp = add_flag(test_lo[j], flags[k - 1]);
				cl = printf(temp, input[i]);
				ft = ft_printf(temp, input[i]);
				printf("Returns: %d | %d\n", cl, ft);
				free(temp);
				if (k == 0)
					temp = ft_strdup(test_hi[j]);
				else
					temp = add_flag(test_hi[j], flags[k - 1]);
				cl = printf(temp, input[i]);
				ft = ft_printf(temp, input[i]);
				printf("Returns: %d | %d\n", cl, ft);
				free(temp);
				k++;
			}
			j++;
		}
    	i++;
	}
	return ;
}

static char	*add_flag(const char *s, char c)
{
	char	*ret;
	
	ret = ft_calloc(ft_strlen(s) + 2, 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s, 3);
	ret[2] = c;
	ft_strlcat(ret, s + 2, ft_strlen(s) + 2);
	return (ret);
}

void	test_ints(void)
{
	char	*flags = "0-+ ";
	long	input[7] = {0, -1, 42, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN};
	char	*tests[7] = {"|%d|\n", "|%5i|\n", "|%3.5d|\n", "|%8.11i|\n", "|%11.8d|\n", "|%20.10i|\n", "|%10.20d|\n"};
	int		i = 0;
	int 	j;
	int		k;
	int		cl;
	int		ft;
	char	*temp;

	printf("\nTesting integer outputs, at different widths/precision and different combos of flags %s\n", flags);
	while (i < 7)
	{
		ft_printf("Input: %d\n", input[i]);
		j = 0;
		while (j < 7)
		{
			k = 0;
			printf("format string:'%s'\n", tests[j]);
			while ((size_t)k < ft_strlen(flags) + 1)
			{
				if (k == 0)
					temp = ft_strdup(tests[j]);
				else
					temp = add_flag(tests[j], flags[k - 1]);
				cl = printf(temp, input[i]);
				ft = ft_printf(temp, input[i]);
				printf("Returns: %d | %d\n", cl, ft);
				free(temp);
				k++;
			}
			j++;
		}
    	i++;
	}
	return ;
}

void	test_uints(void)
{
	char			*flags = "0-";
	unsigned long	input[6] = {0, 1, 42, INT_MAX, UINT_MAX, ULONG_MAX};
	char			*tests[7] = {"|%u|\n", "|%5u|\n", "|%3.5u|\n", "|%8.11u|\n", "|%11.8u|\n", "|%20.10u|\n", "|%10.20u|\n"};
	int				i = 0;
	int 			j;
	int				k;
	int				cl;
	int				ft;
	char			*temp;

	printf("\nTesting unsigned integer outputs, at different widths/precision and different combos of flags %s\n", flags);
	while (i < 6)
	{
		ft_printf("Input: %d\n", input[i]);
		j = 0;
		while (j < 7)
		{
			k = 0;
			printf("format string:'%s'\n", tests[j]);
			while ((size_t)k < ft_strlen(flags) + 1)
			{
				if (k == 0)
					temp = ft_strdup(tests[j]);
				else
					temp = add_flag(tests[j], flags[k - 1]);
				cl = printf(temp, input[i]);
				ft = ft_printf(temp, input[i]);
				printf("Returns: %d | %d\n", cl, ft);
				free(temp);
				k++;
			}
			j++;
		}
    	i++;
	}
	return ;
}


void	test_ptrs(void)
{
	const char	*flags = "0-";
    const char  *tests[5] = {"|%p|\n", "|%4p|\n", "|%7p|\n", "|%14.9p|\n", "|%9.14p|\n"};
	void		*input[3] = {NULL, "test", test_ptrs};
	char 		*temp;
    int         i;
	int			j;
	int			k;
    int         cl;
    int         ft;
    
	printf("\nTesting pointer output with different width/precision and flags '-' and '0'\n");
    i = 0;
    while (i < 3)
    {
		j = 0;
		printf("testing pointer %d:\n", i);
		while (j < 5)
		{
			k = 0;
			printf("format string:\n");
			ft_putendl_fd((char *)tests[j], 1);
			while ((size_t)k < ft_strlen(flags) + 1)
			{
					if (k == 0)
							temp = ft_strdup(tests[j]);
					else
							temp = add_flag(tests[j], flags[k-1]);
					cl = printf(temp, input[i]);
					ft = ft_printf(temp, input[i]);
					printf("Returns: %d | %d\n", cl, ft);
					free(temp);
					k++;
			}
			j++;
		}
		i++;
	}
}


int	main(void)
{

	test_chars();

    test_strs(); 
                 
    test_ptrs(); 
                 
    test_ints(); 
                 
    test_uints();
                 
    test_hexes();

	return (0);
}


