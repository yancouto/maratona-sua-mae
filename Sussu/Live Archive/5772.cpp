#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define exp epaodkaso

int n;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

ll exp[10][70];

ll v[80];

bool ehll(ll a, ll b){
	return log10(a) + log10(b) <= 18.;
}

void go(int i, int nn, int ult, ll val, int fl){
//	printf("de %d %d %d %lld %d\n", i, nn, ult, val, fl);
	if(i == 9) {
		if(nn < 152){
//			printf("seta %d com min(%lld %lld)\n", (nn+1-fl)/2, v[(nn+1-fl)/2], val);
			v[(nn+ 1-fl)/2] = min(v[(nn+1-fl)/2], val); 

		}
		return;
	}
	for(int e = 0;e <= ult && ehll(exp[i][e], val);e++){
		go(i+1, nn*(e+1), e, val * exp[i][e], max(fl, e&1)); 
	}
}

int main (){
	for(int i = 0;i<80;i++)
		v[i] = 1000000000000000001ll;
	for(int i=0;i<9;i++){
		ll val = 1;
		exp[i][0] = 1;
		int e = 1;
		for(e=1;ehll(val, p[i]);e++){
			val *= p[i];
			exp[i][e] = val;
		}	
		exp[i][e] = LLONG_MAX;

	}
	go(0, 1, 70, 1, 0);
	while(scanf("%d", &n) != EOF && n){
		printf("%lld\n", v[n]);
	}
}
