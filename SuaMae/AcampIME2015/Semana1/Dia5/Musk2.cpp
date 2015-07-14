#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 110, INF = 0x3f3f3f3f;

int t, n, m, M[MAXN][MAXN], vez, cnt, mrk[MAXN], res[MAXN], degr;

vector <int> adj[MAXN];

void dfs(int v){
    mrk[v]=1;
    cnt++;
    int tam = adj[v].size();
    for(int a=0;a<tam;a++){
        int nxt = adj[v][a];
        if(mrk[nxt]!=1){
            dfs(nxt);
        }
    }
}

int main (){
    scanf("%d", &t);
    for(int z=0;z<t;z++){
        degr=0;
        scanf("%d", &n);
        for(int a=0;a<n;a++)
            adj[a].clear();
        for(int a=0;a<n;a++){
            mrk[a]=0;
            for(int b=0;b<n;b++){
                char aux;
                scanf(" %c", &aux);
                M[a][b]=aux-'0';
               //if(a==b)
                   // M[a][b]=0;
                if(M[a][b]==1){
                    adj[a].push_back(b);
                }
            }
        }
        for(int a=0;a<n;a++){
            cnt=0;
            dfs(a);
            if(cnt==n){
                res[degr++]=a+1;
            }
        }
        printf("%d\n", degr);
        for(int a=0;a<degr;a++){
            printf("%d\n", res[a]);
        }
    }
    return 0;
}

/*

1
7
1111101
0101100
0111111
0001101
0000101
1101111
0100001

2


1
3
100
111
101
3
110
011
101
7
1111101
0101100
0111111
0001101
0000101
1101111
0100001

*/
