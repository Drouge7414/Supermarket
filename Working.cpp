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

    // Loop to process subsequent days and accumulate totals.
    while (notDone)
    {
        cout << "Enter day of week or done to quit: ";
        cin >> dayOfWeek;

		//Before we proceed, we need to check if the user wants to quit.
        if (dayOfWeek == SENTINEL) {
			notDone = false; //Since we are breaking out of the loop, setting notDone to false is kinda redundant, but it's good practice.
			break; //have to break out of the loop. None of the code below and inside this loop will be executed
        }

		//Proceed with the rest of the program, since the user doesn't want to quit.
        cout << "Enter hours worked: ";
        cin >> hoursTotal;

        // Control break logic: Check if day has changed.
        if (dayOfWeek != prevDay)
        {
              // Output the previous day's total before resetting.
              cout << "\t\t" << DAY_FOOTER << hoursWorked << endl;
              prevDay = dayOfWeek;
              hoursWorked = 0; // Reset daily total for new day.
        }

        // Prompt for hours worked on current day.
        hoursWorked += hoursTotal; // Accumulate total hours worked.
        cout << dayOfWeek << ": " << hoursTotal << endl;
    }

    // Output the final day's total after exiting the loop.
	//if (dayOfWeek == SENTINEL) //This is not needed, since the loop will only exit if the user enters "done"
    cout << "\t\t" << DAY_FOOTER << hoursWorked << endl;

    return 0;
}
