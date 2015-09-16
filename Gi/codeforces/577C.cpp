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

int mark[1003];
int main() {
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 2; i <= n; i++) {
		if(mark[i]) continue;
		ans++;
		for(int j = i * i; j <= n; j *= i) {
			mark[j] = 2;
			ans++;
		}
		for(int j = i + i; j <= n; j += i) {
			if(mark[j]) continue;
			mark[j] = 1;
		}
	}
	printf("%d\n", ans);
	for(int i = 2; i <= n; i++) {
		if(mark[i] == 1) continue;
		printf("%d ", i);
	}
	putchar('\n');
	return 0;
}
