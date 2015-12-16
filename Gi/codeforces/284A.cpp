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

int main() {
	int p, i, j; 
	int v[2005];
	scanf("%d", &p);
	for(i = 0; i <= p; i++) v[i] = 1;
	for(i = 1; i < p - 1; i++) {
		for(j = 1; j < p; j++) {
			if(v[j] == -1) continue;
			v[j] = (v[j] * j) % p;
			if((v[j] - 1 + p) % p == 0) v[j] = -1;
		}
	}
	int ans = 0;
	for(j = 1; j < p; j++) {
		if(v[j] == -1) continue;
		if((v[j] * j - 1 + p) % p == 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
