#include <bits/stdc++.h>
using namespace std;

// declaring shortcuts.. just to use later
#define ppp pair<int, pair<int,int>>
#define fi first
#define se second
#define mp make_pair

int main() {
	string question;
	getline(cin, question);

	// making array of strings of the 3 given questions
	// ignoring "?" , as it is common in all of them
	//    .. will not affect matching-criteria
	vector<string> quest1{"What", "is", "your", "name"};
	vector<string> quest2{"How", "can", "I", "help", "you"};
	vector<string> quest3{"What", "is", "the", "weather", "today"};

	// make a frequency map of words.. of the 3 questions
	//   .. based on which, will calculate the matching
	unordered_map<string,int> freq1, freq2, freq3;
	int n1=quest1.size(), n2=quest2.size(), n3=quest3.size();
	for(int i=0; i<n1; i++) {
		freq1[quest1[i]]++;
	}
	for(int i=0; i<n2; i++) {
		freq2[quest2[i]]++;
	}
	for(int i=0; i<n3; i++) {
		freq3[quest3[i]]++;
	}

	// now traverse input-question.. also doing matching simultaneously
	int n = question.size();
	int match1=0, match2=0, match3=0;
	int pseudoMatch1=0, pseudoMatch2=0, pseudoMatch3=0;
	string curr = "";
	for(int i=0; i<=n; i++) {
		// also iterating for nth time.. as it's possible that curr != "" in end
		// .. managing the edge case of i == n  ..  inside conditions of if-else below

		if(i<n && question[i] == ' ') {
			if(curr != "") {
				// matching with quest1 -------------
				if(freq1.find(curr) != freq1.end()) {
					// above condition checks if the word is present in quest1
					if(freq1[curr] > 0) {
						// an unmatched available frequency of this word <curr> is there
						match1++;
						freq1[curr]--;
					}
					else {
						pseudoMatch1++;
					}
				}

				// matching with quest2 -------------
				if(freq2.find(curr) != freq2.end()) {
					// above condition checks if the word is present in quest2
					if(freq2[curr] > 0) {
						// an unmatched available frequency of this word <curr> is there
						match2++;
						freq2[curr]--;
					}
					else {
						pseudoMatch2++;
					}
				}

				// matching with quest3 -------------
				if(freq3.find(curr) != freq3.end()) {
					// above condition checks if the word is present in quest3
					if(freq3[curr] > 0) {
						// an unmatched available frequency of this word <curr> is there
						match3++;
						freq3[curr]--;
					}
					else {
						pseudoMatch3++;
					}
				}

				// reset curr  ==>  as matching is done
				curr = "";
			}
		}
		else if(i<n) {
			curr += question[i];
		}
	}

	// make an array of match & pseudoMatch.. to sort them.. 
	// & get the max matching score
	vector<ppp> scores;
	scores.push_back(mp(match1, mp(pseudoMatch1, 1)));
	scores.push_back(mp(match2, mp(pseudoMatch2, 2)));
	scores.push_back(mp(match3, mp(pseudoMatch3, 3)));

	// had done below cout (commented now) .. just to debug the code (ignore)
	// cout << match1 << " " << match2 << " " << match3 << "\n";
	// cout << pseudoMatch1 << " " << pseudoMatch2 << " " << pseudoMatch3 << "\n";

	sort(scores.begin(), scores.end(), [](ppp score1, ppp score2) {
		if(score1.fi != score2.fi) {
			// greater match-score will be first
			return score1.fi > score2.fi;
		}
		else if(score1.se.fi != score2.se.fi) {
			// if match-score ties.. greater pseudoMatch-score will be first
			return score1.se.fi > score2.se.fi;
		}
		else {
			// if both match-score & pseudoMatch-score ties
			//  .. sort as per initial order .. i.e. 1st answer will be returned
			return score1.se.se < score2.se.se;
		}
	});

	// check .. which question has most matching
	//  .. will be at 0-index in above sorted array
	if(scores[0].se.se == 1) {
		// 1st answer
		cout << "My name is Chatbot." << "\n";
	}
	else if(scores[0].se.se == 2) {
		// 2nd answer
		cout << "I can assist you with your queries." << "\n";
	}
	else {
		// 3rd answer
		cout << "The weather is sunny." << "\n";
	}
	return 0;
}
