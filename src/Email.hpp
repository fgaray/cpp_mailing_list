#ifndef _H_EMAIL_
#define _H_EMAIL_

class Email {
  private:
    std::string from;
    std::string to;


  public:
    Email(std::string from, std::string to);
    virtual ~Email();

};

#endif
