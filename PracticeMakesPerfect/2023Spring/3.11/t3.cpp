#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int>mp;
unordered_map<int,int>mp2;
unordered_map<int,int>mp3;
unordered_map<int,int>mp4;
// const int N=10001000;
int n,t;
// int mp[N],mp2[N],mp3[N],mp4[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>t;
    for(int i=0;i<t;i++){
        int x,y;cin>>x>>y;
        if(!mp.count(x)&& !mp2.count(y) && !mp3.count(y-x+n) && !mp4.count(y+x)){
            mp[x]=mp2[y]=mp3[y-x+n]=mp4[x+y]=1;
            puts("Yes");
        }
        else puts("No");
    }
    return 0;
}