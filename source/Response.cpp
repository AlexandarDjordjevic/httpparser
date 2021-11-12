#include <HTTP/Response.h>
#include <iostream>
namespace HTTP{

    Response::Response(){

    }
    Response::~Response(){

    }

    short Response::get_status_code() const
    {
        return m_status_code;
    }

    std::string Response::get_reason_phrase() const
    {
        return m_reason_phrase;
    }

    bool Response::parse_start_line(const std::string& status_line)
    {
        if (status_line.empty() == true)
        {   
            return false;
        }
        std::pair<std::string, std::size_t > status_line_tokens;
        status_line_tokens = tokenize(status_line, " ", 0);

        if(validate_version(status_line_tokens.first) == false) 
        {
            return false;
        }
        status_line_tokens = tokenize(status_line, " ", status_line_tokens.second);
        if(parse_status_code(status_line_tokens.first) == false)
        {
            return false;
        }
        status_line_tokens = tokenize(status_line, CRLF,status_line_tokens.second);
        if(status_line_tokens.first.empty() == false)
        {
            m_reason_phrase = status_line_tokens.first;
        }
        return true;
    }

    bool Response::parse_status_code(const std::string& status_code)
    {
        std::smatch match;
        if(std::regex_match(status_code, match,std::regex("([1-5][0-9][0-9])")))
        {   
            m_status_code = std::stoi(status_code);
            return true;
        }
        return false; 
    }

}//namespace HTTP