#ifndef __USER_H_
#define __USER_H_

#include <cstdlib>
#include "string.h"

using namespace std;
int usermain();
class user
{
private:
    char* uname;
    size_t ulen;
    char* pass;
    size_t plen;


public:
    user(/* args */);
    user(const char*,const char*);
    user(const user&);
    char* get_uname();
    char* get_pass();
    int operator==(const user&);
    int login();
    void registr() const;
    void forgot() const;

    ~user();
};

#endif //__USER_H_
