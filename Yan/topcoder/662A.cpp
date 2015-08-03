#include <cstdio>

struct Hexspeak {
	string decode(long long ciphertext);
}

string decode(long long ciphertext) {
	char str[130];
	sprintf(str, "%llx", ciphertext);
	for(int i = 0; str[i]; i++) {
		str[i] = toupper(str[i]);
		if(str[i] >= '2' && str[i] <= '9') return "Error!";
		if(str[i] == '0') str[i] = 'O';
		if(str[i] == '1') str[i] = 'I';
	}
	return str;
}
