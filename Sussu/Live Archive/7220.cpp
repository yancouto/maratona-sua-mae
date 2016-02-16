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

const int INF = 0x3f3f3f3f, MAXN = 110;

int d[MAXN][MAXN][11], n, m;

char M[MAXN][MAXN];

set <piiii> s;

int vi[] = {0,0,1,-1};
int vj[] = {-1,1,0,0};

bool valid(int i,int j){
	return (i >= 0 && j >= 0 && i < n && j < m && M[i][j] != '0');
}

inline int num(char a){
	if(a == 'A' || a=='B') return 0;
	return a - '0';
} 

int main (){
	for_tests(t,tt){
		scanf("%d%d", &n, &m);
		int tot = 0;
		memset(d,INF,sizeof(d));
		int ai, aj, bi, bj;
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				scanf(" %c", &M[a][b]);
				if(M[a][b] == 'A'){
					ai = a;
					aj = b;
				}
				if(M[a][b] == 'B'){
					bi = a;
					bj = b;
				}
				tot += num(M[a][b]);
			}
		}
		d[bi][bj][0] = 0;
		s.insert(mp(0,mp(bi, mp(bj, 0))));

		while(!s.empty()){
			piiii top = *s.begin();
			s.erase(top);
			int i = top.snd.fst;
			int j = top.snd.snd.fst;
			int k = top.snd.snd.snd;
			if(M[i][j] == 'A') continue;
			for(int a=0;a<4;a++){
				int ii = i+vi[a], jj = j+vj[a], kk;
				if(valid(ii, jj)){
					kk = num(M[ii][jj]);
					if(d[ii][jj][max(k, kk)] <= d[i][j][k] + kk) continue;
					if(d[ii][jj][max(k, kk)] != INF) s.erase(mp(d[ii][jj][max(k, kk)], mp(ii, mp(jj, max(k, kk)))));
					d[ii][jj][max(k, kk)] = d[i][j][k] + kk;
					s.insert(mp(d[ii][jj][max(k, kk)], mp(ii, mp(jj, max(k, kk)))));
				}
			}
		}
		int res = INF;
		for(int a=1;a<=9;a++){
			res = min(d[ai][aj][a] - a, res);
		}
		printf("Case #%d: ", tt);
		if(res == INF-9) puts("0");
		else printf("%d\n", tot-res);
	}
}