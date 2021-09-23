#include <HTTP/Request.h>

namespace HTTP{

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

    std::pair<std::string, std::string> tokenize(const std::string& text, const std::string& delimeter)
    { 
        std::size_t found = text.find(delimeter);
        return { text.substr(0, found), text.substr(found + 1, text.length()) };
    }

    bool Request::validate_method(const std::string& method)
    {
        auto it = table.find(method);   
        if (it != table.end())
        {
            m_method = it->second;
            return true;
        }
        return false; 
    }

    bool Request::validate_aterisk_uri()
    {
        if(m_method == Method::OPTIONS)
        {
            return true;
        }
        return false;
    }

    bool Request::is_absolute_uri()
    {
        if(m_uri.get_scheme() == http || m_uri.get_scheme() == https )
        {
            return (m_uri.get_path() != empty_string);
        }
        return false;
    }

    bool Request::is_absolute_path()
    {
        if(m_uri.get_scheme() == empty_string)
        {
            return (m_uri.get_path() != empty_string);
        }
        return false;
    }

    bool Request::is_authority_uri(const std::string& uri)
    {
        if(std::regex_match( uri.begin(), uri.end(), std::regex(R"([a-zA-Z0-9+:\_\.@]*)"))){ 
           return true; 
        }
        return false;
    }

    bool Request::validate_absolute_uri(const std::string& uri)
    {
        return true;
    }
    
    bool Request::validate_absolute_path(const std::string& uri)
    {
        return true;
    }
    bool Request::validate_authority_uri(const std::string& uri)
    {
        if(m_method == Method::CONNECT){ 
           return true; 
        }
        return false;
    }

    bool Request::validate_uri(const std::string& uri)
    {

        if(uri == asterisk)
        {
            return validate_aterisk_uri();
        }

        m_uri.from_string(uri);

        if(is_absolute_uri() == true)
        {
            return validate_absolute_uri(uri);
        }
        if(is_absolute_path() == true)
        {
            return validate_absolute_path(uri);
        }
        
        if(is_authority_uri(uri) == true )
        {
            return validate_authority_uri(uri);
        }
        return false;
    
    }

    bool Request::parse_request_line(const std::string& request_line)
    {
        if (request_line == empty_string)
        {   
            return false;
        }
        if (ends_with(request_line, CRLF) == false)
        {
           return false;
        }
        std::pair<std::string,std::string> request_tokens;
        request_tokens = HTTP::tokenize(request_line, " ");
        if(validate_method(request_tokens.first) == false)
        {
            return false;
        }
        request_tokens = HTTP::tokenize(request_tokens.second, " ");
        if(validate_uri(request_tokens.first)== false)
        {
            return false;
        }
        request_tokens = HTTP::tokenize(request_tokens.second, CRLF);
        if(validate_version(request_tokens.first)== false)
        {
            return false;
        }
        return true;
    }
    
    bool Request::validate_version(const std::string& version)
    {
        auto ver = table_versions.find(version);   
        if (ver != table_versions.end())
        {
            m_version = ver->second;
            return true;
        }
        return false; 
    }    

    bool Request::ends_with(const std::string &main_str, const std::string &to_match)
    {
        if (main_str.size() >= to_match.size() &&
            main_str.compare(main_str.size() - to_match.size(), to_match.size(), to_match) == 0)
            {
                return true;
            }
            
        else
        {
            return false;
        }
    }

}//namespace HTTP
