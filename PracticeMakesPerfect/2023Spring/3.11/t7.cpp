#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
int n,m;
int a[N];
int t1[N];int t2[N];
set<int>s;
#define lowbit(x) x&-x
int query(int x,int t[])
{
    int sum = 0;
    for(int i = x; i; i -= lowbit(i))
        sum += t[i];
    return sum;
}
void add(int x, int k ,int t[])
{
    for(int i = x; i <= n; i += lowbit(i))
        t[i] += k;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=10)s.insert(i);
        if(a[i]<100)add(i,1,t2);
        add(i,a[i],t1);
    }
    while(m--){
        int op,l,r;cin>>op>>l>>r;
        if(op==1){
            vector<int>v;
            for(auto i=s.lower_bound(l);i!=s.end();i++){
                if(*i>r)break;
                int j=*i;int val=ceil(1.0*a[j]/3);
                add(j,-val,t1);
                if(a[j]>=100&&2*a[j]/3<100)add(j,1,t2);
                a[j]=a[j]*2/3;
                if(a[j]<10)v.emplace_back(j);
            }
            for(auto i:v)s.erase(i);
        }
        else if(op==2){
            cout<<query(r,t2)-query(l-1,t2)<<endl;
        }else{
            cout<<query(r,t1)-query(l-1,t1)<<endl;
        }
    }
    return 0;
}