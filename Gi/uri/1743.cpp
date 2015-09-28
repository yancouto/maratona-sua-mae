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
	int x[5], y[5];
	for(int i = 0; i < 5; i++) scanf("%d", &x[i]);
	for(int i = 0; i < 5; i++) scanf("%d", &y[i]);
	for(int i = 0; i < 5; i++)
		if(x[i] + y[i] != 1) { puts("N"); return 0; }
	puts("Y");
	return 0;
}
