#include <stdlib.h>
#include "libft.h" 

char	**tabcat(char **tab, char *ptr, int new_size)
{
	char	**new;
	int	i;

	i = 0;
	new = (char**)malloc(sizeof(char) * (new_size + 2));
	if (tab)
		while (i < new_size)
		{
			new[i] = tab[i];
			i++;
		}
	new[i] = ptr;
	new[i + 1] = 0;
	return(new);
}
