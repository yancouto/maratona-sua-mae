#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
const int N = 1000;
const int M = 100000;

char temp[5*N*N];
char name[N+7];
char c;
string str;
int k, par, n, m;
int deg[M+7];
vector<int> adj[M+7];
map<string, int> mp;
map<string, int>::iterator it;
ull memo[M+10][3];
int memo2[M+10][3];

ull min(ull a, ull b) {
	if(a < b) return a;
	return b;
}

ull solve(int no, int pai) {
	if(adj[no].empty()) return pai?n:0;
	ull &mem = memo[no][pai];
	if(mem != -1) return mem;
	ull sum1 = 0, sum2 = 0;
	if(pai) {
		for(int i = 0; i < adj[no].size(); i++) {
			sum1 += solve(adj[no][i], 1);
			sum2 += solve(adj[no][i], 0);
		}
		sum1 += n; sum2 += m;
	}
	else {
		for(int i = 0; i < adj[no].size(); i++) {
			sum1 += solve(adj[no][i], 1);
			sum2 += solve(adj[no][i], 0);
		}
		sum2 += m;
	}
	if(sum1 < sum2)
		memo2[no][pai] = 1;
	else
		memo2[no][pai] = 2;
	return mem = min(sum1, sum2);
}


int NS, NF;
void build(int no, int pai) {
	if(adj[no].empty()) {
		NS += pai;
		return;
	}
	if(memo2[no][pai] == 1) {if(pai) NS++;}
	else NF++;
	for(int i = 0; i < adj[no].size(); i++)
		if(memo2[no][pai] == 1) 
			build(adj[no][i], 1);
		else
			build(adj[no][i], 0);
	return;		
}
	
int main () {
	int count = 0;
	while (42) {
		count++;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) 
			break;
		
		k = 0;
		mp.clear();
		
		while (42) {
			memset(memo, -1, sizeof memo);
			scanf(" %c", &c);		

			par = -1;
			
			if (c >= '0' && c <= '9') {
				ungetc(c, stdin);
				break;
			} else {
				ungetc(c, stdin);
			}

			scanf(" %[a-z ]", temp);
			int len = strlen(temp);
			while(temp[len-1] == ' ')
				temp[--len] = '\0';
			int last = 0;
			for (int i = 0; !i || temp[i-1] != '\0'; i++) {
				if (temp[i] == ' ' || temp[i] == '\0') {
					for (int j = last; j < i; j++)
						name[j-last] = temp[j];
					name[i-last] = '\0';
					last = i+1;
					while(temp[last] == ' ') last++;
					i = last - 1;

					str = name;

					it = mp.find(str);
					if (it != mp.end()) {
						if (par == -1) {
							par = it->second;
						} else {
							adj[par].push_back(it->second);
							deg[it->second]++;
						}
					} else {
						deg[k] = 0;
						adj[k].clear();
						if (par == -1) {
							par = k;
						} else {
							adj[par].push_back(k);
							deg[k]++;
						}
						mp.insert(make_pair(str,k++));
					}
				}
			}
		}
		int ans=0;
		NS = NF = 0;
		for(int i = 0; i <= k+2; i++)
			memo[i][0] = memo[i][1] = -1;
		for(int i=0; i<k; i++)
			if(deg[i]==0) {
				ans += solve(i, 1);
				build(i, 1);
			}
		printf("%d. %d %d %d\n", count, NS, NF, ans);
	}
}
