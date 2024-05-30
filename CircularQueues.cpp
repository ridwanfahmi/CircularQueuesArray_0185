#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];


public:
	Queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;

		//cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		//cek apakah atrian kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//jika rear berada di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}

		queue_array[REAR] = num;
	}

	void remove() {
		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

		//cek jika atrian hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika elemen dihapus berada di posisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;

		}
	}

	void display() {
		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElement in the queue are...\n";

		//jika front <= rear, iterasi dari front hingga rear
		if (FRONT <= REAR) {
			while (FRONT <= REAR) {
				cout << queue_array[FRONT] << " ";
				FRONT++;
			}
			cout << endl;
		}
		else {
			//jika front > rear, iterasi dai front hingga akhir array
			while (FRONT <= max - 1) {
				cout << queue_array[FRONT] << " ";
				FRONT++;
			}

			FRONT = 0;

			//iterasi dari awal array hingga rear
			while (FRONT <= REAR) {
				cout << queue_array[FRONT] << " ";
				FRONT++;

			}
			cout << endl;
		}
	}
};

int main() {
	Queues q;
	
}