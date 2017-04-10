#include<string>
//#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {



        
    /* ****************************************************************************** */    
    //     if (s.empty()) return 0;
        
    //     string result, temp;
    //     string::iterator begin = s.begin(), end=s.end();

    //     result = PreDiff(s);
        
    //     //s.erase(0, result.length()-1);
    //     begin += result.length();
        
        
    //     while( begin!=end && begin<end && (end - begin) > result.length() ) {
    //         //cout<<"result\t=\t" << result << '\t' << result.length()<<endl;
    //         string s1(s, result.length());
    //         temp = PreDiff(s1);
    //         begin += temp.length();
    //         //cout<< "temp\t=\t" << temp << '\t' << temp.length()<<endl;

    //         if ( result.length() < temp.length() ) {
    //             result = temp;
    //             //cout<<"result rest!\t" << result.length()<<endl;
    //         }
    //         //s.erase(0, temp.length()-1);
    //     }
        
    //     return result.length();
    // }
    
    // string PreDiff(string t) {
    //     string ret;
    //     for (int i=0; i < t.length()-1; i++) {
    //         if( ret.find(t[i]) == std::string::npos ) {
    //             ret += t[i];
    //         }
    //         else return ret;
    //     }
    //     return ret;
    /* ****************************************************************************** */
    }
};