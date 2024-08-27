#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
const int N=20;
int a[N],s[N];
typedef pair<int,int>PII;
vector<int>v;
vector<PII>add,query;
int find(int x){
    int l=-1,r=v.size();   
    while(l+1!=r){
        int mid=l+r>>1;
        if(v[mid]<x){    //刚开始这写错了，应该在v中查
            l=mid;
        }
        else r=mid;
    }
    return r+1;         //这是r+1 因为前缀和要从1开始
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x,c;cin>>x>>c;
        add.push_back({x,c});
        v.push_back(x);
    }
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        query.push_back({l,r});
        v.push_back(l);
        v.push_back(r);
    }
    //离散化后，有的坐标相同所以要去重
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    
    for(auto it:add){
        int x=find(it.first);
        a[x]+=it.second;
    }
    for(int i=1;i<=v.size();i++){
        s[i]=s[i-1]+a[i];
    }
    for(auto it:query){
        int l=find(it.first);int r=find(it.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}