/**
 * Approach:
 * 
 * 1. Define a helper function to determine if a given year is a leap year.
 *    - A year is considered a leap year if it is divisible by 4.
 *    - However, if the year is divisible by 100, it is not a leap year unless it is also divisible by 400.
 *    - This function will be used to adjust the days in February for leap years.
 * 
 * 2. Create a function `dayOfTheWeek` that calculates the day of the week for a given date.
 *    - The function takes three parameters: day, month, and year.
 *    - An array `answer` is defined with the days of the week starting from "Sunday" to "Saturday".
 *    - An array `months` is defined with the number of days in each month, assuming it is not a leap year.
 * 
 * 3. Adjust the `months` array for leap years.
 *    - If the given year is a leap year, set the number of days in February to 29.
 * 
 * 4. Initialize a variable `sum` to 4.
 *    - This is because January 1, 1971, is a Friday. Using 0-based indexing, Friday is represented by 4.
 * 
 * 5. Calculate the total number of days from January 1, 1971, to the given date.
 *    - Iterate through each year from 1971 to the year before the given year.
 *      - For each year, add 366 to `sum` if it is a leap year, otherwise add 365.
 *    - Iterate through each month from January to the month before the given month in the given year.
 *      - Add the number of days in each month to `sum`.
 *    - Finally, add the day of the given month to `sum`.
 * 
 * 6. Determine the day of the week.
 *    - Use the modulus operator to find the remainder when `sum` is divided by 7.
 *    - This remainder corresponds to the index in the `answer` array, representing the day of the week.
 * 
 * 7. Return the day of the week.
 * 
 * Time Complexity: O(Y + M)
 * - Y is the difference in years from 1971 to the given year.
 * - M is the number of months in the given year.
 * 
 * Space Complexity: O(1)
 * - The space used by the program does not grow with the input size. We use a constant amount of extra space regardless of the input.
 * 
 * Author: Kiran Jojare
 */

#include <stdio.h>
#include <stdbool.h>

// Function to determine if a given year is a leap year
bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

// Function to get the day of the week for a given date
char* dayOfTheWeek(int day, int month, int year) {
    char *answer[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap year
    if (isLeapYear(year)) {
        months[1] = 29;  // February has 29 days in a leap year
    }

    int sum = 4;  // January 1, 1971 is a Friday (index 4)

    // Add days for each year from 1971 to the given year
    for (int i = 1971; i < year; i++) {
        if (isLeapYear(i)) {
            sum += 366;
        } else {
            sum += 365;
        }
    }

    // Add days for each month in the given year
    for (int i = 0; i < month - 1; i++) {
        sum += months[i];
    }

    // Add days for the current month
    sum += day;

    return answer[sum % 7];
}

int main() {
    int day, month, year;
    
    // Example 1
    day = 31;
    month = 8;
    year = 2019;
    printf("The day of the week for %d/%d/%d is %s\n", day, month, year, dayOfTheWeek(day, month, year));
    
    // Example 2
    day = 18;
    month = 7;
    year = 1999;
    printf("The day of the week for %d/%d/%d is %s\n", day, month, year, dayOfTheWeek(day, month, year));
    
    // Example 3
    day = 15;
    month = 8;
    year = 1993;
    printf("The day of the week for %d/%d/%d is %s\n", day, month, year, dayOfTheWeek(day, month, year));
    
    return 0;
}
