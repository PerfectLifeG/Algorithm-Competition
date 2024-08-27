#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
const int N=10010;
int main(){
	int n;cin>>n;
    while(n--){
        int g[9][9]={};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>g[i][j];
            }
        }
        int f=1;
        for(int i=0;i<9;i++){
            vector<int>book(10);
            if(!f)break;
            for(int j=0;j<9;j++){
                if(book[g[i][j]]){f=0;break;}
                book[g[i][j]]=1;
            }
        }
        for(int i=0;i<9;i++){
            vector<int>book(10);
            if(!f)break;
            for(int j=0;j<9;j++){
                if(book[g[j][i]]){f=0;break;}
                book[g[j][i]]=1;
            }
        }
        for(int i=0;i<9;i+=3){
            if(!f)break;
            for(int j=0;j<9;j+=3){
            	vector<int>book(10);
            	if(!f)break;
                for(int k=i;k<i+3;k++){
                    for(int p=j;p<j+3;p++){
//                    	cout<<k<<' '<<p<<endl;
                        if(book[g[k][p]]){f=0;break;}
                        book[g[k][p]]=1;
                    }
                }
            }
        }
        if(f)cout<<1<<endl;
        else cout<<0<<endl;
    }
}
