#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 112345;

ll n, m;

int mrk[MAXN][3], nt[3];

pii s[MAXN];

int main (){
	cin >> n >> m;
	ll ans = n*n;
	for(int a=0;a<m;a++){
		cin >> s[a].fst >> s[a].snd;
		if(!mrk[s[a].fst][0]){
			mrk[s[a].fst][0] = 1;
			ans -= n - nt[1];
			nt[0]++;
		}
		if(!mrk[s[a].snd][1]){
			mrk[s[a].snd][1] = 1;
			ans -= n - nt[0];
			nt[1]++;
		}
		cout << ans;
		putchar(' ');
	}
}	
