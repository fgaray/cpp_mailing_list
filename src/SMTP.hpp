#ifndef _H_SMTP_
#define _H_SMTP_

#include <string>
#include <list>
#include <curl/curl.h>

class SMTP {
  private:
    CURL *curl;
    CURLcode res;
    struct curl_slist *recipients;

  public:
    SMTP(const std::string &smtp_server);
    virtual ~SMTP();
    void addRecipients(const std::list<std::string> &recipients);
    void addFrom(const std::string &from);
    void send();
};


#endif
