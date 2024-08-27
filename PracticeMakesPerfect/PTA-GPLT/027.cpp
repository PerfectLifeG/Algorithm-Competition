#include<bits/stdc++.h>
using namespace std;
struct Node
{
    string s;
    int sco;
    int num;
};
int cmp(Node n1,Node n2){
    if(n1.sco==n2.sco){
        return n1.s<n2.s;
    }return n1.sco>n2.sco;
}
int main()
{
    int n,g,k;cin>>n>>g>>k;
    Node node[n+5];
    int s=0;
    for (int i = 1; i <= n; i++)
    {
        cin>>node[i].s>>node[i].sco;
        if(node[i].sco>=g){
            s+=50;
        }else if(node[i].sco>=60)s+=20;
    }
    sort(node+1,node+n+1,cmp);
    for (int i = 1; i <= n; i++)
    {
        if(i>1&&node[i].sco==node[i-1].sco){
            node[i].num=node[i-1].num;
        }else node[i].num=i;
    }
    cout<<s<<endl;
    int i=1;
    while(i!=n+1&&node[i].num<=k)
    {
        cout<<node[i].num<<" "<<node[i].s<<" "<<node[i].sco<<endl;
        i++;
    }
    return 0;
}