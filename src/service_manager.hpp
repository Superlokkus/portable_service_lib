/*! @file service_manager.hpp

 */

#ifndef PORTABLE_SERVICE_SERVICE_MANAGER_HPP
#define	PORTABLE_SERVICE_SERVICE_MANAGER_HPP

#include "common.hpp"
#include "api_adapter.hpp"

namespace portable_service {

std::set<service_api> get_avaible_apis();

/*! @brief The core class that manages the service as a whole
 */
class service_manager {
public:
    /*! @brief Adds a core functionality to the service
     @param loop Function that provides a core function i.e. 
           use case of the service, which will be called in a new thread, 
           after run() is beeing called
     @param functionality A service core functionality with the according
            callbacks and main loop
     @param name Name for the service funcationality for identification, reporting 
                and debuging purposes
     @attention The given loop function has to return eventually after 
                the stop event has been issued
     @throws std::invalid_argument When there is no call_back for the 
             stop event
     */
    void add_service_functionality(
            service_functionality_t<service_func_plain_loop_t> functionality,
            std::string name);

    /*! @brief Also adds a function, which loop function 
       may get additional arguments, delivered by the native service API, 
       instead as arguments to main()
     */
    void add_service_functionality(
            service_functionality_t<service_func_with_arg_loop_t> functionality,
            std::string name);


    /*! @brief Non returning function which has to be called 
      after all setup is done
     */
    [[noreturn]] void run();

    static service_manager& get_instance(const service_api &api =
            service_api::automatic) {
        static service_manager instance(api);

        return instance;
    }

    service_manager(const service_manager &) = delete;
    void operator=(const service_manager &) = delete;

private:
    std::unique_ptr<internal::api_adapter> adapter;

    service_manager(const service_api &api);
};


}
#endif

