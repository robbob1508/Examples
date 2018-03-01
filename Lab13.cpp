    #include <cstdlib>								//  these lines tell the programs what special liabries we want to take in
    #include <iostream>								// for example if we wanted to use square root function, we would inport math.h
    
    using namespace std;
    
    const int MILES_PER_YEAR = 21000;				// these lines declare constants
    const double CITY_PERCENT = 45.0;				// that won't change no matter what we input into the program
    const double HIGHWAY_PERCENT = 55.0;
    const double CITY_MPG = 51.0;					//doubles have decmil places, ints don't
    const double HIGHWAY_MPG = 45.0;
    const double USABLE_GAS = 9.0;
    const double INITIAL_PRICE = 3.359;
    const double FINAL_PRICE = 6.00;
    const int NUM_YEARS = 8;       
    
    double gasPrice(int day); 
	double cost_per_mile(double purchase, double fuel, double miles);
    int main(int argc, char * argv[]) {
        
        }
    
    
