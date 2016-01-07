/*! @file api_adapter.hpp

 */

#ifndef PORTABLE_SERVICE_PORTABLE_API_ADAPTER_H
#define	PORTABLE_SERVICE_PORTABLE_API_ADAPTER_H

#include <functional>
#include <map>
#include <string>

#include "portable_service_core.hpp"

namespace portable_service {
    namespace internal {
        class api_adapter {
        public:
            virtual void add_service_functionality(std::function<void(void) > loop,
                    std::map<event, std::function<bool(void) >> call_backs,
                    std::string name);

                    
            virtual ~api_adapter() = default;
        };
    }
}


#endif

