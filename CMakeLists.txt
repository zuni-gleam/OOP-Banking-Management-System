cmake_minimum_required(VERSION 3.19)
project(BankingSystem1 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql)

qt_standard_project_setup()

qt_add_executable(BankingSystem1
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    db/dbmanager.h
    db/dbmanager.cpp
    models/user.h
    models/user.cpp
    models/account.h
    models/account.cpp
    models/savingsaccount.h
    models/savingsaccount.cpp
    models/currentaccount.h
    models/currentaccount.cpp
    security/hasher.h
    security/hasher.cpp
    security/totp.h
    security/totp.cpp
    ui/registerwindow.h
    ui/registerwindow.cpp
    ui/registerwindow.ui
    ui/loginwindow.h
    ui/loginwindow.cpp
    ui/loginwindow.ui
    ui/dashboard.h
    ui/dashboard.cpp
    ui/dashboard.ui
    ui/adminloginwindow.h
    ui/adminloginwindow.cpp
    ui/adminloginwindow.ui
    ui/totpdialog.h
    ui/totpdialog.cpp
    ui/totpdialog.ui
)

target_link_libraries(BankingSystem1
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Sql
)

install(TARGETS BankingSystem1
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET BankingSystem1
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})