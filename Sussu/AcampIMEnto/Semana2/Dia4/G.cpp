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

const int MAXC = 111, INF = 0x3f3f3f3f;

int n, m, k, p;

int ind[30];

char s[MAXC];
int dp[MAXC];


ll fat[20];

inline int num(char c){
	return c - 'A';
}

int go(int i){
	if(i == n)
		return dp[i] = 0;
	if(dp[i] != INF)
		return dp[i];	
	

	int pod = (1<<27)-1;
	for(int a=i;a<=min(n-1, i + k-1);a++){
		int si = num(s[a]);
		if(pod & (1<<si)){
			pod &= ind[si];
			dp[i] = min(dp[i], go(a+1) + 1);
		}	
		else
			break;
	}
	return dp[i];
}

ll nw[MAXC];

ll rego(int i){
	if(i == n)
		return nw[i] = 1;

	if(nw[i] != 0)
		return nw[i];

	int pod = (1<<27)-1;
	for(int a=i;a<=min(n-1, i + k-1);a++){
		int si = num(s[a]);
		if(pod & (1<<si)){
			pod &= ind[si];
			if(dp[i] == dp[a+1] + 1){
				nw[i] = mod( nw[i] + rego(a+1) );
			}
		}	
		else
			break;
	}
	return nw[i];
}

ll expo(ll base, ll exp){
	if(exp == 0)
		return 1;
	ll ans = expo(base, exp/2);
	ans = mod(ans*ans);
	if(exp&1)
		ans = mod(ans * base);
	return ans;
}

ll nex[MAXC];

ll rerego(int i){
	if(i == n)
		return nex[i] = 1;

	if(nex[i] != 0)
		return nex[i];

	int pod = (1<<27)-1;
	for(int a=i;a<=min(n-1, i + k-1);a++){
		int si = num(s[a]);
		if(pod & (1<<si)){
			pod &= ind[si];
			if(dp[i] == dp[a+1] + 1){
				nex[i] = mod( nex[i] + mod(fat[k] * mod(expo(fat[ k - (a-i+1)], modn-2) * rerego(a+1) )));
				//printf("%lld %lld * %lld\n", nex[i], choose(k, a-i+1), rerego(a+1));
			}
		}	
		else
			break;
	}
//	printf("%d %lld\n", i, nex[i]);
	return nex[i];
}

int main (){
	fat[0] = 1;
	for(ll a=1;a<11;a++){
		fat[a] = mod(fat[a-1]*a);
	}
	scanf("%d%d%d%d", &n, &m, &k, &p);
	memset(dp, INF, sizeof(dp));
	memset(nw, 0, sizeof(nw));
	memset(nex, 0, sizeof(nex));
	for(int a=0;a<='Z'-'A';a++){
		ind[a] = 0;
	}
	for(int a=0;a<p;a++){
		char c1, c2;
		scanf(" %c%c", &c1, &c2);
		ind[c1 - 'A'] |= (1<<(c2-'A'));
		ind[c2 - 'A'] |= (1<<(c1-'A'));
	}
	for(int a=0;a<n;a++){
		scanf(" %c", &s[a]);
	}
	cout << go(0) << endl;
	cout << rego(0) << endl;
	cout << rerego(0)<< endl;
}
