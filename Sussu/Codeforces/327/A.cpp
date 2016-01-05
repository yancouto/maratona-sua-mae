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

double l, a, b;

int main (){
	cin >> l;
	cin >> a;
	cin >> b;
	double s = (l/(a+b))*a;
	double t1 = s/a;
	double t2 = (l-s)/b;
	double s0a=0, s0b=0;
	if(t1 < t2){
		s0a = (t2-t1)*a;
	}
	else{
		s0b = (t1-t2)*b;
	}
	printf("%.15f", ((l - s0a - s0b)/(a+b))*a);
}