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

int v[2000];

int main() {
	int n; scanf("%d", &n);
	int b, e;
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &b, &e);
		for(int j = b; j <= e; j++)
			v[j] = 1;
	}
	int sum = 0;
	for(int i = 1; i <= 180; i++)
		sum += v[i];
	for(int i = 181; i <= 1826; i++) {
		if(sum > 90) { puts("No"); return 0; }
		sum = sum - v[i-180] + v[i];
	}
	if(sum > 90) { puts("No"); return 0; }
	puts("Yes");
	return 0;
}
