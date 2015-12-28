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

const int MAXN = 100010;

int dp[MAXN], n;

struct bea
{
	int x, p;
} s[MAXN];

bool cmp(bea a,bea b){
	return a.x<b.x;
}

inline int bb(int i,int f,int val){
	while(i<f){
		int m = (i+f+1)/2;
		if(s[m].x >= val) f = m-1;
		else i = m;
	}
	if(s[i].x >= val) return -1;
	return i;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d%d", &s[a].x, &s[a].p);
	}
	sort(s,s+n,cmp);
	dp[0]=0;
	for(int a=1;a<n;a++){
		int i = bb(0,a-1,s[a].x-s[a].p);
		if(i == -1) dp[a] = a;
		else{
			dp[a] = a-i-1 + dp[i];
		}
		//printf("%d %d\n", a, dp[a]);
	}
	int res  = dp[n-1];
	for(int a=n-1;a>0;a--){
		res = min(res,n-1-a+1 + dp[a-1]);
	}
	res = min(res,n);
	printf("%d\n", res);
}