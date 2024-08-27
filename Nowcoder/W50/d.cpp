#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int a,b,c;cin>>a>>b>>c;

    if(b==0&&c==0){
        cout<<"1 0 "<<a<<' '<<0<<endl;
        return;
    }
    int a1,a2,b1,b2;
    if(c==0){
        b2=0;
        for(int a1=-abs(a);a1<=abs(a);a1++){
            if(a1==0)continue;
            if(a%a1==0){
                a2=a/a1;
                if(b%a2==0){
                    b1=b/a2;
                    cout<<a1<<' '<<b1<<' '<<a2<<' '<<b2<<endl;
                    return;
                }
            }
        }
    }

    if(b*b-4*a*c<0){
        cout<<"NO\n";
        return;
    }
    int x=b*b-4*a*c;
    int s=sqrt(x);
    if(s*s!=x){
        cout<<"NO\n";
        return;
    }
    int t;
    if((b+s)%2==0){
        t=(b+s)/2;
    }else if((b-s)%2==0){
        t=(b-s)/2;
    }else{
        cout<<"NO\n";
        return;
    }

    for(int a1=-abs(a);a1<=abs(a);a1++){
        if(a1==0)continue;
        if(a%a1==0){
            a2=a/a1;
            if(a2==0)continue;
            if(t%a2==0){
                b1=t/a2;
                if(b1==0)continue;
                if(c%b1==0){
                    b2=c/b1;
                    cout<<a1<<' '<<b1<<' '<<a2<<' '<<b2<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}