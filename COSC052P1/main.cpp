
/*
*  main.cpp
*
*  COSC 052 Fall 2018
*  Project #1
*
*  Due on: SEPT 27, 2018
*  Author: mmn60
*
*
*  In accordance with the class policies and Georgetown's
*  Honor Code, I certify that, with the exception of the
*  class resources and those items noted below, I have neither
*  given nor received any assistance on this project.
*
*  References not otherwise commented within the program source code.
*  Note that you should not mention any help from the TAs, the professor,
*  or any code taken from the class textbooks.
*/
#include "main.h"

int main(int argc, const char *argv[]) 
{
	try
	{
		int three = 3;
		if (argc < three) 
		{
			throw invalid_argument( "Not enough command line argument"); 
		}
		//COMMAND ARGUMENTS
		string filepath =  argv[1] ;
		char filetype = *argv[2];
		
		string outputFileName1 = filepath + ".out1"; 
		string outputFileName2 = filepath +".out2"; 
	
		string textFile = "text.txt"; 
	
		IncidentLog incident ; // instantiates an object of the IncidentLog class 
		//cout << "incident log created" << endl;
		incident.read(filepath, filetype); 
		//cout << "read complete in function main" << endl;
		incident.displayReports(textFile);
		incident.write(cout); 
		
		
		cout<< incident.size()<<endl;
		cout<< endl;
		cout<< endl;
		
	
		// put catch blocks for all the thrown exceptions 
		// make a throw invalid_arguments for the parameters in int main 
	}
	
	///// ADD A CATCH BLOCK FOR LOGIC ERROR & RUNTIME ERROR 
	//catch (logic_error & e)
	//{
	//}
	catch (invalid_argument &e)
	{
		cout<< "caught invalid_argument in function main\n"; 
		cout << e.what()<<endl;
	}
	
	catch (...)
	{
		string errMessage; 
		errMessage = "caught unknown exception in function main , ";
		errMessage += "processing terminated.";
	}
	return 0; 
}  