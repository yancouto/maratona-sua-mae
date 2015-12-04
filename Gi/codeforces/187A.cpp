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
const int N = 200005;

int n;
int f[N], s[N], p[N];

int main() {
	int i;
	scanf("%d", &n);	
	for(i = 0; i < n; i++) scanf("%d", &f[i]);
	for(i = 0; i < n; i++) scanf("%d", &s[i]), p[s[i]] = i + 1;
	for(i = 0; i < n; i++) s[i] = p[f[i]];
	for(i = 1; i < n; i++)
		if(s[i] < s[i-1]) break;
	printf("%d\n", n - i);
	return 0;
}
