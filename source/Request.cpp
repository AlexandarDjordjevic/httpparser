#include <HTTP/Request.h>

namespace HTTP{

    std::vector<std::string> splitString(const std::string& s, std::string rgx_str )
    { 
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

    Method Request::validateMethod(const std::string& message)
    {
        auto it = table.find(message);   
        if (it != table.end())
        {
            m_method = it->second;
        }
        return m_method; 
    }

    std::string Request::validateURI(const std::string& message)
    {
        URI::Uri c;
        c.from_string(message);
    }

    std::string Request::parseStartLine(const std::string& message)
    {
        if (message == ""){
            throw ("Faild parsing StartLine, message is empty!");
        }
        if (endsWith(message, CRLF) == false){
            throw ("Faild parsing StartLine, message do not end with CRLF");
        }
        std::vector<std::string> tokens = splitString(message);

        std::string methodtoken = tokens[0];
        std::string URI = tokens[1];
        std::string version = tokens[2];

        validateMethod(methodtoken);
        validateVersion(version);
        validateURI(URI);     
        
    }
    
    Version Request::validateVersion(const std::string& message)
    {
        auto ver = tableVersions.find(message);   
        if (ver != tableVersions.end())
        {
            m_version = ver->second;
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
