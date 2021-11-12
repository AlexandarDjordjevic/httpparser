/**
 * @author krrle
 * @brief 
 * @m_version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <URI/Uri.h>
#include "Message.h"
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

    class Request : public Message {
      
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
         * @brief Get the request method 
         * 
         * @return Method 
         */
        Method get_method() const;

        /**
         * @brief Get the uri type 
         * 
         * @return std::string 
         */
        std::string get_uri_type() const;

    private:
        
        /**
         * @brief Parsing request line
         * 
         * @param request_line 
         * @return true if request line is valid, otherwise returns false
         */
        bool parse_start_line(const std::string& request_line);

        /**
         * @brief Maping enum Uri_type to string 
         * 
         * @return const std::string 
         */
        const std::string uri_type_to_stirng() const;

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
         * @brief Parsing and validating request uri if it represents an absolute uri
         * 
         * @param uri 
         * @return true if uri is absolute, otherwise returns false
         */
        bool parse_absolute_uri(const std::string& uri);

        /**
         * @brief Parsing and validating request uri if it represents an absolute path 
         * 
         * @param uri 
         * @return true if path is absolute, otherwise returns false
         */
        bool parse_absolute_path(const std::string& uri);

        /**
         * @brief Parsing and validating request uri if it represents an authority part of an uri 
         * 
         * @param uri 
         * @return true if uri has only authority, otherwise returns false 
         */
        bool parse_authority_uri(const std::string& uri);
        
        /**
         * @brief Parsing and validating request uri if it is an asterisk
         * 
         * @param uri 
         * @return true if uri is aterisk, otherwise returns false
         */
        bool parse_aterisk_uri(const std::string& uri);

    private:

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
            asterisk, 
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
         * @brief HTTP method attribute
         * 
         */
        Method m_method;

    };


}//namespace Namespace


