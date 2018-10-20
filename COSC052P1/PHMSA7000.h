/*
*  PHMSA7000.h
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
 
#ifndef _COSC052_FALL2018_P1_PHMSA7000_H_
#define _COSC052_FALL2018_P1_PHMSA7000_H_
 
 
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
 
#include "DateTime.h"
 
#define DEBUG_FILE_OPENING = 1
 
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ostream;
using std::istream;
using std::cin;
using std::vector;
using std::istringstream;
using std::ostringstream;
using std::logic_error;
using std::setw;
 


const int FIELD_COUNT = 24;

const int  REPORT_NUM_LENGTH = 8 ;
const string LEN_ERR= " Error: The Report Number must be 8 characters\n"; 
const string DATE_ERR_1= "The 1st four characters of Report Number must be the year ";
const string DATE_ERR_2 = "The year and Report Received Date must match.\n";
const string TYPE_ERR = " The report type be one of the 4 valid types listed below.\n";  
const string DIG_ERR= " All characters in Report Number must be numerical.\n";



const int FIELD_WIDTH[FIELD_COUNT] = {16,10,7,20,7,55,57,18,4,12,16,8,84,10,10,10,
     6,6,5,5,16,45,42,4000};
 
const int NUM_REPORT_TYPES = 4;
const string VALID_REPORT_TYPE[] = {
                                    "ORIGINAL",
                                    "ORIGINAL FINAL",
                                    "SUPPLEMENTAL",
                                    "SUPPLEMENTAL FINAL"
                                    };

enum {REPORT_RECEIVED_DATE,
		REPORT_NUMBER,
		SUPPLEMENTAL_NUMBER,
		REPORT_TYPE,
		OPERATOR_ID,
		NAME,
		STREET_ADDRESS,
		CITY_NAME,
		STATE_ABBR,
		POSTAL_CODE,
		LOCAL_DATE,
		LOCAL_TIME,
		COMMODITY_TYPE,
		UNINTENTIONAL_BBLS,
		INTENTIONAL_BBLS,
		RECOVERED_BBLS,
		FATAL,
		INJURE,
		IGNITE,
		EXPLODE,
		PREPARED_DATE,
		AUTH_NAME,
		AUTH_EMAIL,
		NARRATIVE };

/****************************************************************************
****************************************************************************                                                                       
**                                                                        **
**               struct HazMatData declaration                            **
**                                                                        **
**            This code is provided to students                           **
**            in COSC 052 Fall 2018 to use in part                        **
**            or in total for class projects.                             **
**            Students may use this code as their                         **
**            own, without any attribution.                               **
**                                                                        **
****************************************************************************                                                                       
****************************************************************************/
 
struct HazMatData
{
	Date report_received_date;
	char report_number[10+1];
	char supplemental_number[7+1];
	char report_type[20+1];
	char operator_id[7+1];
	char name[55+1];
	char operator_street_address[57+1];
	char operator_city_name[18+1];
	char operator_state_abbreviation[4+1];
	char operator_postal_code[12+1];
	Date local_date;
	Time local_time;
	char commodity_released_type[84+1];
	double unintentional_release_bbls;
	double intentional_release_bbls;
	double recovered_bbls;
	int fatal;
	int injure;
	char ignite_ind[5+1];
	char explode_ind[5+1];
	Date prepared_date;
	char authorizer_name[45+1];
	char authorizer_email[42+1];
	char narrative[4000+1];
     
}; //END struct HazMatData declaration

/****************************************************************************
****************************************************************************
*****                                                                  *****
*****               CODE BELOW NOT FOR DISTRIBUTION                    *****
*****                                                                  *****
****************************************************************************
****************************************************************************/

/****************************************************************************
****************************************************************************                                                                       
**                                                                        **
**                   class HazMat7k declaration                           **
**                                                                        **
**                      NOT FOR DISTRIBUTION                              **
**                                                                        **
****************************************************************************                                                                       
****************************************************************************/

