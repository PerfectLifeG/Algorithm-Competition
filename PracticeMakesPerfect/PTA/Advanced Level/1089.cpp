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
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>final(n);
    for(int i=0;i<n;i++){
        cin>>final[i];
    }

    auto check=[&](vector<int> &tmp){
        for(int i=0;i<n;i++){
            if(tmp[i]!=final[i])return 0;
        }
        return 1;
    };

    vector<int>tmp=v;
    for(int i=2;i<n;i++){
        sort(tmp.begin(),tmp.begin()+i);
        if(check(tmp)){
            sort(tmp.begin(),tmp.begin()+i+1);
            cout<<"Insertion Sort\n";
            cout<<tmp[0];
            for(int i=1;i<n;i++){
                cout<<' '<<tmp[i];
            }cout<<endl;
            return;
        };
    }

    function<void(int,int)> merge=[&](int l,int r){
        if(l>=r)return;
        int mid=l+r>>1;
        merge(l,mid);
        merge(mid+1,r);
        int p1=l,p2=mid+1;
        int idx=0;
        while(p1<=mid&&p2<=r){
            if(v[p1]<=v[p2])tmp[idx++]=v[p1++];
            else if(p2<=r)tmp[idx++]=v[p2++];
        }
        while(p1<=mid)tmp[idx++]=v[p1++];
        while(p2<=r)tmp[idx++]=v[p2++];

        idx=0;
        for(int i=l;i<=r;i++){
            v[i]=tmp[idx++];
        }
    };

    for(int i=2;i<=2*n;i*=2){
        for(int j=0;j<n;j+=i){
            merge(j,min(n-1,j+i-1));
        }
        if(check(v)){
            i*=2;
            for(int j=0;j<n;j+=i){
                merge(j,min(n-1,j+i-1));
            }
            cout<<"Merge Sort\n";
            cout<<v[0];
            for(int i=1;i<n;i++){
                cout<<' '<<v[i];
            }cout<<endl;
            return;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}