#include "SMTP.hpp"


SMTP::SMTP(const std::string &smtp_server):
  res(CURLE_OK),
  recipients(nullptr) {
  
  this->curl = curl_easy_init();

  if (this->curl) {
    curl_easy_setopt(curl, CURLOPT_URL, smtp_server.c_str());
  }
}

SMTP::~SMTP(){
  if (this->recipients) {
    curl_slist_free_all(recipients);
  }

  if (this->curl) {
    curl_easy_cleanup(curl);
  }
}

void SMTP::addRecipients(const std::list<std::string> &recipients) {
  for (auto &r: recipients) {
    curl_slist_append(this->recipients, r.c_str());
  }
  curl_easy_setopt(this->curl, CURLOPT_MAIL_RCPT, this->recipients);
}

void SMTP::addFrom(const std::string &from) {
  curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from.c_str());
}

void SMTP::send() {
  this->res = curl_easy_perform(this->curl);
}