class HazMat7k
{
	friend ostream& operator<<(ostream &os, const HazMat7k &rhsObj);
	
     
	private:
		Date  reportReceivedDate;           
		string  reportNumber;               
		string  supplementalNumber;         
		string  reportType;                 
		string  operatorID;                 
		string  name;                       
		string  operatorStreetAddress;      
		string  operatorCityName;           
		string  operatorStateAbbreviation;  
		string  operatorPostalCode;         
		Date  localDate;                    
		Time  localTime;                    
		string  commodityReleasedType;      
		double  unintentionalReleaseBbls;
		double  intentionalReleaseBbls;
		double  recoveredBbls; 
		int  fatal;                
		int  injure;               
		string  igniteInd;         
		string  explodeInd;        
		Date  preparedDate;        
		string  authorizerName;    
		string  authorizerEmail;   
		string  narrative;         
	public:
        ~HazMat7k();
		// default constructor
		HazMat7k();
     
		void summaryReport(ostream &os = cout) const throw (std::invalid_argument);
 
		//convert constructor
		HazMat7k( const HazMatData &hzData ) throw (std::invalid_argument);
  
		// simple accessor functions for each data member (all may be implemented in-line)
  
		Date getReportReceivedDate() const { return reportReceivedDate; } 
		string getReportNumber() const { return reportNumber; } 
		string getSupplementalNumber() const { return supplementalNumber; } 
		string getReportType() const { return reportType; } 
		string getOperatorID() const { return operatorID; } 
		string getName() const { return name; } 
		string getOperatorStreetAddress() const { return operatorStreetAddress; }
		string getOperatorCityName() const { return operatorCityName; } 
		string getOperatorStateAbbreviation() const { return operatorStateAbbreviation; }
		string getOperatorPostalCode() const { return operatorPostalCode; } 
		Date getLocalDate() const { return localDate; } 
		Time getLocalTime() const { return localTime; } 	
		string getCommodityReleasedType() const { return commodityReleasedType; }
		double getUnintentionalReleaseBbls() const { return unintentionalReleaseBbls; }
		double getIntentionalReleaseBbls() const { return intentionalReleaseBbls; } 	
		double getRecoveredBbls() const { return recoveredBbls; } 
		int getFatal() const { return fatal; } 
		int getInjure() const { return injure; } 
		string getIgniteInd() const { return igniteInd; } 
		string getExplodeInd() const { return explodeInd; }
		Date getPreparedDate() const { return preparedDate; } 
		string getAuthorizerName() const { return authorizerName; } 
		string getAuthorizerEmail() const { return authorizerEmail; } 
		string getNarrative() const { return narrative; } 
		// simple mutator functions for each data member (most may be implemented in-line)
		
		void setReportReceivedDate(Date value) throw (invalid_argument)
			{ reportReceivedDate.setDate(value); }
     
		//this mutator functions may not be implemented in-line 
		void setReportNumber(string value)  throw (std::invalid_argument);
   
		void setSupplementalNumber(string value) { supplementalNumber = value; }
		
		//this mutator functions may not be implemented in-line 
		void setReportType(string value) throw (std::invalid_argument);
 
		void setOperatorID(string value) { operatorID = value; }
		void setName(string value) { name = value; }
		void setOperatorStreetAddress(string value) { operatorStreetAddress = value; }
		void setOperatorCityName(string value) { operatorCityName = value; }
		void setOperatorStateAbbreviation(string value) { operatorStateAbbreviation = value; }
		void setOperatorPostalCode(string value) { operatorPostalCode = value;}
		
		void setLocalDate(Date value) throw (invalid_argument)
            { localDate.setDate(value); }
		void setLocalTime(Time value) throw (invalid_argument)
			{ localTime.setTime(value.getHour(), value.getMinute()); }

		void setCommodityReleasedType(string value) { commodityReleasedType = value; }
		void setUnintentionalReleaseBbls(double value) { unintentionalReleaseBbls = value; }		
		void setIntentionalReleaseBbls(double value) { intentionalReleaseBbls = value; }	
		void setRecoveredBbls(double value) { recoveredBbls = value; }
		void setFatal(int value) { fatal = value; }
		void setInjure(int value) { injure = value; }
		void setIgniteInd(string value) { igniteInd = value; }
		void setExplodeInd(string value) { explodeInd = value; }  
		void setPreparedDate(Date value) throw (invalid_argument)	
			{ preparedDate.setDate(value); }
		
		void setAuthorizerName(string value) { authorizerName = value; }
		void setAuthorizerEmail(string value) { authorizerEmail = value; }
		void setNarrative(string value) { narrative = value; }
     
	}; // class HazMat7k declaration
  
#endif  /*  _COSC052_FALL2018_P1_PHMSA7000_H_  */

