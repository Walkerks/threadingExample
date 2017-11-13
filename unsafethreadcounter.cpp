#include <cstdlib>
#include <thread>
#include <iostream>

//Count up to
#define STOPNUM 1500

unsigned long long counter = 1;			//The shared counter

void countOdds() {
	for (;;) {
		if (counter % 2 != 0) {
			std::cout << counter << std::endl;
		}

		counter++;
		if (counter >= STOPNUM) {
			break;
		}
	}
}

void countEvens() {
	for (;;) {
		if (counter % 2 == 0) {
			std::cout << counter << std::endl;
		}
		counter++;
		if (counter >= STOPNUM) {
			break;
		}
	}
}


int main() {
	//creats and starts two threads
	std::thread evenThread(countEvens);
	std::thread oddThread(countOdds);

	//waits for the threads to finish
	evenThread.join();
	oddThread.join();


	return EXIT_SUCCESS;
}