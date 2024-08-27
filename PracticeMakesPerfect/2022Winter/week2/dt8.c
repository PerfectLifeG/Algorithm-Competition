#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    scanf("%d",&a);
    if (a<0)
    {
        printf("fu ");
        a=-a;
    }
    b=a;
    int i;
    for (i = 0; b>0; b/=10,i++);
    
    for (; i>1; i--)
    {
         switch (a / (int)pow(10,i-1))
        {
        case 0:printf("ling "); break;
        case 1:printf("yi "); break;
        case 2:printf("er "); break;
        case 3:printf("san "); break; 
        case 4:printf("si "); break;
        case 5:printf("wu "); break;
        case 6:printf("liu "); break;
        case 7:printf("qi "); break;
        case 8:printf("ba "); break;
        case 9:printf("jiu "); break;
        }   
        a= a % (int)pow(10,i-1);
    }
           

    switch (a)
        {
        case 0:printf("ling"); break;
        case 1:printf("yi"); break;
        case 2:printf("er"); break;
        case 3:printf("san"); break; 
        case 4:printf("si"); break;
        case 5:printf("wu"); break;
        case 6:printf("liu"); break;
        case 7:printf("qi"); break;
        case 8:printf("ba"); break;
        case 9:printf("jiu"); break;
        }   
    return 0;
}