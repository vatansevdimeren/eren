#include <iostream>
#include <vector>
using namespace std;
class Book {
private:
	string nameofbook;
	string author;
	bool available;
public:
	Book(string name, string aut) {
		nameofbook = name;
		author = aut;
		available = true;
	}
	string  getnameofbook() {
		return nameofbook;
	}
	string getauthor() {
		return author;
	}
	bool getavaiable() {
		return available;
	}
	bool  barrow() {
		available = false;
	}
	void iadeet() {
		available = true;
	}

};
int Fmenü();
int main() {
	vector<Book> library;
	int secim = Fmenü();
	switch (secim) {
	case 1: {
			string temp_name, temp_author;
			cout << "to quit please write no or NO" << endl;
			cout << "please enter the name of the book :" << endl;
			cin >> temp_name;
			if (temp_name == "no" || temp_name == "NO")break;
			cout << "please enter the name of author :" << endl;
			cin >> temp_author;
			Book newbook(temp_name, temp_author);
			library.push_back(newbook);
			break;
		}
		case 2:
			for (int i = 0; library.size() > i; i++) {
				cout << "name of the book is " << library[i].getnameofbook() << "author of the book is " << library[i].getauthor() <<"its situation is " <<library[i].getavaiable() <<endl;
			}
			break;
		case 3:
			{
			string temp_aranan_name_of_book;
			cout << "please enter the name of the book which you search  to barraw :" << endl;
			cin >> temp_aranan_name_of_book;
			int flag = 0;
			int a = 0;
			for (int i = 0; library.size() > i; i++) {
				if (temp_aranan_name_of_book == library[i].getnameofbook()) {
					flag = 1;
					a = i;
					break;
				}
			}
			if (flag != 0) {
				cout << "the book is here so you can barrow it." << endl;
				library[a].barrow();
				cout << "the process is succesfull." << endl;

			}
			else {
				cout << "something has gone wrong!" << endl;
			}
			}
			break;
		case 4:
			cout << "thank you for chosing us :D" << endl;
			return 0;
			break;
			//defaulta gerek yok Fmenü fonksiyonu baska bir değer döndüremez zaten!
	}

	return 0;
}
int Fmenü() {
	cout << "<---WELCOME TO THE SYSTEM OF LIBRARY--->" << endl;
	cout << "TO ADD NEW BOOK ---> 1" << endl;
	cout << "TO LIST ALL BOOKS ---> 2" << endl;
	cout << "TO BARROW A BOOK ---> 3" << endl;
	cout << "TO QUIT ---> 4" << endl;
	//hata kodu -1 olarak cıktı versin.
	int returnedvalue = 0;
	cout << "please enter choose one of them :" << endl;
	cin >> returnedvalue;
	if (returnedvalue > 4 || returnedvalue < 1) return Fmenü();
	else {
		return returnedvalue;
	}
}