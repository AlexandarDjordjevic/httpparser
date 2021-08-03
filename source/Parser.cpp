#include <HTTP/Parser.h>
#include <vector>

namespace HTTP{

    Parser::Parser()
    {
    }
    Parser::~Parser()
    {
    }

    bool validateMethod(const std::string &token){
        const std::vector<std::string> methodType = {"GET", "HEAD", "POST", "PUT", "DELETE", "CONNECT", "OPTIONS", "TRACE", "PATCH"};
        for (auto &method : methodType){
            if (method == token){
                return true;
            }
        }
        return false;
    }

    bool Parser::validateRequestStartLine(const std::string &message)
    {
        if (message == ""){
            return false;
        }
        
        if (endsWith(message, CRLF) == false){
            return false;
        }

        char *token;
        token = new char[message.length() + 1];
        strcpy(token, message.c_str());

        std::string method = strtok(token, " ");
        std::string URI = strtok(0," ");
        std::string version = strtok(0, CRLF.c_str());

        if (validateMethod(method) == false){
            return false;
        }

        std::string htp=URI.substr(0,7);

        if(!validateURI(URI)) return false;

        if (!validateVersion(version)) return false;

        return true;
    }
    bool Parser::validateURI(std::string &uri)
    {
        if (uri == "*")
        { //Dal je prvi tip
            return true;
        }
        std::string htp = uri.substr(0, 7);
        std::string pocinje = uri.substr(0, 1);
        if (htp == "http://") //dal pocinje sa http://
        {
            if (endsWith(uri, ".html")) // dal se zavrsava sa .html
                return true;
            return false;
        }
        if (pocinje == "/")
            return true;
        return false;
        
    }
    bool Parser::validateVersion(std::string& ver_token){
        if (ver_token != "HTTP/0.9" && ver_token!= "HTTP/1.0" && ver_token != "HTTP/1.1" && ver_token != "HTTP/2.0")
            return false;
        return true;
    }

    bool Parser::endsWith(const std::string &mainStr, const std::string &toMatch)
    {
        if (mainStr.size() >= toMatch.size() &&
            mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
            return true;
        else
            return false;
    }

}//namespace Namespace