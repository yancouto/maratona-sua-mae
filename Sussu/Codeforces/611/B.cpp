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

ull i, j;

vector <ull> s;

void pre(){
	for(ull t = 1;t <= 62;t++){
		for(ull z = 0;z < t;z++){
			s.pb( (1ull << (t+1))-1 - (1ull << z) );
		}
	}
}

int main(){
	pre();
	ull res = 0;
	cin >> i >> j;
	for(int a=0;a<s.size();a++){
		if(s[a] >= i && s[a] <= j){
			res++;
		}
	}
	cout << res;
}