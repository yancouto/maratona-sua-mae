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
	ll h, w, i, j, a, b;
	a = b = 0;
	cin >> h >> w;
	for(i = 0; i <= w; i++)
		for(j = i + 2; j <= w; j++)
			if((j-i) % 2 == 0) a++;
	for(i = 0; i <= h; i++)
		for(j = i + 2; j <= h; j++)
			if((j-i) % 2 == 0) b += a;
	cout << b << "\n";
	return 0;
}
