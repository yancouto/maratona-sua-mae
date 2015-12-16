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
const int N = 100005;

int n, v[N];

int main() {
	int i, j, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
		scanf("%d", &x), v[x-1] = i;
	if(n == 1) { puts("0"); return 0; }
	int mm = 0, l = 0;
	for(i = 1; i < n; i++)
		if(v[i] < v[i-1]) {
			mm = max(mm, i - l);
			l = i;
		}
		else mm = max(mm, i - l + 1);
	printf("%d\n", n - mm);
	return 0;
}
