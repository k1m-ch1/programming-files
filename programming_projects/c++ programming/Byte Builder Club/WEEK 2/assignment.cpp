#include <iostream>
#include <iomanip>

int main(){
	// This block outputs item2 as $23.5 as $23.50 but is the simplest

	double item1 = 15.99;
	double item2 = 23.50;
	double item3 = 9.99;

	std::cout<<"Item 1 Price: $" << item1
	 <<" Item 2 Price: $"<< item2
	 <<" Item 3 Price: $"<< item3 << std::endl;
	

	//This block outputs item2 as $23.50 but is more complicated
	std::cout<<"Item 1 Price: $" << item1
	 <<" Item 2 Price: $"<<std::fixed << std::setprecision(2) << item2
	 <<" Item 3 Price: $"<< item3 << std::endl;


	//DRY code
	double item[]= {15.99, 23.50, 9.99};
	for (int i = 0; i < (sizeof(item)/sizeof(double)); i++){
		std::cout << "Item "<< i + 1 << " Price: $" << item[i]
		<<std::fixed << std::setprecision(2) << " ";
	}
	std::cout<<std::endl;

	//
	return 0;
}
