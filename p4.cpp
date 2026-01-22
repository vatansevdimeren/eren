#include <string>
#include <vector>
#include <iostream>
using namespace std;
void getInputs(int a, vector<string> &names,vector<int> &notes);
double calculateAverage(const vector<int>& notes,int size);
void findBestStudent(const vector<int>& notes,const vector<string> &names);
void findWorstStudent(const vector<int>& notes, const vector<string>& names);
void printGrades(const vector<int>& notes, const vector<string>& names);
int main() {
	vector<string> names;
	vector<int>	notes;
	cout << "Please enter the number of students' ";
	int a;
	cin >> a;
	if (a <= 0) return 0;//oe.
	
	names.resize(a);
	notes.resize(a);
	cin.ignore();
	
	getInputs(a, names, notes);
	cout << "The avarage of the class is : " << calculateAverage(notes, a - 1) / notes.size() << endl;
	findBestStudent(notes, names);
	findWorstStudent(notes, names);
	printGrades(notes,names);

	

	return 0;
}
void getInputs(int a, vector<string>& names, vector<int>& notes) {
	for (int i = 0; a > i; i++) {
		cout << "Please enter name of student :";
		getline(cin, names[i]);
		cout << "Please enter name of student's notes :";
		cin >> notes[i];
		cin.ignore();
	}
}
double calculateAverage(const vector<int>& notes,int size) {
	if (size == 0) return notes[0];
	return notes[size] + calculateAverage(notes, size - 1);
}
void findBestStudent(const vector<int>& notes,const vector<string> &names) {
	int max = notes[0];
	int a=0;
	for (int i = 0; notes.size() > i; i++) {
		if (notes[i] > max) max = notes[i];
	}
	for (int i = 0; notes.size() > i; i++) {
		if (notes[i] == max) {
			a = i;
			break;
		}
	}
	cout << "The highest note in the class is " << max << "and name is " << names[a] << endl;
}
void findWorstStudent(const vector<int>& notes, const vector<string>& names) {
	int min = notes[0];
	int b = 0;
	for (int i = 0; notes.size() > i; i++) {
		if (min > notes[i]) {
			b = i;
			min = notes[i];
		}
	}
	cout << "The worst note in the class is " << min << "and it belongs to " << names[b] << endl;
}
void printGrades(const vector<int>& notes, const vector<string>& names) {
	for (int i = 0; notes.size() > i; i++) {
		cout << names[i] << ":" << notes[i] << endl;
	}
	cout << "<---These student's unfortunaltelly get very bad grades--->" << endl;
	for (int i = 0; notes.size() > i; i++) {
		if (notes[i] < 50) {
			cout << names[i] << endl;
		}
	}
}