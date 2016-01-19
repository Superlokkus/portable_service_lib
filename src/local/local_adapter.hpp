/*! @file local_adapter.hpp

*/

#ifndef PORTABLE_SERVICE_LOCAL_ADAPTER_HPP
#define	PORTABLE_SERVICE_LOCAL_ADAPTER_HPP

namespace portable_service{
namespace internal{

class local_adapter : public api_adapter{
public:
    virtual void add_service_functionality(service_functionality_t
            <service_func_plain_loop_t> service_func,
            std::string name);
    
    
private:
    
    
};

}
}

#endif	

