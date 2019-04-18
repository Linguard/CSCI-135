
#include <iostream>
#include <vector>

using namespace std;

// A helper function adding up numbers in the array
int addUp(int arr[], int N);

int main() {

    const unsigned int CAPACITY = 8;
    int arr [CAPACITY] = {3, 6, 200, 4, 16000, 2, 4000, 25};

    // Part 1.
    // Maximum (correct answer 16000 at index [4])

    int max_i = 0;
    int max_val = 0;
    for(int i = 0; i < CAPACITY; i++) {		//BUG: i > CAPACITY is always false, so this loop is never used. CORRECTED to i < CAPACITY
        if (arr[i] > max_val) {
            max_val = arr[i];			//BUG: max_val not taking maximum value. semi-colon after if statement making it end prematurely. CORRECTED: remove ; after if statement
            max_i = i;
        }
    }
    cout << "Maximum: " << max_val << " ";
    cout << "at index " << max_i << endl << endl;


    // Part 2.
    // Minimum (correct answer 2 at index [5])

    int min_i = 0;
    int min_val = 1000000000;
    for(int i = 0; i < CAPACITY; i++) {
        if (arr[i] < min_val) {			//BUG: Since min_val = 0, every value in the array is higher than it. so min_val stays 0. CORRECTED min_val to 1 billion  
            min_val = arr[i];
            min_i = i;				//BUG: used max_i instead of min_i. CORRECTED max_i to min_i
        }
    }
    cout << "Minimum: " << min_val << " ";
    cout << "at index " << min_i << endl << endl;


    // Part 3.
    // Max difference arr[i+1] - arr[i] (correct answer 15996 at index [3])

    int max_diff = arr[1] - arr[0];
    int max_diff_i = 0;
    for(int i = 0; i < (CAPACITY-1); i++) {	

        int diff = arr[i+1] - arr[i];		//BUG: the highest value we are getting is at index 7. CORRECTED for loop to have i < (CAPACITY - 1)
        if (diff > max_diff) {			//BUG: The conditions after if statement were not enclosed in curly brackets. CORRECTED
            max_diff_i = i;
            max_diff = diff;
        }
    }

    cout << "Maximum difference: " << max_diff << " ";
    cout << "at index " << max_diff_i << endl << endl;


    // Part 4.
    // Mean value (correct answer in 2530)
    double sum = addUp(arr, CAPACITY);
    double mean = sum / CAPACITY;
    cout << "Mean value of the array elements: " << mean << endl << endl;


    // Part 5.
    // Maximum (a revisited implementation)

    max_i = 0;
    for(int i = 0; i < CAPACITY; i++) {
        if (arr[i] > arr[max_i])
            max_i = i;				//BUG: max_i was set to arr[i]. this was setting max_i to the value not the index of the array. CORRECTED max_i to i
    }
    cout << "Maximum (revisited): " << arr[max_i] << " ";
    cout << "at index " << max_i << endl << endl;

}


int addUp(int arr[], int N) {

    int sum = 0;

    for(int i = 0; i < N; i++) {
        sum += arr[i];				//BUG: variable sum was not adding anything from the array. CORRECTED: sum += arr[i]
    }
    return sum;

}






