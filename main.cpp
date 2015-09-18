/***************************************************************************** 
   Taylor Hoss
   X432Z869
   Program #3

   This program implements the Fraction class which allows the user to make
   instances of fractions and then do certain manipulations to them:
   returning decimal value, returning reduced fraction, adding, subtracting,
   multiplying, and dividing the fractions using operator overloading. 
    
*/

#include "fraction.cpp"
#include <iostream>
using namespace std;

int main (void)
{

   //declare interface variables
   int choice;
   int tempChoice;
   int inputNum;
   int inputDen;
 
   //setting up fractions
   cout<<"Let's set up two fractions.\n";

   cout<<"Fraction 1:\n";
   cout<<"What should the numerator be?\n";
   cin>>inputNum;
   cout<<"What should the denominator be?\n";
   cin>>inputDen;
   Fraction f1(inputNum, inputDen);   

   cout<<"Fraction 2:\n";
   cout<<"What should the numerator be?\n";
   cin>>inputNum;
   cout<<"What should the denominator be?\n";   
   cin>>inputDen;
   Fraction f2(inputNum, inputDen);

   Fraction f3;
  
   //main loop of prompting user for input and giving output
   //based on users choices                                 
   do
   {

      //prompt user
      cout<<"\nChoose an option:\n";
      cout<<"   1. Add the two fractions.\n";
      cout<<"   2. Subtract the two fractions.\n";
      cout<<"   3. Multiply the two fractions.\n";
      cout<<"   4. Divide the two fractions.\n"; 
      cout<<"   5. Get the decimal equivalent of a fraction.\n";
      cout<<"   6. Reduce a fraction.\n";  
      cout<<"   7. Quit\n";
      
      //get choice (re-prompt if non-valid response)
      do
      {     
         cin>>choice;

      }while ( choice < 1 || choice > 7 );

      //add the fractions
      if ( choice == 1 )
      {
         f3 = f1 + f2;
         
         cout<<"\n"<<f1.get_num()<<"/"<<f1.get_den()<<" + "<<f2.get_num()<<"/"<<f2.get_den()<<" = "
             <<f3.get_num()<<"/"<<f3.get_den()<<".\n\n";

      }

      //subtract the fractions
      if ( choice == 2 )
      {

         do
         {
            cout<<"Which fraction would you like to be subtracted from"
                <<" (1 or 2)?\n";
            cin>>tempChoice;

            if ( tempChoice == 1 )
            {
               f3 = f1 - f2;               

               cout<<"\n"<<f1.get_num()<<"/"<<f1.get_den()<<" - "<<f2.get_num()<<"/"<<f2.get_den()
                   <<" = "<<f3.get_num()<<"/"<<f3.get_den()<<".\n\n";
            }

            if ( tempChoice == 2 )
            {
               f3 = f2 - f1;

               cout<<"\n"<<f2.get_num()<<"/"<<f2.get_den()<<" - "<<f1.get_num()<<"/"<<f1.get_den()
                   <<" = "<<f3.get_num()<<"/"<<f3.get_den()<<".\n\n";
            }

         }while( tempChoice != 1 && tempChoice != 2 );
      }

      //multiply the fractions
      if ( choice == 3 )
      {
         f3 = f1 * f2;
         
         cout<<"\n"<<f1.get_num()<<"/"<<f1.get_den()<<" * "<<f2.get_num()<<"/"<<f2.get_den()<<" = "
             <<f3.get_num()<<"/"<<f3.get_den()<<".\n\n";

      }

      //divided te fractions
      if ( choice == 4 )
      {

         do
         {
            cout<<"Which fraction would you like to be divided"
                <<" (1 or 2)?\n";
            cin>>tempChoice;

            if ( tempChoice == 1 )
            {
               f3 = f1 / f2;               

               cout<<"\n"<<f1.get_num()<<"/"<<f1.get_den()<<" / "<<f2.get_num()<<"/"<<f2.get_den()
                   <<" = "<<f3.get_num()<<"/"<<f3.get_den()<<".\n\n";
            }

            if ( tempChoice == 2 )
            {
               f3 = f2 / f1;

               cout<<"\n"<<f2.get_num()<<"/"<<f2.get_den()<<" / "<<f1.get_num()<<"/"<<f1.get_den()
                   <<" = "<<f3.get_num()<<"/"<<f3.get_den()<<".\n\n";
            }

         }while( tempChoice != 1 && tempChoice != 2 );

      }

      //get the decimal equivalent of a fraction
      if ( choice == 5 )
      {
         
         do
         {
            cout<<"Which fraction would you like the "
                <<"decimal equivalent of (1 or 2 or 3[1/1 by default])?\n";
            cin>>tempChoice;

            if ( tempChoice == 1 )
            {
               cout<<"Decimal equivalent of "<<f1.get_num()<<"/"<<f1.get_den()<<" = "<<f1.get_decimalValue()<<".\n";
            }

            if ( tempChoice == 2 )
            {
               cout<<"Decimal equivalent of "<<f2.get_num()<<"/"<<f2.get_den()<<" = "<<f2.get_decimalValue()<<".\n";
            }

            if ( tempChoice == 3 )
            {
               cout<<"Decimal equivalent of "<<f3.get_num()<<"/"<<f3.get_den()<<" = "<<f3.get_decimalValue()<<".\n";
            }

         }while( tempChoice != 1 && tempChoice != 2 && tempChoice != 3 );   
      }

      if ( choice == 6 )
      {

         do
         {
            cout<<"Which fraction would you like to "
                <<"reduce (1 or 2 or 3[1/1 by default])?\n";
            cin>>tempChoice;

            if ( tempChoice == 1 )
            {
               cout<<"Reduced version of "<<f1.get_num()<<"/"<<f1.get_den()<<" = ";

               f1 = f1.reduce();

               cout<<f1.get_num()<<"/"<<f1.get_den()<<".\n";
            }

            if ( tempChoice == 2 )
            {
               cout<<"Reduced version of "<<f2.get_num()<<"/"<<f2.get_den()<<" = ";

               f2 = f2.reduce();

               cout<<f2.get_num()<<"/"<<f2.get_den()<<".\n";
            }

            if ( tempChoice == 3 )
            {
               cout<<"Reduced version of "<<f3.get_num()<<"/"<<f3.get_den()<<" = ";

               f3 = f3.reduce();

               cout<<f3.get_num()<<"/"<<f3.get_den()<<".\n";
            }

         }while( tempChoice != 1 && tempChoice != 2 && tempChoice != 3 );  

      }

   }while ( choice != 7 );

   //terminate program
   return 0;

}
