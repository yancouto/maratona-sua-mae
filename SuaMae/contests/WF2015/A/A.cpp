
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

const double INF = 1000000;

int p,  n, a, b, c, d;

int main(){
	while(scanf("%d%d%d%d%d%d", &p, &a, &b, &c, &d, &n)!=EOF){
		double maxi=-INF, mini=INF, res=-INF;
		for(int i=1;i<=n;i++){
			double aux = double(p)*(sin((a*i)+b) + cos((c*i)+d) + 2);
			if(maxi<aux){
				maxi = aux;
				mini = aux;
			}
			if(mini > aux){
				mini = aux;
			}
			res = max(res,maxi-mini);
		}
		printf("%.15f\n", res);
	}
}

