#include <gtest/gtest.h>
#include <HTTP/Request.h>

TEST(first_test, dummy_test){
    ASSERT_FALSE(false);
};
TEST(HTTPParser, RequestURI_valid){
    HTTP::Request parser;
    std::string pom = "*";
    auto result= parser.validateURI(pom);
    ASSERT_TRUE(result);
}
TEST(HTTPParser, RequestURI_invalid){
    HTTP::Request parser;
    std::string pom = "";
    auto result= parser.validateURI(pom);// nije http nego htp
    ASSERT_FALSE(result);
}

TEST(HTTPParser, RequestURI_valid2){
    HTTP::Request parser;
    std::string pom = "http://www.w3.org/pub/WWW/TheProject.html";
    auto result= parser.validateURI(pom);// jedna kosa crta
    ASSERT_TRUE(result);
}
TEST(HTTPParser, RequestURI_invalid2){
    HTTP::Request parser;
    std::string pom = "http:/www.w3.org/pub/WWW/TheProject.html";
    auto result= parser.validateURI(pom);// jedna kosa crta
    ASSERT_FALSE(result);
}


TEST(HTTPParser, RequestURI_invalid3){
    HTTP::Request parser;
    std::string pom = "pub/WWW/TheProject.html HTTP/1.1";
    auto result= parser.validateURI(pom);// pocinje sa Host
    ASSERT_FALSE(result);
}

TEST(HTTPParser, RequestURI_valid3){
    HTTP::Request parser;
    std::string pom = "/pub/WWW/TheProject.html";
    auto result= parser.validateURI(pom);// pocinje sa Host
    ASSERT_TRUE(result);
}

TEST(HTTPParser, validateVersion_valid){
    HTTP::Request parser;
    std::string pom = "HTTP/1.1";
    auto result= parser.validateVersion(pom);
    ASSERT_TRUE(result);
}

TEST(HTTPParser, splitString_valid){
    const std::vector<std::string> expected_result = { "GET" ,"/pub/WWW/TheProject.html", "HTTP/1.1"};
    auto result= HTTP::splitString("GET /pub/WWW/TheProject.html HTTP/1.1\r\n");// pocinje sa Host
    ASSERT_EQ(expected_result,result);
}

TEST(HTTPParser, validateRequestStartLine_valid){
    HTTP::Request parser;
    std::string pom = "";
    auto result= parser.validateRequestStartLine("GET /pub/WWW/TheProject.html HTTP/1.1\r\n");// pocinje sa Host
    ASSERT_TRUE(result);
}

TEST(HTTPParser, validateRequestStartLine_ivalid){
    HTTP::Request parser;
    std::string pom = "";
    auto result= parser.validateRequestStartLine("GT /pub/WWW/TheProject.html HTTP/1.1\r\n");//los metod
    ASSERT_FALSE(result);
}

TEST(HTTPParser, validateRequestStartLine_ivalid2){
    HTTP::Request parser;
    std::string pom = "";
    auto result= parser.validateRequestStartLine("GET /pub/WWW/TheProject.html HTTP/1.1");//nema CRLF
    ASSERT_FALSE(result);
}
TEST(HTTPParser, validateMethod_valid){
    HTTP::Request parser;
    std::string pom = "";
    auto result= parser.validateMethod("GET");//nema CRLF
    ASSERT_EQ(HTTP::Method::GET,parser.getMethod());
}
TEST(HTTPParser, validateMethod_valid2){
    HTTP::Request parser;
    std::string pom = "";
    auto result= parser.validateMethod("PUT");//nema CRLF
    ASSERT_EQ(HTTP::Method::PUT,parser.getMethod());
}