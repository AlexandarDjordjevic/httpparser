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

    bool Request::parse_start_line(const std::string& message)
    {
        if (message == ""){
            return false;
        }
        if (ends_with(message, CRLF) == false){
           return false;
        }
        std::vector<std::string> tokens = split_string(message);

        std::string methodtoken = tokens[0];
        std::string URI = tokens[1];
        std::string version = tokens[2];

        validate_method(methodtoken);
        validate_version(version);
        validate_uri(URI);     
        return true;
    }

    Request_Header Request::validate_header(const std::string& message)
    {
       auto head=tableHeader.find(message);
       if(head!=tableHeader.end())
       {
           m_header= head->second;
       } 
       return m_header;
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
