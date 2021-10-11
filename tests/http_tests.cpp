#include <gtest/gtest.h>
#include <HTTP/Request.h>
#include <HTTP/Response.h>

TEST(HTTPParser, get_request_with_abs_path){
    HTTP::Request request;
    std::string test_http_request = "GET /pub/WWW/TheProject.html HTTP/1.1\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_uri){
    HTTP::Request request;
    std::string test_http_request = "GET https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.1\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, invalid_get_request){
    HTTP::Request request;
    std::string test_http_request = "GET HTTP/1.1";
    auto result = request.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, get_request_with_abs_path_http09){
    HTTP::Request request;
    std::string test_http_request = "GET /pub/WWW/TheProject.html HTTP/0.9\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_uri_http20){
    HTTP::Request request;
    std::string test_http_request = "GET https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/2.0\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_path_http20){
    HTTP::Request request;
    std::string test_http_request = "GET /pub/WWW/TheProject.html HTTP/2.0\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_uri_http09){
    HTTP::Request request;
    std::string test_http_request = "GET https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/0.9\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_path_http10){
    HTTP::Request request;
    std::string test_http_request = "GET /pub/WWW/TheProject.html HTTP/1.0\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_uri_http10){
    HTTP::Request request;
    std::string test_http_request = "GET https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.0\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_abs_uri_invalid_version){
    HTTP::Request request;
    std::string test_http_request = "GET https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.2\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, get_request_with_abs_path_invalid_version){
    HTTP::Request request;
    std::string test_http_request = "GET /pub/WWW/TheProject.html HTTP/2.1\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, post_request_with_abs_path){
    HTTP::Request request;
    std::string test_http_request = "POST /pub/WWW/TheProject.html HTTP/1.1\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, put_request_with_abs_uri){
    HTTP::Request request;
    std::string test_http_request = "PUT https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.1\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, delete_get_request){
    HTTP::Request request;
    std::string test_http_request = "DELETE HTTP/1.0";
    auto result = request.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, options_request_with_abs_path_http09){
    HTTP::Request request;
    std::string test_http_request = "OPTIONS /pub/WWW/TheProject.html HTTP/0.9\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, options_request_asterisk_uri){
    HTTP::Request request;
    std::string test_http_request = "OPTIONS * HTTP/1.1\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, put_request_with_abs_uri_http20){
    HTTP::Request request;
    std::string test_http_request = "PUT https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/2.0\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, post_request_with_abs_path_http20){
    HTTP::Request request;
    std::string test_http_request = "POST /pub/WWW/TheProject.html HTTP/2.0\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, put_request_with_abs_uri_http09){
    HTTP::Request request;
    std::string test_http_request= "PUT https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/0.9\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, fetch_request_with_abs_path_http10){
    HTTP::Request request;
    std::string test_http_request = "PATCH /pub/WWW/TheProject.html HTTP/1.0\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, fetch_request_with_abs_uri_http10){
    HTTP::Request request;
    std::string test_http_request = "PATCH https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.0\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, put_request_with_abs_uri_invalid_version){
    HTTP::Request request;
    std::string test_http_request = "PUT https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc HTTP/1.2\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, put_request_with_abs_path_invalid_version){
    HTTP::Request request;
    std::string test_http_request = "PUT /pub/WWW/TheProject.html HTTP/2.1\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, post_request_with_header){
    HTTP::Request request;
    std::string test_http_request = "POST /test/demo_form.php HTTP/1.1\r\n"
                                    "Host: w3schools.com\r\n\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, get_request_with_header){
    HTTP::Request request;
    std::string test_http_request = "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1\r\n"
                                    "Host: guru99.com\n"
                                    "User-Agent: Mozilla/5.0\n"
                                    "Accept-Encoding: gzip, deflate\n"
                                    "Accept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = request.from_string(test_http_request);
    auto k = request.get_header_field_value("Host");
    ASSERT_EQ(k,"guru99.com" );
};

TEST(HTTPParser, get_request_with_header_agent){
    HTTP::Request request;
    std::string test_http_request= "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1\r\nHost: guru99.com\nUser-Agent: Mozilla/5.0\nAccept-Encoding: gzip, deflate\nAccept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = request.from_string(test_http_request);
    auto k = request.get_header_field_value("User-Agent");
    ASSERT_EQ(k,"Mozilla/5.0" );
};

TEST(HTTPParser, get_request_with_header_full){
    HTTP::Request request;
    std::string test_http_request = "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1\r\n"
                                    "Host: guru99.com\n"
                                    "User-Agent: Mozilla/5.0\n"
                                    "Accept-Encoding: gzip, deflate\n"
                                    "Accept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, parse_request_full){
    HTTP::Request request;
    std::string test_http_request = "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1\r\n"
                                    "Host: guru99.com\n"
                                    "User-Agent: Mozilla/5.0\n"
                                    "Accept-Encoding: gzip, deflate\n"
                                    "Accept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_TRUE(result);
};

