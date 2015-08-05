#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int n;
int v[4][15];
int memo[5000][6][300];

int solve(int mask, int code, int tme){
	 int &m = memo[mask][code][tme];
	 if(m != -1) return m;
	 int ans = 0;
	 for(int i = 0; i < n; i++){
		int k = 1<<i;
		if(mask&k) continue;
		for(int j = 1; j<=3; j++){
			 if(j == code) continue;
			 if(tme + v[j][i] > 280) continue;
			 ans = max(ans, 1 + solve(mask|k, j, tme+v[j][i]));
		}
	 }
	 return m = ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		memset(memo, -1, sizeof memo);
		scanf("%d", &n);
		for(int j = 1; j <= 3; j++)
			for(int i = 0; i < n; i++)
				scanf("%d", &v[j][i]);
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}
