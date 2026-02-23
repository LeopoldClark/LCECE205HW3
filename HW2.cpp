#include <iostream> //include iostream library for I/O
#include <cmath> //include cmath library for sqrt function

using namespace std; //default std namespace

int j, i = 1; //define global integer variables
float a, b, c, s, area; //define global float variables

//function prototypes
float edgesIn(float &edge, int j);
void Area(float a, float b, float c, float &s, float &area);
void repeat();

int main(){

    while (i == 1){ //initilize while loop for continuation
        edgesIn(a, 1); //request user input for edge 1
        edgesIn(b, 2); //request user input for edge 2
        edgesIn(c, 3); //request user input for edge 3
        Area(a, b, c, s, area); //calculate area given user inputs

        if(area == 0){
            cout << "\nThe area of the triangle is: 00000000" << endl; //output area of triangle
        }else{
        cout << "\nThe area of the triangle is: " << area << endl; //output area of triangle
        }

        repeat(); //prompt user for continuation
    }

    if (i == 0){ //if user doesn't wish continuation end program
        cout << "\nHope to assist again soon!" << endl; //program end output
    }

    return 0; //end main function
}

float edgesIn(float &edge, int j){ //build function promting user edge inputs
    cout << "Enter the length of a edge " << j << ": " << endl; //prompt user
    cin >> edge; //assign input

    return edge; //return user input
}

void Area(float a, float b, float c, float &s, float &area){ //build function calculating area of trianle
    s = (.5) * (a + b + c); //calculate semiperimeter
    if (a <= 0 or b <= 0 or c <= 0){ //any invalid inluputs
        area = 0; //assign area to invalid output
    }else if (s <= a or s <= b or s <= c){ //if semiperimeter is less than or equal to any edge
        area = 0; //assign area to invalid output
    }else{ //if all inputs are valid
    area = sqrt(s * (s - a) * (s - b) * (s - c)); //calculate area
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