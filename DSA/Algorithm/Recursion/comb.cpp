#include <vector>
#include <iostream>

using namespace std;

void comb(vector<vector<int>> &res, vector<int> &path, int idx, int list[]);

int main() {
	int list[] = {1, 2, 3, 4, 5, 6};
	vector<int> path;
	vector<vector<int>> res;

	comb(res, path, 0, list);
	
	for (int i = 0; i < res.size(); i++) {
		cout << '(';
		for (int j = 0; j < res[i].size(); j++) {
			if (j == res[i].size() - 1) 
				cout << res[i][j];
			else 
				cout << res[i][j] << ',';
		}
		cout << ')';
	}
	cout << endl;

	return 0;
}

void comb(vector<vector<int>> &res, vector<int> &path, int idx, int list[]) {
	if (path.size() == 2) {
		res.push_back(path);
		return;
	}

	for (int i = idx; i < 6; i++) {
		path.push_back(list[i]);
		comb(res, path, idx + 1, list);
		path.pop_back();
	}
}
