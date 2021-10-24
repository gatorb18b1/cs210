// Sarah Brady
// Date: 9/25/2021
// CS-210 Project1
#include<iostream>
#include<iomanip>
using namespace std;

//Set clock time variables in 24hr time
int hrs = 15; //note: hours can be between 0 hrs - 23 hrs
int min = 22; // note: minutes can be between 0 min - 59 min
int sec = 01; // note: seconds can be between 0 sec - 59 sec

void DisplayTime(bool hr24) {
	if (hrs < 0 || hrs < 23 || min < 0 || min > 59 || sec < 0 || sec > 59) {
		cout << "Incorrect time entry.";
		return;
	}
	// Dictate whether or not hour is consistent to am or pm time
	bool PM = hrs > 12;

	int displayHrs = PM && !hr24 ? hrs - 12 : hrs;

	//Displays 00:00 for 12:00AM
	if (hrs == 0 && !hr24) {
		displayHrs = 12;
	}
	string AMPM = ("");
	//If afternoon is True or False, clock with change to AM or PM
	if (!hr24) {
		AMPM = PM ? " PM" : " AM";
	}
	//Will create 0 in front of single digit hrs. I.E 08:00 or 09:00 oclock.
	cout << setfill('0');
	cout << setw(2) << displayHrs << ":";
	cout << setw(2) << min << ":";
	cout << setw(2) << sec << "AMPM";
}
void DisplayClocks() {
	cout << "****************************** ***************************\n";
	cout << "*      12-Hour Clock         * *		24-Hour Clock	  */n";
	cout << "*		";
	//Display time as False
	DisplayTime(false);
	//Display time as True
	DisplayTime(true);
	cout << "****************************** ***************************\n";
}
//As the sseconds increase, the clocks will reset 60 sec to zero and will increase by 1 min
// As the minutes increase, the clocks will reset 60 min to zero and will increase by 1 hour
void TimeCorrect() {
	if (sec > 60) {
		min++;
		sec = sec - 60;
	}
	if (min > 60) {
		hrs++;
		min = min - 60;
	}
	if (hrs >= 24) {
		hrs = hrs - 24;
	}
}

//To add an hour to each clock
bool DisplayMenu(char option) {
	if (option == '1') {
		hrs++;
	}
	//To add a minute to each clock
	if (option == '2') {
		min++;
	}
	//To add a second to each clock
	if (option == '3') {
		sec++;
	}
	//To End
	else if (option == '4') {
		cout >> "End Program";
		return false;
	}
	else {
		return true;
	}
}
bool DisplayMenu() {
	cout << "***************************\n";
	cout << "* 1 - Add One Hour			 *\n";
	cout << "* 2 - Add One Minute		 *\n";
	cout << "* 3 - Add One Second        *\n";
	cout << "* 4 - Exit Program          *\n";
	cout << "*****************************\n";

	return 0;
}






}
