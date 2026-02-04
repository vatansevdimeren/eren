#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

#define row 10
#define column 10

int Block_1[row][column];
int Block_2[row][column];

using namespace std;

void SaveBlocks(int Block_1[row][column],int Block_2[row][column]);

class Student {
	private:
		string Name;
		long long int ID;
		short int RoomNumber;
		double DebtValue;
		bool Active;
	public:
		Student(string Name, long long int ID, short int RoomNumber, double DebtValue, bool Active) {
			this->Name = Name;
			this->ID = ID;
			this->RoomNumber = RoomNumber;
			this->DebtValue = DebtValue;
			this->Active = Active;
		}
		//get Functions
		string getName() {
			return Name;
		}
		long long int getID() {
			return ID;
		}
		short int  getRoomNumber() {
			return RoomNumber;
		}
		double getDebtValue() {
			return DebtValue;
		}
		bool getActive() {
			return Active;
		}
		//set Functions
		void setName(string Name) {
			this->Name = Name;
		}
		void setID(long long int ID) {
			this->ID = ID;
		}
		void setDebtValue(double DebtValue) {
			this->DebtValue = DebtValue;
		}
		void setActivate(bool act) {
			this->Active = act;
		}
		static void StudentCreater(vector<Student>& Students) {
			string name_temp;
			long long int ID_temp;
			short int RoomNumber_temp;
			double deptValue;
			//here All students will be active becasue you are in the  student Creater funtion.
			
			cin.ignore();
			
			cout << "Please enter your name :";
			getline(cin, name_temp);

			cout << "Please enter Your given ID :";
			cin >> ID_temp;

			cout << "Please enter the value of debt if you have :";
			cin >> deptValue;
			
			bool yerbuldu = false;
			short int yer1 = 0;
			short int yer2 = 0;
			
			for (int i = 0; row  > i; i++) {
				for (int j = 0; column > j; j++) {
					if (Block_1[i][j] == 0) {
						Block_1[i][j] = 1;
						yer1 = i*j;
						yer1 = 100 - yer1;
						yerbuldu = true;
						break;

					}
					if (Block_2[i][j] == 0) {
						Block_2[i][j] = 1;
						yerbuldu = true;
						yer2 = j*i;
						yer2 = 100 + yer2;
						break;
					}
				}
				if (yerbuldu == true) break;
			}
			if (yer1 > yer2) {
				yer2 = yer1;
			}
			
			RoomNumber_temp = yer2;
			
			if (yerbuldu == false) {
				cout << "There is not any place for you please join different kinda dormitory!" << endl;
				return;
			}
			
			Student tempStudent(name_temp, ID_temp, yer2, deptValue, true);
			Students.push_back(tempStudent);

			time_t current_time = time(0);
			char timeBuffer[30];
			ctime_s(timeBuffer, sizeof(timeBuffer), &current_time);

			ofstream logStudent("Slog.txt", ios::app);

			if (bool(logStudent) == false) {
				cout << "The file of log of students' was NOT openned!" << endl;
				return;
			}
			else {
				logStudent << "<------------------------------------------------>" << endl;
				logStudent << timeBuffer << endl;
				logStudent << "Student Name : " << name_temp << endl;
				logStudent << "Student's ID : " << ID_temp << endl;
				logStudent << "Studen's Room's Number : " << RoomNumber_temp << endl;
				logStudent << "Student's debt value : " << deptValue << endl;
				logStudent << "Activate of the Student : " << tempStudent.getActive() << endl;

				logStudent.close();
			}

			ofstream dataStudent("Sdata.txt", ios::app);

			if (bool(dataStudent) == false) {
				cout << "Datas Of the Student's did NOT oppened!" << endl;
				return;
			}
			else {
				dataStudent << tempStudent.getName() << "," << tempStudent.getID() <<
				"," << tempStudent.getRoomNumber() << "," << tempStudent.getDebtValue()
				<< "," << tempStudent.getActive() << endl;

				dataStudent.close();
			}
			SaveBlocks(Block_1, Block_2);
		}
		static void StudentRemover(vector<Student>& Students) {
			string Rname;
			long long int RID;
			bool bulundumu = false;
			
			cout << "Please enter him/her name :";
			getline(cin, Rname);

			cout << "Please enter him/her ID :";
			cin >> RID;

			for (int i = 0; Students.size() > i; i++) {
				if (Students[i].getName() == Rname && Students[i].getID() == RID) {
					cout << "Are you serios for deleting that student's place?";
					short int number = 0;
					cout << "İf you really and want to delete press 1";
					if (number != 1) {
						break;
					}
					else {
						Students[i].setActivate(false);
					}
				}
			}
		}
};
class Personnel {
	private:
		string Personel_name;
		unsigned long long int Personel_password;
		bool Personnel_activate;
		bool Personel_warrant;
	public:
		Personnel(string Personel_name,unsigned long long int Personel_password, bool Personel_activate,bool Personel_warrant) {
			this->Personel_name = Personel_name;
			this->Personel_password = Personel_password;
			this->Personnel_activate = Personel_activate;
			this->Personel_warrant = Personel_warrant;
		}
		
