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

long long t, va, vb, res;

long long gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

long long mmc(ll a,ll b){
	return (a*b)/gcd(a,b);
}

int main(){
	long long tt;
	cin >> tt;
	cin >> va;
	cin >> vb;
	t=tt;
	if(va==vb || (t<va && t<vb)){
		printf("1/1");
		return 0;
	}
	long long mult, men = min(va,vb);
	res=men-1;
	t-=men;
	mult = mmc(va,vb);

	res += max(0LL,men*((t/mult) - 1));
	res += min(men,t%mult);

	ll divi = gcd(res,tt);
	cout << res/divi;
	cout << "/";
	cout << tt/divi;
	return 0;
}