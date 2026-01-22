#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int valuePeople = 0;
	double totalexpenses = 0;

	cout << "Please enter How many people are there :";
	cin >> valuePeople;

	if (valuePeople <= 0) return 0;//oe.

	vector<string> names(valuePeople);
	vector <double> expenses(valuePeople);

	for (int i = 0; valuePeople > i; i++) {
		cout << "please enter " << i + 1 << ". Person's name :";
		cin >> names[i];
		cout << "Please enter how much the person spent :";
		cin >> expenses[i];
		totalexpenses += expenses[i];
	}
	string flag_name = names[0];
	string flag_min_name=names[0];
	double max = expenses[0];
	double min = expenses[0];
	for (int i = 0; valuePeople > i; i++) {
		if (max < expenses[i]) {
			max = expenses[i];
			flag_name = names[i];
		}
		if (min > expenses[i]) {
			min = expenses[i];
			flag_min_name = names[i];
		}
	}
	cout << "Total money spent is equel to :" << totalexpenses << endl;
	cout << "The highest money spent by just one person's name is " << flag_name << endl;
	cout << "The minumum money spent by just one person's name is " << flag_min_name << endl;

	return 0;
}