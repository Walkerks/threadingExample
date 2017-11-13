#include <cstdlib>
#include <thread>
#include <iostream>
#include <mutex>


//Count up to
#define STOPNUM 1500

unsigned long long counter = 1;
std::mutex counterLock;

void countOdds() {
	for (;;) {
		counterLock.lock();
		if (counter % 2 != 0) {
			std::cout << counter << std::endl;
		}
		counter++;
		counterLock.unlock();
		if (counter >= STOPNUM) {
			break;
		}
	}
}



void countEvens() {
	for (;;) {
		counterLock.lock();
		if (counter % 2 == 0) {
			std::cout << counter << std::endl;
		}
		counter++;
		counterLock.unlock();
		if (counter >= STOPNUM) {
			break;
		}
	}
}


int main() {

	std::thread evenThread(countEvens);
	std::thread oddThread(countOdds);

	evenThread.join();
	oddThread.join();


	return EXIT_SUCCESS;
}