/**
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
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
namespace HTTP
{
    std::vector<std::string> splitString(const std::string& s , std::string rgx_str = "\\s+");
    class HTTPRequest{
    private:
    
    public:
        /**
         * @brief Default constructor
         * 
         */
        HTTPRequest();

        /**
         * @brief Default destructor
         * 
         */
        ~HTTPRequest();

        HTTPRequest(const HTTPRequest&) = delete;
        HTTPRequest& operator=(const HTTPRequest&) = delete;
        HTTPRequest(HTTPRequest&&) = delete;
        HTTPRequest& operator=(HTTPRequest &&) = delete;

        bool validateRequestStartLine(const std::string& message);
        bool validateURI(std::string& message);
        bool validateVersion(std::string& ver_token);

        
       
    private:
        bool endsWith(const std::string &mainStr, const std::string &toMatch);
        
    
    private:
        const std::string CRLF = "\r\n";
        std::string request_method;
        std::string request_uri;
        std::string request_version;
        std::map<std::string , std::string> request_header_filds;
    };



}//namespace Namespace


