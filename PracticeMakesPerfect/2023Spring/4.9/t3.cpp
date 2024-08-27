#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int yy1,m1,d1,y2,m2,d2;
int cnt=0;
int book[6][6];
void check(int i,int j,int k){
	int a=i,b=j,c=k;
	int ret=0;int ret9=0;
	while(i){
		if(i%10==2)ret++;
		if(i%10==9)ret9++;
		i/=10;
	}
	while(j){
		if(j%10==2)ret++;
		if(j%10==9)ret9++;
		j/=10;
	}
		while(k){
		if(k%10==2)ret++;
		if(k%10==9)ret9++;
		k/=10;
	}
	// cout<<cnt<<endl;
	// cout<<ret<<' '<<ret9<<endl;
	if(ret>=4||ret9>=2)cnt++;
	// cout<<a<<' '<<b<<' '<<c<<' '<<cnt<<endl;
}
int rn(int i){
	if(i%400==0||i%4==0&&i%100!=0){
		// int a=0,b=0;
		// int t=i;
		// while(i){
		// 	if(i%10==2)a++;
		// 	if(i%10==9)b++;
		// 	i/=10;
		// };
		// s.insert(t);
	return 1;}
	else return 0;
}
int main(){
	book[0][0]=3;
	book[1][0]=5;
	book[2][0]=36;
	book[2][1]=93;
	book[3][0]=181;
	book[4][0]=365;
	book[0][1]=62;
	book[1][1]=64;
	book[0][2]=365;
	cin>>yy1>>m1>>d1>>y2>>m2>>d2;
		int i=yy1;
		for(int j=m1;j<=12;j++){
			if(y2==yy1&&j>m2)break;
			for(int k=1;k<=31;k++){
				if(j==m1){
					k=max(k,d1);
					if(yy1==y2&&m1==m2)if(k>d2)break;
				}
				if((j==4||j==6||j==9||j==11)&&k>30)break;
				if(rn(i)&&j==2&&k>29)break;
				if(!rn(i)&&j==2&&k>28)break;
				// cout<<i<<' '<<j<<' '<<k<<endl;1998 1 1 1999 12 31

				check(i,j,k);
			}
		}
		i=y2;
		if(yy1!=y2){
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=31;k++){
					if(j==m2)k=min(k,d2);
					if((j==4||j==6||j==9||j==11)&&k>30)break;
					if(rn(i)&&j==2&&k>29)break;
					if(!rn(i)&&j==2&&k>28)break;
					// cout<<i<<' '<<j<<' '<<k<<endl;
					check(i,j,k);
					if(j==m2&&k==d2)break;
				}
			}
		}
		for(int i=yy1+1;i<y2;i++){
			int a=0,b=0;
			int t=i;
			while(t){
				if(t%10==2)a++;
				if(t%10==9)b++;
				t/=10;
			};
			// cout<<a<<' '<<b<<endl;
			if(a>=4||b>=2)
			cnt+=365;
			else cnt+=book[a][b];
			if(rn(i)&&(b>=1||a>=2))cnt++;
		}
	cout<<cnt;
	return 0;
}