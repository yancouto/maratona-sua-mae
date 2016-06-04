
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

const int MAXN = 1123456;

int n, degs, degv;

struct data{
	ll i, j;
	data(int ii, int jj){
		i = ii; j= jj;
	}
	data(){}
} s[MAXN], v[MAXN];

bool cmp(data a, data b){
	return a.i < b.i;
}

bool cmp2(data a, data b){
	return a.j > b.j;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		if(j - i > 0)
			s[degs++] = data(i, j);
		else
			v[degv++] = data(i, j);
	}
	sort(s, s+degs, cmp);
	sort(v, v+degv, cmp2);
	ll i = 0, j = 1000000000000100;
	while(i < j){
		ll k = (i+j)/2;
		ll cap = k;
		int fodeu = 0;
		for(int a=0;a<degs;a++){
			if(cap < s[a].i)
				fodeu = 1;
			cap += s[a].j - s[a].i;
		}
		for(int a=0;a<degv;a++){
			if(cap < v[a].i)
				fodeu = 1;
			cap += v[a].j - v[a].i;
		}
		if(fodeu) 
			i = k+1;
		else
			j = k;
	}
	printf("%lld\n", i);
}
