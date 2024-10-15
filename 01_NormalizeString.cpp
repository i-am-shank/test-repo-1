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

	// conversion to Camel case ------------

	// 1st converting 1st character
	if(ans.size() > 0) {
		if(ans[0]>='a' && ans[0]<='z') {
			// convert to capital
			ans[0] = ('A' + (ans[0]-'a'));
		}
	}
	// Then converting starting character of all words
	for(int i=1; i<(n-1); i++) {
		if(ans[i]==' '  &&  (ans[i+1]>='a' && ans[i+1]<='z')) {
			// (i+1) is the starting index of next word
			ans[i+1] = ('A' + (ans[i+1]-'a'));
		}
	}
	cout << ans << "\n";
	return 0;
}