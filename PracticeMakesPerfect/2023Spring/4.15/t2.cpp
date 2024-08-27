#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
	unordered_map<int,string>mp;
	unordered_map<int,string>mp2;
	unordered_map<int,string>mp3;
	mp[0]="零";mp[1]="壹";mp[2]="贰";mp[3]="叁";
	mp[4]="肆";mp[5]="伍";mp[6]="陆";
	mp[7]="柒";mp[8]="捌";mp[9]="玖";
	mp2[1]="元";mp2[2]="拾";mp2[3]="佰";mp2[4]="仟";
	mp2[5]="万";mp2[6]="拾万";mp2[7]="佰万";
	mp2[8]="仟万";mp2[9]="亿";
	mp3[1]="角";mp3[2]="分";
	string s;cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='.')break;
		cnt++;
	}
	for(int i=0;i<cnt;i++){
		if(s[i]!='0'){
			cout<<mp[s[i]-'0']<<mp2[cnt-i];
		}
	}
	for(int i=cnt+1;i<s.size();i++){
		if(s[i]!='0'){
			cout<<mp[s[i]-'0'-1]<<mp3[i-cnt];
		}
	}
	return 0;
}