#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Ball {
private :
	double Vx, Vy;
	double Xx, Xy;
	double mass;
public:
	Ball( double Xx, double Xy, double Vx, double Vy,double mass) {
		this->Xx = Xx;
		this->Xy = Xy;
		this->Vx = Vx;
		this->Vy = Vy;
		this->mass = mass;
	}
	double getmass() {
		return mass;
	}
	double getXx() {
		return Xx;
	}
	double getXy() {
		return Xy;
	}
	double getVx() {
		return Vx;
	}
	double getVy() {
		return Vy;
	}
	void setXx(double Xx) {
		this->Xx = Xx;
	}
	void setXy(double Xy) {
		this->Xy = Xy;
	}
	void setVx(double Vx) {
		this->Vx = Vx;
	}
	void setVy(double Vy) {
		this->Vy = Vy;
	}
	void setmass(double mass) {
		this->mass = mass;
	}
};
void Createball(vector<Ball> &v);
int Fmenü();
void Fpositioncalculator(vector<Ball>& v);
void Fballchanger(vector<Ball>& v);
void Fvelocitycalculator(vector<Ball>& v);
int main() {
	vector<Ball> v;
	while (1) {
		int returnedvariablefrommenü = Fmenü();
		switch (returnedvariablefrommenü) {
		case 0:
			cout << "Do you like it?" << "I hope you enjoy :D" << endl;
			return 0;
		case 1:
			Createball(v);
			break;
		case 2:
			Fpositioncalculator(v);
			break;
		case 3:
			Fvelocitycalculator(v);
			break;
		case 4:
			//It is hard to do that currently I dont wanna write the function
			break;
		case 5:
			break;
			//its value can't be differ from these cases becuase the function when you input different kinda variable it returns Fmenü() again :D

		}
	}

	return 0;
}
int Fmenü() {
	cout << "<---WELCOME TO TWO DIMENSIONAL MOVEMENT--->" << endl;
	cout << "TO ADD A NEW BALL PRESS 1" << endl;
	cout << "TO CALCULATE ITS POSTITON PRESS 2" << endl;
	cout << "TO CALCULATE ITS VELOCITY PRESS 3" << endl;
	cout << "TO DISPLAY ALL VAIRABLES PRESS 4" << endl;
	cout << "TO QUIT PLEASE ENTER 0" << endl;
	int secenek = 0;
	cout << "Please choose one of them :";
	cin >> secenek;
	if (secenek < 0 || secenek > 5) return Fmenü();
	return secenek;
}
void Createball(vector<Ball>& v) {
	double t_xx, t_xy, t_vx, t_vy, t_mass;
	
	cout << "Please enter x position :";
	cin >> t_xx;
	
	cout << "Please enter y position :";
	cin >> t_xy;
	
	cout << "Please enter the velocity of x component :";
	cin >> t_vx;
	
	cout << "Please enter the velocity of y component :";
	cin >> t_vy;

	cout << "Please enter mass of ball :";
	cin >> t_mass;
	
	Ball ball(t_xx,t_xy,t_vx,t_vy,t_mass);
	v.push_back(ball);
	cout << "if you want to change any variable of the ball press 1";
	int changer_ball;
	cin >> changer_ball;
	if (changer_ball == 1) {
		Fballchanger(v);
	}
}
void Fpositioncalculator(vector<Ball>& v) {
	cout << "Which ball do you want to choose to calculate its pozition after :";
	if (v.size() == 0) {
		cout << "The balls packet is empty so you need to add some balls to calculate its values!!!" << endl;
		return;
	}
	for (int i = 0; v.size() > i; i++) {
		cout << ""<<i+1 << ".Mass :" << v[i].getmass() << endl;
		cout << "" << i + 1 << ".Position X :" << v[i].getXx() << endl;
		cout << "" << i + 1 << ".Position Y :" << v[i].getXy() << endl;
		cout << "" << i + 1 << ".Velocity X :" << v[i].getVx() << endl;
		cout << "" << i + 1 << ".Velocity Y :" << v[i].getVy() << endl;
	}
	int ball_index = 0;
	cin >> ball_index;
	if (ball_index <= 0 || ball_index > v.size()) {
		cout << "sen bir orosoocpcpcusuyn....." << endl;
		return Fpositioncalculator(v);
	}
	ball_index--;
	
	cout << "Please enter How many seconds later's position if you want :";
	double sec = 0;
	cin >> sec;
	
	double New_position_x, New_position_y;
	New_position_x = v[ball_index].getXx()  + sec * v[ball_index].getVx();
	New_position_y = v[ball_index].getXy() +  sec * v[ball_index].getVy();
	
	cout << "After " << sec << "later new position of the ball's X exponent is :" << New_position_x << "m" << endl;
	cout << "After " << sec << "later new position of the ball's Y exponent is :" << New_position_y << "m" << endl;
}
void Fballchanger(vector<Ball>& v) {
	cout << "Please enter which ball you want to changed its value :";
	if (v.size() == 0) {
		cout << "The balls packet is empty so you need to add some balls to calculate its values!!!" << endl;
		return;
	}
	for (int i = 0; v.size() > i; i++) {
		cout << "" << i + 1 << ".Mass :" << v[i].getmass() << endl;
		cout << "" << i + 1 << ".Position X :" << v[i].getXx() << endl;
		cout << "" << i + 1 << ".Position Y :" << v[i].getXy() << endl;
		cout << "" << i + 1 << ".Velocity X :" << v[i].getVx() << endl;
		cout << "" << i + 1 << ".Velocity Y :" << v[i].getVy() << endl;
	}
	int ball_index = 0;
	cin >> ball_index;
	if (ball_index<=0 || ball_index > v.size()) {
		cout << "sen bir orospu evladısın.!!!" << endl;
		return Fballchanger(v);
	}
	ball_index--;
	cout << "TO CHANGE ITS POSITION X EXPONENT  PRESS 1" << endl;
	cout << "TO CHANGE	ITS POSITON Y EXPONENT PRESS 2" << endl;
	cout << "TO CHANGE ITS VELOCITY X EXPONENT PRESS 3" << endl;
	cout << "TO CHANGE ITS VELOCITY Y EXPONENT PRESS 4" << endl;
	cout << "TO CHANGE ITS MASS PRESS 5" << endl;
	cout << "Please choose what you want to do :";
	int secenek = 0;
	cin >> secenek;
	if (secenek < 1 || secenek > 5) return Fballchanger(v);
	switch (secenek) {
	case 1: {
		cout << "Please enter new X:";
		double newv;
		cin >> newv;
		v[ball_index].setXx(newv);
		break;
		}
	case 2:
		{
		cout << "Please enter new Y:";
		double newv;
		cin >> newv;
		v[ball_index].setXy(newv);
		break;
		}
	case 3:
		{
		cout << "Please enter new Vx:";
		double newv;
		cin >> newv;
		v[ball_index].setVx(newv);
		break;
		}
	case 4:
		{
		cout << "Please eneter new Vy:";
		double newv;
		cin >> newv;
		v[ball_index].setVy(newv);
		break;
		}
	case 5:
		{
		cout << "Please enter new mass :";
		double new_mass;
		cin >> new_mass;
		v[ball_index].setmass(new_mass);
		break;
		}
	}
}
void Fvelocitycalculator(vector<Ball>& v) {
	cout << "Please choose one of the ball in these balls";
	cout << "<-------------------------------------------->";
	
	if (v.size() == 0) {
		cout << "Please firstly add some balls becuase there isn't any ball in the packet :D";
		return;
	}
	for (int i = 0; v.size() > i; i++) {
		cout << "" << i + 1 << ".Mass :" << v[i].getmass() << endl;
		cout << "" << i + 1 << ".Position X :" << v[i].getXx() << endl;
		cout << "" << i + 1 << ".Position Y :" << v[i].getXy() << endl;
		cout << "" << i + 1 << ".Velocity X :" << v[i].getVx() << endl;
		cout << "" << i + 1 << ".Velocity Y :" << v[i].getVy() << endl;
	}
	cout << "Please enter its index :";
	int index_number;
	cin >> index_number;

	cout << "Please enter its accelaration of X component :";
	double acceleration_x;
	cin >> acceleration_x;
	
	cout << "Please enter its acceleration of Y component :";
	double acceleration_y;
	cin >> acceleration_y;

	double  time;
	cout << "Please enter How many second İt ";
	cin >> time;

	double New_velocity_X=double(v[index_number].getVx()) + acceleration_x * time;
	double New_velocity_y = double(v[index_number].getVy()) + acceleration_x * time;

	cout << "New velocity  of X component :" << New_velocity_X << endl;
	cout << "New velocity of Y compoenet :" << New_velocity_y << endl;

}