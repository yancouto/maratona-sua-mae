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

int a, in, f;

int main() {
	int n, i, j;
	char c;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf(" %c", &c);
		if(c == 'A') a++;
		else if(c == 'I') in++;
		else f++;
	}
	if(in == 1) printf("%d\n", in);
	else if(in) puts("0");
	else printf("%d\n", a);
	return 0;
}
