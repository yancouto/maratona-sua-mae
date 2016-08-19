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

int n, m;

int main (){
	scanf("%d %d ", &m, &n);
	int ans = 0;
	int cnt = 0;
	for(int a=0;a<n;a++){
		int gan = 0;
		for(int b=0;b<m;b++){
			char c;
			scanf(" %c", &c);
			if(c == '0')
				gan = 1;
		}
		if(gan)
			cnt++;
		else
			cnt = 0;
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
}
