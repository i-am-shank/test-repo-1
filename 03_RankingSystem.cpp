#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class college {
public:
	string name;
	string location;
	int fees;
	int ranking;
	float score = 0; // intially all will have 0 score

	// constructor
	college(string name, string location, int fees, int ranking) {
		this->name = name;
		this->location = location;
		this->fees = fees;
		this->ranking = ranking;

		// score not initialized in constructor
		//   .. as it will be assigned later (based on given formula)
	}
};

college* takeInputCollege() {
	string name, location;
	int fees, ranking;
	getline(cin, name);
	getline(cin, location);
	cin >> fees >> ranking;
	// also get past current line here.. 
	//   .. for taking input the next college
	string x;
	getline(cin, x);

	// using our constructor for initializing college-object below :
	college* currCollege = new college(name, location, fees, ranking);
	return currCollege;
}

int main() {
	// Print input-format (just for user-convenience)
	// As no strict input-format is given in problem-statement.
	cout << "Enter colleges in following format :\n";
	cout << "-->  First enter no. of colleges.\n";
	cout << "-->  Then enter name & location of each college in respective separate-lines.\n";
	cout << "-->  Also enter fees & ranking of the colleges before entering next college's details.\n";

	cout << "\n" << "After that enter the user-preferences, as per the order in problem statement.\n";
	cout << "-->  In this too, enter preferred_location in separate-line.\n";

	// first take input college-list ----------
	int numColleges;
	cin >> numColleges;
	string x; // dummy string just to get past current line
	getline(cin, x);
	vector<college*> colleges;
	for(int i=0; i<numColleges; i++) {
		college* currCollege = takeInputCollege();
		colleges.push_back(currCollege);
	}

	// then take input user-preferences ----------
	string preferred_location;
	getline(cin, preferred_location);
	int max_fees, ranking_weight, fees_weight;
	cin >> max_fees >> ranking_weight >> fees_weight;

	// remaining logic will be below

	// filter colleges based on preferred_location & max_fees
	// ----------------
	vector<college*> filteredColleges;
	for(int i=0; i<colleges.size(); i++) {
		if((colleges[i]->location == preferred_location) && (colleges[i]->fees<=max_fees)) {
			filteredColleges.push_back(colleges[i]);
		}
	}

	// assign a score to each college
	// ----------------
	for(int i=0; i<filteredColleges.size(); i++) {
		int ranking = filteredColleges[i]->ranking;
		int fees = filteredColleges[i]->fees;
		float score = ((ranking*ranking_weight)  +  (((float)fees/(float)max_fees) * fees_weight));
		filteredColleges[i]->score = score;
	}

	// sort colleges by score
	sort(filteredColleges.begin(), filteredColleges.end(), [](college* c1, college* c2) {
		// inside comparator-function
		//   ..  return that college first, which has lesser score
		return (c1->score <= c2->score);
	});

	// print colleges (as per given output-format)
	for(int i=0; i<filteredColleges.size(); i++) {
		cout << "Name: " << filteredColleges[i]->name << ", ";
		cout << "Location: " << filteredColleges[i]->location << ", ";
		cout << "Fees: " << filteredColleges[i]->fees << ", ";
		cout << "Ranking: " << filteredColleges[i]->ranking << ", ";
		cout << fixed << setprecision(2) << "Score: " << filteredColleges[i]->score << "\n";
	}
	return 0;
}