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

    bool Request::validateMethod(const std::string& message){
        auto it = table.find(message);
        

        if (it != table.end())
        {
            m_method = it->second;
            return true;
            
        }
        return false;
        
    }

    bool Request::parseStartLine(const std::string &message)
    {
        if (message == ""){
            return false;
        }
        if (endsWith(message, CRLF) == false){
            return false;
        }
        std::vector<std::string> tokens = splitString(message);
        std::string methodtoken = tokens[0];
        std::string URI = tokens[1];
        std::string version = tokens[2];

        if (validateMethod(methodtoken) == false){
            return false;
        }
        
        if(validateURI(URI) == false) {
            return false;
        }
        m_uri = URI;
        if (validateVersion(version) == false){
            return false;
        }
        m_version = version;
        return true;
    }
    bool Request::validateURI(std::string &m_uri)
    {
        if (m_uri == "*")
        { 
            return true;
        }
        std::string uri_beg = m_uri.substr(0, 7);
        std::string uri_first_ch = m_uri.substr(0, 1);
        if (uri_beg == "http://")
        {
                return true;
        }
        if (uri_first_ch == "/"){
            return true;
        }
        
        return false;
        
    }
    bool Request::validateVersion(std::string& version){
        if(version == "HTTP/0.9"){
            return true;
        }
        if(version!= "HTTP/1.0"){
            return true;
        }
        if(version != "HTTP/1.1"){
            return true;
        }
        if(version != "HTTP/2.0"){
            return true;
        }
            
        return false;
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