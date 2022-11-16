#include <string>
#include "IntentRecognizer.h"

BOOST_AUTO_TEST_SUITE( case_insensitive_search )

BOOST_AUTO_TEST_CASE( simple )
{
	size_t IntentRecognizer::findCaseInsensitive(std::string data, std::string toSearch, size_t pos = 0)
    std::string data = "What is the weather like today";
	std::string toSearch = "weather";
    size_t result;
    result = IntentRecognizer::findCaseInsensitive(toRev);

    BOOST_CHECK_EQUAL( result, 1 );

}
BOOST_AUTO_TEST_SUITE_END()


