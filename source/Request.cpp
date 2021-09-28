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

    std::string Request::get_uri_type()
    {
        return uri_type_to_stirng();
    }

    std::pair<std::string, std::size_t> tokenize(const std::string& text, const std::string& delimeter, std::size_t position) 
    { 
        std::size_t found = text.find(delimeter, position);
        return { text.substr(position, found - position), found + 1 };
    }

    const std::string Request::uri_type_to_stirng()
    {
        switch (m_uri.type)
        {
            case Uri_type::asterisk: return "asterisk";
            case Uri_type::absolute_uri: return "absolute_uri";
            case Uri_type::absolute_path: return "absolute_path";
            case Uri_type::authority: return "authority";
            default: return "unknown";
        }
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

    bool Request::validate_aterisk_uri(const std::string& uri)
    {
        if( uri == asterisk && m_method == Method::OPTIONS){
            m_uri.uri_str = asterisk; 
            m_uri.type = Uri_type::asterisk;
            return true;
        }
        return false;
    }

    bool Request::validate_absolute_uri(const std::string& uri)
    {
        m_uri.uri_obj.from_string(uri);
        if((m_uri.uri_obj.get_scheme() == http || m_uri.uri_obj.get_scheme() == https ) && (m_uri.uri_obj.get_path().empty() == false))
        {
            m_uri.type = Uri_type::absolute_uri;
            m_uri.uri_str = uri;
            return true;
        }
        return false;
    }

    bool Request::validate_absolute_path(const std::string& uri)
    {
        m_uri.uri_obj.from_string(uri);
        if(m_uri.uri_obj.get_scheme().empty() == true && m_uri.uri_obj.get_path().empty() == false)
        {
            m_uri.type = Uri_type::absolute_path;
            m_uri.uri_str = uri;
            return true;
        }
        return false;
    }

    bool Request::validate_authority_uri(const std::string& uri)
    {
        if(std::regex_match( uri.begin(), uri.end(), std::regex(R"([a-zA-Z0-9+:\_\.@]*)")) && m_method == Method::CONNECT){
            m_uri.uri_str = uri;
            m_uri.type = Uri_type::authority;
            return true; 
        }
        return false;
    }

    bool Request::validate_uri(const std::string& uri)
    {
        return validate_aterisk_uri(uri) || validate_absolute_uri(uri) || validate_absolute_path(uri) || validate_authority_uri(uri);
    }

    bool Request::parse_request_line(const std::string& request_line)
    {
        if (request_line.empty() == true || ends_with(request_line, CRLF) == false)
        {   
            return false;
        }

        std::pair<std::string, std::size_t > request_tokens;
        request_tokens = HTTP::tokenize(request_line, " ", 0);
        if(validate_method(request_tokens.first) == false)
        {
            return false;
        }
        request_tokens = HTTP::tokenize(request_line, " ", request_tokens.second);
        if(validate_uri(request_tokens.first)== false)
        {
            return false;
        }
        request_tokens = HTTP::tokenize(request_line, CRLF,request_tokens.second);
        if(validate_version(request_tokens.first)== false)
        {
            return false;
        }
        request_tokens = HTTP::tokenize(request_tokens.second, CRLF + CRLF);
        if(parse_header_fields(request_tokens.first)==false)
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
       return (main_str.size() >= to_match.size() &&
            main_str.compare(main_str.size() - to_match.size(), to_match.size(), to_match) == 0);
    }

    bool Request::parse_header_fields(const std::string& header)
    {
        std::pair<std::string, std::string> header_tokens;
        header_tokens = HTTP::tokenize(header, "\n");

        while (header_tokens.first != empty_string)
        {
            std::pair<std::string, std::string> field_tokens = HTTP::tokenize(header_tokens.second," ");

            auto head = fields_table.find(field_tokens.first);
            if (head != fields_table.end())
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
