#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int yy1,m1,d1,y2,m2,d2;
int cnt=0;
void check(int i,int j,int k){
	int a=i,b=j,c=k;
	int ret=0;int ret9=0;
	// cout<<i<<endl;
	while(i){
		if(i%10==2)ret++;
		if(i%10==9)ret9++;
		i/=10;
	}
	// cout<<ret<<' '<<ret9<<endl;
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
	// cout<<i<<' '<<j<<' '<<k<<endl;
	if(ret>=4||ret9>=2)cnt++;
	
	// cout<<a<<' '<<b<<' '<<c<<' '<<cnt<<endl;
}
int rn(int i){
	if(i%400==0||i%4==0&&i%100!=0)return 1;
	else return 0;
}
int main(){
	cin>>yy1>>m1>>d1>>y2>>m2>>d2;
	for(int i=yy1;i<=y2;i++){
		if(i==yy1){
			for(int j=m1;j<=12;j++){
				if(y2==yy1&&j>m2)break;
				for(int k=1;k<=31;k++){
					if(j==m1){
						k=max(k,d1);
						if(y2==yy1&&m1==m2)if(k>d2)break;
					}
					if((j==4||j==6||j==9||j==11)&&k>30)break;
					if(rn(i)&&j==2&&k>29)break;
					if(!rn(i)&&j==2&&k>28)break;
					// cout<<i<<' '<<j<<' '<<k<<endl;
					check(i,j,k);
				}
			}
		}
		else if(i==y2){
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
		}else {
			for(int j=1;j<=12;j++){
				for(int k=1;k<=31;k++){
					if((j==4||j==6||j==9||j==11)&&k>30)break;
					if(rn(i)&&j==2&&k>29)break;
					if(!rn(i)&&j==2&&k>28)break;
					// cout<<i<<' '<<j<<' '<<k<<endl;
					check(i,j,k);
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}