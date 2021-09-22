/**
 * @author krrle
 * @brief 
 * @m_version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <URI/Uri.h>

namespace HTTP
{   

/**
    * @brief Enumeration for HTTP methods
    * 
    */
enum class Method{
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
    HTTP20 = 3,
};
 /**
     * @brief Enumeration for Request-Header
     * 
     */
enum class Request_Header{
    Accept,
    AcceptCharset,
    AcceptEncoding,
    AcceptLanguage,
    Authorization,
    Except,
    From,
    Host,
    IfMatch,
    IfModifiedSince,
    IfNoneMatch,
    IfRange,
    IfUnmodifiedSince,
    MaxForwards,
    ProxyAuthorization,
    Range,
    Referer,
    TE,
    UserAgent
};

struct Header_Field{

    Request_Header field;
    std::string f_value;
};
/**
     * @brief Maping string with enumeration Request-Header
     * 
     */
static std::map<std::string, Request_Header> const header_table ={
    {"Accept:",              Request_Header::Accept              },
    {"Accept-Charset:",      Request_Header::AcceptCharset       },
    {"Accept-Encoding:",     Request_Header::AcceptEncoding      },
    {"Accept-Language:",     Request_Header::AcceptLanguage      },
    {"Authorization:",       Request_Header::Authorization       },
    {"Except:",              Request_Header::Except              },
    {"From:",                Request_Header::From                },
    {"Host:",                Request_Header::Host                },
    {"If-Match:",            Request_Header::IfMatch             },
    {"If-Modified-Since:",   Request_Header::IfModifiedSince     },
    {"If-None-Match:",       Request_Header::IfNoneMatch         },
    {"If-Range:",            Request_Header::IfRange             },
    {"If-Unmodified-Since:", Request_Header::IfUnmodifiedSince   },
    {"Max-Forwards:",        Request_Header::MaxForwards         },
    {"Proxy-Authorization:", Request_Header::ProxyAuthorization  },
    {"Range:",               Request_Header::Range               },
    {"Referer:",             Request_Header::Referer             },
    {"TE:",                  Request_Header::TE                  },
    {"User-Agent:",          Request_Header::UserAgent           }
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
        * @brief Parsing request line, if request line is valid returns true, otherwise returns false
        * 
        * @param request_line 
        * @return true 
        * @return false 
        */
    bool parse_request_line(const std::string& request_line);
    
private:

    /**
        * @brief String tokenize
        * 
        * @param s 
        * @return std::pair<std::string, std::string> 
        */
    std::pair<std::string, std::string> tokenize(const std::string& s, const std::string& delimeter);

    /**
     * @brief validating Request_Header
     * 
     * @param header 
     * @return true 
     * @return false 
     */
    bool validate_header(const std::string& header);

    /**
        * @brief Validating Http request Method
        * 
        * @param method 
        * @return true 
        * @return false 
        */
    bool validate_method(const std::string& method);

    /**
        * @brief Validating Uri using function from_string() from Uri.h
        * 
        * @param uri 
        * @return bool
        */
    bool validate_uri(const std::string& uri);

    /**
        * @brief Validating Http version
        * 
        * @param version 
        * @return true 
        * @return false 
        */
    bool validate_version(const std::string& version);

    /**
        * @brief Checking if "main_string" ends with "to_match" string
        * 
        * @param main_str 
        * @param to_match 
        * @return true 
        * @return false 
        */
    bool ends_with(const std::string &main_str, const std::string &to_match);

    /**
     * @brief Accepts whole header from request and parses header_fields, stores each header_field in vector<Header_Field> m_header 
     * if each header fild is valid, returns true, otherwise returns false
     * 
     * @param header 
     * @return true 
     * @return false 
     */
    bool parse_header_filds(const std::string& header);

private:

    /**
    * @brief Defining CRLF
    * 
    */
    const std::string CRLF = "\r\n";

    /**
        * @brief empty const string 
        * 
        */
    const std::string empty_string{""};

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
        * @brief HTTP method atribute
        * 
        */
    Method m_method;

    /**
        * @brief HTTP uri atribute
        * 
        */
    URI::Uri m_uri;

    /**
        * @brief HTTP version atribute
        * 
        */
    Version m_version;

    /**
        * @brief Represent header that is constucted of header fields 
        * 
        */
    std::vector<Header_Field> m_header;
};

}//namespace Namespace


