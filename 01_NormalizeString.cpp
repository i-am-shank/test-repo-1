#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	string ans = "";
	int n = str.size();
	int s=0, e=(n-1);
	while(s<n && str[s]==' ') { // removing beginning spaces
		s++;
	}
	while(e>=0 && str[e]==' ') { // removing ending spaces
		e--;
	}
	for(int i=s; i<=e; i++) {
		bool hasSpaces=false;
		while(str[i]==' ' && i<=e) {
			i++;
			hasSpaces = true; // flagging to replace multiple spaces
		}
		if(hasSpaces == true) {
			ans += " ";
			i--; // as 1 extra character traversed while checking in above loop
		}
		else if((str[i]>='a' && str[i]<='z')  ||  (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9')) {
			ans += str[i];
		}
	}
	cout << ans << "\n";
	return 0;
}