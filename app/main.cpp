#include <iostream>
#include "IntentRecognizer.h"

int main(int argc, char** argv)
{
    if(argc > 1)
    {
       IntentRecognizer irec;
       std::cout << irec.GetIntent(argc-1, &argv[1]) << std::endl;
	   
    }
}