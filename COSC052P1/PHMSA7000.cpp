/*
*  PHMSA7000.cpp
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
#include "PHMSA7000.h" 


	std:: ostream& operator<<(std::ostream &os, const HazMat7k &rhsObj)
	{
		if (os.fail())
		{
			throw invalid_argument( "File did not open. Please check file name"); 
		}	
		
		os << rhsObj.getReportReceivedDate() << " "; 
		os << rhsObj.getReportNumber() << " "; 
		os << rhsObj.getSupplementalNumber() << " "; 
		os << rhsObj.getReportType() << " "; 
		os << rhsObj.getOperatorID() << " "; 
		os << rhsObj.getName() << " ";
		os << rhsObj.getOperatorStreetAddress() <<" "; 
		os << rhsObj.getOperatorCityName() << " "; 
		os << rhsObj.getOperatorStateAbbreviation() << " "; 
		os << rhsObj.getOperatorPostalCode() << " "; 
		os << rhsObj.getLocalDate() << " "; 
		os << rhsObj.getLocalTime() << " "; 
		os << rhsObj.getCommodityReleasedType() << " "; 
		os << rhsObj.getUnintentionalReleaseBbls() << " ";
		os << rhsObj.getIntentionalReleaseBbls() << " "; 
		os << rhsObj.getRecoveredBbls() << " "; 
		os << rhsObj.getFatal() << " "; 
		os << rhsObj.getInjure() << " "; 
		os << rhsObj.getIgniteInd() << " "; 
		os << rhsObj.getExplodeInd() << " "; 
		os << rhsObj.getPreparedDate() << " "; 
		os << rhsObj.getAuthorizerName() << " "; 
		os << rhsObj.getAuthorizerEmail() << " "; 
		os << rhsObj.getNarrative() << endl; 
		return os; 
	}

	HazMat7k::~HazMat7k()
	{
	
	}

	HazMat7k::HazMat7k()
	{
		std::cout << "Entered constructor HazMat7k::HazMat7k ()" << std::endl;
		 
		reportReceivedDate.setDate(MIN_YYYY, MIN_MM, MIN_DD) ;           
		reportNumber = " " ;               
		supplementalNumber = " " ;         
		reportType = " ";                 
		operatorID = " ";                 
		name= " ";                       
		operatorStreetAddress = " ";      
		operatorCityName = " ";           
		operatorStateAbbreviation = " ";  
		operatorPostalCode = " ";         
		localDate.setDate(MIN_YYYY, MIN_MM, MIN_DD);                    
		localTime.setTime(0,0);                    
		commodityReleasedType = " ";      
		unintentionalReleaseBbls = 0.0;
		intentionalReleaseBbls = 0.0;
		recoveredBbls = 0.0; 
		fatal = 0;                
		injure = 0;               
		igniteInd = " " ;         
		explodeInd = " ";        
		preparedDate.setDate(MIN_YYYY, MIN_MM, MIN_DD);        
		authorizerName = " " ;    
		authorizerEmail = " ";   
		narrative = " " ;
		#ifdef DEBUG_HAZMAT
		std::cout<< "Exiting constructor HazMat7k::HazMat7k()"<<std::endl;
		#endif
	}

	HazMat7k::HazMat7k(const HazMatData & hzData) throw (std::invalid_argument) 
	{
		
		setReportReceivedDate(hzData.report_received_date);           
		setReportNumber(hzData.report_number);               
		supplementalNumber = hzData.supplemental_number;         
		setReportType(hzData.report_type);                 
		operatorID= hzData.operator_id;                 
		name = hzData.name;                       
		operatorStreetAddress = hzData.operator_street_address;      
		operatorCityName = hzData.operator_city_name;           
		operatorStateAbbreviation = hzData.operator_state_abbreviation;  
		operatorPostalCode = hzData.operator_postal_code;         
		setLocalDate(hzData.local_date);                    
		setLocalTime(hzData.local_time) ;                    
		commodityReleasedType = hzData.commodity_released_type;      
		unintentionalReleaseBbls = hzData.unintentional_release_bbls;
		intentionalReleaseBbls = hzData.intentional_release_bbls;
		recoveredBbls = hzData.intentional_release_bbls; 
		fatal = hzData.fatal;                
		injure = hzData.injure;                
		igniteInd = hzData.ignite_ind;         
		explodeInd = hzData.explode_ind;        
		setPreparedDate(hzData.prepared_date);        
		authorizerName = hzData.authorizer_name;    
		authorizerEmail = hzData.authorizer_email;   
		narrative = hzData.narrative;  
		
	}

	void HazMat7k::summaryReport(ostream &os) const throw (std::invalid_argument)
	{
		if (os.fail())
		{
			throw invalid_argument( "File did not open. Please check file name"); 
		}	
		
		os<<"Report Number and Date: " <<reportNumber << " " <<reportReceivedDate <<endl;
		os<<"Local Date and Time: " << localDate<< " " << localTime<<endl; 
		os<<"Number of Injuries: " << injure <<endl; 
		os<<"Number of Fatalities: "<< fatal <<endl ; 
		os<<"Narrative Length: "<< narrative.length() <<endl; 
		os<<"Narrative : "<< narrative <<endl;

	}

	void HazMat7k::setReportNumber (string value ) throw (std::invalid_argument)
	{
		
		bool allGood = true; 
		
		ostringstream combined;
		combined << "\tException thrown from ";
		combined << "HazMat7k::setreportNumber(" << value << ")\n";
		string combinedError = combined.str();
		
		ostringstream length;
		length << "\tException thrown from ";
		length << "HazMat7k:setreportNumber(" << value << ")\n";
		length << "\t" << LEN_ERR << " ";  // constant defined in PHMSA7000.h
		length << "Entered: " << value << ", ";
		length << "Valid: ";
		length << "["<< REPORT_NUM_LENGTH <<"]\n";
		string lengthError = length.str(); 
		
		ostringstream digit;
		digit << "\tException thrown from ";
		digit << "HazMat7k:setreportNumber(" << value << ")\n";
		digit << "\t" <<DIG_ERR << " ";  // constant defined in PHMSA7000.h
		digit << "Entered: " << value << ", ";
		digit << "Valid: ";
		digit << "all characters are numberical.\n";
		string digitError = digit.str(); 
		
		
		ostringstream dateMatch;
		dateMatch << "\tException thrown from ";
		dateMatch << "HazMat7k::setReportNumber(" << value << ")\n";
		dateMatch << "\t" << DATE_ERR_1 << " ";  // constant defined in PHMSA7000.h
		dateMatch << DATE_ERR_2; 
		dateMatch << "Entered: " << value << ", ";
		dateMatch << "Valid: ";
		dateMatch << "[" << reportReceivedDate.getYear() << "]\n";
		string dateMatchErrror = dateMatch.str(); 
		
		//cout<< "value.length = "<< value.length()<< "   "<< REPORT_NUM_LENGTH << endl;
		if (value.length() != REPORT_NUM_LENGTH ) // this checks report Number length == 8
		{
			allGood	= false;
			throw invalid_argument(lengthError);
		}
		for(int i = 0; i < 8; i++)// this checks for report Number is all numbers 
		{
			if ( !(isdigit( value.at(i)) ) )
			{
				allGood= false; 
				throw invalid_argument(digitError);  
			}
		}
		//cout<< " preparing to test first four " <<endl;

		string firstFour = " " ; 
		for ( int i = 0 ; i < 4 ; i++) // this loop gets the 1st 4 characters in the string 
		{
			firstFour += value[i];
		}
		
		// change istringstream to the int.
		istringstream fourNum (firstFour);
		int testFour; 
		fourNum >> testFour; 
		
		// 1st 4 report number = report received date 	
		if (testFour != reportReceivedDate.getYear()) 
		{
			allGood = false; 
			throw invalid_argument(dateMatchErrror);
		}
		if (allGood == false) 
		{
			throw invalid_argument(combinedError);
		}
		//cout<< "Data Validation is done " <<endl;
		
		reportNumber = value; 
	
	}
	
	void HazMat7k::setReportType (string value) throw (std::invalid_argument)
	{
		//cout << " starting to validate for setReportType" << endl;
		bool allGood = true; 
		
		ostringstream type;
		type << "\tException thrown from ";
		type << "HazMat7k:setreportType(" << value << ")\n";
		type << "\t" << TYPE_ERR << " ";  // constant defined in PHMSA7000.h
		type << "Entered: " << value << ", ";
		type << "Valid: ";
		type << "["<< VALID_REPORT_TYPE[0] << " , ";
		type << VALID_REPORT_TYPE[1] << " , "; 
		type << VALID_REPORT_TYPE[2] << " , ";
		type << VALID_REPORT_TYPE[3] << "] \n "; 
		string typeError = type.str(); 
					

		
		if (value != "ORIGINAL" && value != "ORIGINAL FINAL"&&
			value != "SUPPLEMENTAL" && value != "SUPPLEMENTAL FINAL")			
		{
			allGood= false; 
		}
		if (allGood == false) 
		{
			throw invalid_argument(typeError); 
		}	
		//cout<< "end validating setReportType"<<endl;
		reportType = value;  
	}
	
	