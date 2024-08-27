#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int root[N];
int find(int a){
    if(a==root[a])return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    if(a<b)swap(a,b);
    int ra=find(a),rb=find(b);
    root[ra]=rb;
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)root[i]=i;
    char a;
    while(cin>>a,a!='S'){
        int b,c;cin>>b>>c;
        if(a=='I'){
            merge(b,c);
        }else if(a=='C'){
            if(find(b)==find(c))puts("yes");
            else puts("no");
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(root[i]==i)ans++;
    }
    if(ans==1)puts("The network is connected.");
    else printf("There are %d components.",ans);
    return 0;
}