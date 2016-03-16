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

#define INI 0
#define FIM 1

const int MAXN = 110;

struct even{
	int i, f, ind, t;
	even(){}
	even(int ii, int ff, int tt,int iind){
		i = ii;
		f = ff;
		t = tt;
		ind = iind;
	}
	bool operator < (even other) const{
		return ((i != other.i && i < other.i) || (i == other.i && f < other.f));
	}
} s[MAXN];

int mrk[MAXN], n;

set <pii> fil;

bool go(int k){
	memset(mrk, 0, sizeof(mrk));
	fil.clear();
	int ult = -1, ulti = -1;
	int ver = 1;
	for(int a=0;a<2*n;a++){
		if(ult != -1) mrk[ult] += min(s[a].i - ulti, k-mrk[ult]);
		int sobra = 0;
		if(ult != -1) sobra = (s[a].i-ulti > k-mrk[ult])*(s[a].i-ulti - (k-mrk[ult]));
		if(sobra) fil.erase(fil.begin());
		while(sobra && !fil.empty()){
			ulti += k-mrk[ult];
			ult = (*fil.begin()).snd;
			mrk[ult] += min(s[a].i - ulti, k-mrk[ult]);
			sobra = (s[a].i-ulti > k-mrk[ult])*(s[a].i-ulti - (k-mrk[ult]));
			fil.erase(fil.begin());
		}
		if(s[a].t == INI) fil.insert(pii(s[a].f, s[a].ind));
		while((*fil.begin()).fst <= s[a].i){
			if(mrk[(*fil.begin()).snd] < k){
				ver = 0;
				printf("fodeu o %d mrk %d k %d\n", (*fil.begin()).snd, mrk[(*fil.begin()).snd], k);
			}
			fil.erase(fil.begin());
		} 
		ult = fil.begin()->snd;
		ulti = s[a].i;
	}
	return ver;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int i, f;
		scanf("%d%d", &i, &f);
		s[a*2] = even(i, f, INI, a);
		s[a*2+1] = even(f, f, FIM, a);
	}
	sort(s, s+2*n);
	int i = 0, j = 10001;
	while(i < j){
		printf("BB %d %d\n", i, j);
		int m = (i+j+1)/2;
		printf("%d %d\n", m, go(m));
		if(go(m))
			i = m;
		else
			j = m-1;
	}
	printf("%d\n", i);
}