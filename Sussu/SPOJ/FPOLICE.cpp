#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110, MAXT = 260, INF = 0x3f3f3f3f;

int tt, t, n, dp[MAXN][MAXT], tem[MAXN][MAXN], cus[MAXN][MAXN];

int go(int v,int tp){
    if(dp[v][tp]==INF){
        if(v==0) return dp[v][tp]=0;
        for(int a=0;a<n;a++){
            if(a==v) continue;
            if(tp-tem[v][a]>=0)dp[v][tp]=min(dp[v][tp],go(a,tp-tem[v][a])+cus[v][a]);
        }
    }
    return dp[v][tp];
}

int main(){
    scanf("%d", &tt);
    for(int z=0;z<tt;z++){
        scanf("%d%d", &n, &t);
        for(int a=0;a<=n;a++){
            for(int b=0;b<=t;b++){
                dp[a][b]=INF;
            }
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                scanf("%d", &tem[b][a]);
            }
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                scanf("%d", &cus[b][a]);
            }
        }
        int res=INF, rest;
        for(int a=0;a<=t;a++){
            if(go(n-1,a)<res){
                rest=a;
                res=dp[n-1][a];
            }
        }
        if(res==INF)
            printf("-1\n");
        else
            printf("%d %d\n", res,rest);
    }
    return 0;
}

/*
2
4 10
0 6 2 3
6 0 2 3
3 1 0 2
3 3 2 0
0 2 2 7
2 0 1 2
2 2 0 5
7 2 5 0
4 10
0 6 2 3
6 0 2 3
3 1 0 2
3 3 2 0
0 2 2 7
2 0 1 2
2 2 0 5
7 2 5 0
*/
