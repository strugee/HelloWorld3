//HelloWorld program
//Written by Alex Jordan
//v0.6a4

/*
 TODO:
Todos have been moved to the readme!
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
using namespace std;

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
bool inputonevalid = false;
bool inputtwovalid = false;
bool calcagain = false;

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
 
 double convertToInt(string input)
{
    bool isCompatible = true;
    int countChars = 0;
    int size = input.size();
    for(; size > countChars && isCompatible == true; countChars++)
    {
        if( (input[countChars] < 48 || input[countChars] > 57) && input[countChars] != '.')
        {
            isCompatible = false;
        }
    }

    double out = 0;
    int decimalPlaced = 0;
    if(isCompatible)
    {
        for(int i = 0; i < countChars; i++)
        {
            if(input[i] == 46)
            {
                decimalPlaced = 1;
            }
            else {
                if(decimalPlaced > 0) {
                    int x = 1;
                    for (int e=decimalPlaced;e>0;e--) {
                        x *= 10;
                    }
                    //my test code
                    double a = input[i]-48;
                    double b = a / x;
                    double c = out + b;
                    out = c;
                    //    real code: out = out + ( (input[i] - 48) / x );
                    //end test code
                    decimalPlaced++;
                }
                else
                {
                    out = ( out * 10 ) + (input[i]-48) ;
                }
            }
        }
    }

    if(isCompatible)
    {
        return out;
    }
    else {
        return -1;
    }
}

int calculate()
{
	// Eventually, calculations will be moved here and calculate() will be called from main(). The output will be 1 or 0, depending on whether it failed or not.
}
	
int main()
{

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
		
		//get the first number and check to make sure a long double variable can handle it
		do {
			cout << "Type a number.\n";
  			string myInput;
  			cin >> myInput;
  		 	double numToCheck = convertToInt(myInput);
			if(numToCheck == -1) {
				cout << "Input is invalid.\n";
				inputonevalid = false;
			} else {
				cout << "Input is valid. Continuing.\n";
				numbers[0] = numToCheck;
				inputonevalid = true;
    		}
		} while (inputonevalid == false);
		
		//function procedure - the loop makes sure the function is valid, and, if not, try again
		do {
			//ask for the function
			cout << "Type a math function. You can type +, -, *, /, square, cube, exponent, sqrt, cbrt, root, logarithm (log), logarithm10 (log10, comlogarithm, comlog, other variants), or factorial (!). Functions in parentheses can be used in place of their preceding functions. For example, ! can be used instead of factorial. \n";
			//get the function
			cin >> mathfunction;
			//check to make sure mathfunction is valid
			if (mathfunction == "+" || mathfunction == "-" || mathfunction == "*" || mathfunction == "/" || mathfunction == "square" || mathfunction == "sqrt" || mathfunction == "factorial" || mathfunction == "!" || mathfunction == "cube" || mathfunction == "exponent" || mathfunction == "cbrt" || mathfunction == "root" || mathfunction == "log" || mathfunction == "logarithm" || mathfunction == "log10" || mathfunction == "logarithm10" || mathfunction == "10logarithm" || mathfunction == "10log" || mathfunction == "commonlogarithm" || mathfunction == "comlogarithm" || mathfunction == "commonlog" || mathfunction == "logcommon" || mathfunction == "logarithmcommon" || mathfunction == "logcom" || mathfunction == "logarithmcom" /*|| mathfunction == "sin" || mathfunction == "sine" || mathfunction == "cos" || mathfunction == "cosine" || mathfunction == "tan" || mathfunction == "tangent"*/) {
				functionvalidator = true;
			}
		} while (functionvalidator == false);
		
		//get the second number (and check to make sure it's valid) unless the function only needed one number
		if (mathfunction == "square" || mathfunction == "sqrt" || mathfunction == "factorial" || mathfunction == "!" || mathfunction == "cube" || mathfunction == "cbrt" || mathfunction == "log10" || mathfunction == "logarithm10" || mathfunction == "10logarithm" || mathfunction == "10log" || mathfunction == "commonlogarithm" || mathfunction == "comlogarithm" || mathfunction == "commonlog" || mathfunction == "logcommon" || mathfunction == "logarithmcommon" || mathfunction == "logcom" || mathfunction == "logarithmcom" || mathfunction == "sin" || mathfunction == "sine" || mathfunction == "cos" || mathfunction == "cosine" || mathfunction == "tan" || mathfunction == "tangent") {
			//do nothing here
		} else {
			do {
				//tell user to type second number
				cout << "Type a second number. \n";
	    	    string myInput;
    		    cin >> myInput;
    		    double numToCheck = convertToInt(myInput);
    		    if(numToCheck == -1)
    		    {
    		        cout << "Input is invalid.\n";
    	    	    inputtwovalid = false;
				} else {
					cout << "Input is valid. Continuing.\n";
   	         		numbers[1] = numToCheck;
					inputtwovalid = true;
				}
   	 		} while (inputtwovalid == false);
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
		//if the math function is a common logarithm, set up some stuff for the logarithm algorithm
		if (mathfunction == "log10" || mathfunction == "logarithm10" || mathfunction == "10logarithm" || mathfunction == "10log" || mathfunction == "commonlogarithm" || mathfunction == "comlogarithm" || mathfunction == "commonlog" || mathfunction == "logcommon" || mathfunction == "logarithmcommon" || mathfunction == "logcom" || mathfunction == "logarithmcom") {
			numbers[1] = 10;
			mathfunction = "log";
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
			if (numbers[1]==0) {
				mfword = "th power";
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
			mfword = "logarithm";
			numbers[2] = log10(numbers[0]) / log10(numbers[1]);
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
		if (mfword == "logarithm") {
			if (numbers[1] == 10) {
				cout << "The common logarithm (base 10) of your number, " << numbers[0] << ", is " << numbers[2] << ".";
			} else {
				cout << "With a base of " << numbers[1] << ", the logarithm of your number, " << numbers[0] << ", is " << numbers[2] << ".";
			}
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
