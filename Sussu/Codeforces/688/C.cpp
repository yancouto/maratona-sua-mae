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

const int MAXN = 112345;

int n, m, res, mrk[MAXN], c[MAXN];

vector <int> adj[MAXN];


int go(int v){
	mrk[v] = 1;
	for(int nxt: adj[v]){
		if(!mrk[nxt]){
			c[nxt] = 1 - c[v];
			go(nxt);
		}
		else{
			if(c[nxt] != 1-c[v]){
				res = 0;
			}
		}
	}
}

int main (){
	res = 1;
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	for(int a=1;a<=n;a++){
		if(!mrk[a]){
			c[a] = 1;
			go(a);
		}
	}
	if(res){
		int cnt = 0;
		for(int a=1;a<=n;a++){
			if(c[a] == 0)
				cnt++;
		}
		printf("%d\n", cnt);
		for(int a=1;a<=n;a++){
			if(c[a] == 0)
				printf("%d ", a);
		}
		cnt = 0;
		for(int a=1;a<=n;a++){
			if(c[a] == 1)
				cnt++;
		}
		printf("\n%d\n", cnt);
		for(int a=1;a<=n;a++){
			if(c[a] == 1)
				printf("%d ", a);
		}
	}
	else
		puts("-1");
}
