#include <stdio.h>
#include <string.h>
int main(void)
{
	char str01[] = "Hello!";
	char str02[] = "hello World!";
	strcpy(str01,str02);
	puts(str01);
	return 0;

}
