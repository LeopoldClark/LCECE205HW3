#include <iostream> //include iostream library for I/O

using namespace std; //default std namespace

int minutes, hours, i = 1; //define global integer variables
char out; //define global character variables

//function prototypes
int timeIn();
void conversion(char &out);
int timeOut();
int repeat();

int main(){

    while (i == 1){ //if user wishes to continue repeat main function
        timeIn(); //request user intputs
        conversion(out); //convert user input
        timeOut(); //output converted time
        repeat(); //prpmpt user for continuation
    }

    if (i == 0){ //if user doesn't wish continuation end program
        cout << "\nHope to assist again soon!" << endl; //program end output
    }

    return 0; //end main function
}

int timeIn(){ //build function prompting and assigning user input
    cout << "\nEnter the hour: " << endl; //prompt user for hours
    cin >> hours; //assigns user input to hours
    while (hours < 0 or hours > 23){ //if user's input is invaid
        cout << "\nPlease try again from 0 to 23: " << endl; //prompt user for valid input
        cin >> hours; //assign users input to hours
    }

    cout << "\nEnter the minutes: " << endl; //prompt user for minutes
    cin >> minutes; //assign user input to minutes
    while (minutes < 0 or minutes > 59){ //if user's input is invalid
        cout << "\nPlease try again from 0 to 59: " << endl; //prompt user for valid input
        cin >> minutes; //assign user input to minutes=
    }

    return 0; //end funtion
}

void conversion(char &out){ //build function converting user inputs to standard time with reference paramater for output
    if (hours < 12){ //if user's input hours is less than 12
        out = 'A'; //assign standard to AM
    }else if (hours > 12){ //if user's input hours is greater than 12
        hours = hours - 12; //convert hours to standard time
        out = 'P'; //assign standard to PM
    }else{ //if user's input hours is 12
        out = 'P'; //assign standard to PM
    }
}

int timeOut(){ //build function outputting converted time
    cout << "\nYour time in standard is: " << hours << ":" << minutes << out << endl; //output converted time

    return 0; //end function
}

int repeat(){ //build function for continuation
    cout << "\nWould you like to convert another time? 1 for yes, 0 for no: " << endl; //prompt user for continuation
    cin >> i; //assign user input to i
    while (i != 0 and i != 1){ //if user's input is invalid
        cout << "\nPlease try again, 1 for yes, 0 for no: " << endl; //prompt user for valid input
        cin >> i; //assign user input to i
    }

    return 0; //end function
}