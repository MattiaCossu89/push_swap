
#include "libft/libft.h"
#include <stdio.h>
int main()
{
	int j;
	int	i[100];

	ft_bzero(&i, 100 * sizeof(int));
	j = -1;
	while (++j < 10)
		i[j] = j;
	ft_memmove(&i[5], &i[4], (10 - 4) * sizeof(int));
	j = -1;
	while (++j < 12)
		printf("%d\n", i[j]);
}
