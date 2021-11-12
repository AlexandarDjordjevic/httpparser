#include <HTTP/Message.h>

namespace HTTP{

    Message::Message(){

    }
    Message::~Message(){

    }

    Version Message::get_version() const
    {
        return m_version;
    }
  
    std::string Message::get_header_field_value(const std::string& key) const 
    {
        if(m_header.count(key) > 0)
        {
            return m_header.find(key)->second;
        }
        return {};
    }

     std::string Message::get_body_type() const  
    { 
        return m_body.type;
    }

    std::size_t Message::get_body_length() const 
    {
        return m_body.length;
    }
    
    std::string Message::get_body_data() const 
    {
        return m_body.data;
    }

    std::pair<std::string, std::size_t> Message::tokenize(const std::string& text, const std::string& delimeter, std::size_t position) 
    { 
        std::size_t found = text.find(delimeter, position);
        return { text.substr(position, found - position), found + delimeter.length() };
    }
       
    bool Message::validate_version(const std::string& version)
    {
        auto ver = table_versions.find(version);   
        if (ver != table_versions.end())
        {
            m_version = ver->second;
            return true;
        }
        return false; 
    }

    bool Message::parse_header_fields(const std::string& header)
    {
        int first_group = 1;
        int second_group = 2;

        std::string key;
        std::string value;
        std::string header_copy {header};        
        std::smatch match;
       
        while(std::regex_search(header_copy.cbegin(), header_copy.cend(), match, std::regex("(.*):\\s(.*)\\n")))
        {
            key = match[first_group];
            value = match[second_group];        
            m_header[key] = value;
            header_copy = match.suffix().str();
        }

        if(std::regex_search(header_copy.cbegin(), header_copy.cend(), match, std::regex("(.*):\\s(.*)")))
        {
            key = match[first_group];
            value = match[second_group];        
            m_header[key] = value;
        }
        return true;
    }

    bool Message::parse_body(const std::string& body)
    {
        std::string con_len = get_header_field_value("Content-Length");
        std::string encoding = get_header_field_value("Transfer-Encoding");

        const auto body_length([](const std::string &body, std::string &con_len, std::string &encoding) -> size_t
        {
           
            if (con_len.empty() == true && encoding.empty() == false )
            {
                return body.length();
            }
                
            return (con_len.empty()== false && body.length() == std::stoi(con_len)) ? std::stoi(con_len) : 0;
        });
        m_body.length = body_length(body, con_len, encoding);
        m_body.data = body;
        m_body.type = get_header_field_value("Content-Type");

        return true;
    }

    bool Message::from_string(const std::string& message)
    {
        if (message.empty() == true)
        {   
            return false;
        }
        std::pair<std::string, std::size_t> message_tokens;
        message_tokens = tokenize(message, CRLF, 0);
        if(message_tokens.first.empty() == false && parse_start_line(message_tokens.first) == false)
        {
            return false;
        }
        message_tokens = tokenize(message, CRLF + CRLF,message_tokens.second);
        if(message_tokens.first.empty() == false && parse_header_fields(message_tokens.first) == false)
        {
            return false;
            
        }
        if(message_tokens.first.empty() == false){
            message_tokens.first = message.substr(message_tokens.second, message.length()-1);
            if(message_tokens.first.empty() == false && parse_body(message_tokens.first) == false)
            {
                return false;
            }
        }
        return true;
    }

    bool Message::ends_with(const std::string &main_str, const std::string &to_match)
    {
       return (main_str.size() >= to_match.size() &&
            main_str.compare(main_str.size() - to_match.size(), to_match.size(), to_match) == 0);
    }

}//namespace HTTP