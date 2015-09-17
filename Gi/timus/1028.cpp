#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#define oo 1000000000

int level[15005], bit[32005];
int n;

void update(int pos) {
	for(int i = pos; i < 32005; i += (i & -i))
		bit[i]++;
}

int get(int pos) {
	int ret;
	for(int i = pos; i > 0; i -= (i & -i))
		ret += bit[i];
	return ret;
}

int main() {
	int x, y; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		x++; y++;
		level[get(x)]++;
		update(x);
	}
	for(int i = 0; i < n; i++)
		printf("%d\n", level[i]);
	return 0;
}
