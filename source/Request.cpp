#include <HTTP/Request.h>

namespace HTTP{

    std::vector<std::string> split_string(const std::string& s, std::string rgx_str )
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

    Method Request::validate_method(const std::string& message)
    {
        auto it = table.find(message);   
        if (it != table.end())
        {
            m_method = it->second;
        }
        return m_method; 
    }

    bool Request::validate_uri(const std::string& message)
    {
       m_uri.from_string(message);
       if(m_uri.get_scheme() != "http")
       {
           if(m_uri.get_scheme() != "https"){
               return false;
           }

       } 
       return true;
    }

    std::string Request::parse_start_line(const std::string& message)
    {
        if (message == ""){
            throw ("Faild parsing StartLine, message is empty!");
        }
        if (ends_with(message, CRLF) == false){
            throw ("Faild parsing StartLine, message do not end with CRLF");
        }
        std::vector<std::string> tokens = split_string(message);

        std::string methodtoken = tokens[0];
        std::string URI = tokens[1];
        std::string version = tokens[2];

        validate_method(methodtoken);
        validate_version(version);
        validate_uri(URI);     
        return "";
    }
    
    Version Request::validate_version(const std::string& message)
    {
        auto ver = tableVersions.find(message);   
        if (ver != tableVersions.end())
        {
            m_version = ver->second;
        }
        return m_version; 
    }    

    bool Request::ends_with(const std::string &mainStr, const std::string &toMatch)
    {
        if (mainStr.size() >= toMatch.size() &&
            mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
            return true;
        else
            return false;
    }

}//namespace HTTP
