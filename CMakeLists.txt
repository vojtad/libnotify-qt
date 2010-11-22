cmake_minimum_required(VERSION 2.6)
project(libnotify-qt)

find_package(Qt4 REQUIRED)

set(CMAKE_BUILD_TYPE Release)

set(QT_USE_QTCORE TRUE)
set(QT_USE_QTDBUS TRUE)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
include_directories(${QT_INCLUDE_DIR})

set(LIB_SRCS
	src/Notification.cpp
	src/OrgFreedesktopNotificationsInterface.cpp)

set(LIB_MOC_HDRS
	src/Notification.h
	src/OrgFreedesktopNotificationsInterface.h)

qt4_wrap_cpp(LIB_MOC_SRCS ${LIB_MOC_HDRS})

add_library(libnotify-qt ${LIB_MOC_SRCS} ${LIB_SRCS})

install(TARGETS libnotify-qt DESTINATION lib)
install(FILES src/Notification.h DESTINATION include)
