
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


const int MAXN = 100010;

int n;

int s[MAXN], mrk[MAXN];
ll bit[MAXN];
map <int, pii> ind;

void upd(int i, ll v){
	while(i < MAXN){
		bit[i] += v;
		i += (i&-i);
	}
}

ll qry(int i){
	ll ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		upd(a, 1);
		if(ind.find(s[a]) == ind.end())
			ind[s[a]].fst = a;
		else
			ind[s[a]].snd = a;
	}
	ll res = 0;
	for(int a=1;a<=n;a++){
		if(mrk[a]) continue;
		res += qry(ind[s[a]].snd-1) - qry(ind[s[a]].fst);
		upd(ind[s[a]].snd, -1);
		mrk[ind[s[a]].snd] = 1;
	}
	printf("%lld\n", res);
}
