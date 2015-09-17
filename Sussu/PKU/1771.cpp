#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 35, INF = 0x3f3f3f3f;

int n, f[MAXN], dp[MAXN][MAXN][2], ult;

vector <int> res;

inline int mod(int v){
    if(v<0) return -v;
    return v;
}

int go(int v,int k,int pag){
    if(dp[v][k][pag]==INF){
        if(k==n)
            return dp[v][k][pag]=0;
        if(v==32)
            return INF;
        dp[v][k][pag]=min(dp[v][k][pag],go(v+1,k,0)+4+pag*10*min(1,v-1));
        if(pag==0)
            dp[v][k][pag]=min(dp[v][k][pag],max(mod(f[k]-v)*20,go(v,k+1,1)));
        else
            dp[v][k][pag]=min(dp[v][k][pag],max(mod(f[k]-v)*20,go(v,k+1,pag)));
    }
    return dp[v][k][pag];
}

void fazdp(int v,int k,int pag){
    while(k!=n){
        if(dp[v][k][pag]==dp[v+1][k][0]+4+pag*10*min(1,v-1)){
            v++;
            pag=0;
        }
        else if(pag==0 && dp[v][k][pag]==max(mod(f[k]-v)*20,dp[v][k+1][1])){
            if(v!=1)
                res.push_back(v);
            pag=1;
            k++;
        }
        else if(pag==1 && dp[v][k][pag]==max(mod(f[k]-v)*20,dp[v][k+1][pag])){
            k++;
        }
    }
    return;
}

int main (){
    while(scanf("%d", &n) && n!=0){
        res.clear();
        for(int a=0;a<n;a++){
            scanf("%d", &f[a]);
        }
        for(int a=0;a<=32;a++){
            for(int b=0;b<=32;b++){
                for(int c=0;c<2;c++){
                    dp[a][b][c]=INF;
                }
            }
        }
        printf("%d\n", go(1,0,0));
        fazdp(1,0,0);
        printf("%d", res.size());
        for(int a=0;a<res.size();a++){
            printf(" %d", res[a]);
        }
        printf("\n");
    }
    return 0;
}
