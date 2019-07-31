#pragma once

#include <Arduino.h>

#include "consts.h"
#include "time_utils.h"

namespace commands {

class ClockSetCommand : public Printable {
   public:
    void Execute(Print *p);
    size_t printTo(Print &p) const;
};

inline void ClockSetCommand::Execute(Print* p) {
    p->print(FPSTR(str_set));
    p->print(FPSTR(str_date));

    char date_str[32];
    strcpy_P(date_str, str_build_date);
    tm tm;
    if (str_to_date(date_str, tm)) {
        Date d = Date(tm);
        p->println(d);
    } else {
        p->println(FPSTR(str_invalid));
    }
}

size_t ClockSetCommand::printTo(Print& p) const {
    size_t res = p.println("clock set");
    return res;
}

}  // namespace executors
