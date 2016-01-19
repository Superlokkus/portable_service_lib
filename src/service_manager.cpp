/*! @file service_manager.cpp
 */

#include "service_manager.hpp"

#include "local_adapter.hpp"

namespace portable_service {

service_manager::service_manager(const service_api &api) {
    switch (api) {
        case service_api::local:
            this->adapter(internal::local_adapter());
            break;
        case service_api::automatic:
        default:
            throw std::runtime_error("Not implemented yet");
            break;
    }
}

void service_manager::add_service_functionality(service_functionality_t
        <service_func_plain_loop_t> functionality, std::string name){
    
}

}