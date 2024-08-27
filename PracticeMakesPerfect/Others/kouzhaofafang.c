#include<stdio.h>
#include<stdlib.h>
typedef struct People* people;
typedef struct Stack* stack;
struct Stack
{
    people p;
    
};

struct People
{
    char name[11];
    char identity[19];
    int condition;
    int hour;int min;
};

int main()
{
    int d,p;
    scanf("%d %d",&d,&p);
    for (int i = 1; i <= d; i++)
    {
        int t,s;
        scanf("%d %d",&t,&s);
        struct People people[t+1];
        for (int j = 1; j <= t; j++)
        {
            scanf("%s %s %d %d:%d",&people[t].name,&people[t].identity,&people[t].condition,&people[t].hour,&people[t].min);
        }
        for (int j = 0; j < s; j++)
        {
            if (/* condition */)
            {
                /* code */
            }
            
        }
        
    }
    
    return 0;
}