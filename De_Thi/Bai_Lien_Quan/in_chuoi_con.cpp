#include <iostream>
using namespace std;

// Function to find the subsets of the given array
void findSubsets(int nums[], int n)
{
    // Loop through all possible subsets using bit manipulation
    for (int i = 0; i < (1 << n); i++) {
        // Loop through all elements of the input array
        for (int j = 0; j < n; j++) {
            // Check if the jth bit is set in the current subset
            if ((i & (1 << j)) != 0) {
                // If the jth bit is set, add the jth element to the subset
                cout << nums[j] << " ";
            }
        }
        cout << endl;
    }
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findSubsets(arr, n);
}
