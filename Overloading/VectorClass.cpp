   //Vector functions
   
   vector<int>& operator++(vector<int>& v, int x) {  // ++ now changes all values to their elements.
        for (auto a=begin(v); a!=end(v); ++a) {
          *a = distance(a,v.end());
        }
        return v;
    }
    
        vector<int>& operator+=(vector<int>& v, int x) {  // += increments each value of a vector by x;
        for (auto a=begin(v); a!=end(v); ++a) {
          *a = distance(a,v.end());
        }
        return v;
    }
