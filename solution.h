//Class that contains the is with a prompt that selects alogrithm to work on.
#include <string>
#include <vector>
#include "alogNames.h"

class solution{
public
    friend class alogNames; //include names class, add groupings later w/ db

    alogNames m_NameOfAlog; //initate a alog name class
    
    Solution();
    
    void getProblemInfo(); //to do
      
}
