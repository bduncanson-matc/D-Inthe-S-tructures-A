//include the alog names class constructor. Opens text file and adds each line to a vector
#include "alogNames.h"

void alogNames::createSSofNames(){
    
    std::fstream nameFile; //text stream object intiated
    nameFile.open(textFileLocation); //add file to text stream
    
    if(!nameFile){ //if can't open file, prompt and end function
      std::cerr << "The file including the problem names cannot be opened"
        <<std::endl;
      return;
    }
    
    std::string line; //variables used to write each line of the text file to m_ProblemNames
    
    while(std::getline(nameFile, line)){ //change string to each line
      if(str.length()>0) m_ProblemNames.push_back(line); //add line to vector
    }
    if (!m_ProblemNames.empty()) haveNames = true; //change member bool flag
}
