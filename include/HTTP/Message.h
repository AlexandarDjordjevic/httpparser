/**
 * @brief 
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <utility>
#include <map>
#include <regex>
#include <vector>

namespace HTTP
{   
    /**
     * @brief Enumeration for HTTP versions
     * 
     */
    enum class Version {
        HTTP09 = 0,
        HTTP10 = 1,
        HTTP11 = 2,
        HTTP20 = 3
    };

     /**
     * @brief Maping string with enumeration HTTP-versions
     * 
     */
    const std::map<std::string, Version> table_versions = {
        { "HTTP/0.9", Version::HTTP09 },
        { "HTTP/1.0", Version::HTTP10 },
        { "HTTP/1.1", Version::HTTP11 },
        { "HTTP/2.0", Version::HTTP20 }
    };
  
    /**
     * @brief Structure for HTTP body
     * 
     */
    struct Body{
        std::string type;
        std::size_t length;
        std::string data;
    };



    class Message{
    public:
        /**
         * @brief Default constructor
         * 
         */
        Message();

        /**
         * @brief Default destructor
         * 
         */
        ~Message();

        Message(const Message&) = delete;
        Message& operator=(const Message&) = delete;
        Message(Message&&) = delete;
        Message& operator=(Message &&) = delete;

        /**
         * @brief Get the version of HTTP
         * 
         * @return Version 
         */
        Version get_version() const;

        /**
         * @brief Get the header field value which key word is key
         * 
         * @param key 
         * @return std::string 
         */
        std::string get_header_field_value(const std::string& key) const;
       
        /**
         * @brief Get the body type 
         * 
         * @param body 
         * @return std::string 
         */
        std::string get_body_type() const;

        /**
         * @brief Get the body lenght 
         * 
         * @param body 
         * @return std::string 
         */
        std::size_t get_body_length() const;

        /**
         * @brief Get the body data 
         * 
         * @param body 
         * @return std::string 
         */
        std::string get_body_data() const;

        /**
         * @brief Parsin message into its components and validatin each of them
         * 
         * @param message
         * @return true if message is valid otherwise returns false
         */
        bool from_string(const std::string& message);

protected:

        /**
         * @brief Parsing status line of http messag
         * 
         * @param status_line 
         * @return true if status line is valid, otherwise returns false
         */
        virtual bool parse_start_line(const std::string& status_line) = 0;

        /**
         * @brief Validating Http version
         * 
         * @param version 
         * @return true if version is valid, otherwise returns false
         */
        bool validate_version(const std::string& version);

        /**
         * @brief Accepts whole header from request and parses header_fields, stores each header_field in vector<Header_field> m_headers
         * 
         * @param header 
         * @return true 
         */
        bool parse_header_fields(const std::string& header);

        /**
         * @brief 
         * 
         * @param body 
         * @return true if body is valid, otherwise returns false
         */
        bool parse_body(const std::string& body);

        /**
         * @brief A sequence of calls to this function split text into tokens, which are strings separated by delimiter string
         * 
         * @param text 
         * @param delimeter 
         * @param position this is position from witch we search delimeter 
         * @return std::pair<std::string, std::size_t> first is substring from position to delimeter, second is one position after delimeter 
         */
        std::pair<std::string, std::size_t> tokenize(const std::string& text, const std::string& delimeter, std::size_t position);

        /**
         * @brief Checking if "main_string" ends with "to_match" string
         * 
         * @param main_str 
         * @param to_match 
         * @return true if main_stirng ends with to_match otherwise returns false
         */
        bool ends_with(const std::string &main_str, const std::string &to_match);

    protected:

        /**
         * @brief Defining CRLF
         * 
         */
        const std::string CRLF = "\r\n";
         
        /**
         * @brief HTTP version attribute
         * 
         */
        Version m_version;
        
        /**
         * @brief Map for header fields, first element is name of field, second is value 
         * 
         */
        std::map<std::string, std::string> m_header;

        /**
         * @brief Request body attribute
         * 
         */
        Body m_body;

    

    };

} // namespace HTTP
