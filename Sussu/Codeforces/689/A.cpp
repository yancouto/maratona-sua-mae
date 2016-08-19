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

pii p[11];

vector <pii> d;

map<pii, int> num;

bool valid(int i, int j){
	if(num.find(pii(i, j)) != num.end())
		return true;
	return false;
}

int main (){
	scanf("%d", &n);
	int cnt;
	cnt = 0;
	num[pii(3, 1)] = cnt;
	p[cnt].fst = 3;
	p[cnt++].snd = 1;
	for(int a=0;a<3;a++){
		for(int b=0;b<3;b++){
			num[pii(a, b)] = cnt;
			p[cnt].fst = a;
			p[cnt++].snd = b;
		}
	}
	int v = -1;
	int ult;
	for(int a=0;a<n;a++){
		ult = v;
		char c;
		scanf(" %c", &c);
		v = c - '0';
		if(ult != -1){
			d.pb(pii(p[v].fst - p[ult].fst, p[v].snd - p[ult].snd));
		}
	}
	int ans = 0;
	for(int a=0;a<4;a++){
		for(int b=0;b<3;b++){
			if(a == 3)
				b = 1;
			int i = a;
			int j = b;
			int foi = 1;
			for(pii m: d){
				if(!valid(i + m.fst, j + m.snd))
					foi = 0;
				i = i + m.fst;
				j = j + m.snd;
			}
			if(foi)
				ans++;
			if(a == 3)
				break;
		}
	}
	if(ans > 1)
		puts("NO");
	else
		puts("YES");
}
