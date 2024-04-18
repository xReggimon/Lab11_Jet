#include <iostream>

using namespace std;

#define ROWS 13
#define COLS 13
#define ERROR -1

int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][ROWS], int column);

/*char seatingChart[COLS][ROWS] = {
	{'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D'},
	{'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1'},
	{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3'},
	{'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
	{'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}
};*/

char seatingChart[COLS][ROWS] = {
	{'D', 'C', ' ', '1', 'B', 'A'},
	{'D', 'C', ' ', '2', 'B', 'A'},
	{'D', 'C', ' ', '3', 'B', 'A'},
	{'D', 'C', ' ', '4', 'B', 'A'},
	{'D', 'C', ' ', '5', 'B', 'A'},
	{'D', 'C', ' ', '6', 'B', 'A'},
	{'D', 'C', ' ', '7', 'B', 'A'},
	{'D', 'C', ' ', '8', 'B', 'A'},
	{'D', 'C', ' ', '9', 'B', 'A'},
	{'D', 'C', '1', '0', 'B', 'A'},
	{'D', 'C', '1', '1', 'B', 'A'},
	{'D', 'C', '1', '2', 'B', 'A'},
	{'D', 'C', '1', '3', 'B', 'A'},
};



int main() {
	
	string seat;
	int row, col;
	char seatLetter;
	int seatNumber;

	do {
		//Displays seating Chart
		for (int i = 0; i < ROWS; i++) {
			displaySeatColumn(seatingChart, i);
		}
		cout << "Enter a seat or Q to quit: ";
		cin >> seat;

		if (seat[0] == 'Q' || seat[0] == 'q')
			break;

		seatLetter = seat[1];
		seatNumber = seat[0] - '0';

		row = findRowIndex(seatNumber);
		col = findSeatIndex(seatLetter);

		//Occupy seats or indicate error
		if (row == ERROR || col == ERROR) {
			cout << "Sorry, no such seat exists on the CRJ 200. " << endl;
		}
		else {
			if (seatingChart[col][row] != 'X') {
				seatingChart[col][row] = 'X';
				cout << "Seat " << seat << " reserved successfully." << endl;
			}
			else {
				cout << "Seat " << seat << " is already taken." << endl;
			}
		}
	} while (true);

	return 0;

}

int findRowIndex(int thisRow) {
	if (thisRow >= 1 && thisRow <= ROWS) {
		return thisRow - 1;
	}
	else {
		return ERROR;
	}
}

int findSeatIndex(char thisSeat) {
	for (int i = 0; i < COLS; i++) {
			if (seatingChart[i][0] == thisSeat) {
				return i;
			}
		}
	return ERROR;
}

void displaySeatColumn(char seats[][ROWS], int column) {

	for (int i = 0; i < ROWS; i++) {
			cout << seats[i][column] << " ";
	}
	cout << endl;
	
}

