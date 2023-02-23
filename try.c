#include <stdio.h>
#include <string.h>
// #include "../libft/libft.h"
#include "libft.h"
typedef struct s_me
{
	void	*a;
	void	*b;
	int		c;
	int		d;
}	t_me;
void *checker(void)
{
	t_me *var;

	return(var);
}

int	main(void)
{
	// printf("%ld\n", 1L<<25);
	// printf("sizeof:%ld\n", sizeof(long int));
	void *o;

	o = checker();
	printf("size:%ld\n", sizeof(o));

}