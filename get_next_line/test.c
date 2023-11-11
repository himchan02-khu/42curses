#include <stdio.h>

void	test()
{
	printf("nothing return\n");
	return ;
}

char	*ret()
{
	return ((char *)test());
}
int main()
{
	test();
	printf("%s",ret());
}
