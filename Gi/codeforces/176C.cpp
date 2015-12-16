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


int max(int a, int b) { if(a > b) return a; return b; }

int main() {
	int n, m, x1, y1, x2, y2;
	scanf("%d %d %d %d %d %d", &n, &m, &x1, &y1, &x2, &y2);
	if(max(abs(x1-x2), abs(y1-y2)) > 4 || abs(x1-x2) + abs(y1-y2) > 6) puts("Second");
	else puts("First");
	return 0;
}
