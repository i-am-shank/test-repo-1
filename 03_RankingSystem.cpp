#include <iostream>
#include <algorithm>
using namespace std;

class college {
public:
	string name;
	string location;
	int fees;
	int ranking;

	// constructor
	college(string name, string location, int fees, int ranking) {
		this.name = name;
		this.location = location;
		this.fees = fees;
		this.ranking = ranking;
	}
};

college* takeInputCollege() {
	string name, location;
	int fees, ranking;
	cin >> name >> location >> fees >> ranking;
	// using our constructor for initializing college-object below :
	college* currCollege = new college(name, location, fees, ranking);
	return currCollege;
}

int main() {
	// first take input college-list ----------
	int numColleges;
	cin >> numColleges;
	vector<college*> colleges;
	for(int i=0; i<numColleges; i++) {
		college* currCollege = takeInputCollege();
		colleges.push_back(currCollege);
	}

	// then take input user-preferences ----------
	string preferred_location;
	int max_fees, ranking_weight, fees_weight;
	cin >> preferred_location >> max_fees >> ranking_weight >> fees_weight;

	// remaining logic will be below

	return 0;
}