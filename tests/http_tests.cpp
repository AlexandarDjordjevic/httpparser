#include <gtest/gtest.h>
#include <HTTP/Request.h>

TEST(HTTPParser, get_request_with_abs_path){
    HTTP::Request parser;
    std::string test_http_request= "GET /pub/WWW/TheProject.html HTTP/1.1\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_uri){
    HTTP::Request parser;
    std::string test_http_request= "GET https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.1\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, invalid_get_request){
    HTTP::Request parser;
    std::string test_http_request= "GET HTTP/1.1";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_FALSE(result);
};
