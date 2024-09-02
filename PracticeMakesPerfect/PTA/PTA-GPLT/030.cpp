#include<bits/stdc++.h>
using namespace std;
struct Node{
    vector<string>v;
    int sex;
};
map<string,Node>m;
map<string,int>book;
int flag;
void dfs(string s,int cnt){
    if(cnt>=3){return;}
    int len=m[s].v.size();
    if(flag==1)return;
    for (int i = 0; i < len; i++)
    {
        string t=m[s].v[i];
        book[t]=1;
        dfs(t,cnt+1);
    }
}
void dfs2(string s){
    int len=m[s].v.size();
    if(flag==1)return;
    for (int i = 0; i < len; i++)
    {
        string t=m[s].v[i];
        if(book[t]==1)
          { flag=1;
            return;}
        else {
            dfs2(t);
        }
    }
}
int main()
{
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        string a,b;cin>>a>>b;
        Node temp;
        book[a]=0;
        if(b.back()=='n'){
            temp.v.push_back(b.substr(0,b.size()-4));
            m.insert(make_pair(a,temp));
            m[a].sex=1;
        }
        else if(b.back()=='r'){
            temp.v.push_back(b.substr(0,b.size()-7));
            m.insert(make_pair(a,temp));
            m[a].sex=0;
        }else if(b.back()=='m'){
            m.insert(make_pair(a,temp));
            m[a].sex=1;
        }else{m.insert(make_pair(a,temp));
            m[a].sex=0;
        }
    }
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string a,c,b,d;
        cin>>a>>c>>b>>d;
        if(m.find(a)==m.end()||m.find(b)==m.end()){
            cout<<"NA"<<endl;
            continue;
        }
        if((m[a].sex^m[b].sex)!=1){cout<<"Whatever"<<endl;continue;}
        flag=0;
        auto it=book.begin();
        for (;it!=book.end();it++)it->second=0;
        dfs(a,0);
        dfs2(b);
        it=book.begin();
        for (;it!=book.end();it++)it->second=0;
        dfs(b,0);
        dfs2(a);
        if(flag){
            cout<<"No"<<endl;
        }else cout<<"Yes"<<endl;
    }
    return 0;
}