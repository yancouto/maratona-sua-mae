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

const int MAXN = 41234;

string s, pal;

int r, deg;

struct node{
	int l, r;
	int p;
	int ans;
	int f[30];
	node(){
		for(int a=0;a<30;a++){
			f[a] = -1;
		}
		ans = 0;
	}
	node(int ll, int rr, int pp){
		l = ll;
		r = rr;
		p = pp;
		for(int a=0;a<30;a++){
			f[a] = -1;
		}
		ans = 0;
	}
	int len(){
		return r - l + 1;
	}
} v[MAXN*2];

int new_node(int l, int r, int p){
	v[deg++] = node(l, r, p);
	return deg-1;
}

void prints(int i){
	printf("i %d l %d r %d ", i, v[i].l, v[i].r);
	for(int a=v[i].l;a<=v[i].r;a++){
		printf("%c", s[a]);
	}
	printf(" p %d ans %d\n", v[i].p, v[i].ans); 
}

void build(){
	r = new_node(1, 0, 0);

	s += '{';

	int tam = s.size();

	int nd, ni;
	for(int i = 0; i < tam ; i++){
		nd = r;
		ni = 0;
		for(int j = i; j < tam ; j++){
			if(v[nd].len() == ni && v[nd].f[s[j]-'a'] == -1){
				int nw = new_node(j, tam-1, nd);
				v[nd].f[s[j]-'a'] = nw;

				v[nd].ans++;
				v[nw].ans++;
//				printf("do      - ");
//				prints(nd);
//				printf("appende - ");
//				prints(nw);
				break;
			}
			if(v[nd].len() != ni && s[j] != s[v[nd].l + ni]){
				int mid = new_node(v[nd].l, v[nd].l+ni-1, v[nd].p);
//				printf("separei - ");
//				prints(nd);
				v[v[nd].p].f[s[v[nd].l]-'a'] = mid;
				v[mid].ans = v[nd].ans + 1;
				
//				printf("para    - ");
//				prints(mid);
				
				v[nd].p = mid;
				v[nd].l += ni;
				v[mid].f[s[v[nd].l]-'a'] = nd;
//				printf("ligado c- ");
//				prints(nd);
				int nw = new_node(j, tam-1, mid);
				v[mid].f[s[j]-'a'] = nw;
				v[nw].ans++;
//				printf("e com   - ");
//				prints(nw);
				break;
			}
			if(v[nd].len() == ni){
				v[nd].ans++;
				nd = v[nd].f[s[j] - 'a'];
				ni = 0;
			}
			ni++;
		}
	}
}

int k, ans = 0;

map<pii, int> mrk;

int qry(int i, int j){
//	printf("qry %d %d\n", i, j);
	int nd = r;
	int ni = 0;
	for(int a=i;a<=j;a++){
		if(v[nd].len() == ni && v[nd].f[pal[a]-'a'] == -1){
			return 0;
		}
		if(v[nd].len() != ni && pal[a] != s[v[nd].l + ni]){
			return 0;
		}
		if(v[nd].len() == ni){
			nd = v[nd].f[pal[a] - 'a'];
//			printf("nd recebe %d que é a aresta da letra %c\n", nd, pal[a]);
			ni = 0;
		}
		if(!mrk[pii(nd, ni)]){
			mrk[pii(nd, ni)] = 1;
			ans += (v[nd].ans == k);
		}
		if( a == j ){
//			printf("aparece v[%d].ans  %d\n", nd, v[nd].ans);
			return v[nd].ans;
		}
		ni++;
	}
}

int main (){
	freopen("strings.in", "r", stdin);
	freopen("strings.out", "w", stdout);
	getline(cin, pal);
	getline(cin, s);
	scanf("%d", &k);
	build();
	int i=0, j=0;
	int tam = pal.size();
	while(i < tam && j < tam){
		while(qry(i, j) < k && i <= j)
			i++;
		j++;
	}
	i++;
	while(i < tam){
		qry(i, j-1);
		i++;
	}
	printf("%d\n", ans);
}
