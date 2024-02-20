#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Date.h"
#include "SortArr.h"

bool Isleapyear(int year);
int HowManyDays(int month, int year);
void checkDate(Date& other);


template<class T>
int SortArr<T>::_amount = 0;

template<class T>
int SortArr<T>::_lengthSum = 0;


int main() {

	int _size;
	int _addValue;

	cout << "!!!INT ARRAYS!!!\n\n";
	SortArr<int> _intArr1;
	cout << "PLease enter the size of the first int array-->";
	cin >> _size;
	for (int i = 0; i < _size; i++) {
		cout << "\nPlease enter the " << i + 1 << " Value for the int array--> ";
		cin >> _addValue;
		_intArr1 += _addValue;
	}

	SortArr<int> _intArr2;
	cout << "PLease enter the size of the second int array-->";
	cin >> _size;
	for (int i = 0; i < _size; i++) {
		cout << "\nPlease enter the " << i + 1 << " Value for the int array--> ";
		cin >> _addValue;
		_intArr2 += _addValue;
	}

	if (_intArr2 == _intArr1) {
		cout << "The arrays are equal" << endl;
		_intArr1.print();

	}

	else {
		cout << "The arrays arent equal" << endl;
		_intArr1.print();
		_intArr2.print();
	}
	cout << "\n\n\n\n\n\n\n";


	cout << "!!!DATE ARRAYS!!!\n\n";



	bool  val;
	SortArr<Date> darr;
	SortArr<Date> darr1;
	Date _dateAddValue;


	try {

		cout << "Please enter the size of the first date array--> ";
		cin >> _size;
		for (int i = 0; i < _size; i++) {
			cout << "Please enter the date (day/month/year)-->";
			cin >> _dateAddValue;
			checkDate(_dateAddValue);
			val = darr += _dateAddValue;
		}
		darr.print();


		cout << "Please enter the size of the first date array--> ";
		cin >> _size;
		for (int i = 0; i < _size; i++) {
			cout << "Please enter the date (day/month/year)-->";
			cin >> _dateAddValue;
			checkDate(_dateAddValue);
			val = darr1 += _dateAddValue;
		}
		darr1.print();

		if (darr1 == darr) {
			cout << "The arrays are equal\n";
		}
		else
			cout << "The arrays arent equal\n";


		cout << "\nPlease enter the Value you want to add  to the first int array--> ";
		cin >> _addValue;
		_intArr1 += _addValue;
		cout << "The new one--> " << _intArr1;

		cout << "\nPlease enter the Value you want to add  to the second int array--> ";
		cin >> _addValue;
		_intArr2 += _addValue;
		cout << "The new one--> " << _intArr2;


		cout << "\nPlease enter the Value you want to add  to the first Date array--> ";
		cin >> _dateAddValue;
		darr += _dateAddValue;
		cout << "The new one--> " << darr;



		cout << "\nPlease enter the Value you want to add  to the second Date array--> ";
		cin >> _dateAddValue;
		darr1 += _dateAddValue;
		cout << "The new one--> " << darr1;
		cout << "\n\n\n\n";


		cout << "\nfirst int array--> " << _intArr1;
		cout << "\nsecond int array--> " << _intArr2;
		cout << "\nfirst date array--> " << darr;
		cout << "\nsecond date array--> " << darr1;

		cout << "int arrays:\n";
		_intArr1.print_Static();

		cout << "\n\nDate arrays:\n";
		darr.print_Static();


	}
	catch (int a) {
		cout << "You did something wrong and got to the catch block sorry please review the error message above and try again thank you and goodbye" << endl;
	}



	return 0;
}


bool Isleapyear(int year) {
	// leap year if perfectly divisible by 400
	if (year % 400 == 0) {
		return true;
	}
	// not a leap year if divisible by 100
	// but not divisible by 400
	else if (year % 100 == 0) {
		return false;
	}
	// leap year if not divisible by 100
	// but divisible by 4
	else if (year % 4 == 0) {
		return true;
	}
	// all other years are not leap years
	else {
		return false;
	}
}

int HowManyDays(int month, int year) {
	switch (month) {
	case 1:
		return 31;
	case 2:
		if (Isleapyear(year)) {
			return 29;
		}
		else
			return 28;
	case 3:
		return 31;
	case 5:
		return 31;
	case 7:
		return 31;
	case 8:
		return 31;
	case 10:
		return 31;
	case 12:
		return 31;
	default:
		return 30;
	}
}




void checkDate(Date& other) {
	if (other.getYear() < 1000) {
		cout << "Bad year\n";
		throw other.getYear();
	}

	if (Isleapyear(other.getYear()) && other.getMonth() == 2) {//if it is a leap year and the month isnt feburary then the leap year doesnt matter//
		if (other.getDay() > 29 || other.getDay() < 1) {
			cout << "Bad day you entered a leap year which means in feburay there are  29 days\n";
			throw other.getDay();
		}
	}
	if (other.getMonth() < 1 || other.getMonth() > 12) {
		cout << "Bad month\n";
		throw other.getMonth();
	}

	if (other.getDay() < 1 || other.getDay() > HowManyDays(other.getMonth(), other.getYear())) {
		cout << "You have entered a bad day the day for the month you chose should be between 1 to " << HowManyDays(other.getMonth(), other.getYear()) << endl;
		throw other.getDay();
	}
}
