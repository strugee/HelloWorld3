//HelloWorld program
//Written by Alex Jordan
//v0.7a1

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

int FailReason;
bool Failed = false;
long double numbers[3];
string mathfunction;
string mfword;
string historyornot;
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
 cout << "You're currently running version 0.7 alpha 1 of this program.";
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

void GetMathFunction()
{
		//function procedure - the loop makes sure the function is valid, and, if not, try again
		do {
			//ask for the function
			cout << "Type a math function. For help, type \"help\". \n";
			//get the function
			cin >> mathfunction;
			if (mathfunction == "help") {
				cout << "You can type: \n+, -, *, / \nsquare, cube, exponent, sqrt, cbrt, root, \nlogarithm (log), logarithm10 (log10, comlogarithm, comlog, other variants), \nor factorial (!).\nFunctions in parentheses can be used in place of their preceding functions. For example, ! can be used instead of factorial.\n";
			}
			//check if user quit
			if (mathfunction == "quit" || mathfunction == "panic" || mathfunction == "exit") {
				cout << "Calculator terminated\n";
				exit(1);
			}
			//check to make sure mathfunction is valid
			functionvalidator = false;
			if (mathfunction == "+" || mathfunction == "-" || mathfunction == "*" || mathfunction == "/" || mathfunction == "square" || mathfunction == "sqrt" || mathfunction == "factorial" || mathfunction == "!" || mathfunction == "cube" || mathfunction == "exponent" || mathfunction == "cbrt" || mathfunction == "root" || mathfunction == "log" || mathfunction == "logarithm" || mathfunction == "log10" || mathfunction == "logarithm10" || mathfunction == "10logarithm" || mathfunction == "10log" || mathfunction == "commonlogarithm" || mathfunction == "comlogarithm" || mathfunction == "commonlog" || mathfunction == "logcommon" || mathfunction == "logarithmcommon" || mathfunction == "logcom" || mathfunction == "logarithmcom" /*|| mathfunction == "sin" || mathfunction == "sine" || mathfunction == "cos" || mathfunction == "cosine" || mathfunction == "tan" || mathfunction == "tangent"*/) {
				functionvalidator = true;
			}
		} while (functionvalidator == false);
}

void GetFirstNumber()
{
		//get the first number and check to make sure a long double variable can handle it
		do {
			bool AskedNumber = false;
			if (mathfunction == "+") {
				cout << "Type the first number to add.\n";
				AskedNumber = true;
			}
			if (mathfunction == "-") {
				cout << "Type the number to subtract from.\n";
				AskedNumber = true;
			}
			if (mathfunction == "*") {
				cout << "Type the first number to multiply.\n";
				AskedNumber = true;
			}
			if (mathfunction == "/") {
				cout << "Type the number to divide.\n";
				AskedNumber = true;
			}
			if (mathfunction == "exponent") {
				cout << "Type the base of the exponent.\n";
				AskedNumber = true;
			}
			if (mathfunction == "square") {
				cout << "Type the number to square.\n";
				AskedNumber = true;
			}
			if (mathfunction == "cube") {
				cout << "Type the number to cube.\n";
				AskedNumber = true;
			}
			if (mathfunction == "sqrt") {
				cout << "Type the number to square root.\n";
				AskedNumber = true;
			}
			if (mathfunction == "cbrt") {
				cout << "Type the number to cube root.\n";
				AskedNumber = true;
			}
			if (mathfunction == "root") {
				cout << "Type the number to root.\n";
				AskedNumber = true;
			}
			if (mathfunction == "log" && numbers[1] != 10) {
				cout << "Type the number inside the logarithm.\n";
				AskedNumber = true;
			}
			if (mathfunction == "log" && numbers[1] == 10) {
				cout << "Type the number inside the logarithm. The base will be 10.\n";
				AskedNumber = true;
			}
			if (mathfunction == "!") {
				cout << "Type the number to factorial.\n";
				AskedNumber = true;
			}
			//fallback question - if the question hasn't been asked yet, fall back to the default, non-contextual question
			if (AskedNumber == false) {
				cout << "Type a number.\n";
			}
  			string myInput;
  			cin >> myInput;
  			//check if user quit
  			if (myInput == "quit" || myInput == "panic" || myInput == "exit") {
	  			cout << "Calculator terminated\n";
	  			exit(1);
  			}
  		 	double numToCheck = convertToInt(myInput);
			if(numToCheck == -1 && myInput != "-1") {
				cout << "Input is invalid.\n";
				inputonevalid = false;
			} else {
				cout << "Input is valid. Continuing.\n";
				numbers[0] = numToCheck;
				inputonevalid = true;
    		}
		} while (inputonevalid == false);
}

