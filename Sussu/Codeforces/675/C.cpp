
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

const int MAXN = 112345;


map <ll,ll> ind;

ll n, v[MAXN], s[MAXN];
int main (){
	cin >> n;
	for(int a=0;a<n;a++){
		cin >> s[a];
	}
	ll imai = 0, mai = 0;
	ll sum  = 0;
	ind[0]++;
	mai = 1;
	for(int a=1;a<n;a++){
		v[a] = sum+s[a];
		ind[v[a]]++;
		if(ind[v[a]] > mai){
			mai = ind[v[a]];
			imai = v[a];
		}
		sum = v[a];
	}
	ll pul = imai;
	cout << n-mai << endl;
}
