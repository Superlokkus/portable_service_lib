/*! @file portable_service_core.hpp

*/

#include "portable_service_lib.h"

#include <functional>
#include <vector>

namespace portable_service{
    
    /*! @brief The core class that manages the service as a whole
     */
    class service_manager{
        
        /*! Events concerning the service as a whole 
          
         @notice Except for stop, the library user only has to support events,
          for which call backs are registered to.         
         */
        enum struct events {
            stop, /*!< service must stop, i.e. terminate immidiatly 
                    / asap */
            pause, /*!< service has to halt its activity, not to clean 
                     up or terminate*/
            resume, /*!< service has to continue is activity*/
            shutdown /*!< service has to stop its activity and clean up */
        };
        
        /*! @brief Adds a function, which will be called in a new thread, after
         run() is beeing called
         @param root Function that provides the function i.e. 
               use case of the service
         @attention The given function has to return sometime after the stop event
         has been issued
         */
        void add_service_root(std::function<void(void)> root);
        
        /*! @brief Also adds a function, which may get additional arguments,
         delivered by the native service API
         */
        void add_service_root(std::function<void(std::string)> root_with_args);
        
        /*! @brief Not mandatory but helps the library when using very 
          unpatient APIs, by calling it as the first function in the user code
         */
        void pre_run();
        
        /*! @brief Non returning function which has to be called 
          after all setup is done
         */
        [[noreturn]] void run();
    };
}
