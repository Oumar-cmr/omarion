//function f(g(x))

#include <iostream>
#include <cmath>
#include <ctime>
#include <cmath>
using namespace std;

int main() {
  double x, g, y;
  
  cout << "enter the x" << endl;
  cin >> x;
  if (x < -4) {
    cout << "invalid x" << endl;
  }
  else if (x > -4 && x < -1) {
    g = abs(x + 6) / (abs(x + 3) - 3);
  }
  else if (x < 5) {
    g = sqrt(5 - x) - 2;
  }
  else {
    g = log(x + 10) - 2;
  }

  if (g < -2) {
    y = abs(x / (1 - x));
  }
  else if (x <= 1) {
    y = pow(x + 2, 2);
  }
  else {
    cout << "invalid g" << endl;
  }
  cout << "\ng = " << g << endl;
  cout << "\ny = " << y << endl;
  

  return 0;
}
