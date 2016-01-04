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

const int MAXN = 1000010;

int n, k, deg;

struct ev{
	int x, t;
} s[MAXN*2];

bool cmp(ev a,ev b){
	return (a.x < b.x || (a.x==b.x && a.t<b.t));
}

int main(){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		s[deg].x = i;
		s[deg++].t = 0;
		s[deg].x = j;
		s[deg++].t = 1;
	}
	sort(s,s+deg,cmp);
	int res = 0;
	int cnt = 0, is = 0;
	for(int a=0;a<deg;a++){
		int mrk = 0;
		if(s[a].t == 0)
			cnt++;
		else
			mrk = 1;

		while(a != deg-1 && s[a+1].x == s[a].x && s[a+1].t == 0){
			a++;
			cnt++;
		}

		if(cnt>= k && !is){
			is = 1;
			res++;
		}

		if(mrk == 1)
			cnt--;
		
		while(a != deg-1 && s[a+1].x == s[a].x && s[a+1].t == 1){
			a++;
			cnt--;
		}

		if(is && cnt <k){
			is = 0;
		}
	}
	printf("%d\n", res);
	cnt = is = 0;

	for(int a=0;a<deg;a++){
		int mrk = 0;
		if(s[a].t == 0)
			cnt++;
		else
			mrk = 1;

		while(a != deg-1 && s[a+1].x == s[a].x && s[a+1].t == 0){
			a++;
			cnt++;
		}

		if(cnt>= k && !is){
			printf("%d ", s[a].x);
			is = 1;
			res++;
		}

		if(mrk == 1)
			cnt--;
		
		while(a != deg-1 && s[a+1].x == s[a].x && s[a+1].t == 1){
			a++;
			cnt--;
		}

		if(is && cnt <k){
			printf("%d\n", s[a].x);
			is = 0;
		}
	}
}