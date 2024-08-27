#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long  ll;
ll l,r;
struct Node
{
    ll t;
};
ll cmp(Node n1,Node n2){
    if(n1.t<=r&&n2.t<=r&&n1.t>n2.t)return n1.t>n2.t;
    if(n1.t<=r&&n2.t>r)return n1.t<n2.t;
    if(n2.t<=r&&n1.t>r)return n1.t<n2.t;
    return n1.t>n2.t;
}
int main()
{
    int n;cin>>n;
    Node node[n];
    for (int i = 0; i < n; i++)
    {
        cin>>node[i].t;
    }
    cin>>l>>r;
    sort(node,node+n,cmp);
    if(node[0].t<=r)
    cout<<node[0].t+r;
    else cout<<r;
    return 0;
}