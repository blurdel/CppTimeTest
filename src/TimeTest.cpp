#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
using namespace std;
#include <stdio.h>

int main() {

    auto ms_since_epoch = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    auto sec_since_epoch = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();

    cout << "millis: " << ms_since_epoch << endl;
    cout << "second: " << sec_since_epoch << endl;


    for (int i = 0; i < 10; i++) {
    	printf("%d ", i);
    	fflush(stdout);
    }

    return EXIT_SUCCESS;
}
