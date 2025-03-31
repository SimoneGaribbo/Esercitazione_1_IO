#include <iostream>
#include <fstream>
#include <iomanip>

double trans (double n) {
	double a = 3;
	double b = 4;
	double n_transf = (n-1)*(a/b)-1;
	
	return n_transf;
}

int main()
{ 
	std::ifstream file("./data.txt");
	if (file.fail())
	{
		std::cerr<< "Errore nell'apertura del file" << std::endl;
		return 1;
	}
	
	std::ofstream result("./result.txt");
	result<< std::setprecision(16) <<std::scientific;
	
	result << "# N Mean" << std::endl;
	
	double n;
	double sum = 0;
	double mean = 0;
	int i = 1;
	
	while (file>>n) {
		n = trans(n);
		sum = sum+n;
		mean = sum/i;
		result << i << " " << mean << std::endl;
		i++;
	}
	
	file.close();
	result.close();
		
	
	
    return 0;
}
