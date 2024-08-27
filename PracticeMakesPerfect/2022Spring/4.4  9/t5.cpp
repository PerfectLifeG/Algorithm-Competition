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
int cow[10];int n,m;
int cmp(int a,int b){
    return a<b;
}
bool build(int mid){
    int num=1;int t=cow[0];
    for (int i = 1; i < n; i++)
    {
        if(cow[i]-t>=mid){
            t=cow[i];
            num++;
        }
        if(num==m)return 1;
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>cow[i];
    }
    sort(cow,cow+n,cmp);
    int left=0;int right=cow[n-1]-cow[0];int mid=(left+right)/2;
    while (left<=right)
    {
        mid=(left+right)/2;
        if(build(mid)) left=mid+1;
        else right=mid-1;
        
    }
    cout<<left-1;
    return 0;
}