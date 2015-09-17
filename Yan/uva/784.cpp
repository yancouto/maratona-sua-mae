// WA | TLE
#include <bits/stdc++.h>
using namespace std;

char dic[1002][20];
int ls[1002], ls2[1002];
char str[100], str2[100];
vector<char *> sz[25];
unordered_set<string> sts;
char *wws[50]; int wn;
char to[256];
char o[50];
int p[1002], ssz[1002];
bool has(int ww, int ndef) {
	char *w = wws[p[ww]];
	for(int i = 0; !i || w[i-1]; i++)
		o[i] = to[w[i]];
	return sts.count(o);
}

bool solve(int ww, int def) {
	if(ww == wn) return true;
	char *w = wws[p[ww]];
	int a = ssz[p[ww]], j;
	for(char *s : sz[a]) {
		int ndef = def;
		for(j = 0; j < a; j++) {
			if(((1 << (w[j] - 'a')) & ndef) && to[w[j]] != s[j]) break;
			to[w[j]] = s[j]; ndef |= 1 << (w[j] - 'a');
		}
		if(j < a) continue;
		for(j = ww + 1; j < wn; j++)
			if((ndef | ls2[p[j]]) == ndef && !has(j, ndef))
				break;
		if(j < wn) continue;
		if(solve(ww + 1, ndef))
			return true;
	}
	return false;
}

bool cmp_sz(int i, int j) {
	return ssz[i] > ssz[j];
}

int main() {
	int i, n, j;
	fgets(dic[0], 20, stdin);
	sscanf(dic[0], "%d", &n);
	for(i = 0; i < n; i++) {
		fgets(dic[i], 20, stdin);
		int a = strlen(dic[i]);
		dic[i][--a] = '\0';
		for(j = 0; j < a; j++) ls[i] |= 1 << (dic[i][j] - 'a');
		sts.insert(dic[i]);
		sz[a].push_back(dic[i]);
	}
	while(true) {
		fgets(str, sizeof str, stdin);
		if(feof(stdin)) break;
		strcpy(str2, str);
		char *w = strtok(str, " \n"); wn = 0;
		while(w) {
			p[wn] = wn;
			ssz[wn] = strlen(w);
			for(i = 0; w[i]; i++) ls2[wn] |= 1 << (w[i] - 'a');
			wws[wn++] = w;
			w = strtok(NULL, " \n");
		}
		sort(p, p + wn, cmp_sz);
		if(!solve(0, 0)) for(i = 'a'; i <= 'z'; i++) to[i] = '*';
		to[' '] = ' ';
		to['\n'] = '\n';
		for(i = 0; str2[i]; i++)
			putchar(to[str2[i]]);
	}
}
