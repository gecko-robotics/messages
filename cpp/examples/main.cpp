
#include <iostream>
// #include <messages.hpp>
// #include <stdio.h> // freopen
// #include <iomanip> // put_time
// #include <ctime>   // time stuff
// #include <sstream> // convert to string

// using std::cout;
// using std::endl;
// using std::cerr;

// class Logger {
//   public:
//   Logger(const std::string& filename, FILE *stream=stdout) {
//     // std::string fname = get_timedate() + filename;
//     std::string fname = filename;
//     freopen (fname.c_str(), "w", stream);
//   }
//   ~Logger() {
//     fclose(stdout);
//   }
//   std::string get_timedate() {
//     auto t = std::time(nullptr);
//     auto tm = *std::localtime(&t);

//     std::ostringstream oss;
//     oss << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S_");
//     return oss.str();
//   }
// };

// Logger logger("log.txt", stderr);

int main() {
  // printf ("printf: %d %f\n",10,20.0);
  // cout << "cout: " << 30 << " " << 40.0 << endl;
  // cerr << "cerr ..." << endl;

  return 0;
}