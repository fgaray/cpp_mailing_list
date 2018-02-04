#ifndef _H_DB_
#define _H_DB_

#include <sqlite3.h> 
#include <string>
#include <functional>
#include <list>

#include "Result.hpp"

typedef int (*callback)(void*,int,char**,char**);

class DB {
  private:
    sqlite3 *handle;
    char *current_err;
    std::list<Result> *collector;
    int total_results;


  public:
    DB(const std::string db_file = "mailing_list.sqlite3");
    virtual ~DB();
    bool isValid() const;
    void runSQL(const std::string &query);
    void runSQL(const std::string &query, callback fn);
    void runSQLResults(const std::string &query, std::list<Result> &l);
    std::string getError() const;
    bool error() const;
    void cleanError();
    void addResult(Result result);
};


#endif
