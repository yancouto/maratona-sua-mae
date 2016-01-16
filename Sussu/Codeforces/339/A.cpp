#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

ull a, b, c;

int main (){
	cin >> b >> c >> a;
	ull l1 = ((long double)log(b)/(long double)log(a) + 0.5);
	ull l2 = ((long double)log(c)/(long double)log(a) + 0.01);
	ull val = 1;
	int ver = 0;
	for(int i=0;i<l1;i++){
		val*=a;
	}
	for(int i  = l1;i <= l2;i++){
		if(val >= b && val <= c){
			cout << val << " ";
			ver = 1;
		}
		val *= a;
	}
	if(ver==0)printf("-1");
	
}

/*
1 1000000000000000000 1000000000
1 1000000000000000000 999999999
1 1000000000000000000 999990990
2 1000000000000000000 500000000
1 999999999999999999 1000000000
*/