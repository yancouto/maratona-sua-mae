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

int m;
int main() {
	scanf("%d", &m);
	for(int k = 0; k < m; k++) {
		scanf(" %*s");
		for(int i=0;i<m;i++)
			for(int j=i+1;j<m;j++)
				printf("? %d %d\n",i+1,j+1);
		printf("! 1 2\n");
	}
}
