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

int n, m;

int s[MAXN];

struct arv{
	int v;
	unordered_map <int,int> mrk;
} tree[MAXN*4];

vector <arv> ans;

void printIt(std::unordered_map<int,int> m) {
	for(std::unordered_map<int,int>::iterator it=m.begin();it!=m.end();++it)
		std::cout << it->first<<":"<<it->second<<" ";
	std::cout << "\n";
}

inline void build(int idx, int i, int j){
	tree[idx].mrk.clear();
	if(i == j){
		tree[idx].mrk[s[i]]++;
		tree[idx].v = s[i];
		return;
	}

	int m = (i+j) >> 1;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	for(unordered_map<int,int>::iterator it = tree[idx*2].mrk.begin(); it != tree[idx*2].mrk.end(); ++it){
		tree[idx].mrk[it->fst] += it->snd;
	}
	for(unordered_map<int,int>::iterator it = tree[idx*2+1].mrk.begin(); it !=     tree[idx*2+1].mrk.end(); ++it){
		tree[idx].mrk[it->fst] += it->snd;
	}
	if(tree[idx].mrk[tree[idx*2].v] > tree[idx].mrk[tree[idx*2+1].v])
		tree[idx].v = tree[idx*2].v;
	else
		tree[idx].v = tree[idx*2+1].v;
	//	printf("build %d %d:\n   %d\n   ", i, j, tree[idx].v);
	//	printIt(tree[idx].mrk);

}

inline void upd(int idx, int i, int j, int l, int val){
	if(l > j || l < i) return ;
	//	printf("to em %d %d %d %d %d\n", idx, i, j, l, val);
	tree[idx].mrk[s[l]]--;

	if(i == j && i == l){
		tree[idx].mrk.clear();
		s[l] = val;
		tree[idx].mrk[s[l]]=1;
		tree[idx].v = s[l];
		//			printf("upd %d %d:\n   %d\n   ", i, j, tree[idx].v);
		//			printIt(tree[idx].mrk);
		return ;
	}
	int m = (i+j) >> 1;
	upd(idx*2, i, m, l, val);
	upd(idx*2+1, m+1, j, l, val);

	tree[idx].mrk[s[l]]++;
	if(tree[idx].mrk[tree[idx].v] < tree[idx].mrk[val])
		tree[idx].v = val;
	//	printf("upd %d %d:\n   %d\n   ", i, j, tree[idx].v);
	//	printIt(tree[idx].mrk);

}

inline void qry(int idx, int i, int j, int l, int r){
	//	printf("qry %d %d %d %d %d\n", idx, i, j, l, r);
	if( l > j || r < i)
		return ;
	if(i >= l  && j <= r){
		//	printf("achei %d %d %d %d\n", i, j, l, r);
		ans.pb(tree[idx]);
		return;
	}
	int m = (i +j) >> 1;
	qry(idx*2, i, m, l, r);
	qry(idx*2+1, m+1, j, l, r);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	build(1, 0, n-1);
	for(int a=0;a<m;a++){
		int t, i, j;
		scanf("%d %d %d", &t, &i, &j);
		if(t == 1){
			i--;
			upd(1, 0, n-1, i, j);
		}
		else{
			i--;
			j--;
			ans.clear();
			qry(1, 0, n-1, i, j);
			int fnd = 0;
			for(arv u: ans){
				int cnt = 0;
				for(arv v: ans){
					cnt += v.mrk[u.v];
				}
				if(cnt > (j-i+1)/2){
					fnd = 1;
					break;
				}
			}
			if(fnd)
				puts("Yes");
			else
				puts("No");
		}

	}
}
