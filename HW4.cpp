#include <iostream> //include iostream library for I/O
#include <cmath> //include cmath library for abs function

using namespace std; //default std namespace

int lb, oz, kg, g, i = 1; //define global integer variables

//function prototypes
void weightIn(int &lb, int &oz);
void conversion(int lb, int oz, int &kg, int &g);
void weightOut(int kg, int g);
void repeat();

int main(){

    while (i == 1){ //initilize while loop for continuation
        weightIn(lb, oz); //request user inputs for weight in pounds and ounces
        conversion(lb, oz, kg, g); //convert user input weight in pounds and ounces to kilograms and grams
        weightOut(kg, g); //output converted weight in kilograms and grams
        repeat(); //prompt user for continuation
    }

    if (i == 0){ //if user doesn't wish continuation end program
        cout << "\nHope to assist again soon!" << endl; //program end output
    }

    return 0; //end main function
}

void weightIn(int &lb, int &oz){ //build input function with reference params lb and oz
    cout << "\nPlease enter the pounds (lb) of your weight: " << endl; //prompt user for pounds
    cin >> lb; //assign user input to lb
    while (lb < 0){ //if user's input is invalid
        cout << "\nPlease enter a valid weight in pounds: " << endl; //prompt user for valid input
        cin >> lb; //assign user input to lb
    }

    cout << "\nPlease enter the ounces (oz) of your weight: " << endl; //prompt user for ounces
    cin >> oz; //assign user input to oz
    while (oz < 0 or oz > 15){ //if user's input is invalid
        cout << "\nPlease enter a valid weight in ounces: " << endl; //prompt user for valid input
        cin >> oz; //assign user input to oz
    }
}

void conversion(int lb, int oz, int &kg, int &g){ //build function converting lb and oz to kg and g with reference params kg and oz
    kg = (lb * 0.453592) + (oz * 0.0283495); //convert weight in pounds and ounces to kilograms
    g = abs((((lb * 0.453592) + (oz * 0.0283495)) - kg) * 1000); //calculate grams from kilograms
}

void weightOut(int kg, int g){ //build function outputting conversion
    cout << "\nYour weight in kilograms is: " << kg << " kg and " << g << " g." << endl; //output converted weight
}

void repeat(){ //build function for continuation
    cout << "\nWould you like to convert another time? 1 for yes, 0 for no: " << endl; //prompt user for continuation
    cin >> i; //assign user input to i
    while (i != 0 and i != 1){ //if user's input is invalid
        cout << "\nPlease try again, 1 for yes, 0 for no: " << endl; //prompt user for valid input
        cin >> i; //assign user input to i
    }
}