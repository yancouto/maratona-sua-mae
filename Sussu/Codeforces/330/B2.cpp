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

ll n, k, d[MAXN], dig[MAXN], res[MAXN], ans;


ll exp(ll val, ll expo){
	ll aux = 1;
	while(expo){
		aux *= val;
		expo--;
	}
	return aux;
}

int main (){
	cin >> n >> k;
	for(int a=0;a<n/k;a++){
		cin >> d[a];
	}
	for(int a=0;a<n/k;a++){
		cin >> dig[a];
	}
	ans = 1;
	for(int a=0;a<n/k;a++){
		res[a] += (exp(10,k)-1)/d[a] + 1;
		res[a] -= ((dig[a]+1)*exp(10,k-1)-1)/d[a] + 1;
		if(dig[a]>0){
			res[a] += (dig[a]*exp(10,k-1)-1)/d[a] + 1;
		}
		ans= mod(ans*res[a]);
	}
	cout << ans;
}