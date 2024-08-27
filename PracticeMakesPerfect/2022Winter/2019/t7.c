#include<stdio.h>
struct child
{
    int sex;
    int hight;
    int kg;
};

int main()
{
    int n;
    scanf("%d",&n);
    struct child c[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",&c[i].sex,&c[i].hight,&c[i].kg);
    }
    for (int i = 0; i < n; i++)
    {
        if (c[i].sex==0)
        {
            if (c[i].hight<129)
            {
                printf("duo chi yu! ");
            }else if(c[i].hight==129){
                printf("wan mei! ");
            }else if(c[i].hight>129)
                printf("ni li hai! ");
            
            if (c[i].kg<25)
            {
                printf("duo chi rou!\n");
            }else if(c[i].kg==25){
                printf("wan mei!\n");
            }else if(c[i].kg>25)
                printf("shao chi rou!\n");
        }
        
        if (c[i].sex==1)
        {
            if (c[i].hight<130)
            {
                printf("duo chi yu! ");
            }else if(c[i].hight==130){
                printf("wan mei! ");
            }else if(c[i].hight>130)
                printf("ni li hai! ");
            
            if (c[i].kg<27)
            {
                printf("duo chi rou!\n");
            }else if(c[i].kg==27){
                printf("wan mei!\n");
            }else if(c[i].kg>27)
                printf("shao chi rou!\n");
        }

        
    }
    
    return 0;
}