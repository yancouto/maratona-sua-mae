#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 510, MAXM = MAXN*MAXN;


int n, m, deg[MAXN], c[MAXN];

vector<int> adj[MAXN];

int cntb = 0, degb = n-1;
int dega = -1, degc = -1;
int cnta = 0, cntc = 0;
int fodeu = 0;

void go(int v){
    for(int a=0;a<adj[v].size();a++){
        int nxt = adj[v][a];
        if(c[nxt] != 0) continue;
        c[nxt] = c[v];
        if(deg[nxt] != deg[v]){
            puts("No");
            exit(0);
        }
        go(v);
    }
}

int main (){
    dega = -1, degc = -1;
    cnta = 0, cntc = 0;
    fodeu = 0;
    scanf("%d%d", &n, &m);
    cntb = 0, degb = n-1;
    for(int a=0;a<m;a++){
        int u, v;
        scanf("%d%d", &u, &v);
        deg[u]++;
        deg[v]++;
        adj[u].pb(v);
        adj[v].pb(u);
   }
    for(int a=1;a<=n;a++)
        if(deg[a] == degb)
            c[a] = 2;

    for(int a=1;a<=n;a++){
        if(c[a] == 1)
            cnta++;
        else if(c[a] == 2)
            cntb++;
        else if(c[a] == 3)
            cntc++;

        if(c[a] != 0) continue;

        if(dega == -1){
		    c[a] = 1;
            dega = deg[a];
            cnta++;
            go(a);
        }
        else if(degc == -1){
            c[a] = 3;          
            degc = deg[a];
            cntc++;
            go(a);
        }
        else{
            fodeu = 1;
            //printf("fodeu 1\n");
            break;
        }
    }
    if(cnta != 0 && dega != cnta-1 + cntb){
        fodeu = 1;
        //     printf("f2\n");
    }
    if(cntc != 0 && degc != cntc-1 + cntb){
        fodeu = 1;
    //    printf("f3\n");
    }
    if(fodeu || cnta + cntb + cntc != n){
        printf("No\n");
        return 0;
    }
    puts("Yes");
    for(int a=1;a<=n;a++){
        printf("%c", 'a'-1+c[a]);
    }    
    printf("\n");
}