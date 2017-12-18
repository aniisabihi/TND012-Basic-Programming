//========================================
//  Aniisa Bihi 9512272221
//  LiU id: anibi335
//  Dugga 3
//  Exercise 1
//  Created by Aniisa Bihi on 10/10/2015.
//========================================

#include <iostream>
#include <cmath>

using namespace std;

//Data type to represent a point in a two-dimensional space.
struct Point {
    double x;
    double y;
};

//Data type to represent a straight line
struct Line {
    double m;
    double b;
};

//Enter m and b values and read a line
struct Line get_line();

//Enter x and y-coordinates and read a point
void get_point(struct Point points[], int n);

//Display points after all calculations and sorting has been made.
void display_point(int option, double x, double y);

//Classify point and determinate its relations to the line
void classify_point(double x, double y, struct Line &line);

//Read all points entered by the user and sort them by increasing distance to the point (0,0)
void read_points(struct Point points[], struct Line &line, int n);

//Input for size of Point struct size.
int num_of_points();

int main()
{

    //Declaring variables
    int number_of_points;
    struct Line line;

    //Input for line's m and b values.
    line = get_line();

    //Get user input for the amount of points.
    number_of_points = num_of_points();

    //Creates a Point array with the chosen size.
    struct Point points[number_of_points];

    //Input of points in data structure.
    get_point(points, number_of_points);

    //Read, sort and display points.
    read_points(points, line, number_of_points);

    return 0;
}


struct Line get_line()
{
    struct Line line;

    cout << "Enter m: ";
    cin >> line.m;
    cout << "Enter b: ";
    cin >> line.b;

    return line;
}


int num_of_points()
{
    //Declaring variables
    int size_points;
    const int MAX = 100;
    const int MIN = 0;

    do
    {
        //User input of total amount of points
        cout << "Enter number of points: ";
        cin >> size_points;

        //Invalid input if the number of points is not between 0-100.
        if(size_points < MIN || size_points > MAX)
            cout << "Invalid number of points!! " << endl;

    }while( size_points < MIN || size_points > MAX );

    return size_points;

}


void get_point(struct Point points[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Enter x-coordinate: ";
        cin >> points[i].x;

        cout << "Enter y-coordinate: ";
        cin >> points[i].y;
        cout << endl;
    }

}


void display_point(int option, double x, double y)
{
    //Switch-case for every display option
    switch(option)
    {
        case 1:
            cout << "Point: (" << x << "," << y << ") is above the line" << endl;
            break;
        case 2:
            cout << "Point: (" << x << "," << y << ") is on the line" << endl;
            break;
        case 3:
            cout << "Point: (" << x << "," << y << ") is below the line" << endl;
            break;
        default:
            cout << "Not a option" << endl;
            break;
    }
}


void classify_point(double x, double y, struct Line &line)
{
    // Above the line
    if( ((x * line.m) - y + line.b) < 0)
    {
        display_point(1, x, y);
    }

    // On the line
    else if( ((x * line.m) + line.b) == y)
    {
        display_point(2, x, y);
    }

    // Below the line.
    else
    {
        display_point(3, x, y);
    }

}


void read_points(struct Point points[], struct Line &line, int n)
{
    //Declaring variables
    int i = 0;
    int sum = 0;
    int ascending = 0;
    const int MAX_VALUE = 1000;


    // Continues until every point is printed.
    while(i <= n)
    {
        // Prints the points in ascending order.
        for(int j = 0; j < n; j++)
        {
            // Takes the sum of x and y squared.
            sum = sqrt(pow(points[j].x, 2) + pow(points[j].y, 2));

            // Prints a point the the sum equals some number in ascending.
            if(sum == ascending)
            {
                classify_point(points[j].x, points[j].y, line);
                i++; // Increments only if a point is printed on the terminal.
            }
        }
        ascending++;

        // Breaks the loop if the loop haven't found a point yet.
        if(ascending > MAX_VALUE)
            i = ascending;
    }
}
