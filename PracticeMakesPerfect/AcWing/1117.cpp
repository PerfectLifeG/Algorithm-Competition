#include<bits/stdc++.h>
using namespace std;
const int N=25;
string word[N];
int book[N];
int n;
int ans;
void dfs(string s){
    ans=max((int)s.size(),ans);
    for(int i=s.size()-1;i>=0;i--){//字符串的下标
        for(int j=0;j<n;j++){//和其他字符串匹配
            int len=s.size()-i;
            if( len<min(word[j].size(),s.size()) &&s.substr(i,len)==word[j].substr(0,len) ){
                string str=s.substr(0,i)+word[j];
                if(book[j]>=2)continue;
                book[j]++;
                dfs(str);
                book[j]--;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>word[i];
    char c;cin>>c;
    for(int i=0;i<n;i++){
        if(word[i][0]==c){
            memset(book,0,sizeof(book));
            book[i]=1;
            dfs(word[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}