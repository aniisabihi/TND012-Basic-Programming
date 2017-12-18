//========================================
//  Aniisa Bihi 9512272221
//  LiU id: anibi335
//  Dugga 1
//  Exercise 1
//  Created by Aniisa Bihi on 11/09/2015.
//========================================

#include <iostream>
#include <iomanip> //setprecision
#include <cstdlib> //rand
#include <ctime> //time


using namespace std;

int main()
{
    //Declaring Variables
    double total_prize = 0;
    int number = 0, number1 = 0, number2 = 0;
    int lucky_number = 0, lucky_number1 = 0, lucky_number2 = 0;
    const double MAX = 99, MIN = 0, EXACT_MATCH_PRIZE = 10.000,
    DIGITS_MATCH_PRIZE = 5.000, ONE_DIGIT_MATCH_PRIZE = 1.000;


    //Welcome message
    cout << "Welcome to the guessing game. Guess a number between 0-99 to win money!" << endl;
    cout << "If you wish to stop playing, enter a negative number or a three digit number." << endl;


    while ( number >= MIN && number <= MAX )
    {
        //Output instructions for user
        //User input of number
        cout << "Guess a number: ";
        cin >> number;            //read number

        //Seperating number by first and second digit
        number1 = number / 10;
        number2 = number % 10;


        //Invalid input f user enters a negative integer or a 3 digit number
        //Finish lottery and display total amount won
        if ( number < MIN || number > MAX )
        {
            cout << "Total amount earned = " << total_prize << " sek!!" << endl;

            return 0;
        }

        //initialize the random number generator
        srand( time(0) );

        //Generate a number between 0-99 for lucky number
        //Seperating lucky_number by first and second digit
        lucky_number = rand() % 100;
        lucky_number1 = lucky_number / 10;
        lucky_number2 = lucky_number % 10;


        //Output of lucky number
        cout << "Your lucky number = " << lucky_number << endl;

        //Output for prize for exact match
        if ( number1 == lucky_number1 && number2 == lucky_number2 )
        {
            //Display Prize
            cout << "Exact match: You win " << fixed << setprecision(3)
                 << EXACT_MATCH_PRIZE << " sek!!" << endl;

            //Total prize
            total_prize = total_prize + EXACT_MATCH_PRIZE;
        }

        //Output of prize if lucky number is number reversed
        else if ( number1 == lucky_number2 && number2 == lucky_number1 )
        {
            //Display Prize
            cout << "Digits match: You win " << fixed << setprecision(3)
                 << DIGITS_MATCH_PRIZE << " sek!!" << endl;

            //Total prize
            total_prize = total_prize + DIGITS_MATCH_PRIZE;
        }

        //Output of prize if one digit from lucky number matches one digit from number
        else if( number1 == lucky_number1 || number2 == lucky_number2 )
        {
            //Display Prize
            cout << "One Digit match: You win " << fixed << setprecision(3)
                 << ONE_DIGIT_MATCH_PRIZE << " sek!!" << endl;

            //Total prize
            total_prize = total_prize + ONE_DIGIT_MATCH_PRIZE;
        }

        else if( number1 == lucky_number2 || number2 == lucky_number1 )
        {
            //Display Prize
            cout << "One Digit match: You win " << fixed << setprecision(3)
                 << ONE_DIGIT_MATCH_PRIZE << " sek!!" << endl;

            //Total prize
            total_prize = total_prize + ONE_DIGIT_MATCH_PRIZE;
        }

        //Output if number isn't at all the same as the lucky number
        else
        {
            //Display loss
            cout << "Nothing to win!!" << endl;
        }

    }
}
