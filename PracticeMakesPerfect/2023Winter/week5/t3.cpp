#include<bits/stdc++.h>
using namespace std;
const int N=100010;
#define all(x) x.begin(),x.end()
struct Node{
    int number;
    int de;
    int cai;
    int s;
}node[N];
vector<Node>v1,v2,v3,v4;
int cmp(Node n1,Node n2){
    if(n1.s==n2.s){
        if(n1.de==n2.de)return n1.number<n2.number;
        else return n1.de>n2.de;
    }
    return n1.s>n2.s;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,l,h;
    cin>>n>>l>>h;
    for(int i=0;i<n;i++){
        cin>>node[i].number>>node[i].de>>node[i].cai;
        node[i].s=node[i].de+node[i].cai;
        if(node[i].de>=h&&node[i].cai>=h)v1.push_back(node[i]);
        else if(node[i].de>=h&&node[i].cai>=l)v2.push_back(node[i]);
        else if(node[i].de>=l&&node[i].cai>=l&&node[i].de>=node[i].cai)v3.push_back(node[i]);
        else if(node[i].de>=l&&node[i].cai>=l)v4.push_back(node[i]);
    }
    printf("%d\n",v1.size()+v2.size()+v3.size()+v4.size());
    sort(all(v1),cmp);
    for(auto it:v1)printf("%d %d %d\n",it.number,it.de,it.cai);
    sort(all(v2),cmp);
    for(auto it:v2)printf("%d %d %d\n",it.number,it.de,it.cai);
    sort(all(v3),cmp);
    for(auto it:v3)printf("%d %d %d\n",it.number,it.de,it.cai);
    sort(all(v4),cmp);
    for(auto it:v4)printf("%d %d %d\n",it.number,it.de,it.cai);
    return 0;
}