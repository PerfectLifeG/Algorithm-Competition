#include<stdio.h>
#include<string.h>
int main(){
    int n,t,k;
    scanf("%d %d %d",&n,&t,&k);
    char w[n+1];
        for (int j = 0; j < k; j++)
        {
            int p=0;
            scanf("%s",w);
            if (w[0]=='f')
            {
                p-=2;
            }
            if (w[n-1]=='a')
            {
                p-=1;
            }
            if (strstr(w,"aaaaaa"))
            {
                p+=3;
            }if (strstr(w,"bbbbbb"))
            {
                p+=3;
            }if (strstr(w,"cccccc"))
            {
                p+=3;
            }if (strstr(w,"dddddd"))
            {
                p+=3;
            }if (strstr(w,"eeeeee"))
            {
                p+=3;
            }if (strstr(w,"ffffff"))
            {
                p+=3;
            }if (strstr(w,"gggggg"))
            {
                p+=3;
            }if (strstr(w,"hhhhhh"))
            {
                p+=3;
            }
            char *x=strstr(w,"a");
            x++;
            if (strstr(w,"a")&&(*x=='e'||*x=='h'))
            {
                p-=4;
            }
            if (strstr(w,"abcd")||strstr(w,"bcde")||strstr(w,"cdef")||strstr(w,"defg")||strstr(w,"efgh"))
            {
                p+=5;
            }
            if (p>t)
            {
                 printf("%d!!!\n",p);
            }
            else
            printf("%d\n",p);
        }
        
    
    
    return 0;
}