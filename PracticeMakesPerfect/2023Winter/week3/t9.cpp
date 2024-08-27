#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int pre[N];
vector<int>post;
int ismirror=0;
void getpost(int l,int r){
    if(l>r)return;
    int i=l+1;int j=r;
    if(ismirror){
        while(i<=r&&pre[l]<=pre[i]){i++;}
        while(j>l&&pre[l]>pre[j]){j--;}
    }else{
        while(i<=r&&pre[l]>pre[i]){i++;}
        while(j>l&&pre[l]<=pre[j]){j--;}
    }
    if(j+1!=i)return;
    getpost(l+1,i-1);
    getpost(i,r);
    post.push_back(pre[l]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>pre[i];
    getpost(0,n-1);
    if(post.size()!=n){
        ismirror=1;
        post.clear();
        getpost(0,n-1);
    }
    if(post.size()==n){
        cout<<"YES"<<endl<<post[0];
        for(int i=1;i<n;i++){
            cout<<' '<<post[i];
        }
    }else cout<<"NO";
    return 0;
}