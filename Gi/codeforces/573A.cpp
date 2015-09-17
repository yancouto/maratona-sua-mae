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

int div(int x) {
	while(x % 2 == 0) x /= 2;
	while(x % 3 == 0) x /= 3;
	return x;
}

int main() {
	int n; scanf("%d", &n);
	int a; scanf("%d", &a);
	int d = div(a);
	bool yes = true;
	for(int i = 1; i < n; i++) {
		scanf("%d", &a);
		if(div(a) != d) yes = false;
	}
	if(yes) puts("Yes");
	else puts("No");
	return 0;
}
