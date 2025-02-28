#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSum(vector<int> nums, int target, vector<int> &memo);

int main(int argc, char *argv[]) {
	
	vector<int> case1 = {2,3,5};
	vector<int> case2 = {2,4};
	vector<int> case3 = {7,14};

	vector<int> memo1(10 ,2);
	vector<int> memo2(7, 2);
	vector<int> memo3(300, 2);

	// Test cases
	cout << "1. " << (canSum(case1, 10, memo1) ? "true" : "false") << endl;
	cout << "2. " << (canSum(case2, 7, memo2) ? "true" : "false") << endl;
	cout << "3. " << (canSum(case3, 300, memo3) ? "true" : "false") << endl;

	return 0;
}


bool canSum(vector<int> nums, int target, vector<int> &memo) {
	if (memo[target] != 2) return memo[target];
	if (target == 0) return true;
	if (target < 0) return false;

	int n = nums.size();

	for (int i = 0; i < n; i++) {
		int temp = target - nums[i];
		if (canSum(nums, temp, memo) == true) {
			return memo[target] = true;
		}
	}
	
	return memo[target] = false;
}

