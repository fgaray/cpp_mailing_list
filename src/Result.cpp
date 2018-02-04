#include "Result.hpp"

Result::Result() {

}

Result::~Result() {

}

void Result::addResult(std::string name, std::string value) {
  this->rs.insert(std::make_pair(name, std::make_optional(value)));
}

void Result::addResult(std::string name) {
  this->rs.insert(std::make_pair(name, std::nullopt));
}

std::string Result::toString() const {
  std::stringstream ss;
  for (auto it = this->rs.begin(); it != this->rs.end(); ++it) {
    ss << it->first << " -> " << it->second.value_or("NULL");
  }

  return ss.str();
}


std::optional<std::optional<std::string>> Result::getCol(const std::string &name) const {
  auto found = this->rs.find(name);
  if (found == this->rs.end()) {
    return std::nullopt;
  } else {
    return std::make_optional(*found->second);
  }
}
