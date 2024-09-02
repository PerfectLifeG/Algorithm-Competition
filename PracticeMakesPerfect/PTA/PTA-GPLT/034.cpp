#include<bits/stdc++.h>
using namespace std;
#define pss pair<string,string>
struct Node{
    string name;
    int time;
    string num;
    int con;
};
unordered_map<string,int>book;
unordered_map<string,int>book2;
vector<pss>v;
int cmp(Node n1,Node n2){
    return n1.time<n2.time;
}
int main()
{
    int d,p;cin>>d>>p;
    for (int i = 0; i < d; i++)
    {
        Node node[1001];
        int t,s;cin>>t>>s;
        int cnt=0;
        int j=0;
        for (int i = 0; i < t; j++,i++)
        {
            string a,b;
            int c;int h,min;
            cin>>a>>b>>c;
            scanf("%d:%d",&h,&min);
            if(b.size()!=18)j--;
            if(b.size()==18){
                node[j].name=a;
                node[j].time=h*60+min;
                node[j].num=b;
                node[j].con=c;
                cnt++;
                if(node[i].con==1&&book2[node[i].num]==0){
                    book2[node[i].num]=1;
                    v.push_back({node[i].name,node[i].num});
                }
            }
        }
        sort(node,node+cnt,cmp);
        for (int i = 0; i<s&&i<cnt; i++)
        {
            if(book[node[i].num]==0)
            cout<<node[i].name<<" "<<node[i].num<<endl;
            book[node[i].num]=(book[node[i].num]+1)%p;
        }
    }
    for(auto it:v)
    {
        cout<<it.first<<' '<<it.second<<endl;
    }
    return 0;
}