#include<bits/stdc++.h>
using namespace std;
const int N=20010;
int n,p,k;
int h[N],w[N],e[N],ne[N],idx;
void add(int a,int b,int c){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=c;
    h[a]=idx++;
}
deque<int>q;
int d[N];
int book[N];
int check(int x){
    memset(d,0x3f,sizeof(d));
    memset(book,0,sizeof(book));
    d[1]=0;
    q.push_back(1);
    while(q.size()){
        auto t=q.front();
        q.pop_front();
        if(book[t])continue;
        book[t]=1;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(book[j])continue;
            if(d[j]>d[t]+(w[i]>x)){
                d[j]=d[t]+(w[i]>x);
                if(w[i]>x)q.push_back(j);
                else q.push_front(j);
            }
        }
    }
    return d[n]<=k;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>p>>k;
    memset(h,-1,sizeof(h));
    for(int i=0;i<p;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    int l=-1,r=1e6+1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    if(r==1e6+1)r=-1;
    cout<<r;
    return 0;
}