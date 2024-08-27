#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
	int n;cin>>n;
	string s;
	getline(cin,s);
	while(n--){
		getline(cin,s);
		if(s[s.size()-1]!='?'){puts("enen");continue;}
		if(s.find("PTA")!=-1){
			puts("Yes!");
		}else puts("No.");
	}
	return 0;
}
