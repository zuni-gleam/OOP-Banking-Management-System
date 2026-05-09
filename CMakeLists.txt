cmake_minimum_required(VERSION 3.19)
project(BankingSystem1 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(BankingSystem1
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    db/dbmanager.h db/dbmanager.cpp
    user.h user.cpp
    account.h account.cpp
    savingsaccount.h savingsaccount.cpp
    currentaccount.h currentaccount.cpp
)

target_link_libraries(BankingSystem1
    PRIVATE
        Qt::Core
        Qt::Widgets
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
