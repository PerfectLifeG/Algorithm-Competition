#include<stdio.h>
int my(char*p , char a);
int main(){
    static int n,s;
    char a[1000]={},*p;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%c",&a[i]);
    }
    p=&a[0];
    while(*p!='N')p++;
    my(p,'E',s);
    my(p,'U',s);
    my(p,'Q',s);
    printf("%d",s);
    return 0;
}
int my(char*p , char a,int s){
    int i;
for (i = 0; *p!=a; i++)
    {
        p++;
    }
    s+=i;
    return s;
}