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
ull memo[12][40][40];

ull solve(int i, int si, int sf){
	if(i == n) return si == sf;
	ull &m = memo[i][si][sf];
	if(m != -1) return m;
	ull ans = 0;
	for(int k = 0; k <= 9; k++){
		if(i < n/2)
			ans += solve(i+1, si+k, sf);
		else
			ans += solve(i+1, si, sf+k);
	}
	return m = ans;
}

int main(){
	scanf("%d", &n);
	memset(memo, -1, sizeof memo);
	printf("%lld\n", solve(0, 0, 0));
	return 0;
}
