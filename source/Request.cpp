#include <HTTP/Request.h>

namespace HTTP{

    std::vector<std::string> splitString(const std::string& s, std::string rgx_str ){ 
        std::vector<std::string> tokens;
        std::regex pattern (rgx_str);
        std::sregex_token_iterator iter(s.begin(),s.end(), pattern,-1);
        std::sregex_token_iterator end;
        while(iter != end){
            tokens.push_back(*iter);
            ++iter;
        }
        return tokens;
    }

    Request::Request()
    {
    }
    Request::~Request()
    {
    }

    Method Request::getMethod()
    {
        return m_method;
    }

    Method Request::validateMethod(const std::string& message){
        auto it = table.find(message);   
        if (it != table.end())
        {
            m_method = it->second;
        }
        return m_method; 
    }

    // bool Request::parseStartLine(const std::string& message)
    // {
    //     if (message == ""){
    //         return false;
    //     }
    //     if (endsWith(message, CRLF) == false){
    //         return false;
    //     }
    //     std::vector<std::string> tokens = splitString(message);
    //     std::string methodtoken = tokens[0];
    //     std::string URI = tokens[1];
    //     std::string version = tokens[2];

    //     validateMethod(methodtoken);
    //     validateVersion(version);
    //     //fromString(URI);
        
    //     if(validateURI(URI) == false) {
    //         return false;
    //     }
    //     m_uri = URI;
    //     if (validateVersion(version) == false){
    //         return false;
    //     }
    //     m_version = version;
    //     return true;
    // }
    
    Version Request::validateVersion(const std::string& message){
        auto it = tableVersions.find(message);   
        if (it != tableVersions.end())
        {
            m_version = it->second;
        }
        return m_version; 
    }    

    bool Request::endsWith(const std::string &mainStr, const std::string &toMatch)
    {
        if (mainStr.size() >= toMatch.size() &&
            mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
            return true;
        else
            return false;
    }

}//namespace HTTP
