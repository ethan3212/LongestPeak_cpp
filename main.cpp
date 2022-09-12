#include <iostream>
#include <vector>
using namespace std;

// O(n) time | O(1) space
int longestPeak(vector<int> &array) {
    int longestPeakFoundSoFar = 0;// O(1) space
    int index = 1;// O(1) space
    while(index < int(array.size() - 1)) {// O(n) time
        bool peak = (array[index] > array[index - 1] && array[index] > array[index + 1]);// O(1) time
        if(!peak) {// O(1) time
            index++;// O(1) time | O(1) space
            continue;
        }
        int left = index - 2;// O(1) space
        int right = index + 2;// O(1) space
        while(left >= 0 && array[left] < array[left + 1]) {// O(n) time
            left--;// O(1) time | O(1) space
        }
        while(right < array.size() && array[right] < array[right - 1]) {// O(n) time
            right++;// O(1) time | O(1) space
        }
        int currentPeakLength = right - left - 1;// O(1) time | O(1) space
        longestPeakFoundSoFar = max(longestPeakFoundSoFar, currentPeakLength);// O(1) time | O(1) space
        index = right;// O(1) time | O(1) space
    }
    return longestPeakFoundSoFar;
}

int main() {
    vector<int> input = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    cout << longestPeak(input) << endl;
    return 0;
}
