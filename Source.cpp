#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
string superuser[2][10];
float pricetoday[10];
string show[2][10];
float showp[10];
void cw1(string superuser[2][10]);
void cw2(string superuser[2][10],float pricetoday[10]);
void cw3(string superuser[2][10],string show[2][10], float showp[10]);
void cw4(string superuser[2][10], float pricetoday[10], string show[2][10], float showp[10]);
void cw5(string superuser[2][10], float pricetoday[10], string show[2][10], float showp[10]);
void cw6();
void Showmenu() {
	cout << "1. Add customer information ::" << endl;
	cout << "2. Add vehicle information ::" << endl;
	cout << "3. Car rental ::" << endl;
	cout << "4. Return the car ::" << endl;
	cout << "5. Report ::" << endl;
	cout << "6. Exit ::" << endl;
}
void semenu(char &menu) {
sw:
	cout << "Select your menu in choice : ";
	cin >> menu;
	switch (menu) {
		case '1': cw1(superuser); break;
		case '2': cw2(superuser,pricetoday); break;
		case '3': cw3(superuser,show, showp); break;
		case '4': cw4(superuser, pricetoday, show, showp); break;
		case '5': cw5(superuser, pricetoday, show, showp); break;
		case '6': cw6(); break;
		default : goto sw;
	}
}
int main() {
	char menu = ' ';
	superuser[0][0] = "ten";
	superuser[1][0] = "Iesuzu";
	pricetoday[0] = 600.00;
	while(menu != '6'){
		Showmenu();
		semenu(menu);
	}
	system("pause");
	return 0;
}
void cw1(string superuser[2][10]) {
	string user;
	system("cls");
	cout << "::You select Add customer information::" << endl;
	cout << "Enter username : ";
	cin >> user;
	for (int x = 0; x < 10; x++) {
		
		if (user == superuser[0][x]) {
			cout << "overlord name\nSelect Chooice again." << endl;
			break;
		}
		else if (superuser[0][x].empty()) {
			superuser[0][x] = user;
			cout << "Completed" << endl;
			break;
		}
	}
}
void cw2(string superuser[2][10],float pricetoday[10]) {
	string user,car;
	float price;
	system("cls");
	cout << "::You select Add customer information::" << endl;
	cout << "Enter username : ";
	cin >> user;
	for (int x = 0; x < 10; x++) {
		if (user == superuser[0][x]) {
			cout << "Enter carname : ";
			cin >> car;
			cout << "Enter price to day : ";
			cin >> price;
			for (int j = 0; j < 10; j++){
				if (superuser[1][j].empty()) {
					superuser[1][j] = car;
					pricetoday[j] = price;
					cout << "Completed is brand" << endl;
					break;
				}
			}	
		}
	}
}
void cw3(string superuser[2][10], string show[2][10], float showp[10]) {
	string user;
	int count = 1;
	bool lo = false;
	system("cls");
	cout << "::You select Car rental::" << endl;
	cout << "Enter username : ";
	cin >> user;
	cout << "\t\t*Booking status*" << endl;
	cout << setfill('=') << setw(90) << "\n";
	cout << setfill(' ') << "No." << setw(10) << "username" << setw(10) << "brand cars." << setw(30) << "total price." << endl;
	for (int i = 0; i < 10; i++) {
		if (!show[1][i].empty()) {
			cout << i + 1 << setw(10) << show[0][i] << setw(10) << show[1][i] << setw(30) << showp[i] << endl;
		}
	}
	cout << setfill('=') << setw(90) << "\n\n\n\n\n";
	for (int x = 0; x <= 10; x++) {
		if (user == superuser[0][x]) {
			lo = true;
			cout << setfill('=') << setw(90) << "\n";
			cout << setfill(' ') << "No." << setw(10) <<"brand cars." << setw(30) << "price to day." << endl;
			for (int i = 0; i < 10; i++) {
				if (!superuser[1][i].empty()) {
					cout << count++ <<setw(10)<< superuser[1][i] << setw(30) << pricetoday[i] << endl;
				}
				else break;
			}
			cout << setfill('=') << setw(90) << "\n";
			break;
		}
		if (x == 10) {
			cout << "We not fould you.\nSelect Chooice again." << endl;
			break;
		}
	}
	int select,menycar,menyday;
	float total=0;
	char ch=' ';
	if (lo == true) {
		for (int i = 0;; i++) {
			if (show[0][i].empty()) {
				int day[] = { 22,10,2020 };
				show[0][i] = user;
				cout << "Select the item to rent.";
				cin >> select;
				select--;
				cout << "You select " << superuser[1][select] << "" << endl;
				show[1][i] = superuser[1][select];
				cout << "How many cars do you need : ";
				cin >> menycar;
				cout << "How many days do you want to rent : ";
				cin >> menyday;
				day[0] += menyday;
				while (day[0] > 30) {
					day[1]++;
					day[0] -= 30;
					while (day[1] > 12) {
						day[2]++;
						day[1] -= 12;
					}
				}
				cout << "Period from 22/10/2020 :: ";
				cout << day[0] << "/" << day[1] << "/" << day[2] << endl;
				cout << endl;
				total = menycar * pricetoday[select] * menyday;
				showp[i] = total;
			k:
				cout << "You need more? (Y/N)";
				cin >> ch;
				if (ch == 'n' || ch == 'N') {
					break;
				}
				else if (ch == 'y' || ch == 'Y') {
					cout << "Add Agin" << endl;
					total = 0;
					menyday = 0;
					menycar = 0;
					select = 0;
				}
				else {
					cout << "Plase put Y. or N." << endl;
					goto k;
				}
			}	
		}
	}
}
void cw4(string superuser[2][10], float pricetoday[10],string show[2][10], float showp[10]) {
	int count = 1;
	string user;
	system("cls");
	cout << "::You select Add customer information::" << endl;
	cout << "Enter username : ";
	cin >> user;
	cout << setfill('=') << setw(90) << "\n";
	cout << setfill(' ') << "No." << setw(10) << "brand cars." << setw(30) << "total price."<< setw(20)<<"status" << endl;
	for (int i = 0; i <= 10; i++) {
		if (user == show[0][i]) {
			cout << count++ << setw(10) << show[1][i] << setw(30) << showp[i] << setw(25) << "Completed return" << endl;
			show[0][i] = {};
			show[1][i] = {};
			showp[i] = {};
		}
	}
		cout << setfill('=') << setw(90) << "\n";
}
void cw5(string superuser[2][10], float pricetoday[10], string show[2][10], float showp[10]) {
	int count = 1;
	cout << setfill('=') << setw(80) << "\n";
	cout << setfill(' ') << "No." << setw(10)<<"username"<<setw(10) << "brand cars." << setw(30) << "total price." << setw(30) << "status" << endl;
	for (int i = 0; i < 10; i++) {
		if (!show[1][i].empty()) {
			cout << count << setw(10)<< show[0][i]<<setw(10)<< show[1][i] << setw(30) << showp[i] << setw(35) << "Not returned" << endl;
		}
		count++;
	}
	cout << setfill('=') << setw(90) << "\n";
}
void cw6() {
	cout << "Exit Program" << endl;
	system("exit");
}