#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, m, mrk[110];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		int num;
		scanf("%d", &num);
		for(int b=0;b<num;b++){
			int i;
			scanf("%d", &i);
			mrk[i] = 1;
		}
	}
	int ans = 1;
	for(int a = 1;a<=m;a++){
		ans = min(ans,mrk[a]);
	}
	if(ans)
		puts("YES");
	else
		puts("NO");
}