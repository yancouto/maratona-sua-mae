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

int n, dp[310], mrk[310];

int main (){
	scanf("%d", &n);
	mrk[1] = 0;
	mrk[2] = 0;
	dp[0] = 1;
	for(int i=1;i<n;i++){
		if(mrk[i]) continue;
		printf("nao pula %d\n", i);
		for(int a=3 x 00;a>=0;a--){
			if(dp[a] != 0){
				dp[a+i] = i;
				mrk[a+i] = 1;
				if(a+i == n){
					puts("win");
					while(i != 0){
						printf("%d\n", i);
						i = dp[a]
					}

				}
			}
		}
		if(mrk[n] == 1) break;
	}
	if(!mrk[n]) puts("lose");
	return 0;
}