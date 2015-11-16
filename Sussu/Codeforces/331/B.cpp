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

ll s[200020];
long long res, ant;

inline int abs(int v){
	if(v<0) return -v;
	return v;
}

int main (){
	int n;
	scanf("%d", &n);
	ant=0;
	for(int a=0;a<n;a++){
		
		cin >> s[a];
		res += abs(ant-s[a]);
		ant = s[a];
	}
	cout << res;
}