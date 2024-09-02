#include<bits/stdc++.h>
using namespace std;
struct node
{
    int thi;
    int nex;
    int data;
};
int main()
{
    int start,n;
    cin>>start>>n;
    node temp[100005];
    for (int i = 0; i < n; i++)
    {
        int a,b,c;cin>>a>>b>>c;
        temp[a].thi=a;
        temp[a].nex=c;
        temp[a].data=b;
    }
    node ans[n+5];
    for (int i = 1; i <= n; i++)
    {
        ans[i].data=temp[start].data;
        ans[i].nex=temp[start].nex;
        ans[i].thi=temp[start].thi;
        if(ans[i].nex==-1){n=i;break;}
        start=temp[start].nex;
    }
    printf("%05d %d ",ans[n].thi,ans[n].data);
    for (int i = 1; i <= n/2; i++)
    {
        printf("%05d",ans[i].thi);
        printf("\n%05d %d ",ans[i].thi,ans[i].data);
        if(n%2==0&&i==n/2){cout<<-1;return 0;}
        printf("%05d",ans[n-i].thi);
        printf("\n%05d %d ",ans[n-i].thi,ans[n-i].data);
    }
    cout<<-1;
    return 0;
}