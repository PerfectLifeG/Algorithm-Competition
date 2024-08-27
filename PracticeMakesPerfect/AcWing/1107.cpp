#include<bits/stdc++.h>
using namespace std;
typedef pair<char,string>PCS;
#define x first
#define y second
unordered_map<string,int>book;
unordered_map<string,PCS>pre;
queue<string>q;
string op[3]={"87654321", "41236785", "17245368"};
string move(string t,int k){
    string res="";
    for (int i = 0; i < 8; i ++)
        res += t[op[k][i] - '1'];
    return res;
}
void bfs(string end){
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(t==end)return;
        for(int i=0;i<3;i++){
            string res=move(t,i);
            if(book.count(res)==0){
                book[res]=book[t]+1;
                pre[res].x='A'+i;
                pre[res].y=t;
            }
        }
    }
}
int main(){
    char c;
    string start="12345678";
    string end;
    for(int i=0;i<8;i++){cin>>c;end+=c;}
    book[start]=0;
    q.push(start);
    bfs(end);
    cout<<book[end]<<endl;
    string ans;
    while(end!=start){
        c=pre[end].x;
        end=pre[end].y;
        ans+=c;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}