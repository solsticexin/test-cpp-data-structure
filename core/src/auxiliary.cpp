#include "../include/auxiliary.h"
#include <sstream>
namespace auxiliary {
    int max(int a,int b){
        if (a>=b) 
            return a;
        else return b;
    }   
    
    // 将字符串按空格分割为vector
    std::vector<std::string> splitString(const std::string& str) {
        std::vector<std::string> result;
        std::istringstream iss(str);
        std::string token;
        
        while (iss >> token) {
            result.push_back(token);
        }
        
        return result;
    }
}
