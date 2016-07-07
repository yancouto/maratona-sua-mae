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

vector <int> s;

int mrk[11], tem[11], tt;

bool digi(int r, int a, int b){
	tt++;
	while(r != 0){
		if(tem[r%10] != tt){
			tem[r%10] = tt;
			mrk[r%10] = 0;
		}
		mrk[r%10]++;
		r /= 10;
	}

	bool ans = true;
	while(a != 0){
		if(tem[a%10] != tt){
			tem[a%10] = tt;
			mrk[a%10] = 0;
		}
		mrk[a%10]--;
		a /= 10;
	}
	while(b != 0){
		if(tem[b%10] != tt){
			tem[b%10] = tt;
			mrk[b%10] = 0;
		}
		mrk[b%10]--;
		b /= 10;
	}
	for(int a=0;a<10;a++){
		if(tem[a] != tt){
			mrk[a] = 0;
			tem[a] = tt;
		}
		if(mrk[a] != 0)
			ans = false;
	}
	return ans;
}

inline int bb(int i, int j, int v){
	while(i < j){
		int m = (i + j)/2;
		if(s[m] < v)
			i = m+1;
		else
			j = m;
	}
}

int main (){
	tt = 1;
	for(int a = 1;a<=1000300;a++){
		for(int b = 1;ll(b)*ll(a)<=1000300ll;b++){
			if(digi(a*b, a, b)){
				s.pb(a*b);
				//if(a*b > 1000000)
				//	printf("%d = %d * %d\n", a*b, a, b);
			}
		}
	}
	unique(s.begin(), s.end());
	sort(s.begin(), s.end());
	while(scanf("%d", &n) != EOF && n != 0){
		printf("%d\n", s[bb(0, s.size()-1, n)]);
	}
}
