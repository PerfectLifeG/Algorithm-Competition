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
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    vector<int>book(n,1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1)book[i]=0;
    }
    sort(all(a));
    int l=0,r=n-1;
    int ans=0;
    while(l<r){
        int t=a[l];
        // 1 1 2 3 7
        while(a[r]>t&&l+1<r){
            t+=a[++l];
        }
        if(a[r]<=t){
            ans+=a[r]+1;
            a[l]-=a[r]-(t-a[l]);
            r--;
        }else{
            ans+=(a[r]+t)/2-t+1;
            break;
        }
    }
    cout<<ans<<endl;

    while(l<r){
        if(a[r]<a[l]){
            a[l]-=a[r];
            a[r]=0;
            book[r]=0;
            r--;
            ans++;
        }else {
            a[r]-=a[l];
            book[l]=0;
            ans+=a[l];
            if(a[r]==0){
                ans++;
                book[r]=0;
                r--;
            }
            a[l]=0;
            l++;
        }
    }
    // 1 2 3 8
    if(a[l]==1){
        cout<<ans+1+book[l]<<endl;
    }
    else if(a[l]){
        cout<<ans+(a[l]+1)/2+1+book[l]<<endl;
    }else cout<<ans<<endl;
    // 1 2 2 3 4 5
    // 1+4+5=6
    // 2+2=3

    // 1+2+2+5=6
    // 3+4=3+1+1=5

    // 1+2+3=4
    // 2+4+5=5+1+1
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}