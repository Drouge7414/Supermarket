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

   // Read first record 
   cout << "Enter day of week or done to quit: ";
   cin >> dayOfWeek;
 
   if(dayOfWeek  == SENTINEL)
      notDone = false;
   else
   {
      cout << "Enter hours worked: ";
      cin >> hoursTotal;
      prevDay = dayOfWeek;
      hoursWorked += hoursTotal;
      cout << dayOfWeek <<": " << hoursTotal << endl;
   
   }	   
		
   
   
  
      // Implement control break logic here
      // Include work done in the dayChange() function


    // Loop to process subsequent days and accumulate totals.
    while (notDone)
    {
        cout << "Enter day of week or done to quit: ";
        cin >> dayOfWeek;
         cout << "Enter hours worked: ";
            cin >> hoursTotal;

        if (dayOfWeek == SENTINEL)
            notDone = false;
        else
        {
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
    }

    // Output the final day's total after exiting the loop.
    if (dayOfWeek == SENTINEL)
        cout << "\t\t" << DAY_FOOTER << hoursWorked << endl;

    return 0;
}