		//get functions.

		string GetName_personel() {
			return Personel_name;
		}
		unsigned long long int  GetPersonnel_password() {
			return Personel_password;
		}
		bool GetPersonel_activate() {
			return Personnel_activate;
		}
		bool GetPersonel_warrant() {
			return Personel_warrant;
		}
		
		//set functions.

		void setPersonelName(string Personel_name) {
			this->Personel_name = Personel_name;
		}
		void setPersonnel_password(unsigned long long int Personnel_pass) {
			this->Personel_password = Personnel_pass;
		}
		void setActivate(bool Activate) {
			this->Personnel_activate = Activate;
		}
		void setPersonel_warrant(bool warrant) {
			this->Personel_warrant = warrant;
		}

		//Personel Creater Funciton

		static void PersonnelCreater(vector<Personnel>& Personnels) {
			string Personnel_name;
			string Personnel_Password;
			unsigned long long int hash_of_personel_password;
			bool Personel_activate=true;
			bool Personel_warrant = true;

			cout << "Please enter your name and surname with space : ";
			cin.ignore();
			getline(cin, Personnel_name);

			cout << "Please enter your Passoword";
			getline(cin, Personnel_Password);
			
			char* ptr = &Personnel_Password[0];
			short int length_of_word = 0;

			for (int i = 0; 1000 > i; i++) {
				if (Personnel_Password[i] != '\0') {
					length_of_word++;
				}
				else {
					break;
				}
			}
			bool flagSmallLetter = false;
			bool FlagBigLetter = false;
			for (int i = 0; length_of_word > i; i++) {
				char c = Personnel_Password[i];
				if (c >= 65 && c <= 90) {
					FlagBigLetter = true;
				}
				else if (c >= 97 && c <= 122) {
					flagSmallLetter = true;
				}
			}
			
			//Password accept conditions.
			
			if (length_of_word <8) {
				cout << "your password must have minimum 8 characters!" << endl;
				return PersonnelCreater(Personnels);
			}
			if (flagSmallLetter == false) {
				cout << "Your password must have at least one small character!" << endl;
				return PersonnelCreater(Personnels);
			}
			if (FlagBigLetter == false) {
				cout << "Your password must have at least one big character!" << endl;
				return PersonnelCreater(Personnels);
			}

			//if pass thought upper if conditions than the password will be crypted by a algoritm that called DJB1
			
			unsigned long long int hash = 5381;//it is a special prime number that provides distiruption clearly.
			
			if (length_of_word >= 8 && flagSmallLetter == true && FlagBigLetter == true) {
				for (int i = 0; length_of_word > i; i++) {
					char c = Personnel_Password[i];
					hash += ((hash << 5) + hash) + c;
				}
			}
			Personnel TempPersonel(Personnel_name, hash, true, true);

			Personnels.push_back(TempPersonel);

			// real time system for long system.

			time_t  current_time = time(0);
			char time_buffer[30];
			ctime_s(time_buffer, sizeof(time_buffer), &current_time);
			
			//log saving system

			ofstream PersonnelLog("Plog.txt", ios::app);

			if (bool(PersonnelLog) == false) {
				cout << "The Personnel log file was NOT oppened" << endl;
				return;
			}
			else {
				PersonnelLog << "<--------------------------------->" << endl;
				PersonnelLog << time_buffer << endl;
				PersonnelLog << "Name of Personnel : " << Personnel_name << endl;
				PersonnelLog << "Changed to hash number is : " << hash << endl;
				PersonnelLog << "Activate of Personnel is : " << true << endl;
				PersonnelLog << "Personnel warrant activate is : " << true << endl;
				
				PersonnelLog.close();
			}

			//Data saving system.

			ofstream PersonnelData("Pdata.txt", ios::app);

			if (bool(PersonnelData) == false) {
				cout << "The file of Personnels' data file was NOT OPPENED!" << endl;
				return ;
			}
			else {
				PersonnelData << Personnel_name << "," << hash << "," << Personel_activate << "," << Personel_warrant << endl;
				PersonnelData.close();
			}
		}
		static void PersonnelRemover(vector<Personnel>& Personnels) {
			string temp_name;
			string temp_password;
			unsigned long long int temp_hash=0;
			static short int counter=0;
			short int index_value = -1;

			if (counter > 3) {
				cout << "you try so much times so you need to have a break!" << endl;
				cout << "Please 2 minutes later try again!" << endl;
				return ;
			}
			cout << "Please enter Personnel's name which you want to delete : ";
			getline(cin, temp_name);
			bool bulundumu = false;
			for (int i = 0; Personnels.size() > i; i++) {
				if (temp_name == Personnels[i].GetName_personel()) {
					bulundumu = true;
					index_value = i;
					break;
				}
			}
			if (bulundumu == false) {
				cout << "Please enter available Personnel name!" << endl;
				cout << "You need to pay atention big or small letters while you enter!" << endl;
				return PersonnelRemover(Personnels);
			}

			cout << "Please enter Personnel's Password which you want to delete : ";
			getline(cin, temp_password);

			for (int i = 0; temp_password.size() > i; i++) {
				char c = temp_password[i];
				temp_hash += ((temp_hash << 5)+temp_hash) + c;
			}
			if (temp_hash != 0) {
				if (temp_hash == Personnels[index_value].GetPersonnel_password()) {
					cout << "The process is succesfull!" << endl;
					Personnels[index_value].setActivate(false);
					Personnels[index_value].setPersonel_warrant(false);
					return;
				}
				else {
					cout << "The password is wrong Please try again!!!" << endl;
					return PersonnelRemover(Personnels);
				}
			}
			else {
				cout << "Name or pass did NOT match as beforrue you enter!" << endl;
				cout << "Please try again!" << endl;
				counter++;
				return PersonnelRemover(Personnels);
			}
		}
		static Personnel* PersonnelEnterance(vector<Personnel>& Personnels) {
			string temp_name;
			string temp_password;
			unsigned long long int temp_hash = 5381;
			static short int counter = 0;
			short int index_value = -1;

			if (counter > 3) {
				cout << "you try so much times so you need to have a break!" << endl;
				cout << "Please 2 minutes later try again!" << endl;
				return nullptr;
			}

			cout << "Please enter your name : ";
			//sanırım buraya cin.ignore(); koyucağım
			cin.ignore();
			getline(cin, temp_name);
			
			bool bulundumu = false;
			//
			cout << "Personel size : " << Personnels.size() << endl;
			//
			for (int i = 0; Personnels.size() > i; i++) {
				if (Personnels[i].GetName_personel() == temp_name) {
					index_value = i;
					//girdim
					cout << "Girdim" << endl;
					bulundumu = true;
					break;
				}
			}
			
			if (bulundumu == false) {
				cout << "Please enter available Personnel name!" << endl;
				cout << "You need to pay atention big or small letters while you enter!" << endl;
				return PersonnelEnterance(Personnels);
			}
			else {
				cout << "Please enter your password : ";
				getline(cin, temp_password);

				for (int i = 0; temp_password.size() > i; i++) {
					char c = temp_password[i];
					temp_hash += ((temp_hash << 5) + temp_hash) + c;
				}
				
				if (temp_hash != 0) {
					if (temp_hash == Personnels[index_value].GetPersonnel_password()) {
						cout << "You have A token that surf on the app!" << endl;
						//here I am gonna put a function that makes the idea that upper that you can see!
						return &Personnels[index_value];
					}
					else {
						cout << "You entered wrong password!" << endl;
						cout << "Please try again!" << endl;
						counter++;
						return PersonnelEnterance(Personnels);
					}
				}
				else {
					return nullptr;
				}
			}
		}
};

