// #include <gtest/gtest.h>
// #include <HTTP/Request.h>

// // TEST(HTTPParser, RequestURI_valid){
// //     HTTP::Request parser;
// //     std::string test_uri = "*";
// //     auto result = parser.validateURI(test_uri);
// //     ASSERT_TRUE(result);
// // }
// // // TEST(HTTPParser, RequestURI_invalid){
// // //     HTTP::Request parser;
// // //     std::string test_uri = "";
// // //     auto result= parser.validateURI(test_uri);
// // //     ASSERT_FALSE(result);
// // // }

// // TEST(HTTPParser, RequestURI_valid2){
// //     HTTP::Request parser;
// //     std::string test_uri = "http://www.w3.org/pub/WWW/TheProject.html";
// //     auto result= parser.validateURI(test_uri);
// //     ASSERT_TRUE(result);
// // }
// // TEST(HTTPParser, RequestURI_invalid2){
// //     HTTP::Request parser;
// //     std::string test_uri = "http:/www.w3.org/pub/WWW/TheProject.html";
// //     auto result= parser.validateURI(test_uri);
// //     ASSERT_FALSE(result);
// // }


// // TEST(HTTPParser, RequestURI_invalid3){
// //     HTTP::Request parser;
// //     std::string test_uri = "pub/WWW/TheProject.html HTTP/1.1";
// //     auto result= parser.validateURI(test_uri);
// //     ASSERT_FALSE(result);
// // }

// TEST(HTTPParser, RequestURI_valid3){
//     HTTP::Request parser;
//     std::string test_uri = "/pub/WWW/TheProject.html";
//     auto result= parser.validateURI(test_uri);
//     ASSERT_TRUE(result);
// }

// TEST(HTTPParser, validateVersion_valid){
//     HTTP::Request parser;
//     std::string test_uri = "HTTP/1.1";
//     auto result= parser.validateVersion(test_uri);
//     ASSERT_TRUE(result);
// }

// TEST(HTTPParser, splitString_valid){
//     const std::vector<std::string> expected_result = { "GET" ,"/pub/WWW/TheProject.html", "HTTP/1.1"};
//     auto result= HTTP::splitString("GET /pub/WWW/TheProject.html HTTP/1.1\r\n");
//     ASSERT_EQ(expected_result,result);
// }

// TEST(HTTPParser, parseStartLine_valid){
//     HTTP::Request parser;
//     auto result= parser.parseStartLine("GET /pub/WWW/TheProject.html HTTP/1.1\r\n");
//     ASSERT_TRUE(result);
// }

// TEST(HTTPParser, parseStartLine_ivalid){
//     HTTP::Request parser;
//     auto result= parser.parseStartLine("GT /pub/WWW/TheProject.html HTTP/1.1\r\n");
//     ASSERT_FALSE(result);
// }

// TEST(HTTPParser, parseStartLine_ivalid2){
//     HTTP::Request parser;
//     auto result= parser.parseStartLine("GET /pub/WWW/TheProject.html HTTP/1.1");
//     ASSERT_FALSE(result);
// }
// // TEST(HTTPParser, validateMethod_valid){
// //     HTTP::Request parser;
// //     auto result= parser.validateMethod("GET");
// //     ASSERT_EQ(HTTP::Method::GET,parser.getMethod());
// // }
// // TEST(HTTPParser, validateMethod_valid2){
// //     HTTP::Request parser;
// //     auto result= parser.validateMethod("PUT");
// //     ASSERT_EQ(HTTP::Method::PUT,parser.getMethod());
// // }