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
	int i, j;
	char m[5][5];
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			scanf(" %c", &m[i][j]);
	for(i = 0; i < 4-1; i++)
		for(j = 0; j < 4-1; j++) {
			int b = 0, w = 0;
			b += (m[i][j] == '.') + (m[i+1][j] == '.') + (m[i][j+1] == '.') + (m[i+1][j+1] == '.');
			w = 4 - b;
			if(b >= 3 || w >= 3) { puts("YES"); return 0; }
		}
	puts("NO");
	return 0;
}
