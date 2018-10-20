/*
*  IncidentLog.cpp
*
*  COSC 052 Fall 2018
*  Project #1
*
*  Due on: SEP 27, 2018
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

#include "IncidentLog.h"

	IncidentLog:: IncidentLog()
	{
		
		std::cout << "Entered constructor IncidentLog::IncidentLog ()" << std::endl;
		
		
		
		std::cout<< "Exiting constructor IncidentLog::IncidentLog()"<<std::endl;
		
    
	}
	
	IncidentLog:: ~IncidentLog()
	{
		
	}
	
	void IncidentLog::displayReports(string outputFileName)
				const throw (logic_error, invalid_argument)
	{
		ofstream displayFile; 
		displayFile.open(outputFileName);
		if(displayFile.fail()) 
		{
	
			throw logic_error(" The file failed to open. Check filename ") ;
		}
	
		displayReports(displayFile);
		displayFile.close(); 
		
	}
	void IncidentLog::displayReports(ostream & os ) const throw (invalid_argument)
	{
		if (os.fail())
		{
			throw invalid_argument( "File did not open. Check file name "); 
		}
		
		os << "Form PHMSA F 7000-1 Accident Report - Hazardous Liquid Pipeling Systems ";
		os<< allIncidents.size()<< "records: \n";
		
		for (int i = 0 ; i < allIncidents.size(); i++) 
		{
			allIncidents[i].summaryReport(os);	
		}

	}
	HazMat7k & IncidentLog::find(string incidentNum) throw (logic_error) 
	{
		string check = " "; 
		int i = 0;
		while ( incidentNum != check || i < allIncidents.size())
		{
			check = allIncidents[i].getReportNumber();
			i++;
		}
		if (check == incidentNum)
		{
			return allIncidents[i];
		}
		throw logic_error (" Data member not found " ); 
			
	}
	
	
	void IncidentLog::read(string inputFileName, char fileFormat) 
							throw (logic_error,invalid_argument)
	{ 
	
		 //creating a binary file stream called inFile
		std::fstream inFile( inputFileName.c_str(), std::ios::in|std::ios::binary);
			if (!inFile) 
			{
				string errmsg= "" ; 
				errmsg += "Input file didn't open, check path and name:\n"; 
				errmsg+= inputFileName; 
				errmsg+= "\n";
				cout<< errmsg; 
				throw logic_error(errmsg); 
			}// End if (!inFile)
				
			if (fileFormat != 'q' && fileFormat != 'b') 
			{
				throw invalid_argument ("Incorrect File Format"); 
			}
			cout << "File open success.You are all set to read in data!"<<endl; 
			cout << inputFileName<<endl;
			
			read (inFile,fileFormat);
			
			inFile.close(); 
			
	} 
	
	void IncidentLog::read(istream& in, char fileFormat) throw (invalid_argument) 
	{
		cout << "in second read method" << endl;
		HazMatData hazDat1; //declaring a HazMatData (Struct) object
		if(in.fail()) 
		{
			throw invalid_argument ("File did not open. Check File name ");
		}
		while (in.read(reinterpret_cast<char *>(&hazDat1), (sizeof(hazDat1))))
		{
			
			try
			{
				//declaring HazMat7k object and populating this object with struct data		
				
				HazMat7k haz1(hazDat1); 
				allIncidents.push_back(haz1);	// adding this to the vector 
			}
			catch (std:: invalid_argument &e)
			{
				cout << "WARNING: caught invalid_argument in IncidentLog::read(istream&)\n";
				cout << "probably data validation failure, allowing processing to continue\n";
				cout << "error text:\n";
				cout << e.what() << endl;
			}
			catch (...)
			{
				string errMessage; 
				errMessage = "unknowing exception caught in loop to read data file, ";
				errMessage += "processing terminated.";
				throw std::runtime_error(errMessage);
			}
		}
		
	}
	
	void IncidentLog::write (string outputFileName) const throw (logic_error, invalid_argument) 
	{
		ofstream writeFile; 
		writeFile.open(outputFileName.c_str());
		cout << " in first write function" <<endl;
		if(writeFile.fail()) 
		{
			throw logic_error(" The file failed to open. Check filename ") ;
		}
		cout<< " text file opened" <<endl;
		write(writeFile); 
	
	}
	
	void IncidentLog::write (ostream& os) const throw (invalid_argument) 
	{
		cout<< "in second write file " <<endl;
		if (os.fail())
		{
			throw invalid_argument( "File did not open. Please check file name"); 
		}	
				
		for (int i = 0; i < allIncidents.size(); i++)
			
		{
			
			os << allIncidents[i];
			
			
			
		}
		
	}

bool IncidentLog::readDoubleQuotedString (istream & in, string & s) const
	throw (logic_error, invalid_argument)
{ 
	if (in.fail())
	{
		throw invalid_argument("Error in readDoubleQuotedString: stream not working"); 
	}
	//cout<< " inside Double Quoted String " <<endl;
	char startquotes = ' '; 
	char startquotestrue = '\"'; 
	char endquotes = ' '; 
	char endquotestrue = '\"'; 
	bool valid = false ; 
	
	s = "";

	in >> startquotes;
	//cout << startquotes<<endl;
	if (startquotes == startquotestrue)
	{
		endquotes = in.get(); 
		//cout<< endquotes<<endl;
		while( endquotes != endquotestrue)
		{
			s += endquotes;
			endquotes= in.get();
			//cout<<endquotes<<endl;
			valid= true; 
			
		}
		//cout << s<<endl; 
	}
	if ( valid == false) 
	{
		throw logic_error("Error in readDoubleQuotedString: char is not double quoted string"); 
	}
	return valid; 
}	
	
	
