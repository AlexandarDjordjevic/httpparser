/**
 * @author krrle
 * @brief 
 * @m_version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <utility>
#include <map>
#include <regex>
#include <URI/Uri.h>

namespace HTTP
{   

    /**
     * @brief Enumeration for HTTP methods
     * 
     */
    enum class Method {
        GET = 0,
        HEAD = 1,
        POST = 2, 
        PUT = 3, 
        DELETE = 4, 
        CONNECT = 5, 
        OPTIONS = 6, 
        TRACE = 7, 
        PATCH = 8,
        COUNT = 9
    };

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
     * @brief Maping string with enumeration HTTP method
     * 
     */
    const std::map<std::string, Method> table = { 
        { "GET",     Method::GET     }, 
        { "HEAD",    Method::HEAD    },
        { "POST",    Method::POST    }, 
        { "PUT",     Method::PUT     }, 
        { "DELETE",  Method::DELETE  }, 
        { "CONNECT", Method::CONNECT },
        { "OPTIONS", Method::OPTIONS },
        { "TRACE",   Method::TRACE   },
        { "PATCH",   Method::PATCH   },
        { "COUNT",   Method::COUNT   }
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

    class Request{

    public:

        /**
         * @brief Default constructor
         * 
         */
        Request();

        /**
         * @brief Default destructor
         * 
         */
        ~Request();

        Request(const Request&) = delete;
        Request& operator=(const Request&) = delete;
        Request(Request&&) = delete;
        Request& operator=(Request &&) = delete;

        /**
         * @brief Get the Method object
         * 
         * @return Method 
         */
        Method get_method();

        /**
         * @brief Get the version object
         * 
         * @return Version 
         */
        Version get_version();

        /**
         * @brief Get the uri type 
         * 
         * @return std::string 
         */
        std::string get_uri_type();

        /**
         * @brief Parsing request line
         * 
         * @param request_line 
         * @return true if request line is valid, otherwise returns false
         */
        bool parse_request_line(const std::string& request_line);

    private:

        /**
         * @brief Maping enum Uri_type to string 
         * 
         * @return const std::string 
         */
        const std::string uri_type_to_stirng();
        
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
         * @brief Validating Http request Method
         * 
         * @param method 
         * @return true if method is valid, otherwise returns false
         */
        bool validate_method(const std::string& method);

        /**
         * @brief Validating Uri 
         * 
         * @param uri 
         * @return true if uri is valid, otherwise returns false
         */
        bool validate_uri(const std::string& uri);

        /**
         * @brief Checks if uri of request is an absolute uri
         * 
         * @param uri 
         * @return true if uri is absolute, otherwise returns false
         */
        bool validate_absolute_uri(const std::string& uri);

        /**
         * @brief Checks if uri of request is an absolute path
         * 
         * @param uri 
         * @return true if path is absolute, otherwise returns false
         */
        bool validate_absolute_path(const std::string& uri);

        /**
         * @brief Checks if uri of request is just authority part of an uri 
         * 
         * @param uri 
         * @return true if uri has only authority, otherwise returns false 
         */
        bool validate_authority_uri(const std::string& uri);
        
        /**
         * @brief Validate conditions of asterisk uri 
         * 
         * @param uri 
         * @return true if uri is aterisk, otherwise returns false
         */
        bool validate_aterisk_uri(const std::string& uri);

        /**
         * @brief Validating Http version
         * 
         * @param version 
         * @return true if version is valid, otherwise returns false
         */
        bool validate_version(const std::string& version);

        /**
         * @brief Checking if "main_string" ends with "to_match" string
         * 
         * @param main_str 
         * @param to_match 
         * @return true if main_stirng ends with to_match otherwise returns false
         */
        bool ends_with(const std::string &main_str, const std::string &to_match);

    private:

        /**
         * @brief Defining CRLF
         * 
         */
        const std::string CRLF = "\r\n";

        /**
         * @brief asterisk const string for checking scheme of uri
         * 
         */
        const std::string asterisk {"*"};

        /**
         * @brief http const string for checking scheme of uri
         * 
         */
        const std::string http{"http"};

        /**
         * @brief https const string for checking scheme of uri
         * 
         */
        const std::string https{"https"};

        /**
         * @brief Enum for request uri type 
         * 
         */
        enum class Uri_type{
            asterisk , 
            absolute_uri,
            absolute_path,
            authority
        };

        /**
         * @brief Struct that supports different types of uri 
         * 
         */
        struct Request_uri
        {
            Uri_type type;
            URI::Uri uri_obj;
            std::string uri_str;
        };

        /**
         * @brief Struct that represents different types of uri in requests
         * 
         */
        Request_uri m_uri; 

        /**
         * @brief HTTP method atribute
         * 
         */
        Method m_method;
        
        /**
         * @brief HTTP version atribute
         * 
         */
        Version m_version;

    };

}//namespace Namespace


