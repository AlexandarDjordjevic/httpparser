/**
 * @author your name (you@domain.com)
 * @brief 
 * @m_version 0.1
 * @date 2021-08-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <regex>
#include <../../Uri/include/URI/Uri.h>

namespace HTTP
{   
    /**
     * @brief Spliting string in pieces
     * 
     * @param s 
     * @param rgx_str 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> splitString(const std::string& s , std::string rgx_str = "\\s+");

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
        // HTTP/0.9 = 0,
        // HTTP/1.0 = 1,
        // HTTP/1.1 = 2,
        // HTTP/2.0 = 3,
        
    };
     
    /**
     * @brief Enumeration for Request-Header
     * 
     */
    enum class Request_Header{
    //     Accept,
    //     AcceptCharset,
    //     Accept-Encoding,
    //     Accept-Language,
    //     Authorization,
    //     Except,
    //     From,
    //     Host,
    //     If-Match,
    //     If-Modified-Since,
    //     If-None-Match,
    //     If-Range,
    //     If-Unmodified-Since,
    //     Max-Forwards,
    //     Proxy-Authorization,
    //     Range,
    //     Referer,
    //     TE,
    //     User-Agent
    };

    /**
     * @brief Maping string with enumeration HTTP method
     * 
     */
    static std::map<std::string,Method> const table = { 
        {"GET",Method::GET}, 
        {"HEAD",Method::HEAD},
        {"POST",Method::POST}, 
        {"PUT",Method::PUT}, 
        {"DELETE",Method::DELETE}, 
        {"CONNECT",Method::CONNECT},
        {"OPTIONS",Method::OPTIONS},
        {"TRACE",Method::TRACE},
        {"PATCH",Method::PATCH},
        {"COUNT",Method::COUNT}
    };

    /**
     * @brief Maping HTTP versions
     * 
     */
    static std::map<std::string, int> const tableVersions = {
        {"HTTP/0.9", 0},
        {"HTTP/1.0", 1},
        {"HTTP/1.1", 2},
        {"HTTP/2.0", 3}
    };

    class Request{
    private:

        /**
         * @brief HTTP method atribute
         * 
         */
        Method m_method;

        /**
         * @brief HTTP uri atribute
         * 
         */
        std::string m_uri;

        /**
         * @brief HTTP version atribute
         * 
         */
        Version m_version;

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
         * @brief Parsing start Line
         * 
         * @param message 
         * @return true 
         * @return false 
         */
        bool parseStartLine(const std::string& message);

        /**
         * @brief Validating Http Method
         * 
         * @param message 
         * @return Method 
         */
        Method validateMethod(const std::string& message);

        /**
         * @brief Validating Uri using function FromString() from URI.h
         * 
         * @param message 
         * @return std::string 
         */
        std::string validateURI(const std::string& message);

        /**
         * @brief Validating Http version
         * 
         * @param message 
         * @return std::string 
         */
        Version validateVersion(const std::string& message);

        /**
         * @brief Mathcing "mainStr" to "toMatch" string and telling if main string ends with "toMatch" string
         * 
         * @param mainStr 
         * @param toMatch 
         * @return true 
         * @return false 
         */
        bool endsWith(const std::string &mainStr, const std::string &toMatch);

    private:

        /**
        * @brief Get the Method object
        * 
        * @return Method 
        */
        Method getMethod();

        /**
         * @brief Get the Version object
         * 
         * @return std::string 
         */
        std::string getVersion();

        /**
         * @brief Get the Uri object
         * 
         * @return std::string 
         */
        std::string getUri();


    private:

        /**
        * @brief Defining CRLF
        * 
        */
        const std::string CRLF = "\r\n";
    };



}//namespace Namespace


