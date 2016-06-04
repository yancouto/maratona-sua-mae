#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<int, piii> piiii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1000009;

int n, m, mrk[MAXN], ult[MAXN], ml[MAXN], mc[MAXN], tim[MAXN];

vector<int> l[MAXN], c[MAXN], val;

int dumb[MAXN], ultd[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		int **M = (int **) malloc((n+2)*sizeof(int *));
		for(int a=0;a<n;a++){
			M[a]  = (int *) malloc((m+2)*sizeof(int));
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				scanf("%d", &M[a][b]);
				if(!mrk[M[a][b]])
					val.pb(M[a][b]);
				mrk[M[a][b]] = 1;
				tim[M[a][b]] = -1;
				ml[M[a][b]] = 0;
				mc[M[a][b]] = 0;
			}
		}
		int res = 0;
		if( n * m <= 10000){
			for(int a=0;a<n;a++){
				for(int b=0;b<m;b++){
					for(int c=0;c<n;c++){
						if(ultd[M[c][b]] != a*n+b){
							ultd[M[c][b]] = a*n+b;
							mrk[M[c][b]] = 0;
						}
						mrk[M[c][b]]++;
					}
					for(int c=0;c<m;c++){
						if(ultd[M[a][c]] != a*n+b){
							ultd[M[a][c]] = a*n+b;
							mrk[M[a][c]] = 0;
						}
						mrk[M[a][c]]++;
						res = max(res, mrk[M[a][c]] - (M[a][b] == M[a][c]));
					}
				}
			}
			printf("%d\n", res);
			val.clear();
			for(int a=0;a<n;a++){
				delete [] M[a];
			}
			delete [] M;
			continue;
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				int v = M[a][b];
				if(tim[v] != 1){
					tim[v] = 1;
					ult[v] = -1;
				}
				if(ult[v] != a){
					ult[v] = a;
					mrk[v] = 0;
				}
				mrk[v]++;
				ml[v] = max(ml[v], mrk[v]);
			}
		}

		for(int b=0;b<m;b++){
			for(int a=0;a<n;a++){
				int v = M[a][b];
				if(tim[v] != 2){
					tim[v] = 2;
					ult[v] = -1;
				}
				if(ult[v] != b){
					ult[v] = b;
					mrk[v] = 0;
				}
				mrk[v]++;
				mc[v] = max(mc[v], mrk[v]);
				res = max(res, mc[v]+ml[v]);
			}
		}

		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				int v = M[a][b];
				if(tim[v] != 3){
					tim[v] = 3;
					ult[v] = -1;
				}
				if(ult[v] != a){
					ult[v] = a;
					mrk[v] = 0;
				}
				mrk[v]++;
				if(mrk[v] + mc[v] == res)
					l[v].pb(a);
			}
		}
		for(int b=0;b<m;b++){
			for(int a=0;a<n;a++){
				int v = M[a][b];
				if(tim[v] != 4){
					tim[v] = 4;
					ult[v] = -1;
				}
				if(ult[v] != b){
					ult[v] = b;
					mrk[v] = 0;
				}
				mrk[v]++;
				if(mrk[v] + ml[v] == res)
					c[v].pb(b);
			}
		}

		res--;
		int ver = 0;
		for(int v: val){
			if(l[v].empty() || c[v].empty()) continue;
			for(int a: l[v]){
				for(int b: c[v]){
					if(M[a][b] != v){
						res++;
						ver = 1;
						break;
					}
				}
				if(ver) break;
			}
			if(ver) break;
		}
		for(int v: val){
			l[v].clear();
			c[v].clear();
		}
		val.clear();
		printf("%d\n", res);
		for(int a=0;a<n;a++){
			delete [] M[a];
		}
		delete [] M;
	}
}
