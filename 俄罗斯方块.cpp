#include<iostream>
#include<vector>
using namespace std;
int YN(int temp[][4], int space[][10], int n, int m) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (temp[i][j] == 1 && space[i + m - 2][j + n - 1] == 1)
				return 0;
		}
	}
	return 1;
}
void move(int temp[][4], int space[][10], int n, int m) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (temp[i][j])
				space[i + m - 2][j + n - 1] = 1;
		}
	}
	
	
}
int main()
{
	int space[15][10];
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 10; j++)
			cin >> space[i][j];
			
	int temp[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> temp[i][j];
	int n;
	cin >> n;
	int k;
	int m = 14;
	for (int i = 3; i >= 0; i--) {
		int j;
		for (j = 0; j < 4; j++)
			if (temp[i][j])
				break;
		if (j != 4)
			break;
		m++;
	}
	for (k = 0; k < m; k++) {
		if (!YN(temp, space, n, k))
			break;
	}
	move(temp, space, n, k-1);
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++)
			cout << space[i][j] << " ";
		cout << endl;
	}
	getchar();
	getchar();
	return 0;
}