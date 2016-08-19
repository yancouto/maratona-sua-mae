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

const int MAXN = 412345;

int n, k;
ll fat[MAXN], dp[MAXN];

pii s[MAXN];

int val(int i, int j){
	int ans = 0;
	if(i == 0)
		ans++;
	if(j == 1)
		ans++;
	return ans;
}

ll expo(ll base, ll e){
	if(e == 0)
		return 1;
	ll ans = expo(base, e/2);
	ans = mod(ans*ans);
	if(e&1)
		ans = mod(ans*base);
	return ans;
}

ll choose(int i, int j){
	if(i < j) return 0;
	return mod(fat[i] * mod(expo(fat[j], modn-2) * expo(fat[i - j], modn-2)));
}

int main (){
	scanf("%d%d", &n, &k);
	fat[0] = 1;
	for(ll a=1;a<=n;a++){
		fat[a] = mod(fat[a-1]*a);
	}
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		s[a*2] = pii(i, 0);
		s[a*2+1] = pii(j, 1);
	}
	sort(s, s+2*n);
	int cnt = 0;
	int ult = 0;
	for(int a=0;a<2*n;a++){
	//	printf("%d cnt %d - %d -1 + %d\n", cnt, s[a].fst, s[a-1].fst, val(s[a-1].snd, s[a].snd));
		dp[cnt] += s[a].fst - 1 - s[a-1].fst + val(s[a-1].snd, s[a].snd);
		if(!s[a].snd)
			cnt++;
		else
			cnt--;
	}
	ll ans = 0;
	for(int a=1;a<=n;a++){
	//	printf("choose(%d, %d) %lld*%lld\n", a, k, choose(a, k), dp[a]);
		ans = mod(ans + mod(choose(a,k) * dp[a]));
	}
	cout << ans << endl;
}
