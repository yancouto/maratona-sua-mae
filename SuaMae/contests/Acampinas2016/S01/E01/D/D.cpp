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


long double h1, t1, h2, t2;

int main(){
	scanf("%Lf %Lf %Lf %Lf", &h1, &t1, &h2, &t2);
	long double del = (-2*h2*t1 + 2*t2*h1)*(-2*h2*t1 + 2*t2*h1) - 4*(h2-h1)*(h2*t1*t1 - h1*t2*t2);
	long double ans = (-(-2*h2*t1 + 2*h1*t2) + (long double)sqrt(del))/(2*(h2-h1));
	long double ans2 = (-(-2*h2*t1 + 2*h1*t2) - (long double)sqrt(del))/(2*(h2-h1));
	long double men = min(ans,ans2), mai = max(ans,ans2);
	if(men < 0.) swap(men,mai);
	cout << setprecision(20) << men <<  "\n";
	//printf("%.15lf\n", ans);
}
