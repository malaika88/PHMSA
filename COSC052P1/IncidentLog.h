/*
*  IncidentLog.h
*
*  COSC 052 Fall 2018
*  Project #1
*
*  Due on: SEP 27, 2018
*  Author: waw23
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
 
 
 
#ifndef _COSC052_FALL2018_P1_INCIDENT_LOG_H
#define _COSC052_FALL2018_P1_INCIDENT_LOG_H
 
 
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
 
#include "PHMSA7000.h"
 
using std::ostream;
using std::istream; 
using std::cout;
using std::logic_error;
using std:: ofstream; 
 
/****************************************************************************
*                                                                          *
*                  class IncidentLog declaration                           *
*                                                                          *
****************************************************************************/
 
class IncidentLog
{
	private:
        vector<HazMat7k> allIncidents; 
	public:
     
		IncidentLog();
		~IncidentLog();
  
		void displayReports(string outputFileName) const throw (logic_error, invalid_argument);
		void displayReports(ostream &os = cout) const throw (invalid_argument);
		
		HazMat7k& find(string incidentNum) throw (logic_error);    
		void read( string inputFileName, char fileFormat ) throw (logic_error, invalid_argument);	
		void read( istream& in, char fileFormat ) throw (invalid_argument);
     
		void write( string outputFileName ) const throw (logic_error, invalid_argument);
		void write( ostream& out = cout ) const throw (invalid_argument);

// read one string, enclosed in double quotation marks, from the stream passed in
		bool readDoubleQuotedString( istream& in, string &s ) const
                                              throw (logic_error, invalid_argument);
     
		unsigned long size() const { return allIncidents.size(); }
  
}; //END class IncidentLog declaration
 
 
 
 
 
 
#endif   /*  _COSC052_FALL2018_P1_INCIDENT_LOG_H  */
