#include "fonctiongraph.h"


bool printMessageErreur(std::string message){
    std::cout << "\n\n-----------------------------------------------------\n";
    std::cout << "\t\tFATAL ERROR\n\n\t" << message;
    std::cout << "\n \n-----------------------------------------------------\n";
    return false;
}
