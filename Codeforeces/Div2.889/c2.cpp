#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<int>a(n+1);
    int f=0,z=0;
    int mn=1e9,mx=0;
    int mxid,mnid;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mx){
            mx=a[i];
            mxid=i;
        }
        if(a[i]<mn){
            mn=a[i];
            mnid=i;
        }
        if(a[i]>0)z++;
        if(a[i]<0)f++;
    }

    if(f==0){
        cout<<n-1<<endl;
        for(int i=1;i<=n-1;i++){
            cout<<i+1<<' '<<i<<endl;
            a[i+1]+=a[i];
        }
    }else if(z==0){
        cout<<n-1<<endl;
        for(int i=n-1;i>=1;i--){
                cout<<i<<' '<<i+1<<endl;
                a[i]+=a[i+1];
        }
    }
    else if(z>=f){
        if(abs(mx)<=abs(mn)&&z<=12){
            cout<<n-1+z<<endl;
            for(int i=1;i<=n;i++){
                if(a[i]>0){
                    cout<<i<<' '<<mnid<<endl;
                    a[i]+=a[mnid];
                }
            }
            for(int i=n-1;i>=1;i--){
                cout<<i<<' '<<i+1<<endl;
                a[i]+=a[i+1];
            }
        }else{
            if(abs(mx)>abs(mn)){
                cout<<n-1+f<<endl;
            }else{
                cout<<5+n-1+f<<endl;
                int t=5;
                while(t--){
                    cout<<mxid<<' '<<mxid<<endl;
                    a[mxid]+=a[mxid];
                }
            }
            for(int i=1;i<=n;i++){
                if(a[i]<0){
                    cout<<i<<' '<<mxid<<endl;
                    a[i]+=a[mxid];
                }
            }
            for(int i=1;i<=n-1;i++){
                cout<<i+1<<' '<<i<<endl;
                a[i+1]+=a[i];
            }
        }
    }else{
        if(abs(mn)<=abs(mx)&&f<=12){
            cout<<n-1+f<<endl;
            for(int i=1;i<=n;i++){
                if(a[i]<0){
                    cout<<i<<' '<<mxid<<endl;
                    a[i]+=a[mxid];
                }
            }
            for(int i=1;i<=n-1;i++){
                cout<<i+1<<' '<<i<<endl;
                a[i+1]+=a[i];
            }
        }else{
            if(abs(mx)<abs(mn)){
                cout<<n-1+z<<endl;
            }
            else {cout<<5+n-1+z<<endl;
                        int t=5;
                        while(t--){
                            cout<<mnid<<' '<<mnid<<endl;
                            a[mnid]+=a[mnid];
                        }}
            for(int i=1;i<=n;i++){
                if(a[i]>0){
                    cout<<i<<' '<<mnid<<endl;
                    a[i]+=a[mnid];
                }
            }
            for(int i=n-1;i>=1;i--){
                cout<<i<<' '<<i+1<<endl;
                a[i]+=a[i+1];
            }
        }

    }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<' ';
    // }
    // cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}