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

map <int,bool> mrk;

long long t, va, vb, res;

long long gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

long long mmc(ll a,ll b){
	return (a*b)/gcd(a,b);
}

int main(){
	cin >> t;
	cin >> va;
	cin >> vb;
	if(va==vb){
		printf("1/1");
		return 0;
	}
	long long mult = 1, men = min(va,vb), mai = max(va,vb), vala,valb;
	res+=men-1;
	mult = mmc(va,vb);
	mrk[0]=1;
	vala=va;
	for(int a=1;;a++){
		valb=vb;
		mult = mmc(vala,valb);
		if(mult>t) break;
		for(int b=1;;b++){
			if(mrk.find(mult)==mrk.end()){
				mrk[mult]=1;
				res += men;
				if(mult == t){
					res-=men;
					res++;
				}
			}
			valb+=vb;
			mult=mmc(vala,valb);
			if(mult>t) break;
		}
		vala+=va;
	}
	ll divi = gcd(res,t);
	cout << res/divi;
	cout << "/";
	cout << t/divi;
	return 0;
}