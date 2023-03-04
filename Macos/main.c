#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_def
{
	int x;
	void *content;
	struct s_def *next;
}	t_def;

void	*ft_set(char *str)
{
	t_def *def;
	// t_def test;
	// test.x = 5;
	// printf("x: %d\n", test.x);

	def = malloc(sizeof(t_def));
	def->x = 5;
	printf("x: %d\n", def->x);
	printf("sizeof def :%lu\n", sizeof(*def));
	printf("address def :%p\n", &def);
	def->content = strdup(str);
	printf("address x :%p\n", &def->x);
	printf("address content :%p\n", def->content);
	def->next = NULL;
	return (def);
}

int	main(void)
{
	void *ptr;
	// t_def *ptr;

	ptr = ft_set("Hello\n");
	// printf("sizeof ptr :%lu\n", sizeof(ptr->content));
	printf("address ptr :%p\n", &ptr);
	printf("ptr :%p\n", ptr);
	ptr++;
	printf("ptr :%p\n", ptr);
	// printf("ptr->x: %d\n", ((t_def *)(ptr))->x);
	// printf("address x :%p\n", ptr);
	// printf("address content :%p\n", ((t_def *)ptr)->content);

	// printf("str :%p\n", ptr);
	// char *str;
	// printf("str :%p\n", str);
	// printf("str :%p\n", &str);
	// printf("---------------");
	// str = malloc(5);
	// printf("str :%p\n", str);
	// printf("str :%p\n", &str);
	// printf("str :%p\n", &str[0]);
	// printf("str :%p\n", &(str[0]));
	// int a = 10;
	// char b = 'x';

	// void *p = &a;  // void pointer holds address of int 'a'
	// p = &b; // void pointer holds address of char 'b'
	// printf("&a:%p\n", &a);
	// printf("&p:%p\n", p);
	// printf("p:%d\n", *(char *)p);
}

