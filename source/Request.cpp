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

    std::pair<std::string, std::string> tokenize(const std::string& str, const std::string& delimeter)
    { 
        std::string remining_string;
        std::string token;
        std::size_t found = str.find(delimeter);
        token = str.substr(0, found);
        remining_string = str.substr(found + 1, str.length());
        return { token, remining_string };
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
        request_tokens = HTTP::tokenize(request_tokens.second, CRLF + CRLF);
        if(parse_header_filds(request_tokens.first)==false)
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

    bool Request::validate_uri(const std::string& uri){

        m_uri.from_string(uri);
        bool ret_val = (m_uri.get_scheme().empty())? (m_uri.get_path().empty())? (m_uri.get_authority().empty())? false : true  
                                                                                : true 
                                                    :(m_uri.get_scheme() == http || m_uri.get_scheme() == https)? (m_uri.get_path().empty())? false
                                                                                                                                            : true 
                                                                                                                : false;
        return ret_val;
    
    }

    bool Request::parse_header_filds(const std::string& header)
    {
        std::pair<std::string, std::string> header_tokens;
        header_tokens = HTTP::tokenize(header, "\n");

        while (header_tokens.first != empty_string)
        {
            std::pair<std::string, std::string> field_tokens = HTTP::tokenize(header_tokens.second," ");
            
            auto head = header_table.find(field_tokens.first);
            if (head != header_table.end())
            {
                Header_Field h_field;
                h_field.field = head->second;
                h_field.f_value = field_tokens.second;
                m_header.push_back(h_field);
                
            }
            else
            {
                return false;
            }

            header_tokens = HTTP::tokenize(header, " ");
        }
     
        return true;
    }

}//namespace HTTP
