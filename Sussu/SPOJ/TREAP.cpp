
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

const int MAXN = 2000010;

struct arv{
	int x, y;
	int l, r, p;
	int mn, mx;
	arv(){};
	arv(int xx){
		x = xx;
		y = rand();
		p = 0;
		l = 0;
		r = 0;
	};
} tree[MAXN];