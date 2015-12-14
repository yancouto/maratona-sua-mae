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

int bit[5009];
int get(int i) {
	int sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}

void add(int i, int x) {
	for(i += 2; i < 5009; i += (i & -i))
		bit[i] += x;
}

int main() {
	int i, n, x;
	for_tests(t, tt) {
		scanf("%d", &n);
		memset(bit, 0, sizeof bit);
		int tot = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &x);
			tot += get(x);
			add(x, 1);
		}
		printf("%d\n", tot);
	}
}
