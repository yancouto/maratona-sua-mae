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

const int MAXN = 500010;

int n1, n2;
ll b1, b2;
int s1[15], s2[15];

ll calcula(int n, ll b){
	ll pot = 1;
	ll ans=0;
	for(int a=0;a<n;a++){
		ans+=s1[a]*pot;
		pot*=b;
	}
	return ans;
}

int main (){
	scanf("%d", &n1);
	cin >> b1;
	for(int a=0;a<n1;a++){
		scanf("%d", &s1[n1-a-1]);
	}
	ll x1 = calcula(n1,b1);
	scanf("%d", &n2);
	cin >> b2;
	for(int a=0;a<n2;a++){
		scanf("%d", &s1[n2-a-1]);
	}
	ll x2 = calcula(n2,b2);
	if(x1< x2)
		printf("<\n");
	else if(x1>x2)
		printf(">\n");
	else
		printf("=\n");
}