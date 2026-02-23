#include <iostream> //include iostream library for I/O

using namespace std; //default std namespace

int startT, endT, startH, startM, endH, endM, T, i = 1; //define global integer variables

//function prototypes
void betweenT (int &startT, int &endT , int &T);
void repeat();

int main(){

    while (i == 1){ //initilize while loop for continuation
    betweenT(startT, endT, T); //request user inputs and calculate minutes between
    cout << "\nThe time between the two times is: " << T << endl; //output time between
    repeat(); //prompt user for continuation
    }

    if(i == 0){ //if user doesn't wish to continue
        cout << "\nHope to assist again soon!" << endl; //output program end
    }

    return 0; //end main function
}

void betweenT (int &startT, int &endT, int &T){ //build input and calculation function
    cout << "\nEnter the start time in 24 hour format: " << endl; //prompt user for start time
    cin >> startT; //assign user input to startT
    while (startT < 0 or startT > 2359 or startT % 100 > 59){ //if user's input is invalid
        cout << "\nPlease enter a valid time from 0000 to 2359: " << endl; //prompt user for valid input
        cin >> startT; //assign user input to startT
    }

    cout << "\nEnter the end time in 24 hour format: " << endl; //prompt user for end time
    cin >> endT; //assign user input to endT
    while (endT < 0 or endT > 2359 or endT % 100 > 59){ //if user's input is invalid
        cout << "\nPlease enter a valid time from 0000 to 2359: " << endl; //prompt user for valid input
        cin >> endT; //assign user input to endT
    }

    startH = startT / 100; //calculate start hours
    startM = startT % 100; //calculate start minutes
    endH = endT / 100; //calculate end hours
    endM = endT % 100; //calculate end minutes

    startT = (startH * 60) + startM; //convert start time to minutes
    endT = (endH * 60) + endM; //convert end time to minutes

    T = endT - startT; //calculate minutes between
    if (T < 0){ //if minutes between is negative or wraping to next day
        T = T + (24 * 60); //add 24 hours in minutes to T
    }
}

void repeat(){ //build function for continuation
    cout << "\nWould you like to convert another time? 1 for yes, 0 for no: " << endl; //prompt user for continuation
    cin >> i; //assign user input to i
    while (i != 0 and i != 1){ //if user's input is invalid
        cout << "\nPlease try again, 1 for yes, 0 for no: " << endl; //prompt user for valid input
        cin >> i; //assign user input to i
    }
}