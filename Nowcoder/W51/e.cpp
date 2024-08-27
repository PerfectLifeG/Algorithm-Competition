#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int g[550][550];
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }

    auto check=[&](int mid){
        queue<PII>q;q.push({0,0});
        vector<vector<int>> book(n,vector<int>(n));
        while(q.size()){
            auto t=q.front();
            q.pop();
            if(t.x==n-1&&t.y==n-1)return 1;
            for(int i=0;i<4;i++){
                int tx=t.x+dir[i][0],ty=t.y+dir[i][1];
                if(tx<0||ty<0||tx>=n||ty>=n||book[tx][ty]||g[tx][ty]>mid)continue;
                book[tx][ty]=1;
                q.push({tx,ty});
            }
        }
        return 0;
    };


    int l=g[0][0]-1,r=1e9;
    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}