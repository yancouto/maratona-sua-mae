#include <bits/stdc++.h>


using namespace std;

const int S = 27;

typedef long long int num;

char c;
int sta, len, mul, ade;
int n;

int main () {
	freopen("mahdi.in", "r", stdin);
	int t;
	scanf("%d", &t);

	for (int ts = 1; ts <= t; ts++) {
		vector<int> s[S];
		scanf(" %c %d %d %d", &c, &len, &mul, &ade);
		sta = c-'a';
		
		s[sta].push_back(0);
		for (int i = 1; i < len; i++) {
			sta = (num(sta)*num(mul) + num(i)*num(ade))%26;
			s[sta].push_back(i);
		}
		printf("Case %d:\n", ts);

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf(" %c %d %d %d", &c, &len, &mul, &ade);
			sta = c-'a';
			
			int ls = -1;
			int j = 0;
			for (j = 0; j < len; j++) {
				int pos = upper_bound(s[sta].begin(), s[sta].end(), ls) - s[sta].begin();

				if (pos >= s[sta].size())
					break;

				ls = s[sta][pos];

				sta = (sta*mul + (j+1)*ade)%26;
			}

			if (j < len)
				printf("REPEAT\n");
			else
				printf("BRAVO\n");
		}
	}
}
