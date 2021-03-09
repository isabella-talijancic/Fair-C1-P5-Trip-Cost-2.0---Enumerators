//C1 P5 Trip Cost 2.0 - Enumerators

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Variable Declarations
string destination;
string vehicle;
char decision;
char anotherCar = 'Y';
double milesDriven;
double gasPrice;
int carMenu;
enum MILES_PER_GALLON {
    vehicle1 = 14,
    vehicle2 = 26,
    vehicle3 = 131,
} m_p_g;
const int MPG = 26;
const float INCREASE_PERCENT = 1.10;
double increasedTripCost;
double tripCost = 0;
double tripCostEnd = 0;

int main() {
  cout << "☆ ☆ ☆ ☆ ☆ Trip Cost: Gasoline ☆ ☆ ☆ ☆ ☆\n";

  cout << "\nEnter the destination: ";
  cin >> destination;
  cout << "Enter the miles driven: ";
  cin >> milesDriven;
  cout << "Enter the price per gallon of gas: $";
  cin >> gasPrice;

  while (anotherCar == 'Y' || anotherCar == 'y')
  {
    cout << "\n✧ ✧ ✧ ✧ ✧ Choose From Your List of Cars ✧ ✧ ✧ ✧ ✧ \n\n";
    cout << " 1. Rolls-Royce Dawn\n 2. Volkswagen Tiguan \n 3. Tesla Model 3\n\n";
    cout << "✧ Choice: ";
    cin >> carMenu;
    
    cout << "\nYou Chose: ";
    
    if(carMenu == 1)
    {
	    cout << "Rolls-Royce Dawn";
	    m_p_g = vehicle1;
	    cout << "\n\n✧ The MPG for this car is: " << vehicle1 << endl;
    }
    else if(carMenu == 2) {
	    cout << "Volkswagen Tiguan";
	    m_p_g = vehicle2;
	    cout << "\n\n✧ The MPG for this car is: " << vehicle2 << endl;
    }
    else if(carMenu == 3) {
	    cout << "Tesla Model 3";
	    m_p_g = vehicle3;
	    cout << "\n\n✧ The MPG for this car is: " << vehicle3 << endl;
    }
    else {
    	m_p_g = vehicle1;
	    cout << "Invalid Menu Choice -> Default to Rolls-Royce Dawn";
	    cout << "\n\n✧ The MPG for this car is: " << vehicle1 << endl;
    }
    
    //Processing

    tripCost = (milesDriven / m_p_g) * (gasPrice);
    increasedTripCost = tripCost + (tripCost * INCREASE_PERCENT);

    cout << "\nDid gas prices increase during the trip (Y/N)? ";
    cin >> decision;

    if (decision == 'Y' || decision == 'y')
      tripCostEnd = increasedTripCost;

    else if (decision == 'N' || decision == 'n')
      tripCostEnd = tripCost;
    else
      tripCostEnd = 0;

    cout << "\nTrip cost is: $" << setprecision(2) << fixed << tripCostEnd;
    cout << "\n\nWould you like to try another car (Y/N)? ";
    cin >> anotherCar;
  }
  cout << "\nEnd of Program";
  return 0;
}