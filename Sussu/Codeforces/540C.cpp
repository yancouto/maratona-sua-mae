#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 510;

int n, m, mrk[MAXN][MAXN][2];
char M[MAXN][MAXN];

int vi[4]={0,0,1,-1};
int vj[4]={1,-1,0,0};

bool valid(int i,int j){
    return (i>0 && j>0 && i<=n && j<=m);
}

void go(int i,int j){
    mrk[i][j][0]=1;
    for(int a=0;a<4;a++){
        if(valid(i+vi[a],j+vj[a])){
            int ii = i+vi[a], jj = j+vj[a];
            if(M[ii][jj]=='X' || mrk[ii][jj][0]==1){
                mrk[ii][jj][1]=1;
            }
            else{
                go(ii,jj);
            }
        }
    }
}

int main (){
    scanf("%d%d", &n, &m);
    for(int a=1;a<=n;a++){
        for(int b=1;b<=m;b++){
            scanf(" %c", &M[a][b]);
        }
    }
    int i, j, ii, jj;
    scanf("%d %d", &i, &j);
    scanf("%d %d", &ii, &jj);
    go(i,j);
    if(mrk[ii][jj][1]==1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
