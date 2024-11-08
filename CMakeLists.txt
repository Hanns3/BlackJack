cmake_minimum_required(VERSION 3.16)

project(Black VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Black
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        deck.h deck.cpp
        card.h card.cpp
        resources.qrc
        images/cards/10_of_clubs.png images/cards/10_of_diamonds.png images/cards/10_of_hearts.png images/cards/10_of_spades.png images/cards/2_of_clubs.png images/cards/2_of_diamonds.png images/cards/2_of_hearts.png images/cards/2_of_spades.png images/cards/3_of_clubs.png images/cards/3_of_diamonds.png images/cards/3_of_hearts.png images/cards/3_of_spades.png images/cards/4_of_clubs.png images/cards/4_of_diamonds.png images/cards/4_of_hearts.png images/cards/4_of_spades.png images/cards/5_of_clubs.png images/cards/5_of_diamonds.png images/cards/5_of_hearts.png images/cards/5_of_spades.png images/cards/6_of_clubs.png images/cards/6_of_diamonds.png images/cards/6_of_hearts.png images/cards/6_of_spades.png images/cards/7_of_clubs.png images/cards/7_of_diamonds.png images/cards/7_of_hearts.png images/cards/7_of_spades.png images/cards/8_of_clubs.png images/cards/8_of_diamonds.png images/cards/8_of_hearts.png images/cards/8_of_spades.png images/cards/9_of_clubs.png images/cards/9_of_diamonds.png images/cards/9_of_hearts.png images/cards/9_of_spades.png images/cards/ace_of_clubs.png images/cards/ace_of_diamonds.png images/cards/ace_of_hearts.png images/cards/ace_of_spades.png images/cards/jack_of_clubs.png images/cards/jack_of_diamonds.png images/cards/jack_of_hearts.png images/cards/jack_of_spades.png images/cards/king_of_clubs.png images/cards/king_of_diamonds.png images/cards/king_of_hearts.png images/cards/king_of_spades.png images/cards/queen_of_clubs.png images/cards/queen_of_diamonds.png images/cards/queen_of_hearts.png images/cards/queen_of_spades.png images/background.jpg
        images/cards/back.png
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Black APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Black SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Black
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Black PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Black)
endif()
set_target_properties(Black PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Black
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Black)
endif()