short int FirstMenü();
short int PersonnelMenü();
short int LastMenü();
short int StudentMenü();

void LoadStudents(vector<Student>& Students);
void LoadPersonnels(vector<Personnel>& Personnels);

void ShowBlockOne(int Block_1[row][column]);
void ShowBlockTwo(int Block_2[row][column]);

void LoadMapBlocks();

void SortStudentForDebt(vector<Student>& Students);

void PrivateStudentAndPersonnelLogPrinter();
void PrivateStudentAndPersonnelDataPrinter();
int main() {
	vector <Student> Students;
	vector <Personnel> Personnels;

	Personnel* PersonnelToken = nullptr;
	
	LoadStudents(Students);
	LoadPersonnels(Personnels);
	LoadMapBlocks();
	
	//deneme yapıcam hata var

	while (true) {
		short int secenek1 = FirstMenü();
		switch (secenek1) {
			case 0:
				cout << "Thank you for chosing us!" << endl;
				return 0;
				break;
			case 1:
			{
				short int Secenek_Student_menü = StudentMenü();
				switch (Secenek_Student_menü) {
					case 0:
						cout << "The menü is closing wait a second...." << endl;
						system("cls");
						break;
					case 1:
					{
						if (Students.size() == 0) {
							break;
						}
						string name_temp;
						long long int temp_ID;

						cout << "Please enter Student's name : ";
						cin.ignore();
						getline(cin, name_temp);

						cout << "Please enter Student's ID : ";
						cin >> temp_ID;

						bool flag = false;
						for (int i = 0; Students.size() > i; i++) {
							if (Students[i].getName() == name_temp && Students[i].getID() == temp_ID && Students[i].getActive() == true) {
								flag = true;
							}
						}
						if (flag == false) {
							cout << "There is not acount like you entered." << endl;
							cout << "Please firsly Create an acount!" << endl;
							break;
						}
						else {
							cout << "You are entered succesfully" << endl;
							//here will come a funciton that the student will have a token to surf on the website of the dormitory!
							//you can make a token system like I did for Personnels.Also they can see log and datas
						}
						break;
					}
				case 2:

					Student::StudentCreater(Students);
					
					break;
				case 3:

					Student::StudentRemover(Students);
					
					break;
				}
				break;
			}
			case 2:
			{
				short int secenek = PersonnelMenü();

				switch (secenek) {
					case 0:
						cout << "Personnel menü system is closing..." << endl;
						break;
					case 1:
						Personnel::PersonnelCreater(Personnels);
						break;
					case 2:
						PersonnelToken = Personnel::PersonnelEnterance(Personnels);
						break;
					case 3:
						Personnel::PersonnelRemover(Personnels);
						break;
				}
			}
				break;
			case 3:
			{
				short int secenek = LastMenü();
				switch (secenek) {
					case 0:
						cout << "The last Menü is closing..." << endl;
						break;
					case 1:
						cout << "Map of first block!" << endl;
						ShowBlockOne(Block_1);
						
						cout << "Map of second block!" << endl;
						ShowBlockTwo(Block_2);
						break;
					case 2:
						//here I am gonna write a function that sort all debt of students'.
						SortStudentForDebt(Students);
						break;
					case 3:
						{
						if (PersonnelToken == nullptr) {
							cout << "Please firstly login!" << endl;
						}

						else if (PersonnelToken->GetPersonel_warrant() == true) {
							// FONKSİYON GELİCEK BURAYA!!
							PrivateStudentAndPersonnelLogPrinter();
						}

						else {
							cout << "Bro you do NOT have permission to see log and data files..." << endl;
						}
						}

						break;
					case 4:
					{
						if (PersonnelToken == nullptr) {
							cout << "Bro Please firstly login!" << endl;
						}
						else if (PersonnelToken->GetPersonel_warrant() == true) {
							PrivateStudentAndPersonnelDataPrinter();
						}
						else {
							cout << "Dude you do not have a permission to see data files..." << endl;
							break;
						}
					}

						break;
				}
			}
				break;
			case 4:
				cout << "To see the first block press 1 " << endl;
				cout << "To see the second block press 2 " << endl;
				unsigned short int a;
				cin >> a;
				if (a < 1 || a>2) {
					cout << "ananıskm";
				}
				else if (a == 1) {
					ShowBlockOne(Block_1);
				}
				else if (a == 2) {
					ShowBlockTwo(Block_2);
				}
				break;
		}
	}

	return 0;
}
short int FirstMenü() {
	//system("cls");
	cout << "<-----WELCOME TO ESKISEHIR'S DORMITORY APP----->" << endl;
	cout << "0 - QUIT" << endl;
	cout << "1 - STUDENT ENTERANCE" << endl;
	cout << "2 - PERSONEL ENRERANCE" << endl;
	cout << "3 - LOGIN MENU" << endl;
	cout << "4 - BLOCK'S WIEW" << endl;
	cout << "Please enter your option :";
	int secenek = 0;
	cin >> secenek;
	if (secenek < 0 || secenek > 4) return FirstMenü();
	return secenek;
	
}
short int StudentMenü() {
	system("cls");
	cout << "************************" << endl;
	cout << "TO ENTER STUDENTS' INFORMATION '1'" << endl;
	cout << "TO CREATE A NEW STUDENT '2'" << endl;
	cout << "TO DELETE ANY KIND OF STUDENTS' ACOUNT '3'" << endl;
	cout << "TO QUIT PRESS '0'" << endl;
	cout << "Please enter your opinion :";
	int a;
	cin >> a;
	if (a < 0 || a>3) return StudentMenü();
	return  a;
}
short int PersonnelMenü() {
	short int secenek = 0;
	system("cls");
	cout << "TO CREATE A NEW PERSONEL ACOUNT PRESS 1" << endl;
	cout << "TO ENTER PERSONEL SYSTEM PRESS 2" << endl;
	cout << "TO DELETE A PERSONEL ACOUNT PRESS 3" << endl;
	cout << "TO QUIT PRESS 0" << endl;
	cout << "Please choose one of them :";

	cin >> secenek;
	if (secenek < 0 || secenek > 3) return PersonnelMenü();

	return secenek;
}
short int LastMenü() {
	system("cls");
	cout << "TO SHOW ALL BLOCKS OF BUILDINGS '1'" << endl;
	cout << "TO SEE LEADERBORD OF STUDENTS' DEBT '2'" << endl;
	cout << "TO SEE LOG SYSTEM(FOR Personnels) '3'" << endl;
	cout << "TO SEE DATA BASE(FOR Personnels) '4'" << endl;
	cout << "TO QUIT '0'" << endl;
	cout << "Please choose one of them :";
	int secenek = 0;
	cin >> secenek;
	if (secenek < 0 || secenek > 4) return LastMenü();
	return secenek;
}
void LoadStudents(vector<Student>& Students) {
	ifstream ReadDataStudents("Sdata.txt");

	if (bool(ReadDataStudents) == false) {
		cout << "The students' data file did NOT ridden!" << endl;
		return;
	}
	else {
		string Tname;
		long long int TID;
		short int TRooomNumber;
		double TdoubtValue;
		bool TActive;
		char virgülreader;

		while (getline(ReadDataStudents, Tname, ',')) {
	
			ReadDataStudents >> TID >> virgülreader;
			ReadDataStudents >> TRooomNumber >> virgülreader;
			ReadDataStudents >> TdoubtValue >> virgülreader;
			ReadDataStudents >> TActive;

			ReadDataStudents.ignore();

			Student TempStudent(Tname, TID, TRooomNumber, TdoubtValue, TActive);

			Students.push_back(TempStudent);
		}
		ReadDataStudents.close();
	}
}
void LoadPersonnels(vector<Personnel>& Personnels) {
	ifstream ReadPersonnel("Pdata.txt");

	if (bool(ReadPersonnel) == false) {
		cout << "The reading operation of personnels' data file is unsuccesfull!!!" << endl;
		return;
	}
	else {
		string temp_p_name;
		unsigned long long int temp_p_hash;
		bool temp_p_activate;
		bool temp_p_warrant_activate;
		char virgülbuffer;
		
		while (getline(ReadPersonnel, temp_p_name, ',')) {
			
			ReadPersonnel >> temp_p_hash >> virgülbuffer;
			ReadPersonnel >> temp_p_activate >> virgülbuffer;
			ReadPersonnel >> temp_p_warrant_activate;

			ReadPersonnel.ignore();

			Personnel tempPerson(temp_p_name, temp_p_hash, temp_p_activate, temp_p_warrant_activate);

			Personnels.push_back(tempPerson);

		}
		ReadPersonnel.close();
	}
}
void ShowBlockOne(int Block_1[row][column]) {
	for (int i = 0; row > i; i++) {
		for (int j = 0; column > j; j++) {
			if (Block_1[i][j] == 1) cout << "[X]  ";
			else cout << "[ ]  ";
		}
		cout << "\n";
	}
}
void ShowBlockTwo(int Block_2[row][column]) {
	for (int i = 0; row > i; i++) {
		for (int j = 0; column > j; j++) {
			if (Block_2[i][j] == 1)cout << "[X]  ";
			else cout << "[ ]  ";
		}
		cout << "\n";
	}
}
void SaveBlocks(int Block_1[row][column], int Block_2[row][column]) {
	ofstream Blockmap("BlockMap.txt");

	if (bool(Blockmap) == false) {
		cout << "The writing file of Block map was NOT openned!" << endl;
		return ;
	}
	else {
		for (int i = 0; row > i; i++) {
			for (int j = 0; column > j; j++) {
				Blockmap << Block_1[i][j]<<" ";
			}
		}
		Blockmap << "\n";

		for (int i = 0; row > i; i++) {
			for (int j = 0; column > j; j++) {
				Blockmap << Block_2[i][j] <<" ";
			}
		}

		Blockmap.close();
	}
}
void LoadMapBlocks() {
	ifstream ReadMap("BlockMap.txt");

	if (bool(ReadMap) == false) {
		cout << "The reading file of Blocks' map was NOT oppened!" << endl;
		return;
	}
	else {
		for (int i = 0; row > i; i++) {
			for (int j = 0; column > j; j++) {
				ReadMap >> Block_1[i][j];
			}
		}

		for (int i = 0; row > i; i++) {
			for (int j = 0; column > j; j++) {
				ReadMap >> Block_2[i][j];
			}
		}

		ReadMap.close();
	}
}
void SortStudentForDebt(vector<Student>& Students) {
	//Normally we can use an algoritm that has nlog(n) big tetha notation But I dont do that becuase,
	//we just have 200 rooms for Student's I mean we can use there buble sort for n^2 200^2 = 4000 Any kind of processor can
	//works under 1 milisecond.

	vector<Student> SortedStudents=Students;

	
	for (int i = 0; SortedStudents.size() - 1 > i; i++) {
		for (int j = 0; SortedStudents.size() - 1 - i; j++) {
			if (SortedStudents[j].getDebtValue() > SortedStudents[j + 1].getDebtValue()) {
				Student TempStudent = SortedStudents[j];
				SortedStudents[j] = SortedStudents[j + 1];
				SortedStudents[j+1] = TempStudent;
			}
		}
	}
	for (int i = 0; SortedStudents.size() > i; i++) {
		cout << i + 1 << ". Student's debt value : " << SortedStudents[i].getDebtValue() <<endl;
	}
	cout << "The highest debt value is : " << SortedStudents[SortedStudents.size() - 1].getDebtValue() <<
		"And his/her name is : " << SortedStudents[SortedStudents.size() - 1].getName() << endl;
	// I EMPHASISE THAT THE FUNCTION IS NOT EFFECTIVE FOR LONG SORT OPERARIONS!!!
}
void PrivateStudentAndPersonnelLogPrinter() {

	cout << "<##########################	Students' LOG   ##########################>" << endl;
	
	ifstream LogReader("Slog.txt");

	if (bool(LogReader) == false) {
		cout << "in Private Students' log printer's funtion Slog function was NOT oppened!" << endl;
		return;
	}
	else {
		string Reader;
		while (getline(LogReader, Reader)) {
			cout << Reader << endl;
		}
		LogReader.close();
	}
	cout << "<##########################   FINISHED   ##########################>" << endl;
	
	//personnels' log system
	
	cout << "<##########################   Personnels' LOG   ##########################>" << endl;
	
	ifstream ReaderLog("Plog.txt");

	if (bool(ReaderLog) == false) {
		cout << "Reading to ReaderLog Of Personnels' was NOT oppened!" << endl;
		return;
	}

	else {
		string a;
		while (getline(ReaderLog, a)) {
			cout << a << endl;
		}
		ReaderLog.close();
	}
}
void PrivateStudentAndPersonnelDataPrinter() {
	cout << "<##########################	STUDENTS' DATAS   ##########################>" << endl;
	ifstream StudentsReader("Sdata.txt");

	if (bool(StudentsReader) == false) {
		cout << "Private Students' datas reader function has not been working...." << endl;
		cout << "So the file was not oppened!!!" << endl;
		return ;
	}
	else {
		string a;
		while (getline(StudentsReader, a)) {
			cout << a << endl;
		}
		StudentsReader.close();
	}

	cout << "<##########################   FINISHED   ##########################>" << endl;

	cout << "<##########################	PERSONNELS' DATAS   ##########################>" << endl;
	ifstream PersonnelReader("Pdata.txt");

	if (bool(PersonnelReader) == false) {
		cout << "The private Personnel Reader file was not oppened!!!" << endl;
		return;
	}

	else {
		string satir;
		while (getline(PersonnelReader, satir)) {
			cout << satir << endl;
		}
		PersonnelReader.close();
	}

	cout << "<##########################   FINISHED   ##########################>" << endl;
}