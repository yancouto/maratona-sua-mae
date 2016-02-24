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

int n;

char m[110][110];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			scanf(" %c", &m[a][b]);
		}
	}
	ll res = 0;
	for(int a=0;a<n;a++){
		ll cnt = 0;
		for(int b=0;b<n;b++){
			if( m[a][b] == 'C')
				cnt++;
		}
		res += (cnt*(cnt-1))/2;
	}
	for(int b=0;b<n;b++){
		ll cnt = 0;
		for(int a=0;a<n;a++){
			if( m[a][b] == 'C')
				cnt++;
		}
		res += (cnt*(cnt-1))/2;
	}
	cout << res;
}