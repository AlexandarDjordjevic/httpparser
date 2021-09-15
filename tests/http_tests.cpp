#include <gtest/gtest.h>
#include <HTTP/Request.h>

TEST(HTTPParser, RequestURI_invalid3){
    HTTP::Request parser;
    std::string test_http_request= "GET /pub/WWW/TheProject.html HTTP/1.1";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_FALSE(result);
}
