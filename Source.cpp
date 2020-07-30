#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;

void DisplayMenu() {//function that prints the menu when called.
	string userSelection = "";
	cout << "**********************************\n";
	cout << "* Enter 1 to add an hour.        *\n";
	cout << "* Enter 2 to add a minute.       *\n";
	cout << "* Enter 3 to add a second.       *\n";
	cout << "* Enter Exit to end the program. *\n";
	cout << "**********************************\n";
	
}
string FormatTime(int timeToFormat) {//function that formats the time correctly for times less than 10.
	string formattedTime = "";
	if (timeToFormat > 10) {//If statement that checks for proper formating if the number is greater than 10 time is converted to string.
		formattedTime = to_string(timeToFormat);
	}
	else {//If the variable is less than 10 it is converted to a string and a 0 is added in front.
		formattedTime = "0" + to_string(timeToFormat);
	}
	return formattedTime;// Returns the formatted variable.
}
void Show12Hour(int inputTime) {//function that calculates and displays the 12 hour clock.
	int hours = inputTime / 3600;//variable to hold the hours and the formula to initialize it
	int minutes = inputTime % 3600 / 60;//variable to hold the minutes and the formula to initialize it
	int seconds = inputTime % 3600 % 60;//variable to hold the seconds and the formula to initialize it

	if (hours == 0) {//if statement that handles the error of a 12 hour clock not having a 0 hour.
		hours = 12;
	}
	if (hours > 12) {//if statement that converts 24 hour time to 12 hour time
		hours = hours - 12;
	}
	// the next lines print out the formatted clock
	cout << "*****************\n";
	cout << "* 12 hour clock *\n";
	cout <<"*    "<< FormatTime(hours) << ":" << FormatTime(minutes) << ":" << FormatTime(seconds) <<"   *"<< endl;
	cout << "*****************\n";
}
void Show24Hour(int inputTime ) {//function that calculates and displays the 24 hour clock.
	int hours = inputTime / 3600;//variable to hold the hours and the formula to initialize it
	int minutes = inputTime % 3600 / 60;//variable to hold the minutes and the formula to initialize it
	int seconds = inputTime % 3600 % 60;//variable to hold the seconds and the formula to initialize it

	// the next lines print out the formatted clock
	cout << "*****************\n";
	cout << "* 24 hour clock *\n";
	cout << "*    " << FormatTime(hours) << ":" << FormatTime(minutes) << ":" << FormatTime(seconds) << "   *" << endl;
	cout << "*****************\n";
}
int UserUpdateTime(int inputTime, string userSelection) {//function that takes the users input and updates the time.
	if (userSelection == "1") {// this if statement adds an hour if the user selects it
		inputTime = inputTime + 3600;
	}
	else if (userSelection == "2") {// this if statement adds an minute if the user selects it
		inputTime = inputTime + 60;
	}
	else if (userSelection == "3") {// this if statement adds an second if the user selects it
		inputTime = inputTime + 1;
	}
	else if (userSelection == "exit" || userSelection == "Exit") {//Ends the program when the user is finished
		cout << "Program end.\n";
		Sleep(1000);//pauses the program for 1 second before exiting
		exit(0);//terminates the program
	}
	else {//here anything entered not on the menu is returned with an error
		cout << "ERROR please try again.\n";
	}
	
return inputTime;
}
int main() {
	int inputTime=0;    // this variable holds the time in seconds
	string userSelection = ""; // allows user to select from menu

	while (userSelection !="exit" || userSelection != "Exit") {//Main loop of program repeats until user exits.
		system("cls");//used to clear the screen and prevent clutter.
		cout << "Press any key to open the menu." << endl;
		if (inputTime >= 86400) { inputTime = 0; }//If statement that checks for time overflow resetting the time at the end of a day.
		Show24Hour(inputTime);
		Show12Hour(inputTime);
			if(_kbhit()){//If loop to that waits for a keyboard press that interupts the main while loop.
				_getch();// getch is used to remove the kbhit character from the input buffer.
				DisplayMenu();
				cin >> userSelection;//the user is able to make a selection from the menu here.
				inputTime = UserUpdateTime(inputTime, userSelection); //update the clock depending what the user inputs.
				Sleep(1000);//pauses the loop for 1 second.
		}
			else {//if the user does nothing the clock increase by 1 second every second
				Sleep(1000);//pauses the loop for 1 second.
				inputTime++;//increments the clock by one second
			}
		

		
	}
	return 0;
}