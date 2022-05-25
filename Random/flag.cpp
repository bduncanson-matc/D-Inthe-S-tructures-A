/*
 * Solution give for the problem :
 * https://www.w3resource.com/cpp-exercises/basic/cpp-basic-exercise-41.php
int main()
{
    cout << "\n\n Print the American flag:\n"; //fyi ignored by test fucntion
    cout << "-----------------------------\n"; // fyi ignored by test fucntion
    cout <<"* * * * * * =================================="<<"\n";
    cout <<" * * * * *  =================================="<<"\n";
    cout <<"* * * * * * =================================="<<"\n";
    cout <<" * * * * *  =================================="<<"\n";
    cout <<"* * * * * * =================================="<<"\n";
    cout <<" * * * * *  =================================="<<"\n";
    cout <<"* * * * * * =================================="<<"\n";
    cout <<" * * * * *  =================================="<<"\n";
    cout <<"* * * * * * =================================="<<"\n";
    cout <<"=============================================="<<"\n";
    cout <<"=============================================="<<"\n";
    cout <<"=============================================="<<"\n";
    cout <<"=============================================="<<"\n";
    cout <<"=============================================="<<"\n";
    cout <<"=============================================="<<"\n";
}
 */
// My solution using functions


#include <iostream>
#include <vector>
#include <string>

//creates an equals string with number of repeating '=' characters as the argument
std::string strEquals(int num);
//creates the stars string, not 5, 6 offset with spaces in between
std::string strStars(int lineNumber);
//create the vector, vector[lineNumber] = string sequence
std::vector<std::string> createFlag();
//prints the flag vector could add arg to add customization of the pattern but meh
void printFlag();
void testProgram();
//driver function
int main() {
    printFlag();
    testProgram();
    return 0;
}

std::string strEquals(int num){
    std::string str(num, '=');
    return str;
}

std::string strStars(int lineNumber){
    std::string str;
    if( lineNumber%2 == 0) {
        // pattern for lines 0, 2, 4, 6, 8
        str = "* * * * * * ";//single space at the end
    }else {
        // pattern for lines 1, 3, 5, 7
        str = " * * * * *  ";// double space
    }
    return str;
}
std::vector<std::string> createFlag()
{
    std::string str;
    std::vector<std::string> flag;
    for (int i = 0; i < 15; i++) {
        //lines 0 through 8 hold strings with stars
        if (i < 9){
            str = strStars(i) + strEquals(34);
            flag.push_back(str);
        }
        //lines 9 through 14 have strings of just equals
        else if (i >= 9 && i < 15) {
            str = strEquals(46);
            flag.push_back(str);
        }
        // if no condition are met break the loop
        else
            break;
    }
    return flag;
}
void printFlag() {
    //declare and initiate vector
    std::vector<std::string> flag = createFlag();
    std::string subStr1 = "\t\t\t  My flag solution\n",
        subStr2(46, '-'),
        str = subStr1 + subStr2 + "\n";  // used to create a centered intro
    std::cout << str;
    //iterate through each line of the string vector and print them then end the output line
    for (auto const& x : flag) {
        std::cout << x << std::endl;
    }
}
void testProgram()
{
    //copy and pasted all the lines from the website after the first two
    // add those lines to a vector and then looped with my function generated
    //solution to check if the match.
    int count = 0;//variable used to count changes
    std::vector <std::string> testVector, flagVec = createFlag();
    testVector.push_back("* * * * * * ==================================");
    testVector.push_back(" * * * * *  ==================================");
    testVector.push_back("* * * * * * ==================================");
    testVector.push_back(" * * * * *  ==================================");
    testVector.push_back("* * * * * * ==================================");
    testVector.push_back(" * * * * *  ==================================");
    testVector.push_back("* * * * * * ==================================");
    testVector.push_back(" * * * * *  ==================================");
    testVector.push_back("* * * * * * ==================================");
    testVector.push_back("==============================================");
    testVector.push_back("==============================================");
    testVector.push_back("==============================================");
    testVector.push_back("==============================================");
    testVector.push_back("==============================================");
    testVector.push_back("==============================================");
    for (int i = 0; i<testVector.size(); i++){
        if (testVector[i] != flagVec[i]){
            count += 1;
        }
    }
    if (count == 0)
        std::cout << "\n\n\n All lines match";

}

/* Console result of main()
* * * * * * =================================
 * * * * *  =================================
* * * * * * =================================
 * * * * *  =================================
* * * * * * =================================
 * * * * *  =================================
* * * * * * =================================
 * * * * *  =================================
* * * * * * =================================
=============================================
=============================================
=============================================
=============================================
=============================================
=============================================
