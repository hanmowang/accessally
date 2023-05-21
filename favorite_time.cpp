#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int favorite_time(int n) {
    int answer = 0;
    int first_digit = 1;
    int second_digit = 2;
    int third_digit = 0;
    int fourth_digit = 0;

    // The clock will go back to 12:00 after 720 minutes
    int count = n / 720;
    // There are 31 arithmetic sequences from 12:00 to 11:59
    answer = count * 31;
    n = n % 720;

    for (int i = 0; i < n; i++) {
        // Updating the clock
        fourth_digit++;
        third_digit += fourth_digit / 10;
        second_digit += third_digit / 6;
        if (first_digit == 0) {
            first_digit += second_digit / 10;
            second_digit = second_digit % 10;
        }
        else if (second_digit == 3) {
            first_digit = 0;
            second_digit = 1;
        }
        fourth_digit = fourth_digit % 10;
        third_digit = third_digit % 6;
        first_digit = first_digit % 2;

        int diff = third_digit - second_digit;

        if (first_digit == 0 && fourth_digit - third_digit == diff) {
            answer++;
        }
        else {
            if (second_digit - first_digit == diff && fourth_digit - third_digit == diff) {
                answer++;
            }
        }
    }
    
    return answer;
}

int main() {
    int n;
    cin >> n;
    cout << favorite_time(n) << endl;
    return 0;
}

