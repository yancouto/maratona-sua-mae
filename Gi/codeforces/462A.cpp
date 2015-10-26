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

int main() {
	int n, i, j, sum;
	char t[105][105];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf(" %c", &t[i][j]);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			sum = (i > 0 && t[i-1][j] == 'o');
			sum += (i < n-1 && t[i+1][j] == 'o');
			sum += (j > 0 && t[i][j-1] == 'o');
			sum += (j < n-1 && t[i][j+1] == 'o');
			if(sum % 2) { puts("NO"); return 0; }
		}
	puts("YES");
	return 0;
}
