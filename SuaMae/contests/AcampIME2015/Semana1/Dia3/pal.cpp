#include <cstdio>
#include <cstring>
#include <cstdlib>
char orig[20], str[20];
int d;

void cp() {
	for(int i = 0; i < d; i++)
		str[i] = orig[i];
}

bool check_pal() {
	for(int i = 0; i < (d/2); i++) {
		if(str[i] == 'x' || str[d-i-1] == 'x')
			continue;
		if(str[i] != str[d-i-1])
			return false;
	}
	return true;
}

void fix_pal() {
	for(int i = 0; i < (d/2); i++) {
		if(str[i] == 'x' && str[d-i-1] == 'x')
			str[i] = str[d-i-1] = '0';
		else if(str[i] == 'x')
			str[i] = str[d-i-1];
		else if(str[d-i-1] == 'x')
			str[d-i-1] = str[i];
	}
	if((d%2) && str[d/2] == 'x')
		str[d/2] = '0';
}

int try_up(int dig) {
	for(int i = dig + 1; i < d; i++)
		str[i] = 'x';
	while(str[dig] != '9') {
		str[dig]++;
		if(check_pal()) {
			fix_pal();
			str[d] = orig[d] = '\0';
			return atoi(str) - atoi(orig);
		}
	}
	return 0;
}

int solve() {
	int x;
	for(int i = d - 1; i >= 0; i--) {
		cp();
		if(x = try_up(i))
			return x;
	}
	return -1; //n acontece
}


int main() {
	while(true) {
		scanf(" %s", orig);
		if(orig[0] == '0' && orig[1] == '\0') return 0;
		d = strlen(orig);
		cp();
		if(check_pal()) { puts("0"); continue; }
		printf("%d\n", solve());
	}
}