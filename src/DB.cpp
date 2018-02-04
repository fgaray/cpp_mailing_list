#include "DB.hpp"

#include <iostream>

static int callback_fn(void *db_ptr, int total_results,char **results, char **names) {
  DB *db = static_cast<DB*>(db_ptr);

  if (results) {
    Result res;
    for (int i = 0; i < total_results; ++i, ++results, ++names){
      // null pointers does not have a result
      if (*results) {
        res.addResult(*names, *results);
      } else {
        res.addResult(*names);
      }
    }
    db->addResult(res);
  }

  return 0;
}



DB::DB(const std::string db_file):
  current_err(nullptr),
  collector(nullptr) {
  sqlite3_open(db_file.c_str(), &this->handle);
}

DB::~DB() {
  if (this->handle) {
    sqlite3_close(this->handle);
    this->handle = nullptr;
  }

  if (this->current_err) {
    sqlite3_free(this->current_err);
  }
}

bool DB::isValid() const {
  return this->handle != nullptr;
}

void DB::runSQL(const std::string &query) {
  sqlite3_exec(this->handle, query.c_str(), nullptr, nullptr, &this->current_err);
}

void DB::runSQL(const std::string &query, callback fn) {
  sqlite3_exec(this->handle, query.c_str(), fn, this, &this->current_err);
}

void DB::runSQLResults(const std::string &query, std::list<Result> &l) {
  this->collector = &l;
  this->runSQL(query, &callback_fn);
}

std::string DB::getError() const {
  if (this->current_err) {
    return this->current_err;
  } else {
    return "OK";
  }
}

bool DB::error() const {
  return this->current_err == nullptr;
}

void DB::cleanError() {
  sqlite3_free(this->current_err);
  this->current_err = nullptr;
}

void DB::addResult(Result result) {
  this->collector->push_back(result);
}
