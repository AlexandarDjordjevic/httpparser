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

TEST(HTTPParser, get_request_with_abs_path_http09){
    HTTP::Request parser;
    std::string test_http_request= "GET /pub/WWW/TheProject.html HTTP/0.9\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_uri_http20){
    HTTP::Request parser;
    std::string test_http_request= "GET https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/2.0\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_path_http20){
    HTTP::Request parser;
    std::string test_http_request= "GET /pub/WWW/TheProject.html HTTP/2.0\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_uri_http09){
    HTTP::Request parser;
    std::string test_http_request= "GET https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/0.9\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_path_http10){
    HTTP::Request parser;
    std::string test_http_request= "GET /pub/WWW/TheProject.html HTTP/1.0\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_uri_http10){
    HTTP::Request parser;
    std::string test_http_request= "GET https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.0\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_uri_invalid_version){
    HTTP::Request parser;
    std::string test_http_request= "GET https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.2\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, get_request_with_abs_path_invalid_version){
    HTTP::Request parser;
    std::string test_http_request= "GET /pub/WWW/TheProject.html HTTP/2.1\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, post_request_with_abs_path){
    HTTP::Request parser;
    std::string test_http_request= "POST /pub/WWW/TheProject.html HTTP/1.1\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, put_request_with_abs_uri){
    HTTP::Request parser;
    std::string test_http_request= "PUT https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.1\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, delete_get_request){
    HTTP::Request parser;
    std::string test_http_request= "DELETE HTTP/1.0";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, options_request_with_abs_path_http09){
    HTTP::Request parser;
    std::string test_http_request= "OPTIONS /pub/WWW/TheProject.html HTTP/0.9\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, options_request_asterisk_uri){
    HTTP::Request parser;
    std::string test_http_request= "OPTIONS * HTTP/1.1\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, put_request_with_abs_uri_http20){
    HTTP::Request parser;
    std::string test_http_request= "PUT https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/2.0\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, post_request_with_abs_path_http20){
    HTTP::Request parser;
    std::string test_http_request= "POST /pub/WWW/TheProject.html HTTP/2.0\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, put_request_with_abs_uri_http09){
    HTTP::Request parser;
    std::string test_http_request= "PUT https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/0.9\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, fetch_request_with_abs_path_http10){
    HTTP::Request parser;
    std::string test_http_request= "PATCH /pub/WWW/TheProject.html HTTP/1.0\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, fetch_request_with_abs_uri_http10){
    HTTP::Request parser;
    std::string test_http_request= "PATCH https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.0\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, put_request_with_abs_uri_invalid_version){
    HTTP::Request parser;
    std::string test_http_request= "PUT https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.2\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, put_request_with_abs_path_invalid_version){
    HTTP::Request parser;
    std::string test_http_request= "PUT /pub/WWW/TheProject.html HTTP/2.1\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, post_request_with_header){
    HTTP::Request parser;
    std::string test_http_request= "POST /test/demo_form.php HTTP/1.1\r\nHost: w3schools.com\r\n\r\n";
    auto result = parser.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_header){
    HTTP::Request parser;
    std::string test_http_request= "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1\r\nHost: guru99.com\nUser-Agent: Mozilla/5.0\nAccept-Encoding: gzip, deflate\nAccept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = parser.from_string(test_http_request);
    auto k = parser.get_field_value("Host");
    ASSERT_EQ(k,"guru99.com" );
};

TEST(HTTPParser, get_request_with_header_agent){
    HTTP::Request parser;
    std::string test_http_request= "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1\r\nHost: guru99.com\nUser-Agent: Mozilla/5.0\nAccept-Encoding: gzip, deflate\nAccept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = parser.from_string(test_http_request);
    auto k = parser.get_field_value("User-Agent");
    ASSERT_EQ(k,"Mozilla/5.0" );
};

TEST(HTTPParser, get_request_with_header_full){
    HTTP::Request parser;
    std::string test_http_request= "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1\r\nHost: guru99.com\nUser-Agent: Mozilla/5.0\nAccept-Encoding: gzip, deflate\nAccept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = parser.parse_request_line(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, parse_request_full){
    HTTP::Request parser;
    std::string test_http_request= "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1\r\nHost: guru99.com\nUser-Agent: Mozilla/5.0\nAccept-Encoding: gzip, deflate\nAccept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = parser.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, parse_request_full_invalid_wrong_version){
    HTTP::Request parser;
    std::string test_http_request= "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.4\r\nHost: guru99.com\nUser-Agent: Mozilla/5.0\nAccept-Encoding: gzip, deflate\nAccept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = parser.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, parse_request_invalid_no_crlf){
    HTTP::Request parser;
    std::string test_http_request= "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1 Host: guru99.com\nUser-Agent: Mozilla/5.0\nAccept-Encoding: gzip, deflate\nAccept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = parser.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, parse_request_invalid_no_crlfx2){
    HTTP::Request parser;
    std::string test_http_request= "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1 Host: guru99.com\nUser-Agent: Mozilla/5.0\nAccept-Encoding: gzip, deflate\nAccept-Cherset: ISO-8859-1, utf-8\r\n";
    auto result = parser.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, parse_body_full){
    HTTP::Request parser;
    std::string test_http_request= "POST /test HTTP/1.1\r\nHost: foo.example\nContent-Type: application/x-www-form-urlencoded\nContent-Length: 27\r\n\r\nfield1=value1&field2=value2";
    auto result = parser.from_string(test_http_request);
    std::size_t body_len = parser.get_body_length();
    ASSERT_EQ(body_len, 27);
};
