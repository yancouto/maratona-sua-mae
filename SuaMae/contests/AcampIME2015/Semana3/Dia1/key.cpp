#include <bits/stdc++.h>

using namespace std;

const int N = 107;
const int ml[4] = {1, -1, 0, 0};
const int mc[4] = {0, 0, 1, -1};

#define mp make_pair
#define ff first
#define ss second

struct vert {
	int i, j;
	int keys, dist;
};

queue<vert> q;
vert aux, att;
int n, m;
int inil, inic;
int dist[N][N][18];
char mat[N][N];
bool found;

inline bool valPos(vert v) {
	if (v.i >= n || v.i < 0)
		return 0;
	if (v.j >= m || v.j < 0)
		return 0;
	if (mat[v.i][v.j] == '#')
		return 0;
	return 1;
}

inline bool hasKeys(vert v) {
	int key;
	char loc = mat[v.i][v.j];

	if (loc == 'B')
		key = 1;
	else if (loc == 'Y')
		key = 2;
	else if (loc == 'R')
		key = 4;
	else if (loc == 'G')
		key = 8;
	else key = 0;

	if ((key&(v.keys)) == key)
		return 1;
	return 0;
}

inline int getKeys(vert v) {
	int key;
	char loc = mat[v.i][v.j];

	if (loc == 'b')
		key = 1;
	else if (loc == 'y')
		key = 2;
	else if (loc == 'r')
		key = 4;
	else if (loc == 'g')
		key = 8;
	else key = 0;

	return (key|(v.keys));
}

inline bool isFinal(vert v) {
	if (mat[v.i][v.j] == 'X')
		return 1;
	return 0;
}

int main () {
	while (scanf("%d %d", &n, &m) != EOF && n && m) {
		for (int i = 0; i < n; i++) {
			scanf(" %s", mat+i);
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == '*') {
					inil = i;
					inic = j;
				}
				for (int k = 0; k < 18; k++)
					dist[i][j][k] = INT_MAX;
			}
		}

		while(!q.empty()) q.pop();
		att.i = inil;
		att.j = inic;
		att.keys = att.dist = 0;
		q.push(att);
		dist[inil][inic][0] = 0;

		found = 0;
		while (!q.empty() && !found) {
			att = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				aux.i = att.i + ml[k];
				aux.j = att.j + mc[k];
				aux.keys = att.keys;
				aux.dist = att.dist + 1;

				if (!valPos(aux) || !hasKeys(aux))
					continue;

				aux.keys = getKeys(aux);

				if (dist[aux.i][aux.j][aux.keys] <= aux.dist)
					continue;
				dist[aux.i][aux.j][aux.keys] = aux.dist;

				if (isFinal(aux)) {
					found = 1;
					break;
				}

				q.push(aux);
			}
		}

		if (found)
			printf("Escape possible in %d steps.\n", aux.dist);
		else
			printf("The poor student is trapped!\n");
	}
}
