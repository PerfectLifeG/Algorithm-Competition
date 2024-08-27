#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;cin>>n>>m>>q;
    int s=0;int flag1=0,flag2=0;
    for (int i = 0; i < q; i++)
    {
        int a,b;cin>>a>>b;
        
        if(a==0){if(b>m||b<=0)continue;s+=m;flag1++;}
        if(a==1){if(b>n||b<=0)continue;s+=n;flag2++;}
    }
    int ans=n*m-s+flag1*flag2;
    if(ans<0)ans=0;
    cout<<ans;
    return 0;
}