void GetSecondNumber() {
		//get the second number (and check to make sure it's valid) unless the function only needed one number
		if (mathfunction == "square" || mathfunction == "sqrt" || mathfunction == "factorial" || mathfunction == "!" || mathfunction == "cube" || mathfunction == "cbrt" || mathfunction == "log10" || mathfunction == "logarithm10" || mathfunction == "10logarithm" || mathfunction == "10log" || mathfunction == "commonlogarithm" || mathfunction == "comlogarithm" || mathfunction == "commonlog" || mathfunction == "logcommon" || mathfunction == "logarithmcommon" || mathfunction == "logcom" || mathfunction == "logarithmcom" || mathfunction == "sin" || mathfunction == "sine" || mathfunction == "cos" || mathfunction == "cosine" || mathfunction == "tan" || mathfunction == "tangent") {
			if (mathfunction == "square") {
				cout << "Since you said to square the number, we don't need a second number.\n";
			}
			if (mathfunction == "cube") {
				cout << "Since you said to cube the number, we don't need a second number.\n";
			}
			if (mathfunction == "sqrt") {
				cout << "The square root function only needs one number.\n";
			}
			if (mathfunction == "cbrt") {
				cout << "The cube root function only needs one number.\n";
			}
			if (mathfunction == "log" && numbers[1] == 10) {
				cout << "Since you specified the common logaithm, a second number is not needed.\n";
			}
			if (mathfunction == "!") {
				cout << "Since you said to factorial, we don't need a second number.\n";
			}
		} else {
			do {
				//tell user to type second number
				bool AskedNumber = false;
				if (mathfunction == "+") {
					cout << "Type the number to be added to your first number.\n";
					AskedNumber = true;
				}
				if (mathfunction == "-") {
					cout << "Type the number to subtract.\n";
					AskedNumber = true;
				}
				if (mathfunction == "*") {
					cout << "Type the second number to multiply.\n";
					AskedNumber = true;
				}
				if (mathfunction == "/") {
					cout << "Type the number to divide by.\n";
					AskedNumber = true;
				}
				if (mathfunction == "exponent") {
					cout << "Type the coefficient of the exponent.\n";
					AskedNumber == true;
				}
				if (mathfunction == "root") {
					cout << "Type the number to root by.\n";
					AskedNumber = true;
				}
				if (mathfunction == "log" && numbers[1] != 10) {
					cout << "Type the base of the logarithm.\n";
					AskedNumber = true;
				}
				//fallback question - if question hasn't been asked yet, fall back to the default, non-contextual question
				if (AskedNumber = false) {
					cout << "Type a second number.\n";
				}
	    	    string myInput;
    		    cin >> myInput;
    		    //check if user quit
    		    if (myInput == "quit" || myInput == "panic" || myInput == "exit") {
	    		    cout << "Calculator terminated\n";
	    		    exit(1);
    		    }
    		    double numToCheck = convertToInt(myInput);
    		    if(numToCheck == -1 && myInput != "-1")
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
}

int calculate()
{
	// calculate() is called from main() now. The output is 1 or 0, depending on whether it failed or not.
	// In addition to returning 1 when it fails, the calculate() function sets the FailReason variable.
	// For a chart of what FailReason values mean, see Fail Values under the Development header in the readme.
	
	// When you add to this, MAKE SURE to add a contextual question for your function in GetFirstNumber() and GetSecondNumber()
	
	// Addition
	if (mathfunction == "+") {
		numbers[2] = numbers[0] + numbers[1];
		mfword = "plus";
		return 0;
	}
	// Subtraction
	if (mathfunction == "-") {
		numbers[2] = numbers[0] - numbers[1];
		mfword = "minus";
		return 0;
	}
	
	// Multiplication
	if (mathfunction == "*") {
		if (numbers[0] == numbers[1]) {
			mathfunction = "exponent";
			numbers[1] = 2;
		} else {
			numbers[2] = numbers[0] * numbers[1];
			mfword = "times";
		}
		return 0;
	}
	
	// Division
	if (mathfunction == "/") {
		// Check if user divided by 0
		if (numbers[1] == 0) {
			/*cout << "Done.\n";
			cout << "Your first number, " << numbers[0] << ", divided by your second number, 0 , is negative infinity and positive infinity.";
			cout << "\nThank you for using this program. To close, hit any key. \n";
			system("pause");
			return 0; */
			FailReason = 0;
			Failed = true;
			return 1;
		// If they didn't divide by 0, do the calculations
		} else {
			numbers[2] = numbers[0] / numbers[1];
			mfword = "divided by";
			return 0;
		}
	}
	
	// Exponents
	if (mathfunction == "exponent") {
		exponent = true;
		numbers[2]=1;
		// Do the actual calculations
		for (int i=numbers[1];i>0;i--) {
			numbers[2]*=numbers[0];
		}
		// Set stuff up to be outputted
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
		return 0;
	}
	if (mathfunction == "sqrt")	{
		// Check if user attempted to root a negative number. If not, do the calculations.
		if (numbers[0]>0) {
			numbers[2] = sqrt(numbers[0]);
			mfword = "square root";
			return 0;
		// If user *did* attempt to root a negative number, fail and exit
		} else {
			FailReason = 1;
			Failed = true;
			return 1;
		}
	}
	
	// Roots
	if (mathfunction == "root") {
		root = true;
		// Calculations
		numbers[2] = pow(numbers[0], (1.0/numbers[1]));
		// Stuff for the output
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
		return 0;
	}
	
	// Logarithms
	if (mathfunction == "log" || mathfunction == "logarithm") {
		mfword = "logarithm";
		numbers[2] = log10(numbers[0]) / log10(numbers[1]);
	}
	
	// Factorials
	if (mathfunction == "!" || mathfunction == "factorial") {
		// See if the number is not 0. If it's not, continue.
		if (numbers[0] != 0) {
			// See if number is smaller than 13. If not, calculate the factorial
			if (numbers[0]<13) {
				numbers[2]=1;
				for (int i=1; i<=numbers[0]; i++) {
					numbers[2] *= i;
				}
			// If number *is* bigger than 13, fail and exit
			} else {
				FailReason = 2;
				Failed = true;
				return 1;
			}
			mfword = "factorial";
			return 0;
		// If the number to factorial *was* 0, set the answer to 1
		} else {
			numbers[2] = 1;
			mfword = "factorial";
			return 0;
		}
	}
}

void printresults()
{
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
	cout << "I'm a C++ program!\n";
	
	/*
	 //get the input and assign it to the historyornot variable
	 cin >> historyornot;
	 //read historyornot and go to the history procedure if it says yes
	 if (historyornot=="yes") {history();}
	 */
	
	do {
		
		GetMathFunction();

		//if the math function is a common logarithm, set up some stuff for the logarithm algorithm
		if (mathfunction == "log10" || mathfunction == "logarithm10" || mathfunction == "10logarithm" || mathfunction == "10log" || mathfunction == "commonlogarithm" || mathfunction == "comlogarithm" || mathfunction == "commonlog" || mathfunction == "logcommon" || mathfunction == "logarithmcommon" || mathfunction == "logcom" || mathfunction == "logarithmcom") {
			numbers[1] = 10;
			mathfunction = "log";
		}
		
		GetFirstNumber();

		GetSecondNumber();
		
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
		int calculateexit;
		calculateexit = calculate();
		if (calculateexit == 0) {
			cout << "Done.\n";
		} else {
			string FailOutput;
			if (FailReason == 0 && Failed == true) {
				FailOutput = "user attempted to divide by zero";
			}
			if (FailReason == 1 && Failed == true) {
				FailOutput = "complex numbers using i are not supported";
			}
			if (FailReason == 2 && Failed == true) {
				FailOutput = "number to factorial is too big";
			}
			cout << "Failed.\nInvalid operation: " << FailOutput << ", exiting...\n";
			cout << "Calculator terminated\n";
			return 1;
		}
		//end of calculations
		
		// Print the results
		printresults();
		
		//ask the user if they want to use again
		cout << "\nWould you like to use the calculator again? y/n: ";
		cin >> ccalcagain;
		if (ccalcagain == 'y') {calcagain = true;} else {calcagain = false;}
		
	} while (calcagain == true);
	
	cout << "Calculator terminated\n";
	
	//exit the program
	return 0;
}


/*int main()
 {
 main1();
 }*/
