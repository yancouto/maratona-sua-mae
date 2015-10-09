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

char mat[105][105];

int main() {
	int n; scanf("%d", &n);
	char s[10005];
	while(n--) {
		scanf("%s", s);
		int nn = strlen(s), ii = 0;
		int sqr;
		for(sqr = 1; sqr * sqr < nn; sqr++);
		for(int i = 0; i < sqr; i++)
			for(int j = 0; j < sqr; j++) {
				if(ii >= nn) { mat[i][j] = '*'; continue;}
				mat[i][j] = s[ii++];
			}
		for(int j = 0; j < sqr; j++)
			for(int i = sqr-1; i >= 0; i--) 
				if(mat[i][j] != '*') printf("%c", mat[i][j]);

		putchar('\n');
	}
	return 0;
}
