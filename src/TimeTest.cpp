#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


void slow_motion()
{
    std::vector<int> a{1,2,3,4,5,6,7,8,9,10,11};
    while ( std::next_permutation(a.begin(), a.end()) )
    { } // generates 12! permutations
}

int main() {

	auto    ams_since_epoch = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
	uint64_t ms_since_epoch = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

	auto    asec_since_epoch = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();
	uint64_t sec_since_epoch = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();

	cout << "millis: " << ms_since_epoch << ", " << ams_since_epoch << endl;
	cout << "second: " << sec_since_epoch << ", " << asec_since_epoch << endl;
	cout << endl;


	unsigned long int sec = time(NULL);
	cout << "second: " << sec << endl << endl;


	std::time_t result = std::time(nullptr);
	std::cout << "asctime = " << std::asctime(std::localtime(&result)) << result << " seconds since the Epoch"  << endl;


	// *** epoch time to string
	// epoch time
	long atime = 1548841260;
	std::time_t secsSinceEpoch = atime;
	std::stringstream ss;
	ss << std::put_time(std::localtime(&secsSinceEpoch), "%Y-%m-%d %H:%M:%S");
	std::cout << std::endl << "*** epoch time to string: " << ss.str() << std::endl;



	std::time_t t = std::time(nullptr);
	char tstr[100]{};
	if (std::strftime(tstr, sizeof(tstr), "%T", std::localtime(&t))) {
		std::cout << endl << "timestring = " << tstr << endl << endl;
	}


	using namespace std::literals; // enables the usage of 24h, 1ms, 1s instead of e.g. std::chrono::hours(24)
	const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

	const std::time_t t_c = std::chrono::system_clock::to_time_t(now - 24h);
	std::cout << "24 hours ago, the time was "
			<< std::put_time(std::localtime(&t_c), "%F %T.\n") << std::flush;

	const std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
	slow_motion();
	const auto end = std::chrono::steady_clock::now();

	std::cout
		<< "Slow calculations took "
		<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
		<< (end - start) / 1ms << "ms ≈ " // almost equivalent form of the above, but
		<< (end - start) / 1s << "s.\n";  // using milliseconds and seconds accordingly


	std::cout << "Done." << std::endl;
    return EXIT_SUCCESS;
}
