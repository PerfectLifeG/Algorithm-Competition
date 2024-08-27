#include<bits/stdc++.h>
using namespace std;
const int N=10010;
stack<string>s;
string ans,res;
void sovle(){
    while(1){
        getline(cin,res);
        if(res==".")break;
        ans+=res;
    }
    for(int i=0;i<ans.size();i++){
        if(i+1<ans.size()&&ans[i]=='/'&&ans[i+1]=='*')
        {s.push("/*");i++;}
        else if(i+1<ans.size()&&ans[i]=='*'&&ans[i+1]=='/'){
            if(s.size()&&s.top()=="/*"){s.pop();i++;}
            else{
                cout<<"NO"<<endl;
                if(s.empty())cout<<"?-*/";
                else cout<<s.top()<<"-?"<<endl;
                return;
            }
        }
        else if(ans[i]=='{')s.push("{");
        else if(ans[i]=='}'){
            if(s.size()&&s.top()=="{")s.pop();
            else{
                cout<<"NO"<<endl;
                if(s.empty())cout<<"?-}";
                else cout<<s.top()<<"-?"<<endl;
                return;
            }
        }else if(ans[i]=='[')s.push("[");
        else if(ans[i]==']'){
            if(s.size()&&s.top()=="[")s.pop();
            else{
                cout<<"NO"<<endl;
                if(s.empty())cout<<"?-]";
                else cout<<s.top()<<"-?"<<endl;
                return;
            }
        }else if(ans[i]=='(')s.push("(");
        else if(ans[i]==')'){
            if(s.size()&&s.top()=="(")s.pop();
            else{
                cout<<"NO"<<endl;
                if(s.empty())cout<<"?-)";
                else cout<<s.top()<<"-?"<<endl;
                return;
            }
        }
    }
    if(s.empty())cout<<"YES"<<endl;
    else cout<<"NO"<<endl<<s.top()<<"-?";
}
int main(){
    sovle();
    return 0;
}