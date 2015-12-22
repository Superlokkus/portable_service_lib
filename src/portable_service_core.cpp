/*! @file portable_service_core.cpp
 
*/

#include "portable_service_core.hpp"

namespace portable_service{
    service_manager service_manager::service_manager(const service_api &api) {
        switch (api){
            case service_api::debug:
            
            case service_api::automatic:
            default:
                throw std::runtime_error("Not implemented yet");
                break;
        }
    }
    
}
