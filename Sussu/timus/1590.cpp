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

#define set asldjas

const int MAXN = 512345;

string s;

struct node{
	int l, r;
	int idx;
	node(){};
	node(int ll, int rr, int iidx){
		l = ll;
		r = rr;
		idx = iidx;
	}
	
	int sz(){
		return r - l + 1;
	}
} r, v[MAXN];

int p[MAXN], f[MAXN][30];

int deg;

int set(int l, int r, int pai){
	v[deg].l = l;
	v[deg].r = r;
	v[deg].idx = deg;
	p[deg] = pai;
	for(int a=0;a<30;a++){
		f[deg][a] = -1;
	}
	deg++;
	return deg-1; 
}

int go(int i){
//	printf("to em idx %d l %d r %d p %d\n", v[i].idx, v[i].l, v[i].r, v[p[v[i].idx]].idx); 
//	for(int a=v[i].l; a<=v[i].r;a++){
//		printf("%c", s[a]);
//	}
//	printf("\n");
	int ans = v[i].sz();
	for(int a=0;a<26;a++){
		if(f[i][a] != -1){
//			printf("%d ta ligado com %c de idx %d\n", i, a + 'a', f[i][a]);
			ans += go(f[i][a]);
		}
	}
	if(s[v[i].r]== '{')
		ans--;
//	printf("para idx %d ans %d\n", i, ans);
	return ans;
}

int main (){
	getline(cin, s);
	deg = 0;
	//suffix tree
	v[deg] = node(1, 0, 0);
	for(int a=0;a<30;a++){
		f[deg][a] = -1;
	}
	deg++;
	s += '{';
	int len = s.size();
	for(int i = 0;i < len;i++){
		int cn = 0;
		int ci = 0;
		for(int j = i;j < len;j++){
			if(ci == v[cn].sz() && f[cn][s[j]-'a'] == -1){
				int nw = set(j, len-1, cn);
			//	printf("fiz nw %d: ", nw);
			//	for(int a=v[nw].l;a<=v[nw].r;a++)
			//		printf("%c", s[a]);
			//	printf("\n");
			//	if(s[v[nw].l] != s[j])
			//		puts("*****FODEU4");
				f[cn][s[j]-'a'] = nw;
				break;
			}
			if(ci < v[cn].sz() && s[j] != s[v[cn].l+ci]){
				int mid = set(v[cn].l, v[cn].l + ci-1, p[cn]);
			//	printf("fiz mid %d de pai %d: ", mid, p[mid]);
			//	for(int a=v[mid].l;a<=v[mid].r;a++)
			//		printf("%c", s[a]);
			//	printf("\n");
				f[p[cn]][s[v[cn].l]-'a'] = mid;
			//	if(s[v[cn].l]  != s[v[mid].l])
			//		puts("*****FODEU3");

				int nw = set(j, len-1, mid);
			//	printf("fiz nw %d: ", nw);
			//	for(int a=v[nw].l;a<=v[nw].r;a++)
			//		printf("%c", s[a]);
			//	printf("\n");
				f[mid][s[j]-'a'] = nw;
			//	if(s[j] != s[v[nw].l])
			//		puts("*****FODEU2");
				v[cn].l += ci;
				p[cn] = mid;
				//printf("alterei cn %d: ", cn);
				//for(int a=v[cn].l;a<=v[cn].r;a++)
			//		printf("%c", s[a]);
			//	printf("\n");
			//	if(s[v[cn].l] != s[v[cn].l])
			//		puts("*****FODEU1");
				f[mid][s[v[cn].l]-'a'] = cn;

				break;
			}
			if(ci == v[cn].sz()){
				ci = 0;
				cn = f[v[cn].idx][s[j] - 'a'];
			}
			ci++;
		}
	}

	printf("%d\n", go(0));
}