TEST(HTTPParser, parse_request_full_invalid_wrong_version){
    HTTP::Request request;
    std::string test_http_request = "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.4\r\n"
                                    "Host: guru99.com\n"
                                    "User-Agent: Mozilla/5.0\n"
                                    "Accept-Encoding: gzip, deflate\n"
                                    "Accept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, parse_request_invalid_no_crlf){
    HTTP::Request request;
    std::string test_http_request = "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1"
                                    "Host: guru99.com\n"
                                    "User-Agent: Mozilla/5.0\n"
                                    "Accept-Encoding: gzip, deflate\n"
                                    "Accept-Cherset: ISO-8859-1, utf-8\r\n\r\n";
    auto result = request.from_string(test_http_request);

    ASSERT_FALSE(result);
};

TEST(HTTPParser, parse_request_invalid_no_crlfx2){
    HTTP::Request request;
    std::string test_http_request = "GET /REgisterStudent.asp?user=jhon&pass=java HTTP/1.1"
                                    "Host: guru99.com\n"
                                    "User-Agent: Mozilla/5.0\n"
                                    "Accept-Encoding: gzip, deflate\n"
                                    "Accept-Cherset: ISO-8859-1, utf-8\r\n";
    auto result = request.from_string(test_http_request);
    ASSERT_FALSE(result);
};

TEST(HTTPParser, parse_body_full){
    HTTP::Request request;
    std::string test_http_request = "POST /test HTTP/1.1\r\n"
                                    "Host: foo.example\n"
                                    "Content-Type: application/x-www-form-urlencoded\n"
                                    "Content-Length: 27\r\n\r\n"
                                    "field1=value1&field2=value2";
    auto result = request.from_string(test_http_request);
    std::string body_len = request.get_header_field_value("Content-Length");
    ASSERT_EQ(body_len, "27");
};

TEST(HTTPParser, parse_body_get){
    HTTP::Request request;
    std::string test_http_request = "GET /doc/test.html HTTP/1.1\r\n"
                                    "Host: www.test.com\n"
                                    "Accept-Language: en-us\n"
                                    "Content-Length: 35\r\n\r\n"
                                    "bookId=q2345&author=Tan+Ah+Teck";
    auto result = request.from_string(test_http_request);
    std::string body_len = request.get_header_field_value("Content-Length");
    ASSERT_EQ(body_len, "35");
};

TEST(HTTPParser, parse_body_type){
    HTTP::Request request;
    std::string test_http_request= "POST /test HTTP/1.1\r\n"
                                   "Host: foo.example\n"
                                   "Content-Type: application/x-www-form-urlencoded\n"
                                   "Content-Length: 27\r\n\r\n"
                                   "field1=value1&field2=value2";
    auto result = request.from_string(test_http_request);
    std::string body_type = request.get_body_type();
    ASSERT_EQ(body_type, "application/x-www-form-urlencoded");
};

TEST(HTTPParser, parse_body_transfer_encoding){
    HTTP::Request request;
    std::string test_http_request = "POST /test HTTP/1.1\r\n"
                                    "Content-Type: text/plain\n"
                                    "Transfer-Encoding: chunked\r\n\r\n"
                                    "7\r\n"
                                    "Mozilla\r\n"
                                    "Developer\r\n"
                                    "Network\r\n"
                                    "0\r\n\r\n";
    auto result = request.from_string(test_http_request);
    std::string body_type = request.get_body_type();
    ASSERT_EQ(body_type, "text/plain");
};

TEST(HTTPParser, parse_response_with_body){
    HTTP::Response response;
    std::string test_response = "HTTP/1.1 404 Not Found\r\n"
                                "Content-Type: text/plain\n"
                                "Transfer-Encoding: chunked\r\n\r\n"
                                "7\r\n"
                                "Mozilla\r\n"
                                "Developer\r\n"
                                "Network\r\n"
                                "0\r\n\r\n";
    auto result = response.from_string(test_response);
    std::string body_type = response.get_body_type();
    ASSERT_EQ(body_type, "text/plain");
};

TEST(HTTPParser, parse_response_status){
    HTTP::Response response;
    std::string test_response = "HTTP/1.1 200 OK\r\n"
                                "Date: Mon, 27 Jul 2009 12:28:53 GMT\n"
                                "Server: Apache/2.2.14 (Win32)\n"
                                "Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\n"
                                "Content-Length: 88\n"
                                "Content-Type: text/html\n"
                                "Connection: Closed\r\n\r\n";
    auto result = response.from_string(test_response);
    short status_code = response.get_status_code();
    ASSERT_EQ(status_code, 200);
};

TEST(HTTPParser, validate_respons){
    HTTP::Response response;
    std::string test_response = "HTTP/1.1 200 OK\r\n"
                                "Date: Mon, 27 Jul 2009 12:28:53 GMT\n"
                                "Server: Apache/2.2.14 (Win32)\n"
                                "Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\n"
                                "Content-Length: 88\n"
                                "Content-Type: text/html\n"
                                "Connection: Closed\r\n\r\n";
    auto result = response.from_string(test_response);
    ASSERT_TRUE(result);
};



