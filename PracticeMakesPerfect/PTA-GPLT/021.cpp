#include<bits/stdc++.h>
using namespace std;
struct node
{
    string name;
    int cnt;
    map<int,int>m;
    float a;
};
int cmp(node n1,node n2){
    //return n1.a<n2.a;
    if(n1.m.size()==n2.m.size()){
        return (n1.cnt*1.0/n1.m.size()) < (n2.cnt*1.0/n2.m.size());
    }return n1.m.size()>n2.m.size();
}
int main()
{
    int n;cin>>n;
    node name[n];
    for (int i = 0; i < n; i++)
    {
        cin>>name[i].name;
        int m;cin>>m;name[i].cnt=m;
        for (int j = 0; j < m; j++)
        {
            int a;cin>>a;
            name[i].m[a]++;
        }
        name[i].a=name[i].m.size()*1.0/name[i].cnt;
    }
    sort(name,name+n,cmp);
    if(n==0){
        cout<<"- - -";
    }
    if(n==1){
        cout<<name[0].name<<" - -";
    }
    if(n==2){
        cout<<name[0].name<<" "<<name[1].name<<" -";
    }
    if(n>=3){
        cout<<name[0].name<<" "<<name[1].name<<" "<<name[2].name;
    }
    return 0;
}