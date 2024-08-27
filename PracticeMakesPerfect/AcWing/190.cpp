#include<bits/stdc++.h>
using namespace std;
const int N=10010;
unordered_map<string,int>book[2];
queue<string>q[2];
string a[6][2];
string st,ed;
int n;
int bfs(){
    q[0].push(st);book[0][st]=0;
    q[1].push(ed);book[1][ed]=0;
    while(q[1].size()&&q[2].size()){
        int idx=(q[1].size()<q[0].size());
        if(q[0].size()==0)idx=1;//注意这个条件，没有的话会导致死循环
        for(int k=0,dot=q[idx].size();k<dot;k++){
            auto t=q[idx].front();
            q[idx].pop();
            for(int i=0;i<t.size();i++)
                for(int j=0;j<n;j++)
                    if(t.substr(i,a[j][idx].size())==a[j][idx]){
                        string str=t.substr(0,i)+a[j][idx^1]+t.substr(i+a[j][idx].size());//a[j][(idx+1)%2]换成a[j][idx^1]
                        if(str.size()>20)continue;
                        if(book[idx^1].count(str)==1)return book[idx][t]+book[idx^1][str]+1;
                        if(book[idx].count(str)==0){
                            book[idx][str]=book[idx][t]+1;
                            q[idx].push(str);
                        }
                    }
        }
    }
    return 11;
}
int main(){
    cin>>st>>ed;
    while(cin>>a[n][0]>>a[n][1])n++;
    if(st==ed){puts("0");return 0;}
    int t=bfs();
    if(t>10)puts("NO ANSWER!");
    else printf("%d",t);
    return 0;
}