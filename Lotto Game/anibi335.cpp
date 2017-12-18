//========================================
//  Aniisa Bihi 9512272221
//  LiU id: anibi335
//  Dugga 2
//  Exercise 1
//  Created by Aniisa Bihi on 25/09/2015.
//========================================

#include <iostream>

using namespace std;

int main()
{
    //Declaring Variables and arrays
    int lucky_number, more_tickets, winning_amount = 0, loop = 1;
    const int prize_lucky_number = 2000, prize_all_numbers = 1000,
    SIZE = 10, SIZE2 = 100;
    int a[SIZE], b[SIZE2] = {0};

    //Loop for output/input of ticket numbers
    while (loop)
    {
        //output for ticket numbers
        cout << "Enter your ticket numbers: ";

        //array for input of ticket numbers
        for(int i = 0; i< SIZE; ++i)
        {
            cin >> a[i];
        }

        //Calculation of lucky number
        lucky_number = a[0] + a[9];

        //If ticket numbers include lucky number prize_lucky_number adds on the winning amount
        for( int j = 0; j< SIZE; j++)
        {
            if ( a[j] == lucky_number)
            {
                winning_amount += prize_lucky_number;
            }

        //Saving every ticket number entered, in an array
            b[a[j]] = a[j];
        }

        //Output/input for more tickets
        cout << "One more ticket? ";
        cin >> more_tickets;

        //End loop and display winning amount
        if( more_tickets != loop)
        {
            break;
        }

    }

    //If all the numbers 1-99 are included in ticket numbers,
    //add on prize_all_numbers on winning amount
    for (int k = 1; k < SIZE2; k++)
    {
        if(b[k] == 0)
        {
            break;
        }

        else if (k == SIZE2-1)
        {
            winning_amount += prize_all_numbers;
        }
    }

    //Display winning amount
    cout << "Winning amount = " << winning_amount << endl;

}
