// Binary search on sorted array - recurive solution
// Apr 5, 2019

// There is a bug in this code. Find it! 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int n, int left, int right)
{
    cout << left << " " << right << endl;
    // base condition - one element
    if (left > right)
        return false;
   // base condition - match
    int mid = (right + left)/2;
    if (nums[mid] == n)
        return true;
     // recursively call search on lower half
    else if (n < nums[mid])
        return search(nums, n, left, mid);
    // recursively call search on upper half
    else
        return search(nums, n, mid + 1, right);
  
}

int main()
{
    string s;
    s.append("hi");
    cout << s << endl;
    vector<int> nums{3, 7, 16, 22, 85, 102, 555, 999};
    if (search(nums, 7, 0, nums.size()-1))
        cout << "Number present" << endl;
    else 
        cout << "Number absent" << endl;
}