#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

int main(){
    testAll();
    testAllExtended();
    std::cout<<"Finished all tests!"<<std::endl;
	system("pause");
}
