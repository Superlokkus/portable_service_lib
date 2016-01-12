/*! @file common.hpp

 */

#ifndef PORTABLE_SERVICE_COMMON_HPP
#define	PORTABLE_SERVICE_COMMON_HPP

#include <functional>
#include <vector>
#include <string>
#include <memory>
#include <set>
#include <map>
#include <type_traits>

namespace portable_service {

enum struct service_api : unsigned long long {
    debug = 0x0u, /*!< Use this to use run the service locally, i.e. 
                       as an ordinary program, for e.g. debugging purposes */
            unix_daemon, /*!< Use the most common unix way, aka SysV initd, aka
                      double fork() etc.*/
            win_scm, /*!< Use the microsoft windows service manager */
            automatic = (unsigned long long) - 1 /*!< Let the library choose the best fitting one*/
};

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

std::set<service_api> get_avaible_apis();

using service_func_plain_loop_t = std::function<void(void) >;
using service_func_with_arg_loop_t = std::function<void(std::string)>;
using service_callbacks_t = std::map<event, std::function<bool(void) >>;

template <typename service_loop>
struct service_functionality {
    static_assert(
            std::is_convertible<service_loop, service_func_plain_loop_t>::value ||
            std::is_convertible<service_loop, service_func_with_arg_loop_t>::value,
            "service_loop has to be either service_func_plain_loop_t or "
            "service_func_with_arg_loop_t");

    using type = std::pair<service_loop, service_callbacks_t>;
};

template<typename service_loop> using service_functionality_t =
typename service_functionality<service_loop>::type;

}

#endif

