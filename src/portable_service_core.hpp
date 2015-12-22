/*! @file portable_service_core.hpp

*/
#ifndef PORTABLE_SERVICE_PORTABLE_SERVICE_CORE_H
#define PORTABLE_SERVICE_PORTABLE_SERVICE_CORE_H

#include "portable_service_lib.h"

#include <functional>
#include <vector>
#include <string>
#include <memory>

#include "api_adapter.hpp"

namespace portable_service{
    
    enum struct service_api : unsigned long long{
        debug = 0x0u, /*!< Use this to use run the service locally, i.e. 
                       as an ordinary program, for e.g. debugging purposes */
        unix_daemon, /*!< Use the most common unix way, aka SysV initd, aka
                      double fork() etc.*/
        win_scm, /*!< Use the microsoft windows service manager */
        automatic = -1 /*!< Let the library choose the best fitting one*/
    };
    
    std::set<service_api> get_avaible_apis();
    
    /*! @brief The core class that manages the service as a whole
     */
    class service_manager{
    public:
        /*! Events concerning the service as a whole 
          
         @notice Except for stop, the library user only has to support events,
          for which call backs are registered for.       
         */
        enum struct event {
            start, /*!< will be called whenever the service has to start */
            stop, /*!< service must stop, i.e. terminate immidiatly 
                    / asap */
            pause, /*!< service has to halt its activity, not to clean 
                     up or terminate*/
            resume, /*!< service has to continue is activity*/
            shutdown, /*!< service has to stop its activity and clean up */
            interrogate /*!< will be called occasionally up to periodically, to
                         ask for the proper function of the service, 
                         to achieve a watchdoged functionality */
        };
        
        /*! @brief Adds a core functionalty to the service
         @param loop Function that provides a core function i.e. 
               use case of the service, which will be called in a new thread, 
               after run() is beeing called
         @param call_backs Functions to be called in the regarding events.
         Shall return whenever reaction to the event was successfull and complete.
         @param name Optional name for the service funcationality for reporting 
                    and debug mode
         @attention The given loop function has to return eventually 
         after the stop event has been issued
         @throws std::invalid_argument When there is no call_back for the 
         stop event
         */
        void add_service_functionality(std::function<void(void)> loop, 
             std::map<event,std::function<bool(void)>> call_backs,
             std::string name = std::string{} );
        
        /*! @brief Also adds a function, which loop function 
           may get additional arguments, delivered by the native service API, 
           instead as arguments to main()
         */
        void add_service_functionality(std::function<void(std::string)> loop, 
             std::map<event,std::function<bool(void)>> call_backs,
             std::string name = std::string{} );
        

        /*! @brief Non returning function which has to be called 
          after all setup is done
         */
        [[noreturn]] void run();
        
        
        static service_manager& get_instance(const service_api &api = 
                                service_api::automatic){
            static service_manager instance(api);
            
            return instance;
        }
        
        service_manager service_manager(const service_manager &) = delete;
        void operator=(const service_manager &) = delete;
        
    private:
        std::unique_ptr<internal::api_adapter> adapter;
        
        service_manager service_manager(const service_api &api);
    };
}

#endif 