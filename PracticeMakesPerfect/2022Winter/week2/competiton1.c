    #include<stdio.h>
    int main()
    {
        int n,s=0;
        scanf("%d",&n);
        struct date{
            char x;
            char hour[2];
            char min[2];
        }d[100];
        while (s!=n)
        {
            int i=0;int t[100];
            scanf("%d %c %c%c:%c%c",&i,&d[i].x,&d[i].hour[0],&d[i].hour[1],&d[i].min[0],&d[i].min[1]);
            
            t[i]=((d[i].hour[0]-'0')*10+(d[i].hour[1]-'0'))*60+(d[i].min[0]-'0')*10+(d[i].min[1]-'0');
            if(i==0)s++;
        }

        for (int i = 0; i < n; i++)
        {
            printf("%d");
        }
        
        return 0;
    }