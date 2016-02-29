// Mo's

#include <cstdio>
#include <algorithm>
#include <iostream>

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

const int MAXN = 200800, BLOCK = 448, MAXV = 1000010;

int n, m;

int s[MAXN], cnt[MAXV], sq;
ll res[MAXN];

int L[MAXN], R[MAXN], ind[MAXN];

/*struct qry{
	int i, j, ind, c;
	qry(){}
	qry(int ii, int jj, int indd){
		i = ii; j = jj; ind = indd;
		c = ii/sq;
	}
	bool operator < (const qry other) const {
		if( c != other.c )
			return c < other.c;
		return j < other.j;
	}
};*/

//qry q[MAXN];

ll result;

inline void add(int v){
	result -= (ll)v*(ll)cnt[v]*(ll)cnt[v];
	++cnt[v];
	result += (ll)v*(ll)cnt[v]*(ll)cnt[v];
}

inline void rmv(int v){
	result -= (ll)v*(ll)cnt[v]*(ll)cnt[v];
	--cnt[v];
	result += (ll)v*(ll)cnt[v]*(ll)cnt[v];
}


inline bool cmp(int a,int b){
	if(L[a]/sq != L[b]/sq)
		return L[a]/sq < L[b]/sq;
	return R[a] < R[b];
}

int main (){

	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	sq = sqrt(n);
	
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		i-=2;
		L[a] = i;
		R[a] = j;
		//q[a] = qry(i, j, a);
		ind[a] = a;
	}

	//sort(q, q+m);
	sort(ind, ind+m, cmp);

	int i = -1, j = 0;
	for(int a = 0; a < m; a++){
		int ii = L[ind[a]];
		int jj = R[ind[a]];
		//printf("FAZENDO %d l %d r %d\n", v.ind, v.i, v.j);
		while(j < jj){
			add(s[j]);
			//printf("move j dir %d->%d, add %I64d\n", j, j+1, s[j]);
			++j;
		}
		while(j > jj){
			--j;
			rmv(s[j]);
			//printf("move j esq %d->%d, add %I64d\n", j+1, j, s[j]);
		}
		while(i < ii){
			++i;
			rmv(s[i]);
			//printf("move i dir %d->%d, rmv %I64d\n", i-1, i, s[i]);
		}
		while(i > ii){
			add(s[i]);
			//printf("move i esq %d->%d, add %I64d\n", i, i-1, s[i]);
			--i;
		}
		//printf("RESULT qry ind %d l %d r %d, res %I64d\n", v.ind, v.i, jj, result);
		//printf("cnt[1] = %I64d cnt[2] = %I64d\n\n", cnt[1], cnt[2]);
		res[ind[a]] = result;
	}
	
	for(int a=0;a<m;a++){
		//cout << res[a] << endl;
		printf("%I64d\n", res[a]);
	}
}