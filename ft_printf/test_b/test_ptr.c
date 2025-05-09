/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:07:06 by nraatika          #+#    #+#             */
/*   Updated: 2025/05/08 12:39:26 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tests.h"

static char	*add_flag(const char *s, char c);

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
