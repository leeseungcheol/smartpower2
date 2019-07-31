#pragma once

#include "ParameterlessCommand.h"

namespace shell {

class ShowClients : public ParameterlessCommand {
   public:
    void Execute(Print* p);
    size_t printTo(Print& p) const;
};

inline void ShowClients::Execute(Print* p) {
    if (wireless::getWirelessMode() != WLAN_STA) {
        p->print(FPSTR(str_wifi_));
        p->print(FPSTR(str_two_dots));
        p->println(getConnectedStationInfo().c_str());
    }
    p->print(FPSTR(str_http_));
    p->print(FPSTR(str_two_dots));
    p->println(get_http_clients_count());
    
    p->print(FPSTR(str_telnet_));
    p->print(FPSTR(str_two_dots));
    p->println(get_telnet_clients_count());
}

inline size_t ShowClients::printTo(Print& p) const {
    size_t res = p.println(F("show clients"));
    return res;
}

ShowClients *showClients = new ShowClients();

}  // namespace shell