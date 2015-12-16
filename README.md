portable_service_lib
====================

General
--------
portable_service_lib is a C++ library for a portable way to run as a 
service/daemon/agent e.g. background process, 
using the available OS supported ways.

In short: This is not another NSSM (the Non-Sucking Service Manager) like wrapper.
So its intended for use with programs, that are aware, that they are a service.

Design goal
------------
Modern and portable C++ interface for a user to 
generate a portable and reliable service aka daemon, that will use an intersection of 
functions to report e.g. manage its status and in return also respond to events and requests, 
delivered by common service/init/daemon APIs.

Minimum supported APIs / OS
---------------------------

-   service control manager (SCM) aka service application for windows /  Microsoft Windows
-   systemd / Linux (Unix)
-   launchd / Apple OS X (Unix)
-   init aka. SysV-style init / Unix


 
