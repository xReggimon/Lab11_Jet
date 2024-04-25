#include <iostream>
using namespace std;

const int ROWS = 13;
const int COLS = 8;

int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][ROWS], int column);

int row;
char cols;
int arrayRow;
int arrayCol;

char seats[COLS][ROWS] = {
	{'D','D','D','D','D','D','D','D','D','D','D','D',' '},
	{'C','C','C','C','C','C','C','C','C','C','C','C',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ','1','1','1','1'},
	{'1','2','3','4','5','6','7','8','9','0','1','2','3'},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{'B','B','B','B','B','B','B','B','B','B','B','B','B'},
	{'A','A','A','A','A','A','A','A','A','A','A','A','A'}
};


int main() {
	
	for (int i = 0; i < COLS; i++) {
		displaySeatColumn(seats, i);
		cout << endl;
	}

	cout << "---------------------------------" << endl;

	cout << "Enter a seat or Q to quit: ";

	while (cin >> row >> cols) {
		arrayCol = findSeatIndex(cols);
		arrayRow = findRowIndex(row);
		if (cols == 'D' || cols == 'C') {
			if (row == 13) {
				cout << "Sorry, no such seat exists on the CRJ 200." << endl;
				cout << "Enter a seat or Q to quit: ";
				continue;
			}
		}
		if (arrayRow == -1) {
			cout << "Sorry, no such seat exists on the CRJ 200." << endl;
			cout << "Enter a seat or Q to quit: ";
			continue;
		}
		if (arrayCol == -1) {
			cout << "Sorry, no such seat exists on the CRJ 200." << endl;
			cout << "Enter a seat or Q to quit: ";
			continue;
		}
		if (seats[arrayCol][arrayRow] != 'X') {
			seats[arrayCol][arrayRow] = 'X';
		}
		else {
			cout << "This seat is already taken, please pick another seat." << endl;
			cout << "Enter a seat or Q to quit: ";
			continue;
		}
		
		for (int i = 0; i < COLS; i++) {
			displaySeatColumn(seats, i);
			cout << endl;
		}
		cout << "---------------------------" << endl;
		cout << "Enter a seat or Q to quit: ";
	}
	return 0;
}

//finds the desired row
int findRowIndex(int thisRow) {
	if (thisRow < 14 && thisRow > 0) {
		return thisRow - 1;
	}
	else {
		return -1;
	}
}

//finds the desired column
int findSeatIndex(char thisSeat) {
	switch (thisSeat) {
	case 'A':
		return 7;
	case 'B':
		return 6;
	case 'C':
		return 1;
	case 'D':
		return 0;
	default:
		return -1;
	}
}
//updates the seating chart
void displaySeatColumn(char seats[][ROWS], int column) {

	for (int i = 0; i < ROWS; i++) {
			cout << seats[column][i] << " ";
	}
}

