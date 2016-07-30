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

const int MAXN = 112345;

int n, np;

int mrk[MAXN];

char t[MAXN];

stack <int> s[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %c", &t[a]);
		if(mrk[t[a]] == 0)
			np++;
		mrk[t[a]] = 1;
	}
	int i = 0;
	int j = -1;
	int m = 0;
	int res = INT_MAX;
	while(j < n){
		if(s[t[j+1]].empty())
			m++;
		s[t[j+1]].push(j+1);
		j++;
		while(s[t[i]].size() > 1){
			s[t[i]].pop();
			i++;
		}
		if(m == np){
			res = min(res, j-i+1);
		}
	}
	printf("%d\n", res);
}
