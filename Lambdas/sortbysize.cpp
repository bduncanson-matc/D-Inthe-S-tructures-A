sort(strs.begin(), strs.end(), [](const string& first, //using std::sort sort your container by size of the rather than value.
    const string& second){
      return first.size() < second.size();});

Example:
vector<string>& strs {"DD","DDDD","DDD","D")
std::sort(strs.begin(), strs.end(), [](const string& first, //if not using std namespace.
    const string& second){
      return first.size() < second.size();});
 //return would be str = {"D","DD","DDD","DDDD"}; 
 //can be useful in dynamic programming to quickly populate your lower values
