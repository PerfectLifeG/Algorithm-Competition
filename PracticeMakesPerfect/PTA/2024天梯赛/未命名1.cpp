#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
const int N=1010;
string v[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int cnt=0;
    int k;cin>>k;
    string s;getline(cin,s);
    getline(cin,s);
    for(int i=0;i<n;i++){
        int pos;
        while((pos=s.find(v[i]))!=-1){
            s.erase(pos,min(s.size()-pos,v[i].size()));
            s.insert(pos,"<censored>");
            cnt++;
        }
    }
    if(cnt>=k){
        cout<<cnt<<endl;
        cout<<"He Xie Ni Quan Jia!\n";
    }else cout<<s<<endl;
}
