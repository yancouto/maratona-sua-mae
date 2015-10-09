#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 100010;

int n, m, q;

vector <int> adj[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].push_back(j);
		adj[j].push_back(i);
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
	
		scanf("%d%d%d", &tip, &A, &B);
	
	}
	
}
