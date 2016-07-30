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

char d[212345];

int v[212345];

int main (){
	int i, j;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %c", &d[a]);
	}
	int ultr = -1;
	int res = INT_MAX;
	for(int a=0;a<n;a++){
		scanf("%d", &v[a]);
		if(d[a] == 'R')
			ultr = a;
		else{
			if(ultr == -1)
				continue;
			else
				res = min(res, (v[a] - v[ultr])/2);
		}
	}
	if(res == INT_MAX)
		res = -1;
	printf("%d\n", res);

}
