#include "testScanner.h"
#include <iostream> 
#include <iomanip>
#include <fstream> 
#include "token.h"
#include "scanner.h" 

using namespace std; 

int main(int argc, char *argv[]) {
	ifstream inFile; 
	istream *input_stream;  
	string file; 
	
	if (argc > 2) { 
		cout << "Too many arguments passed." << endl; 
		return 1; 
	}

	if (argc == 1) {
        	input_stream = &cin; // stdin
    	} else {
		file = string(argv[1]); 
		if (file.substr(file.size()-4) != ".f23") {
                        file += ".f23";
                }
		inFile.open(file); 
		if (!inFile.is_open()) { 
			cout << "Error opening the file." << endl; 
			return 1; 
		} else { 
			input_stream = &inFile; 
		} 
	} 

	// Pass file to testScanner
	testScanner(*input_stream); 
	if (inFile.is_open()) { 
		inFile.close(); 
	} 

	return 0; 
}

