/*
 * Calculator.cpp
 *
 *  Date: 5/23/2020
 *  Author: Adam Putnick
 */

#include <iostream>
using namespace std;


void main()
{
	char statement[100];
	int op1, op2;
	char operation;
	char answer = 'y';//change " to ' which is used with char added missing semicolon
	while (answer == 'y' || answer == 'Y') //added or so program catches people who maybe enter Y
	{
		std::cout << "Enter expression" << endl;
		cin >> op1 >> operation >> op2; //corrected order to of inputs
		if (operation == '+') {
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;//corrected arrows from input to output arrows
		}
		else if (operation == '-') {
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;//corrected arrows from input to output arrows
		}
		else if (operation == '*') {
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;//added semicolon fixed operation so output is correct

		}
		else if (operation == '/') {
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; //fixed operation so output is correct
		}
		cout << "Do you wish to evaluate another expression? y/n" << endl; // added y/n so user has some clue what to enter for another expression
		cin >> answer;
	}
}






