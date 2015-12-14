#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

void makeblock(int i, char m[102], char c[102], vector< vector<int> > prec[2]){
	for(char s='a'; s<='z'; s++) {
		bool f = false;
		int count=0, count2=0;
		for(int j=i; j<i+k; j++) {
			if (m[j]==s) {
				if(!f){
					prec[0].push_back(vector<int>());
					f=true;
				}
				prec[0].back().push_back(j);
				count++;
			}
		}
		f=false;
		for(int j=i; j<i+k; j++){
			if(c[j]==s {
				if(!f){
					prec[1].push_back(vector<int>());
					f=true;
				}
				prec[1].back().push_back(j);
			}
		}
	}
}

void go(int k, int tam, char m[102], char c[102],  vector< vector<int> > pfim[2], vector< vector<int> > prec[2]) {
	vectorM vector<int> > prec2[2];
	for(int i=0; i<m; i+=k){
		makeblock(i, m, c, prec);
		int seen[102];
		memset(seen, 0, sizeof seen);
		for(int j=0; prec[0].size(); j++){
			for(int jj=0; jj<prec[0].size(); jj++) {
				int x=prec[0][j][jj];
				if(seen[x]) continue;
				vector< pair<int,int> > pp;	
				for(int g=0; g<pfim[0].size(); g++) {
					auto beg=pfim[0][g].begin();
					auto en=pfim[0][g].end();
					if(binary_search(beg, en, x)){
						for(int y=0; y<prec[0][j].size(); y++) {
							auto it=lower_bound(beg, en, x)
							if(it!=en && *it==x && !seen[x]){
								if(pfim[1][g][it-beg]==prec[1][j][y]) 
									pp.push_back(pair(it-beg, y));
								else
									return 0;
								seen[x]=1;
							}
						}
					}
				}
				prec2[0].push_back(vector<int>());
				prec2[1].push_back(vector<int>());
				for(int p=0; p<pp.size(); p++){
					prec2[0].back().push_back(pp[p].second);
					prec2[1].back().push_back(prec[1][j][pp[p].second]);
				}
				pp.clear();
			}
		}
		prec.clear();
	}
}


int main () {
	int k, tam;
	char m[102], c[102];
	vector< vector<int> > pfim[2], prec[2];
	while(scanf("%d %s %s", &k, m, c)) {
		tam=strlen(m);
		makeblock(0, m, m, pfim);
		printf("%ull\n",go(k, tam, m, c, pfim, prec));
		prec.clear();
		pfim.clear();
	}
	return 0;
}