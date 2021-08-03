#include <gtest/gtest.h>
#include <HTTP/Parser.h>

TEST(first_test, dummy_test){
    ASSERT_FALSE(false);
};
TEST(HTTPParser, RequestURI_valid){
    HTTP::Parser parser;
    std::string pom = "*";
    auto result= parser.validateURI(pom);
    ASSERT_TRUE(result);
}
TEST(HTTPParser, RequestURI_invalid){
    HTTP::Parser parser;
    std::string pom = "";
    auto result= parser.validateURI(pom);// nije http nego htp
    ASSERT_FALSE(result);
}

TEST(HTTPParser, RequestURI_valid2){
    HTTP::Parser parser;
    std::string pom = "http://www.w3.org/pub/WWW/TheProject.html";
    auto result= parser.validateURI(pom);// jedna kosa crta
    ASSERT_TRUE(result);
}
TEST(HTTPParser, RequestURI_invalid2){
    HTTP::Parser parser;
    std::string pom = "http:/www.w3.org/pub/WWW/TheProject.html";
    auto result= parser.validateURI(pom);// jedna kosa crta
    ASSERT_FALSE(result);
}


TEST(HTTPParser, RequestURI_invalid3){
    HTTP::Parser parser;
    std::string pom = "pub/WWW/TheProject.html HTTP/1.1";
    auto result= parser.validateURI(pom);// pocinje sa Host
    ASSERT_FALSE(result);
}

TEST(HTTPParser, RequestURI_valid3){
    HTTP::Parser parser;
    std::string pom = "/pub/WWW/TheProject.html";
    auto result= parser.validateURI(pom);// pocinje sa Host
    ASSERT_TRUE(result);
}

TEST(HTTPParser, validateVersion_valid){
    HTTP::Parser parser;
    std::string pom = "HTTP/1.1";
    auto result= parser.validateVersion(pom);
    ASSERT_TRUE(result);
}

TEST(HTTPParser, validateRequestStartLine_valid){
    HTTP::Parser parser;
    std::string pom = "";
    auto result= parser.validateRequestStartLine("GET /pub/WWW/TheProject.html HTTP/1.1\r\n");// pocinje sa Host
    ASSERT_TRUE(result);
}

TEST(HTTPParser, validateRequestStartLine_ivalid){
    HTTP::Parser parser;
    std::string pom = "";
    auto result= parser.validateRequestStartLine("GT /pub/WWW/TheProject.html HTTP/1.1\r\n");//los metod
    ASSERT_FALSE(result);
}

TEST(HTTPParser, validateRequestStartLine_ivalid2){
    HTTP::Parser parser;
    std::string pom = "";
    auto result= parser.validateRequestStartLine("GET /pub/WWW/TheProject.html HTTP/1.1");//nema CRLF
    ASSERT_FALSE(result);
}