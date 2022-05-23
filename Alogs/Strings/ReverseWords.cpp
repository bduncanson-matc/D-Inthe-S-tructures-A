//***Recursive 
Given a character array s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by a single space.
Your code must solve the problem in-place, i.e. without allocating extra space.
example vector<char> input = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
example vector<char> output = ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Using a helper function with iterator args that recursively call a swap with the next increment/decrement in the string until the reach each other.
*/
class Solution {
public:
    void reverseWord(vector<char>::iterator& f, vector<char>::iterator b){ //helper
        if(f == --b)
            return;
        swap(*(f++),*(b));
        if(f == b) return; 
        return reverseWord(f,b);
    }
    void reverseWords(vector<char>& s) {
        auto it = s.begin();
        for(auto it2 = s.begin()+1; it2!=s.end();++it2){ //move it2 until it hits a space char s.end();
            if(*it2 == ' '){
                reverseWord(it, it2); //reverse words one at a time at each space character
                it = it2 + 1; //move it to it over it2
            }
        }
        if(it==s.begin()) return;  //if it has not moved there are not spaces and this the original string is the return.
        reverseWord(it, s.end());  //the final word did not reverse since the while loop quits at s.end() so reverse the last word
        reverse(s.rbegin(),s.rend());  //reverse the entire string since the words are backwards and opposite of their possistion.
    }
};

/*
Write a function that reverses a string. The input string is given as an array of characters s.
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/
class Solution {
public:
    void swapChars(vector<char>::iterator f, vector<char>::iterator b){
   if(f+1 == b) return;
   swap(*(f++), *(--b));   
if(f!=b) return swapChars(f,b);
  }
    void reverseString(vector<char>& s) {
     swapChars(s.begin(),s.end());
    }
};
