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
using namespace std;
struct node
{
    int y;
};
int cmp(int nd1,int  nd2){
    return nd1>nd2;
}
int main()
{
    int  n;
    cin>>n;
    int y[1000000];
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i = 0;int s=0;
    for (; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        y[i]=b;
    }
    sort(y,y+n,cmp);
    int a=y[n/2];
    for (int i = 0; i < n; i++)
    {
        s+=abs(y[i]-a);
    }
    cout<<s;
    return 0;
}