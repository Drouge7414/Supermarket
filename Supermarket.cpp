// SuperMarket.cpp - This program creates a report that lists weekly hours worked 
// by employees of a supermarket. The report lists total hours for 
// each day of one week. 
// Input:  Interactive
// Output: Report. 

#include <iostream>
#include <string>
using namespace std;
int main() 
{
   // Declare variables.
   const string HEAD1 = "WEEKLY HOURS WORKED";
   const string DAY_FOOTER = "                              Previous Day Total ";
   // Leading spaces in DAY_FOOTER are intentional.
   const string SENTINEL = "done";  // Named constant for sentinel value. 
   double hoursWorked = 0;  // Current record hours.
   string dayOfWeek;  // Current record day of week.
   double hoursTotal = 0;  // Hours total for a day.
   string prevDay = "";  // Previous day of week.
   bool notDone = true;  // loop control
  
   // Print two blank lines.
   cout << endl << endl; 
   // Print heading.
   cout << "\t\t\t\t\t" << HEAD1 << endl;
   // Print two blank lines.
   cout << endl << endl;  

   // Implement control break logic here
   // Include work done in the dayChange() function


   while (notDone) {
       cout << "Enter day of week or done to quit: ";
       cin >> dayOfWeek;

	   //Before we proceed, we need to check if the user wants to quit.
       if (dayOfWeek == SENTINEL) {
		   notDone = false; //Since we are breaking out of the loop, setting notDone to false is kinda redundant, but it's good practice.
		   break; //have to break out of the loop. None of the code below and inside this loop will be executed
       }

       //Since we are not quitting, we can proceed with the rest of the program.
	   cout << "Enter hours worked: ";
       cin >> hoursTotal;

	   //Here we check if user entered the same day as the previous day.
       if (dayOfWeek == prevDay) {
		   //prevDay = dayOfWeek; //This line is not needed, because both dayOfWeek and prevDay are already the same.
		   hoursTotal = hoursTotal + hoursTotal; // Accumulate total hours worked for this same day.
		   hoursWorked = hoursWorked + hoursTotal; //Accumulating total hours worked for the week.
       }
       else { //If it's a new day...
           prevDay = dayOfWeek; //Set the previous day to the current day.
		   hoursWorked += hoursTotal; //Updating weekly total hours worked.
       }

       cout << "\t\t" << DAY_FOOTER << hoursTotal << endl;
       cout << dayOfWeek << ": " << hoursTotal << endl;
   }


   if (hoursTotal > 0) {
       cout << "\t\t" << DAY_FOOTER << hoursTotal << endl;
	   cout << "\t\t" << "Weekly Total: " << hoursWorked << endl; //Output the total hours worked for the week.
   }
   return 0;

}
