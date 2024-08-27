#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f;
inline int Log2(double x){
    if(x==0)return -1;
    if(x==1)return 0;
    return ((*(unsigned long long*)&x>>52)&1023)+1;
}
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>a(n);
    int flag=0;
    for(int i=0;i<n-1;i++)cin>>a[i];
    int b[n+1]={};
    vector<int>book(32);
    for(int i=n-2;i>=0;i--){
        int idx=0;
        int t=a[i];
        int j=i;
        while(t){
            if(t>>1==0){
                if(book[idx]){
                    if((b[i]>>idx&1)!=0){
                        cout<<-1<<endl;
                        return;
                    }
                    continue;
                }
                book[idx]=1;
                while(i-1>=0){
                    if((a[i-1]>>idx)&1){
                        int q=(b[i]>>idx)&1;
                        b[i-1]+=((q^1)<<idx);
                    }
                    else {
                        int q=(b[i]>>idx)&1;
                        b[i-1]+=(q<<idx);
                    }
                    i--;
                }
            }
            idx++;
            t>>=1;
            i=j;
        }
    }
    for(int i=0;i<n-1;i++){
        int idx=0;
        int t=a[i];
        while(idx<31){
            // int q=(b[i]>>idx)&1;
            // b[i+1]+=(q)^((t>>idx)&1)<<idx;
            if((t>>idx)&1){
                int q=(b[i]>>idx)&1;
                b[i+1]+=((q^1)<<idx);
            }
            else {
                int q=(b[i]>>idx)&1;
                b[i+1]+=(q<<idx);
            }
            idx++;
        }
    }

    // vector<int>bb(n);
    // for(int i=0;i<n;i++){
    //     bb[i]=b[i].to_ullong();
    //     if(i>0&&bb[i-1]>bb[i]){
    //         cout<<-1<<endl;
    //         return;
    //     }
    // }
    int mx=-1;
    for(int i=0;i<n;i++){
        mx=max(mx,Log2(b[i]));
    }
    mx++;
    int t=(k-1)*(1<<mx);
    // cout<<mx<<' '<<k<<endl;

    for(int i=0;i<n;i++){
        cout<<b[i]+t<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}