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

namespace HTTP
{
    class Parser{
    private:
    const std::string CRLF = "\r\n";
    public:
        /**
         * @brief Default constructor
         * 
         */
        Parser();

        /**
         * @brief Default destructor
         * 
         */
        ~Parser();

        Parser(const Parser&) = delete;
        Parser& operator=(const Parser&) = delete;
        Parser(Parser&&) = delete;
        Parser& operator=(Parser &&) = delete;

        bool validateRequestStartLine(const std::string& message);

        bool endsWith(const std::string &mainStr, const std::string &toMatch);
        bool validateURI(std::string& message);
        bool validateVersion(std::string& ver_token);
       
    private:
    };



}//namespace Namespace


