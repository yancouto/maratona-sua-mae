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

const int MAXN = 100010, MAXV = (1 << 21) + 5;

int n, m;

int pref[MAXN], k, cnt[MAXV], s[MAXN];

ll res[MAXN];

int sq;

struct qry{
	int i, j, c, ind;
	qry(){}
	qry(int ii, int jj, int indd){
		i = ii; j = jj; ind = indd;
		c = ii/sq;
	}
	bool operator < (const qry other) const{
		if(c != other.c)
			return c < other.c;
		return j < other.j;
	}
};

vector <qry> blocks;

ll result;

void add(int i){
	result += cnt[k^i];
	cnt[i]++;
}

void rmv(int i){
	cnt[i]--;
	result -= cnt[k^i];
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	sq = (int)sqrt(n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		pref[a+1] = pref[a] ^ s[a];
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		i-=2;j++;
		blocks.pb(qry(i, j, a));
	}
	result = 0ll;
	sort(blocks.begin(), blocks.end());
	int i = -1, j = 0;
	for(int a=0;a < blocks.size();a++){
		int ii = blocks[a].i, jj = blocks[a].j;
		while(j < jj){
			add(pref[j]);
			//printf("j dir %d->%d add %I64d\n", j, j+1, pref[j]);
			j++;
		}
		while(i > ii){
			add(pref[i]);
			//printf("i esq %d->%d add %I64d\n", i, i-1, pref[i]);
			i--;
		}
		while(j > jj){
			j--;
			//printf("j esq %d->%d rmv %I64d\n", j+1, j, pref[j]);
			rmv(pref[j]);
		}
		while(i < ii){
			i++;
			//printf("i dir %d->%d rmv %I64d\n", i-1, i, pref[i]);
			rmv(pref[i]);
		}
		//printf("para a qry %d temos cnt[0] %I64d cnt[1] %I64d, portanto res %I64d\n", blocks[a].ind, cnt[0], cnt[1], result);
		res[blocks[a].ind] = result;
	}
	for(int a=0;a<m;a++){
		cout << res[a];
		printf("\n");
	}
}
