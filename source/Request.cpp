#include <HTTP/Request.h>
#include <regex>

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

    bool Request::validateMethod(const std::string& message){
        auto it = table.find(message);
        

        if (it != table.end())
        {
            method = it->second;
            return true;
            
        }
        return false;
        
    }

    bool Request::validateRequestStartLine(const std::string &message)
    {
        if (message == ""){
            return false;
        }
        
        if (endsWith(message, CRLF) == false){
            return false;
        }
        std::vector<std::string> tokens = splitString(message);
        std::string method = tokens[0];
        std::string URI = tokens[1];
        std::string version = tokens[2];
        Method m;

        if (validateMethod(method) == false){
            return false;
        }

        std::string htp=URI.substr(0,7);

        if(!validateURI(URI)) return false;

        if (!validateVersion(version)) return false;

        //this->request_method = method;
        //this->request_uri = URI;
        //this->request_version = version;
        return true;
    }
    bool Request::validateURI(std::string &uri)
    {
        if (uri == "*")
        { 
            return true;
        }
        std::string htp = uri.substr(0, 7);
        std::string pocinje = uri.substr(0, 1);
        if (htp == "http://")
        {
                return true;
        }
        if (pocinje == "/"){
            return true;
        }
        return false;
        
    }
    bool Request::validateVersion(std::string& ver_token){
        if (ver_token != "HTTP/0.9" && ver_token!= "HTTP/1.0" && ver_token != "HTTP/1.1" && ver_token != "HTTP/2.0")
            return false;
        return true;
    }
    

    bool Request::endsWith(const std::string &mainStr, const std::string &toMatch)
    {
        if (mainStr.size() >= toMatch.size() &&
            mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
            return true;
        else
            return false;
    }

}//namespace Namespace