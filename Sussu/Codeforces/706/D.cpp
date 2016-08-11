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

const int MAXN = 412345*30 + 1000000;

int L[MAXN], R[MAXN], deg, sz[MAXN];

int n;

void add(int x){
	int p = 30;
	int v = 0;
	sz[v]++;
	while(p >= 0){
		if(x & (1<<p)){
			if(R[v] == -1)
				R[v] = deg++;
			v = R[v];
			sz[v]++;
		}
		else{
			if(L[v] == -1)
				L[v] = deg++;
			v = L[v];
			sz[v]++;
		}
		p--;
	}
}

void rmv(int v, int p, int x){
	sz[v]--;
	if(p == -1) return;
	if(x & (1<<p)){
		rmv(R[v], p-1, x);
		if(R[v] != -1 && sz[R[v]] == 0)
			R[v] = -1;
	}
	else{
		rmv(L[v], p-1, x);
		if(L[v] != -1 && sz[L[v]] == 0)
			L[v] = -1;
	}
}

int qry(int v, int p, int x){
	if(p == -1) return 0;
	int ans = 0;
	if(x & (1<<p)){
		if(L[v] != -1)
			ans = max(ans, (1<<p) + qry(L[v], p-1, x));
		else
			ans = max(ans, qry(R[v], p-1, x));
	}
	else{
		if(R[v] != -1)
			ans = max(ans, (1<<p) + qry(R[v], p-1, x));
		else
			ans = max(ans, qry(L[v], p-1, x));
	}
	return ans;
}

int main (){
	scanf("%d", &n);
	deg = 1;
	for(int a=0;a<MAXN;a++){
		L[a] = -1;
		R[a] = -1;
	}
	add(0);
	for(int a=0;a<n;a++){
		char c;
		int x;
		scanf(" %c %d", &c, &x);
		if(c == '+'){
			add(x);
		}
		else if(c == '-'){
			rmv(0, 30, x);
		}
		else{
			printf("%d\n", qry(0, 30, x));
		}
	}
}

