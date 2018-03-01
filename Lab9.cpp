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
        cout << "Driving the Toyota Prius" << endl;
    
        double daily_miles = MILES_PER_YEAR / 365.0;
        double daily_city_miles = daily_miles * CITY_PERCENT/100.0;
        double daily_highway_miles = daily_miles*HIGHWAY_PERCENT/100.0;
        double daily_gas_consumed = daily_highway_miles / HIGHWAY_MPG +
                daily_city_miles / CITY_MPG;
    
        double gas_in_tank = USABLE_GAS;		// these vars will vary as the program works, can't make them contstant 
        double price;							// as the only thing constant about them is how they change. :P
        double amount_purchased;
        double gallons_purchased;
        double total_gas_purchases = 0;
        for(int day = 0;day < 365*8; day++) {	// using loops add up how many gallons are used per day
            cout << "Driving summary for day " << day << endl;
            cout << " highway miles: " << daily_highway_miles << endl;
            cout << " city miles   : " << daily_city_miles << endl;
            cout << " gas consumed : " << daily_gas_consumed << endl;
            gas_in_tank = gas_in_tank - daily_gas_consumed;
            cout << " gas in tank  : " << gas_in_tank << endl;
            if (gas_in_tank < 0.0) {            // using if statement, fill up car only if the gas tank is empty
                cout << "  BUY GAS" << endl;	
                gallons_purchased = USABLE_GAS - gas_in_tank;
                price = gasPrice(day);
                cout << "  price today is   : " << price << endl;
                cout << "  Gallons purchased: " << gallons_purchased << endl;
                cout << "  fillup cost      : " << gallons_purchased * price << endl;
                total_gas_purchases = total_gas_purchases + gallons_purchased * price;	// add cost of filling up to total cost if the gas
                cout << "  total gas cost   : " << total_gas_purchases << endl;
                gas_in_tank = USABLE_GAS;										// make sure the amount of gas in tank is set back to what has been purchased.	
            }
        }
    
    	cout << "Test of cost per mile, Prius" << endl;
 		    double CostPerMile = cost_per_mile(INITIAL_PRICE, total_gas_purchases, MILES_PER_YEAR* NUM_YEARS);

  		   cout << CostPerMile  << endl;
    
        system("PAUSE");
        return EXIT_SUCCESS;
    }  
    
    double gasPrice(int day) {										// by creating subroutines, we brake problem into chunks can be solved easily
        double dailyIncrease = (FINAL_PRICE - INITIAL_PRICE) / 
                (NUM_YEARS * 365);
        double currentPrice = INITIAL_PRICE + day * dailyIncrease;
       if( day > 365 * 4  )			// test to see if more than 4 years have passed
	   {
	   	currentPrice = INITIAL_PRICE + 365 * 4 * dailyIncrease;   // after 4 years gas will remain at fixed higher value for the following years
	   }															// currentPrice will only be over ridden if the if statement is true
	    return currentPrice;
    }     
    
    double cost_per_mile(double purchase, double fuel, double miles)  {
    	double cost = purchase + fuel;
    	
    	cost = cost / miles;
    	
    	return cost;
	}
    
    
    
    
