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

int n, m, tab;
char dic[1005][20], *txt[1005];
vector<int> szd[20];
int dt[100], td[100];

struct Word {
	int ind, sz;
};
Word woord[100];

bool solve(int ww, int mdic, int mtxt) {
	if(ww == m) return true;
	int w = woord[ww].ind;
	int sz = strlen(txt[w]);
	for(int i = 0; i < szd[sz].size(); i++) {
		int d = szd[sz][i];
		bool can = true;
		int m1 = mdic, m2 = mtxt;
		for(int j = 0; j < sz && can; j++) {
			if(m1 & (1 << (dic[d][j]-'a')) && dt[dic[d][j]-'a'] != txt[w][j]) { 
				can = false;
				break;
			}
			dt[dic[d][j]-'a'] = txt[w][j];
			m1 |= (1 << (dic[d][j]-'a'));
			if(m2 & (1 << (txt[w][j]-'a')) && td[txt[w][j]-'a'] != dic[d][j]) { 
				can = false;
				break;
			}	
			td[txt[w][j]-'a'] = dic[d][j];
			m2 |= (1 << (txt[w][j]-'a'));
		}
		if(can && solve(ww + 1, m1, m2)) return true;
	}
	return false;
}

bool cmp(Word a, Word b) {
	 return a.sz < b.sz;
}

int main() {
	char input[100], word[100], in2[100];
	fgets(input, 100, stdin);
	sscanf(input, "%d", &n);
	for(int i = 0; i < n; i++) {
		fgets(input, 100, stdin);
		sscanf(input, "%s", dic[i]);
		szd[strlen(dic[i])].pb(i);		
	}
	while(42) {
		fgets(input, 100, stdin);
		if(feof(stdin)) break;
		m = 0;
		input[strlen(input)-1] = '\0';
		strcpy(in2, input);
		char *ptr = strtok(input, " ");
		while(ptr != NULL) {
			txt[m] = ptr;
			woord[m].ind = m;
			woord[m].sz = strlen(ptr);
			ptr = strtok(NULL, " ");
			m++;
		}
		sort(woord, woord + m, cmp);	
		int nn = strlen(in2);
		if(solve(0, 0, 0)) {
			for(int i = 0; i < nn; i++) {
				if(in2[i] == ' ') printf(" ");
				else printf("%c", td[in2[i]-'a']);
			}
		}
		else {
			for(int i = 0; i < nn; i++) {
				if(in2[i] == ' ') printf(" ");
				else printf("*");
			}
		}
		putchar('\n');
	}
	return 0;
}
