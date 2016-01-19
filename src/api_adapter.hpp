/*! @file api_adapter.hpp

 */

#ifndef PORTABLE_SERVICE_PORTABLE_API_ADAPTER_H
#define	PORTABLE_SERVICE_PORTABLE_API_ADAPTER_H

#include <functional>
#include <map>
#include <string>

#include "common.hpp"

namespace portable_service {
namespace internal {

class api_adapter {
public:
    virtual void add_service_functionality(service_functionality_t
            <service_func_plain_loop_t> service_func,
            std::string name);


    virtual ~api_adapter() = default;
};
}
}


#endif

