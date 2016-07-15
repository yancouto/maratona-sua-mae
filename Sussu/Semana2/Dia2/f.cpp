#include<cstdio>
#include<algorithm>

using namespace std;
const int MAX = 600;
const int INF = 1<<29;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};
int n, m, ni, nj, ui, uj, ti, tj, si, sj, cnt, head, tail, fi[MAX], fj[MAX], vis[MAX][MAX], d[MAX][MAX];
char t[MAX][MAX];

bool ok(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m && t[i][j] != '#';
}

int main(){
	scanf(" %d %d", &n, &m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf(" %c", &t[i][j]);
			if(t[i][j] == 'S'){ si = i; sj = j; }
			if(t[i][j] == 'T'){ ti = i; tj = j; }
			
			d[i][j] = INF;
			vis[i][j] = 0;
		}
	}
	
	head = tail = 0;
	d[si][sj] = 0;
	fi[tail] = si; fj[tail] = sj; tail++;
	while(head < tail){
		ui = fi[head]; uj = fj[head]; head++;
		vis[ui][uj] = 1;
		for(int k=0;k<4;k++){
			//aresta k
			cnt = 1;
			ni = ui+di[k]; nj = uj+dj[k];
			while(ok(ni, nj)){ ni += di[k]; nj += dj[k]; cnt++; }
			
			ni = ui + (cnt/2)*di[k]; nj = uj + (cnt/2)*dj[k];
			
			if(!vis[ni][nj]){
				vis[ni][nj] = 1;
				d[ni][nj] = d[ui][uj] + 1;
				fi[tail] = ni; fj[tail] = nj; tail++;
			}
		}
	}
	
	if(d[ti][tj] == INF) printf("-1\n");
	else printf("%d\n", d[ti][tj]);
	return 0;
}
