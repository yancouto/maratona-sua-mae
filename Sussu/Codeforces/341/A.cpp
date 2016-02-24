
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

int n;

ll som, val, mn = LLONG_MAX;

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		cin >> val;
		if(val%2 && val < mn) mn = val;
		som+=val;
	}
	if(som%2)
		cout << som - mn;
	else
		cout << som;
}
