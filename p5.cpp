#include <vector>
#include <iostream>
#include <string>
using namespace std;
struct Hardware {
	string ItemName;
	double price;
	string catogory;
};
void getInventory(vector<Hardware> &list,int size);
double calculateCategoryTotal(string targetcatogory,vector<Hardware> &list);
void findMostExpensive(vector<Hardware>& list);
void printShortageReport(vector<Hardware>& list, int price);
int main() {
	vector<Hardware> list;
	int size;
	
	cout << "Please enter the size of list whose hardware :";
	cin >> size;
	cin.ignore();
	
	if (size <= 0) return 0;//oe
	list.resize(size);
	
	getInventory(list, size);
	
	cout << "Please enter a catogory it needs to match";
	string temp1_catogry;
	getline(cin, temp1_catogry);
	cout << "The total money of the catogory is :" << calculateCategoryTotal(temp1_catogry, list) << endl;
	
	findMostExpensive(list);
	
	cout << "Please enter to enlist all item upper than ... price which you want to enter :";
	
	int price_0=0;
	cin >> price_0;
	cin.ignore();

	printShortageReport(list, price_0);

	return 0;
}
void getInventory(vector<Hardware>& list, int size) {
	for (int i = 0; size > i; i++) {
		cout << "Please enter name of Item :";
		getline(cin, list[i].ItemName);
		
		cout << "Please enter price of " << list[i].ItemName << " :";
		cin >> list[i].price;
		cin.ignore();

		cout << "Please enter catogory of " << list[i].ItemName << " :";
		getline(cin, list[i].catogory);

	}
}
double calculateCategoryTotal(string targetcatogory, vector<Hardware>& list) {
	double total = 0;
	for (int i = 0; list.size() > i; i++) {
		if (targetcatogory == list[i].catogory) {
			total += list[i].price;
		}
	}
	return total;
}
void findMostExpensive(vector<Hardware>& list) {
	double max = list[0].price;
	for (int i = 0; list.size() > i; i++) {
		if (max < list[i].price) max = list[i].price;
	}
	for (int i = 0; list.size() > i; i++) {
		if (max == list[i].price) {
			cout << "The most expensive item name is :" << list[i].ItemName << endl;
			cout << "The most expensive price of item is :" << list[i].price << endl;
			cout << "The most expensive catogory of the item is :" << list[i].catogory << endl;
			break;
		}
	}
}
void printShortageReport(vector<Hardware>& list, int price) {
	for (int i = 0; list.size() > i; i++) {
		if (list[i].price > price) {
			cout << "Item name :" << list[i].ItemName << endl;
			cout << "Price of item :" << list[i].price << endl;
			cout << "The catogort of the item :" << list[i].catogory << endl;
		}
	}
}