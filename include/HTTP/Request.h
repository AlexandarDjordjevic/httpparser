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

namespace HTTP
{
    std::vector<std::string> splitString(const std::string& s , std::string rgx_str = "\\s+");
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

    class Request{
    private:
    
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

        bool parseStartLine(const std::string& message);
        bool validateMethod(const std::string& message);
        bool validateURI(std::string& message);
        bool validateVersion(std::string& version);

        Method getMethod();
       
    private:
        bool endsWith(const std::string &mainStr, const std::string &toMatch);
    private:
        const std::string CRLF = "\r\n";
        Method m_method;
        std::string m_uri;
        std::string m_version;
    };



}//namespace Namespace


