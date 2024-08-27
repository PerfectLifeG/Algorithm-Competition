#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *p[5],*t;
    for (int i = 0; i < 5; i++)
    {
        p[i]=(char*)malloc(80*sizeof(char));
    }
    for (int i = 0; i < 5; i++)
    {
        scanf("%s",p[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        int k=i;
        for (int j = i+1; j < 5; j++)
        if(strcmp(p[k],p[j])>0)k=j;

        t=p[i];
        p[i]=p[k];
        p[k]=t;
    }
    printf("After sorted:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",p[i]);
    }
    return 0;
}