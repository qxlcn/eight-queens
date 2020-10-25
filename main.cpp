#include <iostream>
using namespace std;

int tot = 0;
int ans[9] = {0};

void print() {
    tot++;
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (ans[i] / 10 == j) cout << '@';
			else cout << 'O';
		}
		cout << endl;
	}
	cout << endl;
}

int available(int x, int y) {
	for (int i = 1; i < 9; i++)
		if (ans[i] != 0)
			if (x == ans[i]/10 || x+y == ans[i]/10+ans[i]%10 || x-y == ans[i]/10-ans[i]%10)
				return false;
    return true;
}

void search(int y) {
	for (int x = 1; x < 9; x++) {
		if (available(x, y)) {
			ans[y] = x * 10 + y;
			if (y == 8) print();
			else search(y + 1);
			ans[y] = 0;
		}
	}
}

int main() {
	search(1);
	cout << "Total: " << tot <<endl;
    return 0;
}
