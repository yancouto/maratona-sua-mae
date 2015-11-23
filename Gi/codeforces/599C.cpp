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
	int n, c, x, i;
	int h[100005], ih = 0;
	scanf("%d %d", &n, &c);
	for(i = 1; i < n; i++) {
		scanf("%d", &x);
		if(x >= c) { h[ih++] = c; c = x; }
		else 
			while(ih && h[ih-1] > x) 
				ih--;
	}
	printf("%d\n", ih + 1);
	return 0;
}
