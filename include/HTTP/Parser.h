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

namespace HTTP
{
    class Parser{
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

    private:
    };



}//namespace Namespace


