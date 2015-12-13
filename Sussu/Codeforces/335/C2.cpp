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

const int MAXN = 100010, INF = 0x3f3f3f3f;

int n, m, deg, s[MAXN], p[MAXN];

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		p[s[a]] = a;
	}
	int ult=-1, cnt =0, res=0;
	for(int a=1;a<=n;a++){
		if(p[a] > ult){
			cnt++;
			ult = p[a];
			res = max(cnt,res);
		}
		else{
			cnt = 1;
			ult = p[a];
		}
	}
	printf("%d\n", n-res);
	return 0;
}