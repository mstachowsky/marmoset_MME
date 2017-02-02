/*

Copyright David Lau, January 2017

Let the first location tower be located at the coordinates (x_tower1, y_tower1),
where tower1 is located at a distance r_tower1 from your current location.
This is similar for the second location tower at (x_tower2, y_tower2) at a
distance of r_tower2.

The equation of the circles describing your possible location on a
Cartesian plane are:
[1]: (x_loc - x_tower1)^2 + (y_loc - y_tower1)^2 = r_tower1^2
[2]: (x_loc - x_tower2)^2 + (y_loc - y_tower2)^2 = r_tower2^2

Expanding these equations give:
[1] -> [3]: (x_loc^2 - 2*x_loc*x_tower1 + x_tower1^2) + (y_loc^2 - 2*y_loc*y_tower1 + y_tower1^2) = r_tower1^2
[2] -> [4]: (x_loc^2 - 2*x_loc*x_tower2 + x_tower2^2) + (y_loc^2 - 2*y_loc*y_tower2 + y_tower2^2) = r_tower2^2

Subtracting [3] - [4]:
[5]: -2*x_loc*x_tower1 + 2*x_loc*x_tower2 + x_tower1^2 - x_tower2^2
        -2*y_loc*y_tower1 + 2*y_loc*y_tower2 + y_tower1^2 - y_tower2^2
    = r_tower1^2 - r_tower2^2

Isolating x_loc terms on left side:
[6]: x_loc*2*(x_tower2 - x_tower1) = y_loc*2*(y_tower1 - y_tower2)
                                      - x_tower1^2 + x_tower2^2
                                      - y_tower1^2 + y_tower2^2
                                      + r_tower1^2 - r_tower2^2

To help keep these equations simpler, and since the coordinates and distances
to the towers are known, let
A = x_tower2 - x_tower1
B = y_tower1 - y_tower2
C = - x_tower1^2 + x_tower2^2 - y_tower1^2 + y_tower2^2 + r_tower1^2 - r_tower2^2

Substituting these into [6] gives:
[7]: x_loc*2*A = y_loc*2*B + C
Rearranging:
[8]: x_loc = (y_loc*2*B + C)/2*A

Substituting [8] into [1]:
[9]: [(y_loc*2*B + C)/2*A]^2 - 2*[(y_loc*2*B + C)/2*A]*x_tower1 + x_tower1^2
        + (y_loc^2 - 2*y_loc*y_tower1 + y_tower1^2) = r_tower1^2
Expanding first term:
[10]: (4*B^2*y_loc^2 + 4*B*C*y_loc + 2*C)/(4*A^2) - 2*[(y_loc*2*B + C)/(2*A)]*x_tower1 + x_tower1^2
        + (y_loc^2 - 2*y_loc*y_tower1 + y_tower1^2) = r_tower1^2

Collecting terms to form quadratic:
[11]: (4*B^2/(4*A^2) + 1)*y_loc^2 + (4*B*C/(4*A^2) - 4*B*x_tower1/(2*A) - 2*y_tower1)*y_loc
        + 2*C/(4*A^2) - 2*C*x_tower1/(2*A) + x_tower1^2 + y_tower1^2 - r_tower1^2 = 0

Solving the quadratic will give two possibilities for y_loc, which can be
substitutded back into equation [8] to give corresponding x_loc.

*/

#include <iostream>
#include <cmath>

using namespace std;

void get_data(double & x_tower1, double & y_tower1, double & r_tower1,
              double & x_tower2, double & y_tower2, double & r_tower2);

int main()
{
  double x_tower1 = 0.0, y_tower1 = 0.0, r_tower1 = 0.0,
          x_tower2 = 0.0, y_tower2 = 0.0, r_tower2 = 0.0;

  get_data(x_tower1, y_tower1, r_tower1, x_tower2, y_tower2, r_tower2);

  double intermediate_A = x_tower2 - x_tower1;
  double intermediate_B = y_tower1 - y_tower2;
  double intermediate_C = - pow(x_tower1,2) + pow(x_tower2,2)
                          - pow(y_tower1,2) + pow(y_tower2,2)
                          + pow(r_tower1,2) - pow(r_tower2,2);

  double quadratic_a = 4*pow(intermediate_B,2)/(4*pow(intermediate_A,2)) + 1;
  double quadratic_b = 4*intermediate_B*intermediate_C/(4*pow(intermediate_A,2))
                        - 4*intermediate_B*x_tower1/(2*intermediate_A) - 2*y_tower1;
  double quadratic_c = 2*intermediate_C/(4*pow(intermediate_A,2))
                        - 2*intermediate_C*x_tower1/(2*intermediate_A)
                        + pow(x_tower1,2) + pow(y_tower1,2) - pow(r_tower1,2);

  double y_loc1 = (- quadratic_b + sqrt(pow(quadratic_b,2) - 4*quadratic_a*quadratic_c))/(2*quadratic_a);
  double y_loc2 = (- quadratic_b - sqrt(pow(quadratic_b,2) - 4*quadratic_a*quadratic_c))/(2*quadratic_a);

  double x_loc1 = (y_loc1*2*intermediate_B + intermediate_C)/(2*intermediate_A);
  double x_loc2 = (y_loc2*2*intermediate_B + intermediate_C)/(2*intermediate_A);

  cout << "loc1: " << x_loc1 << ", " << y_loc1 << endl;
  cout << "loc2: " << x_loc2 << ", " << y_loc2 << endl;

  return 0;
}

void get_data(double & x_tower1, double & y_tower1, double & r_tower1,
              double & x_tower2, double & y_tower2, double & r_tower2)
{
  cout << "all distances are in meters." << endl << endl;

  cout << "enter the x and y coordinates of tower1, separated by a space: ";
  cin >> x_tower1 >> y_tower1;

  cout << "enter the x and y coordinates of tower2, separated by a space: ";
  cin >> x_tower2 >> y_tower2;

  cout << "enter the distance to tower1: ";
  cin >> r_tower1;

  cout << "enter the distance to tower2: ";
  cin >> r_tower2;
}
