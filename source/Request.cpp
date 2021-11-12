#include <HTTP/Request.h>
#include <regex>

namespace HTTP{

    Request::Request()
    {
    }

    Request::~Request()
    {
    }

    Method Request::get_method() const
    {
        return m_method;
    }

    std::string Request::get_uri_type() const
    {
        return uri_type_to_stirng();
    }

    const std::string Request::uri_type_to_stirng() const 
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

    bool Request::parse_aterisk_uri(const std::string& uri)
    {
        if( uri == asterisk && m_method == Method::OPTIONS){
            m_uri.uri_str = asterisk; 
            m_uri.type = Uri_type::asterisk;
            return true;
        }
        return false;
    }

    bool Request::parse_absolute_uri(const std::string& uri)
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

    bool Request::parse_absolute_path(const std::string& uri)
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

    bool Request::parse_authority_uri(const std::string& uri)
    {
        if(std::regex_match( uri.begin(), uri.end(), std::regex(R"([a-zA-Z0-9+:\_\.@]*)")) && m_method == Method::CONNECT)
        {
            m_uri.uri_str = uri;
            m_uri.type = Uri_type::authority;
            return true; 
        }
        return false;
    }

    bool Request::validate_uri(const std::string& uri)
    {
        return parse_aterisk_uri(uri) || parse_absolute_uri(uri) || parse_absolute_path(uri) || parse_authority_uri(uri);
    }    

    bool Request::parse_start_line(const std::string& request_line)
    {
        if (request_line.empty() == true)
        {   
            return false;
        }
        std::pair<std::string, std::size_t > req_line_tokens;
        req_line_tokens = tokenize(request_line, " ", 0);
        if(validate_method(req_line_tokens.first) == false)
        {
            return false;
        }
        req_line_tokens = tokenize(request_line, " ", req_line_tokens.second);
        if(validate_uri(req_line_tokens.first) == false)
        {
            return false;
        }
        req_line_tokens = tokenize(request_line, CRLF,req_line_tokens.second);
        if(validate_version(req_line_tokens.first) == false)
        {
            return false;
        }
        return true;
    }

}//namespace HTTP
