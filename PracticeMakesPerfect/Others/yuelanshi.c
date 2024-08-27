#include<stdio.h>
#include<stdlib.h>
struct Book
{
    char action;
    int hour;
    int min;
};

int main()
{
    int n,name,s=0,p=0;
    scanf("%d",&n);
    struct Book book[1001];
    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            scanf("%d",&name);
            getchar();
            if (book[name].action=='S')
            {
                s=s-book[name].hour*60-book[name].min;
                scanf("%c %d:%d",&book[name].action,&book[name].hour,&book[name].min);
                s=s+book[name].hour*60+book[name].min;
                book[name].action='0';
                p++;
            }else{
            scanf("%c %d:%d",&book[name].action,&book[name].hour,&book[name].min); 
            }
            if (name==0)
            {
                if (s==0)
                {
                    printf("0 0\n");
                }
                else printf("%d %d\n",p,(int)(1.0*s/p+0.5));
                s=0,p=0;
                book[0].action='0';
                for (int i = 0; i < 1001; i++)
                {
                    book[i].action='0';
                }
                
                break;
            }
        }
    }
    
    return 0;
}