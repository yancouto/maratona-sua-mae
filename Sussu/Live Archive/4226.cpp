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

const int MAXN = 1123;

int n, k;


int t[MAXN], p[MAXN];

vector <int> adj[MAXN];

queue <int> q;

int mrk[MAXN];

pii sum(pii a, pii other){
	return pii(a.fst + other.fst, a.snd + other.snd);
}

pii go(int v){
	mrk[v] = 1;
	pii res = pii(1, t[v]);
	for(int nxt: adj[v]){
		if(mrk[nxt]) continue;
		res = sum(res, go(nxt));
	}
	return res;
}

int main (){
	while(scanf("%d%d", &n, &k)!=EOF && n+k!=0){
		for(int a=0;a<n;a++){
			int m;
			adj[a].clear();
			mrk[a] = 0;
			scanf("%d %d", &t[a], &m);
			p[a] = t[a];
			for(int b=0;b<m;b++){
				int j;
				scanf("%d", &j);
				adj[a].pb(j);
			}
		}
		for(int a=0;a<n;a++){
			for(int nxt: adj[a]){
				p[a] += t[nxt];
			}
			if(p[a] < k){
				q.push(a);
				mrk[a] = 1;
			}
		}
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(int nxt: adj[v]){
				if(mrk[nxt]) continue;
				p[nxt] -= t[v];
				if(p[nxt] < k){
					q.push(nxt);
					mrk[nxt] = 1;
				}
			}
		}
		pii res = pii(0, 0);
		for(int a=0;a<n;a++){
			if(!mrk[a])
				res = sum(res, go(a));
		}
		printf("%d %d\n", res.fst, res.snd);
	}
}
