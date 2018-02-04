#include <iostream>
#include <list>
#include <string>

#include "DB.hpp"
#include "Result.hpp"


int main() {
  DB db;

  std::list<Result> l;

  //db.runSQL("INSERT INTO usuarios (nombre) VALUES (NULL)");
  db.runSQLResults("SELECT * FROM usuarios", l);

  for (auto &s: l) {
    std::cout << s.toString() << std::endl;
  }


  return 0;
}
