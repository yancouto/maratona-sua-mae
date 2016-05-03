
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


int bit[2][55][112345];

inline int qry(int t, int c, int i){
	int ans = 0;
	while(i > 0){
		ans += bit[t][c][i]
		i -= (i&-i);
	}
	return ans;
}

inline void upd(int t, int c, int i, int val){
	while(i < 112345){
		bit[t][c][i] += val;
		i += (i&-i);
	}
}

inline void limpa(int t,int i){
	for(int c=0;c<51;c++){
		int s = qry(t, c, i) - qry(t, c, i-1);
		if(s == 0) continue;
		upd(t, c, i, -s);
		int s2 = qry((t&1) + 1, c, n);
		 
	}

}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int t, i, j, r;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d%d", &i, &r);
			limpa(1, i);
			upd(1, r, i, n);
		}
	}

}
