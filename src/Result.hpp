#ifndef _H_RESULT_
#define _H_RESULT_

#include <string>
#include <unordered_map>
#include <sstream>
#include <optional>


class Result {
  private:
    std::unordered_map<std::string, std::optional<std::string>> rs;

  public:
    Result();
    virtual ~Result();
    void addResult(std::string name, std::string value);
    void addResult(std::string name);
    std::optional<std::optional<std::string>> getCol(const std::string &name) const;
    std::string toString() const;
};

#endif
