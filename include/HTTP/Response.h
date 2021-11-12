/**
 * @brief 
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include "Message.h"

namespace HTTP
{
    class Response : public Message{
    public:
        /**
         * @brief Default constructor
         * 
         */
        Response();

        /**
         * @brief Default destructor
         * 
         */
        ~Response();

        Response(const Response&) = delete;
        Response& operator=(const Response&) = delete;
        Response(Response&&) = delete;
        Response& operator=(Response &&) = delete;

        /**
         * @brief Get the status code of response
         * 
         * @return short 
         */
        short get_status_code() const;

        /**
         * @brief Get the reason phrase for status code 
         * 
         * @return std::string 
         */
        std::string get_reason_phrase() const;
        
    private:

        /**
         * @brief Validating Http version
         * 
         * @param status_code 
         * @return true if status_code is valid, otherwise returns false
         */
        bool parse_status_code(const std::string& status_code);

        /**
         * @brief Parsing status line
         * 
         * @param status_line 
         * @return true if status line is valid, otherwise returns false
         */
        bool parse_start_line(const std::string& status_line);

    private:

        /**
         * @brief Keeps status code from response
         * 
         */
        short m_status_code;

        /**
         * @brief Reason for status code 
         * 
         */
        std::string m_reason_phrase;

    };

} // namespace HTTP
