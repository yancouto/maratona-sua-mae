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
const int N = 200010;

int sum[N];

int main() {
	int i;
	ll ans = 0;
	char a[N], b[N];
	scanf("%s %s", a, b);
	int na = strlen(a);
	int nb = strlen(b);
	for(i = 0; i < nb; i++) 
		sum[i] = (i?sum[i-1]:0) + b[i] - '0';
	for(i = 0; i < na; i++) {
		int end = nb - na + i;
		if(a[i] == '0')
			ans += sum[end] - (i?sum[i-1]:0);
		else 
			ans += end - i + 1 - (sum[end] - (i?sum[i-1]:0));
	}
	cout << ans << '\n';
	return 0;

}
