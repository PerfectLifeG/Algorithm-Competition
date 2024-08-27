#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int book[N];
int p[N];
unordered_map<int,int>mp;
vector<int>v;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    memset(book,-1,sizeof(book));
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        book[a]=b;
        book[b]=a;
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int a;cin>>a;
        p[i]=a;mp[a]++;
    }
    for(int i=0;i<m;i++){
        if(!mp.count(book[p[i]]))v.push_back(p[i]);
    }
    sort(v.begin(),v.end());
    if(v.size()){
        printf("%d\n%05d",v.size(),v.front());
        for(int i=1;i<v.size();i++){
            printf(" %05d",v[i]);
        }
    }
    return 0;
}