#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BRUTE FORCE APPROACH
    // This method removes duplicates from a sorted array using a set.
    // 1. Inserts all elements from the input vector into a set, which automatically removes duplicates and sorts the elements.
    // 2. Clears the original vector.
    // 3. Copies the unique, sorted elements from the set back into the vector.
    // 4. Returns the new size of the vector.
    // Time Complexity: O(n log n) because inserting n elements into a set takes O(log n) time per insertion.
    // Space Complexity: O(n) for the set.
    int removeDuplicates(vector<int>& nums) {
        set<int> unums; // Set to store unique elements
        for(auto ele : nums) unums.insert(ele); // Insert all elements into the set
        
        nums.clear(); // Clear the original vector
        
        for(auto ele : unums) nums.push_back(ele); // Copy unique elements back
        
        int k = nums.size(); // New size after removing duplicates
        
        return k;
    }

    // OPTIMAL APPROACH
    // Time Complexity: O(n)
    int removeDuplicates2(vector<int>& arr) {
        int n = arr.size();

        int i = 0;
        for(int j = 1; j < n; j++){
            if(arr[j] != arr[i]){
                arr[i + 1] = arr[j];
                i++;
            }
        }
        // After the loop, 'i' points to the last unique element's index.
        // The number of unique elements is (i + 1).
        // Return the count of unique elements.
        return i+1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    
    int newSize = sol.removeDuplicates(nums);
    cout << "New size after removing duplicates: " << newSize << endl;
    cout << "Array after removing duplicates: ";
    for(int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    vector<int> nums2 = {1, 1, 2, 2, 3, 4, 4, 5};
    int newSize2 = sol.removeDuplicates2(nums2);
    cout << "New size after removing duplicates (Optimal): " << newSize2 << endl;
    cout << "Array after removing duplicates (Optimal): ";
    for(int i = 0; i < newSize2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}