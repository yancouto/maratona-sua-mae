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
const int N = 201009;
int bit[N];
int get(int i) {
	int sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}
inline int get(int i, int j) { return get(j) - get(i - 1); }
void add(int i, int x) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] += x;
}

int main() {
	int i, n, x;
	scanf("%d", &n);
	for(i = 0; i < N; i++)
		bit[i] = (i & -i);
	int res = n;
	for(i = 0; i < n; i++) {
		scanf("%d", &x); x--;
		add(x, -1);
		if(get(0, x) && get(x, n - 1)) res--;
	}
	printf("%d\n", res);
}
