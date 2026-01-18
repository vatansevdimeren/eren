#include <iostream>
#include <vector>
using namespace std;
vector <string> harcamalar;
vector <double> fiyatlar;
int Fmenü();
void Fharcamalar();
void Fharcamasilme();
void Fharcamaarama();
int main() {
	bool devam = true;
	while (devam) {
		int returned_value_from_menü = Fmenü();
		switch (returned_value_from_menü) {
		case 0:
			cout << "the program is closing thank you for chosing us :D" << endl;
			devam = false;
			break;
		case 1:
			Fharcamalar();
			break;
		case 2:
			Fharcamaarama();
			break;
		case 3:
			Fharcamasilme();
			break;
		default:
			cout << "hata kodu cıktısı olamaz lan wtf??!?!??!?";
			break;
		}
	}

	return 0;
}
int Fmenü() {
	cout << "<---HOSGELDINIZ--->" << endl;
	cout << "HARCAMA EKLEMEK ICIN 1" << endl;
	cout << "HARCAMA KONTROLU 2" << endl;
	cout << "HARCAMA SILME 3" << endl;
	cout << "CIKMAK ICIN 0 " << endl;
	int secim = 0;
	cout << "lütfen yapmak istediğiniz islemi giriniz :";
	cin >> secim;
	if (secim > 3 || secim < 0) {
		cout << "please enter avaliable number!";
		return Fmenü();
	}
	else { return secim; }
}
void Fharcamalar() {
	cout << "lütfen harcama yaptıgınız ürünün ismini giriniz :" << endl;
	string temp_harcanan;
	cin >> temp_harcanan;
	harcamalar.push_back(temp_harcanan);
	cout << " " << temp_harcanan << "isimli ürünün fiyatını giriniz :" << endl;
	double temp_price;
	cin >> temp_price;
	fiyatlar.push_back(temp_price);
	int secenek = 0;
	cout << "daha fazla ürün eklemek icin 1 e basınız " << endl;
	cout << "cıkmak icin 0'a basınız!" << endl;
	cin >> secenek;
	if (secenek == 0) return;
	else if (secenek == 1) return Fharcamalar();
	else {
		cout << "INVALID INPUT!!!" << endl;
	}
}
void Fharcamaarama() {
	cout << "harcamalar bunlar :" << endl;
	for (int i = 0; harcamalar.size() > i; i++) {
		cout << harcamalar[i] << endl;
	}
	cout << "aramak istediğiniz ürünün ismini giriniz :" << endl;
	string controller1;
	cin >> controller1;
	int flag = 0;//bulma durumu 1
	for (int i = 0; harcamalar.size() > i; i++) {
		if (harcamalar[i] == controller1) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << "aradıgın ürün burada yok." << endl;
	}
	else {
		cout << "aradigin ürün burada vardır." << endl;
	}
}
void Fharcamasilme() {
	int silinecek_index = 0;
	cout << "silmek istedginiz ürünün ismini eksiksiz bir sekilde giriniz :" << endl;
	string aranan;
	cin >> aranan;
	int flag_silme = 0;
	for (int i = 0; harcamalar.size() > i; i++) {
		if (aranan == harcamalar[i]) {
			silinecek_index = i;
			flag_silme = 1;
			break;
		}
	}
	if (flag_silme != 0) {
		cout << "silme işlemi basarıyla gerceklesmistir." << endl;
		harcamalar.erase(harcamalar.begin() + silinecek_index);
		fiyatlar.erase(fiyatlar.begin() + silinecek_index);
	}
	else {
		cout << "INVALID INPUT!!" << endl;
	}
}