#include "IntentRecognizer.h"

using namespace std;

/*Constructor*/
IntentRecognizer::IntentRecognizer()
:m_Weather("")
,m_Fact("")
,m_Time("")
,m_Date("")
,m_Place("")
{

}
/*destructor*/
IntentRecognizer::~IntentRecognizer()
{

}

/*
 * Function to Find Case Insensitive Sub String in a given substring
 */
size_t IntentRecognizer::findCaseInsensitive(std::string data, std::string toSearch, size_t pos = 0)
{
    // Convert complete given String to lower case
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    // Convert complete given Sub String to lower case
    std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
    // Find sub string in given string
    return data.find(toSearch, pos);
}

/*Overloaded GetIntent function to handle input in correct way */
string IntentRecognizer::GetIntent(const int i_countWords, char** i_words)
{
    string converted = Convert2DCharArrayToString(i_countWords, i_words);
	return GetIntent(converted);
}

/*Overloaded GetIntent function to process data and return the final intent*/
string IntentRecognizer::GetIntent(const string i_sentence)
{
    /*clear member variables before running Intent checks*/
    string outputIntent("");
    m_Weather.clear();
    m_Fact.clear();
    m_Time.clear();
    m_Date.clear();
    m_Place.clear();
	
  /*Starting sub-routine for weather and Fact intent checks*/
	findWeatherIntent(i_sentence);
	findFactIntent(i_sentence);
	
    /* determine weather intent*/
	
	if(m_Weather != "")
	{
		outputIntent.append("Intent: Get Weather");
		if(m_Place != "")
		{
			outputIntent.append(" City");
				
			
		}
		if((m_Time != "") || (m_Date != ""))
		{
			outputIntent.append(" Time");
		}
	}
  
	/* determine Fact intent*/
	else if(m_Fact != "")
		{
			outputIntent.append("Intent: Get Fact");
		}

		 else if((m_Time != "") || (m_Date != ""))
		{
			outputIntent.append("Intent: Get Appointment");
		} 
		/* All other cases*/
		else
		{
			outputIntent.append("No Intent Recognized");
		}

		return outputIntent;
}

/*Function that return input console args as string to work on */
string IntentRecognizer::Convert2DCharArrayToString(const int i_count, char** i_array)
{
    /* Convert char** to string */
   string sentence(i_array[0]);

     for(int i=1; i<i_count; i++)
    {
     sentence.append(string(" "));
     sentence.append(string(i_array[i]));
	}
    return sentence;
}

/* FindWeatherIntent sub-rotine function*/
void IntentRecognizer::findWeatherIntent(const string i_sentence)
{
    std::string word,word1,word2;
	  ifstream inFile,inFile1,inFile2;
    inFile.open("../model/weather.txt",ios::in);
	
	  //compare every keywords with phrase
    while (inFile>>word)
        {
                size_t pos = findCaseInsensitive(i_sentence, word);
                if( pos != std::string::npos)
                 {
                   	m_Weather = word;
				 }
		}
		
	inFile1.open("../model/place.txt",ios::in);
	
	//compare every keywords with phrase
	 while (inFile1>> word1)
   {
                size_t pos = findCaseInsensitive(i_sentence, word1);
                if( pos != std::string::npos)
                 {
                    m_Place = word1;
				         }
		}
                    
	//compare every keywords with phrase
   inFile2.open("../model/time.txt",ios::in);
	 while (inFile2>>word2)
   {
                size_t pos = findCaseInsensitive(i_sentence, word2);
                if( pos != std::string::npos)
                 {
                    m_Time = word2;
				 				}
		}		
		
	findCalendarIntent(i_sentence);				                   
             
    // not closing streams can cause memory leaks
    inFile.close();
	  inFile1.close();
	  inFile2.close();

}

/* FindCalendarIntent sub-rotine function*/
void IntentRecognizer::findCalendarIntent(const string i_sentence)
{
	std::smatch searchedResult;
  std::regex searchTarget;

   /* TIME regex*/
     searchTarget = std::regex("([0-9][.|:][0-5][0-9]"
                        "|[0-9][.|:][0-5][0-9][ |][a|A][m|M]"
                        "|[0-9][.|:][0-5][0-9][ |][p|P][m|M]"
                        "|[1][0-9][.|:][0-5][0-9]"
                        "|[1][0-9][.|:][0-5][0-9][ |][a|A][m|M]"
                        "|[1][0-9][.|:][0-5][0-9][ |][p|P][m|M]"
                        "|[2][0-3][.|:][0-5][0-9]"
                        "|[2][0-3][.|:][0-5][0-9][ |][a|A][m|M]"
                        "|[2][0-3][.|:][0-5][0-9][ |][p|P][m|M])");
						
	if(std::regex_search(i_sentence, searchedResult, searchTarget))
  {
		m_Date = string(searchedResult[0]);
  }
}

/* findFactIntent sub-rotine function*/
void IntentRecognizer::findFactIntent(const string i_sentence)
{
    std::string word;
	  ifstream inFile3;
    inFile3.open("../model/fact.txt",ios::in);
	   
    while (inFile3>>word)
     {
				//comparing input sentence against fact keywords
			    size_t pos = findCaseInsensitive(i_sentence, word);
                if( pos != std::string::npos)
                 {
                    m_Fact = word;
		 						 }
		}
		inFile3.close();
}
