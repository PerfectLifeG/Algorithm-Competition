#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
struct peo
{
    int a;
    string name;
    int password;
};
int book[100];
int main()
{
    int n;
    cin>>n;
    struct peo p[n+1];
    for (int i = 1; i <= n; i++)
    {
        int a;string b;int c;
        char point[10];
        scanf("%d,%[^,],%d",&a,point,&c);
        int j=0;
        scanf("%d",&c);
        p[i].a=a;
        p[i].name=b;
        p[i].password=c;
    }
    int m;
    cin>>m;
    int step=m;
    book[m]=1;int flag=m;
    printf("%d,%s,%d\n",p[m].a,p[m].name,p[m].password);
    for (int i = n-1; i >0; i--)
    {
        int pass=p[step].password;
        step=0;
        while (step!=pass)
        {
            if(book[i]==0)step++;
            flag++;
        }
        flag%=n;
        book[flag]=1;
        printf("%d,%s,%d\n",p[flag].a,p[flag].name,p[flag].password);
    }
    
    
    return 0;
}