#ifndef INTENT_RECOGNIZER_H
#define INTENT_RECOGNIZER_H

#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <algorithm>

using namespace std;

class IntentRecognizer
{
public:
	IntentRecognizer();
	~IntentRecognizer();
	/*main routine to calculate intent*/
    	string GetIntent(const int i_countWords, char** i_words);
    	string GetIntent(const string i_sentence);

private:
    	/* Member variables for extracting and storing Keywords */
	 string m_Weather;
	 string m_Fact;
	 string m_Time;
	 string m_Date;
	 string m_Place;
	
	/*data parsing and string utilities*/	
        string Convert2DCharArrayToString(const int i_count, char** i_array);
        size_t findCaseInsensitive(std::string data, std::string toSearch, size_t pos);
	
	/*intent sub-routines*/
	void findWeatherIntent(const string i_sentence);
	void findFactIntent(const string i_sentence);
	void findCalendarIntent(const string i_sentence);
};
#endif
