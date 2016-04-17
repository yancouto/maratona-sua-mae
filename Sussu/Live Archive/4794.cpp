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

const int Maxn = 20;

int n, x, y, s[Maxn];

bool cmp(int a, int b){
	return (a <= x && b <= y) || (b <= x && a <= y);
}

int main (){
	int tt = 0;
	while(1){
		tt++;
		scanf("%d", &n);
		if(n == 0) break;
		scanf("%d%d", &x, &y);
		int sum = 0;
		int ver = 1;
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			sum += s[a];
			int deu = 0;
			for(int b=1;b<=s[a];b++){
				//printf("testa %d %d\n", b, s[a]/b);
				if(s[a]%b == 0 && cmp(b, s[a]/b)){
					deu = 1;
					//printf("deu\n");
					break;
				}
			}
			ver = min(ver, deu);
		}
		//printf("%d  %d == %d\n", ver, sum, x*y);
		if(ver && sum == x*y)
			printf("Case %d: Yes\n", tt);
		else
			printf("Case %d: No\n", tt);

	}
}