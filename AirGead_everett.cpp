#include <iostream>
#include <iomanip>

using namespace std;

//Declaring variables as floats
float monthDepo, iInvest, anInterest, yrs, mnths, intrestAmnt, totalAmount, yearToInterest;

int main() { //creation of user menu
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Depozit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	system("PAUSE");
	system("CLS");
	
	//obtaining user input
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amout: $";
	cin >> iInvest;
	if (iInvest < 0) { //conditional set multi option
		cout << "Initial investment amount can't be less than $0" << endl;
		cout << "Initial Investment Amount: $";
		cin >> iInvest;
	}

	cout << "Monthly Deposit: $";
	cin >> monthDepo;
	if (monthDepo < 0) {
		cout << "Initial investment amount can't be less than $0" << endl;
		cout << "Monthly Deposit: $";
		cin >> monthDepo;
	}

	cout << "Annual Interest: %";
	cin >> anInterest;
	cout << "Number of years: ";
	cin >> yrs;
	mnths = yrs * 12;
	system("PAUSE");
	system("CLS");

	totalAmount = iInvest; // total amount and inital set the same so it chan be changed
	//table shown with data from year without monthly deposits
	cout << " Balance and Interest Without Additional Monthly Deposits" <<
		endl;
	cout << "================================================================="
		<< endl;
	cout << " Year Year End Balance Year End Earned Interest" <<
		endl;
	cout << "-----------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < yrs; i++) {
		//yearly intrest formula 
		intrestAmnt = (totalAmount) * ((anInterest / 100));

		//calculation for year end total
		totalAmount = totalAmount + intrestAmnt;
		//results shown on tabel with limit of two variable points
		cout << " " << (i + 1) << "\t\t$" << fixed << setprecision(2) <<
			totalAmount << "\t\t\t$" << intrestAmnt << "\n";
	}
	
	totalAmount = iInvest; // total amount and inital set the same so it chan be changed
	//table shown with data from year with monthly deposits
	cout << endl;
	cout << " Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "=================================================================" << endl;
	cout << " Year Year End Balance Year End Earned Interest" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	for (int i = 0; i < yrs; i++) {
		yearToInterest = 0; //yearly intrest is set to zero

		for (int j = 0; j < 12; j++) {
			
			//calculation for monthly intrest
			intrestAmnt = (totalAmount + monthDepo) * ((anInterest / 100) / 12);
			
			//calculation for end of month intrest
			yearToInterest = yearToInterest + intrestAmnt;

			//calulation for end of month total
			totalAmount = totalAmount + monthDepo + intrestAmnt;

		}

		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearToInterest << "\n";
	}

	return 0;
		
}