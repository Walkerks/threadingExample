#include <cstdlib>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>


//Count up to
#define STOPNUM 1500

unsigned long long counter = 1;
std::mutex counterLock;
std::condition_variable counterCondition;


void countOdds() {
	for (;;) {
		//Why would this work? That's a question for you.
		std::unique_lock<std::mutex> lock(counterLock);
		//wait while the counter is even
		while (counter % 2 == 0) {
			counterCondition.wait(lock);
		}
		std::cout << counter << std::endl;
		counter++;
		//Tell the other thread it is it's turn
		counterCondition.notify_all();
		if (counter >= STOPNUM) {
			break;
		}
	}
}



void countEvens() {
	for (;;) {
		std::unique_lock<std::mutex> lock(counterLock);
		//wait while the counter is odd
		while (counter % 2 != 0) {
			counterCondition.wait(lock);
		}
		std::cout << counter << std::endl;
		counter++;
		//Tell the other thread it is it's turn
		counterCondition.notify_all();
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