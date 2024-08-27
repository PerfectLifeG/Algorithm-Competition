#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct _dataStc
{
	int buf[100];
	int size;
}dataStc;
 
dataStc* func1(dataStc* p)
{
	p = (dataStc*)malloc(sizeof(dataStc));
	p->size = 10;
	return p;
}
 
dataStc* func2(void)
{
	dataStc* p;
	p = (dataStc*)malloc(sizeof(dataStc));
	p->size = 10;
	return p;
}
 
void func3(dataStc** p)
{
	*p = (dataStc*)malloc(sizeof(dataStc));
	(*p)->size = 10;
	return;
}
 
int main(int argc, const char * argv[]) {
	dataStc ppp;
	dataStc *p1 = &ppp;
	dataStc *p2 = NULL;
	dataStc *p3 = NULL;
 
	p1 = func1(p1);
	p2 = func2();
	func3(&p3);
 
	if (p1 == &ppp)
	{
		printf("p1=NULL\n");
	}
	else
	{
		printf("p1->size:%d\n", p1->size);
	}
	if (p2 == NULL)
	{
		printf("p2=NULL\n");
	}
	else
	{
		printf("p2->size:%d\n", p2->size);
	}
	if (p3 == NULL)
	{
		printf("p3=NULL\n");
	}
	else
	{
		printf("p3->size:%d\n", p3->size);
	}
	return 0;
}
 