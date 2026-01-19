#include <iostream>
#include <vector>
using namespace std;
class Patient {
private:
	string name;
	long long int TC;
	string complaint;
public:
	Patient(string n, long long int Tc, string com) {
		name = n;
		TC = Tc;
		complaint = com;
	}
	string getname() {
		return name;
	}
	long long int getTC() {
		return TC;
	}
	string getcomplaint() {
		return complaint;
	}
};
class Doctor {
private:
	string Doctor_name;
	string specialty;
	int experience;
public:
	Doctor(string D_n, string speci, int exper) {
		Doctor_name = D_n;
		specialty = speci;
		experience = exper;
	}
	string getDoctor_name() {
		return Doctor_name;
	}
	string getspecialty() {
		return specialty;
	}
	int getexperience() {
		return experience;
	}
};
class Appointment {
private:
	Patient p;
	Doctor d;
	string date;
public:
	Appointment(Patient _p, Doctor _d, string _date):p(_p),d(_d),date(_date) 
	{
	}
	void ShowAppointmentinfo() {
		cout << "<-------------------------------------------------->" << endl;
		cout << "Patient's name :" << p.getname() << "Patient's ID :" << p.getname() << endl;
		cout << "Patient's complaint :" << p.getcomplaint() << endl;
		cout << "Name of Doctor :" << d.getDoctor_name() << endl;
		cout << "The date of Appointment :" << date << endl;
		cout << "<-------------------------------------------------->" << endl;
	}
};
int Fmenü();
int main() {
	vector<Patient> Patients;
	vector<Doctor> Doctors;
	vector<Appointment> Appointments;
	
	Doctors.push_back(Doctor("Eren Vatansevdim", "Kardiyolog", 20));
	Doctors.push_back(Doctor("Zeynep Can", "Hemsire", 5));
	Doctors.push_back(Doctor("Talat Bey", "Doctor of Eye", 35));
	
	while (1) {
		int secim = Fmenü();
		if (secim == 0) break;
		else {
			switch (secim) {
				case 1:
						{
						string temp_name_patient;
						long long int temp_TC = 0;
						string temp_name_of_complaint;
						cout << "Please enter your name :" << endl;
						cin >> temp_name_patient;
						cout << "Please enter your ID number :" << endl;
						cin >> temp_TC;
						cout << "Please enter your complaint :" << endl;
						cin >> temp_name_of_complaint;
						int flag1 = 0;
						for (int i = 0; Patients.size() > i; i++) {
							if (Patients[i].getTC() == temp_TC) {
								flag1 = 1;
								break;
							}
						}
						if (flag1 != 0) {
							cout << "You have already recorded." << endl;
						}
						else {
							Patient newpatient(temp_name_patient, temp_TC, temp_name_of_complaint);
							Patients.push_back(newpatient);
							cout << "You are recorded succesfully." << endl;
						}
						}
					break;
				case 2:
					{
					cout << "<---DOCTORS' SPECIALTIES--->" << endl;
					for (int i = 0; Doctors.size() > i; i++) {
						cout << "DOCTOR's Name : " << Doctors[i].getDoctor_name() << "DOCTOR's Branch :" << Doctors[i].getspecialty() << "Doctor experiment's year :" << Doctors[i].getexperience() << endl;
					}	
					}
					break;
				case 3:
					{
					int patient_index = -1;//-1 hatalı cıkıs yapsın eger bulamazsa.
					int doctor_index = -1;
					string temp2_doctor_specialty;
					long long int temp2_TC=0;
					cout << "Please enter Number Of TC :" << endl;
					cin >> temp2_TC;
					for (int i = 0; Patients.size() > i; i++) {
						if (Patients[i].getTC() == temp2_TC) {
							patient_index = i;
							break;
						}
					}
					if (patient_index == -1) {
						cout << "Your Tc is not in our system Please firstly Be Recorded." << endl;
					}
					cout << "Please enter name of speacilty of the doctor which you want to get cure :" << endl;
					cin >> temp2_doctor_specialty;
					for (int i = 0; Doctors.size() > i; i++) {
						if (Doctors[i].getspecialty() == temp2_doctor_specialty) {
							doctor_index = i;
							break;
						}
					}
					if (doctor_index == -1) {
						cout << "We can't have  the doctor whıch has  " << temp2_doctor_specialty << "specialty so try later." << endl;
					}
					string date_of_app = "20/01/2026";
					Appointments.push_back(Appointment(Patients[patient_index], Doctors[doctor_index], date_of_app));
					}
					cout << "Recently You have an Appointment!" << endl;
					break;
				case 4:
					cout << "ALL APPOINTMENTS " << endl;
					if (Appointments.empty()) {
						cout << "There is not any appointments here!" << endl;
					}
					else {
						for (int i = 0; Appointments.size() > i; i++) {
							Appointments[i].ShowAppointmentinfo();
						}
					}
					break;
					//default yazmama gerek yok cünkü Fmenü fonksiyonu 0 ila 4 kapalı kapalı araısnda baska bir şey döndüremez.
			}
		}
	}
	
	return 0;
}
int Fmenü() {
	cout << "<---WELCOME TO HOSPITAL SYSTEM--->" << endl;
	cout << "TO SAVE THE PATIENT PRESS 1" << endl;
	cout << "TO LISTEN ALL DOCTOR PRESS 2" << endl;
	cout << "TO GET APPOINTMENT PRESS 3" << endl;
	cout << "TO LISTEN ALL APPOINTMENTS PRESS 4" <<endl; 
	cout << "TO QUIT PRESS 0" << endl;
	cout << "please choose one of them :" << endl;
	int secim = 0;
	cin >> secim;
	if (secim < 0 || secim > 4) return Fmenü();
	else {
		return secim;
	}

}