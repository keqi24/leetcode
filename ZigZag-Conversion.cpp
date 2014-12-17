class Solution {
public:
    string convert(string s, int nRows) {
       if(nRows <= 1 || s.size() == 0 || s.size() <= nRows) {
            return s;
        }
        
        string *dataArray = new string[nRows];
       
        int arrayIndex = 0;
        int addNum = 1;
        for(string::iterator iter=s.begin(); iter!=s.end(); ++iter) {
        	dataArray[arrayIndex].push_back(*iter);
        	if (arrayIndex == (nRows-1)){
        		addNum = -1;
        	} else if (arrayIndex == 0) {
        		addNum = 1;
        	}
        	arrayIndex += addNum;
        }

        string result;
        for (int i = 0; i < nRows; ++i){
        	result.append(dataArray[i]);
        }

        return result;
    }
};