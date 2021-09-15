#include <HTTP/Request.h>

namespace HTTP{

    
    std::pair<std::string, std::string> tokenize(const std::string& str, const std::string& delimeter)
    { 
        std::string remining_string;
        std::string token;
        std::size_t found = str.find(delimeter);
        token = str.substr(0, found);
        remining_string = str.substr(found + 1, str.length());
        return { token, remining_string };
    }

    Request::Request()
    {
    }

    Request::~Request()
    {
    }

    Method Request::get_method()
    {
        return m_method;
    }

    Version Request::get_version()
    {
        return m_version;
    }

    bool Request::validate_method(const std::string& message)
    {
        auto it = table.find(message);   
        if (it != table.end())
        {
            m_method = it->second;
            return true;
        }
        return false; 
    }

    bool Request::validate_uri(const std::string& message)
    {

        m_uri.from_string(message);
        std::cout<< m_uri.get_path()<<std::endl;

        if (m_uri.get_authority() == message)
        {
            if (m_method != Method::CONNECT)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            if (m_uri.get_scheme() != empty_string && m_uri.get_scheme() != http && m_uri.get_scheme() != https )
            {
                return false;
            }
            else
            {
                if (m_uri.get_path() == empty_string)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }    
            
        }
    
    }

    bool Request::parse_request_line(const std::string& message)
    {
        if (message == empty_string)
        {   
            return false;
        }
        if (ends_with(message, CRLF) == false)
        {
           return false;
        }
        std::pair<std::string,std::string> message_tokens;
        message_tokens = tokenize (message, " ");
        if(validate_method(message_tokens.first) == false)
        {
            return false;
        }
        message_tokens = tokenize(message_tokens.second, " ");
        if(validate_uri(message_tokens.first)== false)
        {
            return false;
        }
        message_tokens = tokenize(message_tokens.second, CRLF);
        if(validate_version(message_tokens.first)== false)
        {
            return false;
        }
        return true;
    }
    
    bool Request::validate_version(const std::string& message)
    {
        auto ver = tableVersions.find(message);   
        if (ver != tableVersions.end())
        {
            m_version = ver->second;
            return true;
        }
        return false; 
    }    

    bool Request::ends_with(const std::string &mainStr, const std::string &toMatch)
    {
        if (mainStr.size() >= toMatch.size() &&
            mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
            {
                return true;
            }
            
        else
        {
            return false;
        }
    }

}//namespace HTTP
