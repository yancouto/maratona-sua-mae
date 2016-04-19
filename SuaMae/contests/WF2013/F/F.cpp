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
const int N = 1000006;

int n, k;
int v[N];

bool check(int d) {
	int i;
	ll lim = 0;
	for(i = 0; i < 2*n*k; i++) {
		if(i < 2*n*k - 1 && v[i+1] - v[i] <= d) 
			lim += (ll)2*k - 2, i++; 
		else lim--;
		if(lim < 0) return false;
	}
	return true;
}

int main() {
	int i;
	scanf("%d %d", &n, &k);
	for(i = 0; i < 2*n*k; i++)
		scanf("%d", &v[i]);
	sort(v, v + 2*n*k);
	int l = 0, r = 1000000000;
	while(l < r) {
		int m = (l + r) / 2;
		if(check(m)) r = m;
		else l = m + 1;
	}
	printf("%d\n", l);
	return 0;
}
