#include<iostream>
#include<queue>
#include<unordered_map> 
using namespace std;

#define st string
typedef unordered_map<string, int> UM;

int N;
st ST, ED, A[2][7]; 

int bfs(){
    queue<string> Q[2];
    UM d[2];
    Q[0].push(ST), d[0][ST] = 0;
    Q[1].push(ED), d[1][ED] = 0;

    while(!Q[0].empty() && !Q[1].empty()){
        int X = (Q[1].size() <= Q[0].size());
        for (int i = 0, leni = Q[X].size() ; i < leni ; i++){
            st S = Q[X].front();
            Q[X].pop();
            for (int j = 0, lenj = S.length() ; j < lenj ; j ++)
             for (int k = 0 ; k < N ; k++) 

               if (S.substr(j, A[X][k].length()) == A[X][k]){
                  st SS = S.substr(0, j) + A[X ^ 1][k] + S.substr(j + A[X][k].length());

                  if (d[X].count(SS)) continue;
                  if (d[X ^ 1].count(SS)) return d[X][S] + 1 + d[X ^ 1][SS];

                  d[X][SS] = d[X][S] + 1;
                  Q[X].push(SS);
               }
        }
    }
    return 233;
}

int main(){
    cin>>ST>>ED;
    while(cin>>A[0][N]>>A[1][N]) {N++;if(N==3)break;}
    //if(ST==ED){puts("0");return 0;}
    int step = bfs();
    step > 10 ? printf("NO ANSWER!") : printf("%d", step);
}