//HelloWorld program
//Written by Alex Jordan
//v0.6a4

/*
 TODO:
 1. Implement a number validator for inputs
 2. Implement logarithm function
 3. Implement trig functions
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
using namespace std;

/*int exit() //to call, type exit(1);
 {
 //exit();
 return 0;
 }*/

/*static int history()
 {
 cout << "This program was developed by Alex Jordan on the 20th of June, 2011, at iD Tech Camps using Microsoft Visual C++ 2010 Express./n";
 cout << "You're currently running version 0.6 alpha 3 of this program.";
 cout << "/n";
 system("pause");
 main1();
 return 0;
 }*/

int main()
{
	long double numbers[3];
	string mathfunction;
	string mfword;
	string historyornot;
	string endinput;
	char ccalcagain;
	bool functionvalidator = false;
	bool exponent = false;
	bool exponentsquare = false;
	bool exponentcube = false;
	bool root = false;
	bool inputonevalidator = true;
	bool inputtwovalidator = true;
	bool calcagain = false;

	/*		//"initialize" and display title
	 cout << "Initializing... \n";
	 Sleep(2000);
	 cout << "Number Processor version 0.5a4 \n";
	 Sleep(1000); */
	
	//print functions
	cout << "Hello World!\n";
	cout << "I'm a C++ program! ";
	
	/*
	 //get the input and assign it to the historyornot variable
	 cin >> historyornot;
	 //read historyornot and go to the history procedure if it says yes
	 if (historyornot=="yes") {history();}
	 */
	
	do {
		
		//get the first number as long as it's a value a double variable can handle
		do {
			cout << "Type a number.\n";
			cin >> numbers[0];
			//			if () {inputonevalidator = true;}
		} while (inputonevalidator == false);
		
		//function procedure - the loop makes sure the function is valid, and, if not, try again
		do {
			//ask for the function
			cout << "Type a math function. You can type +, -, *, /, square, cube, exponent, sqrt, cbrt, root, or factorial (!). Functions in parentheses can be used in place of their preceding functions. For example, ! can be used instead of factorial. \n";
			//get the function
			cin >> mathfunction;
			//check to make sure mathfunction is valid
			if (mathfunction == "+" || mathfunction == "-" || mathfunction == "*" || mathfunction == "/" || mathfunction == "square" || mathfunction == "sqrt" || mathfunction == "factorial" || mathfunction == "!" || mathfunction == "cube" || mathfunction == "exponent" || mathfunction == "cbrt" || mathfunction == "root" || mathfunction == "sin" || mathfunction == "sine" || mathfunction == "cos" || mathfunction == "cosine" || mathfunction == "tan" || mathfunction == "tangent") {
				functionvalidator = true;
			}
		} while (functionvalidator == false);
		
		//get the second number (and check to make sure it's valid) unless the function only needed one number
		if (mathfunction == "square" || mathfunction == "sqrt" || mathfunction == "factorial" || mathfunction == "!" || mathfunction == "cube" || mathfunction == "cbrt" || mathfunction == "sin" || mathfunction == "sine" || mathfunction == "cos" || mathfunction == "cosine" || mathfunction == "tan" || mathfunction == "tangent") {
			//do nothing here
			
		} else {
			do {
				//tell user to type second number
				cout << "Type a second number. \n";
				//get the second number
				cin >> numbers[1];
				//					if () {inputtwovalidator = true;}
			} while (inputtwovalidator == false);
		}
		
		//if the math function is a square or a cube, set up some stuff for the exponent algorithm
		if (mathfunction == "square") {
			numbers[1] = 2;
			mathfunction = "exponent";
		}
		if (mathfunction == "cube") {
			numbers[1] = 3;
			mathfunction = "exponent";
		}
		//if the math function is a cube root, set up some stuff for the root algorithm
		if (mathfunction == "cbrt") {
			numbers[1] = 3;
			mathfunction = "root";
		}
		
		//calculations
		cout << "Calculating... ";
		if (mathfunction == "+") {
			numbers[2] = numbers[0] + numbers[1];
			mfword = "plus";
		}
		if (mathfunction == "-") {
			numbers[2] = numbers[0] - numbers[1];
			mfword = "minus";
		}
		if (mathfunction == "*") {
			if (numbers[0] == numbers[1]) {
				mathfunction = "exponent";
				numbers[1] = 2;
			} else {
				numbers[2] = numbers[0] * numbers[1];
				mfword = "times";
			}
		}
		if (mathfunction == "/") {
			if (numbers[1] == 0) {
				/*cout << "Done.\n";
				 cout << "Your first number, " << numbers[0] << ", divided by your second number, 0 , is negative infinity and positive infinity.";
				 cout << "\nThank you for using this program. To close, hit any key. \n";
				 system("pause");
				 return 0; */
				cout << "Failed.\nInvalid operation: user attempted to divide by zero, exiting\n";
				system("pause");
				return 0;
			} else {numbers[2] = numbers[0] / numbers[1];};
			mfword = "divided by";
		}
		if (mathfunction == "exponent") {
			exponent = true;
			numbers[2]=1;
			for (int i=numbers[1];i>0;i--) {
				numbers[2]*=numbers[0];
			}
			if (numbers[1]==1) {
				mfword = "st power";
			}
			if (numbers[1]==2) {
				mfword = "square";
				exponentsquare = true;
			}
			if (numbers[1]==3) {
				mfword = "cube";
				exponentcube = true;
			}
			if (numbers[1]>3) {
				mfword = "th power";
			}
		}
		if (mathfunction == "sqrt")	{
			if (numbers[0]>0) {
				numbers[2] = sqrt(numbers[0]);
				mfword = "square root";
			} else {
				cout << "Failed.\nInvalid operation: i is not supported, exiting\n";
				system("pause");
				return 0;
			}
		}
		if (mathfunction == "root") {
			root = true;
			numbers[2] = pow(numbers[0], (1.0/numbers[1]));
			if (numbers[1] == 1) {
				mfword = "1st root";
			}
			if (numbers[1] == 2) {
				mfword = "square root";
			}
			if (numbers[1] == 3) {
				mfword = "cube root";
			}
			if (numbers[1] > 3) {
				mfword = "th root";
			}
		}
		if (mathfunction == "log" || mathfunction == "logarithm") {
			//Abandon?
		}
		if (mathfunction == "!" || mathfunction == "factorial") {
			if (numbers[0] != 0) {
				if (numbers[0]<13) {
					numbers[2]=1;
					for (int i=1; i<=numbers[0]; i++) {
						numbers[2] *= i;
					}
				} else {
					cout << "Failed.\nInvalid operation: number to factorial is too big, exiting\n";
					system("pause");
					return 0;
				}
				mfword = "factorial";
			} else {
				numbers[2] = 1;
				mfword = "factorial";
			}
		}
		
		cout << "Done.\n";
		//end of calculations
		
		if (mfword == "plus" || mfword == "minus" || mfword == "times" || mfword == "divided by") {
			cout << "Your first number, " << numbers[0] << ", " << mfword << " your second number, " << numbers[1] << ", is " << numbers[2] << ".";
		}
		if (mfword == "square root" || mfword == "cube root" || mfword == "sin" || mfword == "sine" || mfword == "cos" || mfword == "cosine" || mfword == "tan" || mfword == "tangent" || mfword == "factorial") {
			cout << "The " << mfword << " of your number, " << numbers[0] << ", is " << numbers[2] << ".";
		}
		if (exponent == true) {
			if (exponentsquare == false && exponentcube == false) {
				cout << "When your number, " << numbers[0] << ", is raised to the " << numbers[1] << mfword << ", it equals " << numbers[2] << ".\n";
			}
			if (exponentsquare == true || exponentcube == true)
				cout << "The " << mfword << " of your number, " << numbers[0] << ", is " << numbers[2] << ".\n";
		}
		if (root == true && mfword != "square root" && mfword != "cube root") {
			cout << "The " << numbers[1] << mfword << " of your number, " << numbers[0] << ", is " << numbers[2] << ".";
		}
		
		//ask the user if they want to use again
		cout << "\nWould you like to use the calculator again? y/n\n";
		cin >> ccalcagain;
		if (ccalcagain == 'y') {calcagain = true;} else {calcagain = false;}
		
	} while (calcagain == true);
	
	//new line and instructions to close
	cout << "\nThank you for using this program. To close, type anything and hit enter. \n";
	
	
	//wait for the user to input something
	cin >> endinput;
	
	//exit the program
	return 0;
}


/*int main()
 {
 main1();
 }*/
