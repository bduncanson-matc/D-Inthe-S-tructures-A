#include "solution.h"
#include <algorithm>  //for_each

solution::solution(){
    alogNames NameOfAlog(); //creates a vector with the names of the problems
    int counter = 1; //local variable that populates the text with a number will add a cin that takes the input from the user and matches.
    std::cout << "Enter the number of the problem you would like to know" 
    << "more about:\n";
    for_each(NameOfAlog.m_ProblemNames.begin(), NameOfAlog.m_ProblemNames.end(),  //std for_each with print lambda attached
        [&counter](const string s){std::cout << counter<<":\t" <<
            s << endl;
            ++counter;}); //use a lambda on the for_each function to print txt file contents
  //to add a input next
    }
}
