cmake_minimum_required(VERSION 3.16)

project(Black VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

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
        images/background.jpg


        back.h back.cpp
        front.h front.cpp
        cardwidget.h cardwidget.cpp
        images/hit.png
        player.h player.cpp
        human.h human.cpp
        dealer.h dealer.cpp
        game.h game.cpp
        badgelabel.h
        constants.h
        images/cards/child/back/back.png images/cards/child/front/10_of_clubs.png images/cards/child/front/10_of_diamonds.png images/cards/child/front/10_of_hearts.png images/cards/child/front/10_of_spades.png images/cards/child/front/2_of_clubs.png images/cards/child/front/2_of_diamonds.png images/cards/child/front/2_of_hearts.png images/cards/child/front/2_of_spades.png images/cards/child/front/3_of_clubs.png images/cards/child/front/3_of_diamonds.png images/cards/child/front/3_of_hearts.png images/cards/child/front/3_of_spades.png images/cards/child/front/4_of_clubs.png images/cards/child/front/4_of_diamonds.png images/cards/child/front/4_of_hearts.png images/cards/child/front/4_of_spades.png images/cards/child/front/5_of_clubs.png images/cards/child/front/5_of_diamonds.png images/cards/child/front/5_of_hearts.png images/cards/child/front/5_of_spades.png images/cards/child/front/6_of_clubs.png images/cards/child/front/6_of_diamonds.png images/cards/child/front/6_of_hearts.png images/cards/child/front/6_of_spades.png images/cards/child/front/7_of_clubs.png images/cards/child/front/7_of_diamonds.png images/cards/child/front/7_of_hearts.png images/cards/child/front/7_of_spades.png images/cards/child/front/8_of_clubs.png images/cards/child/front/8_of_diamonds.png images/cards/child/front/8_of_hearts.png images/cards/child/front/8_of_spades.png images/cards/child/front/9_of_clubs.png images/cards/child/front/9_of_diamonds.png images/cards/child/front/9_of_hearts.png images/cards/child/front/9_of_spades.png images/cards/child/front/ace_of_clubs.png images/cards/child/front/ace_of_diamonds.png images/cards/child/front/ace_of_hearts.png images/cards/child/front/ace_of_spades.png images/cards/child/front/jack_of_clubs.png images/cards/child/front/jack_of_diamonds.png images/cards/child/front/jack_of_hearts.png images/cards/child/front/jack_of_spades.png images/cards/child/front/king_of_clubs.png images/cards/child/front/king_of_diamonds.png images/cards/child/front/king_of_hearts.png images/cards/child/front/king_of_spades.png images/cards/child/front/queen_of_clubs.png images/cards/child/front/queen_of_diamonds.png images/cards/child/front/queen_of_hearts.png images/cards/child/front/queen_of_spades.png images/cards/default/back/back.png images/cards/default/front/10_of_clubs.png images/cards/default/front/10_of_diamonds.png images/cards/default/front/10_of_hearts.png images/cards/default/front/10_of_spades.png images/cards/default/front/2_of_clubs.png images/cards/default/front/2_of_diamonds.png images/cards/default/front/2_of_hearts.png images/cards/default/front/2_of_spades.png images/cards/default/front/3_of_clubs.png images/cards/default/front/3_of_diamonds.png images/cards/default/front/3_of_hearts.png images/cards/default/front/3_of_spades.png images/cards/default/front/4_of_clubs.png images/cards/default/front/4_of_diamonds.png images/cards/default/front/4_of_hearts.png images/cards/default/front/4_of_spades.png images/cards/default/front/5_of_clubs.png images/cards/default/front/5_of_diamonds.png images/cards/default/front/5_of_hearts.png images/cards/default/front/5_of_spades.png images/cards/default/front/6_of_clubs.png images/cards/default/front/6_of_diamonds.png images/cards/default/front/6_of_hearts.png images/cards/default/front/6_of_spades.png images/cards/default/front/7_of_clubs.png images/cards/default/front/7_of_diamonds.png images/cards/default/front/7_of_hearts.png images/cards/default/front/7_of_spades.png images/cards/default/front/8_of_clubs.png images/cards/default/front/8_of_diamonds.png images/cards/default/front/8_of_hearts.png images/cards/default/front/8_of_spades.png images/cards/default/front/9_of_clubs.png images/cards/default/front/9_of_diamonds.png images/cards/default/front/9_of_hearts.png images/cards/default/front/9_of_spades.png images/cards/default/front/ace_of_clubs.png images/cards/default/front/ace_of_diamonds.png images/cards/default/front/ace_of_hearts.png images/cards/default/front/ace_of_spades.png images/cards/default/front/jack_of_clubs.png images/cards/default/front/jack_of_diamonds.png images/cards/default/front/jack_of_hearts.png images/cards/default/front/jack_of_spades.png images/cards/default/front/king_of_clubs.png images/cards/default/front/king_of_diamonds.png images/cards/default/front/king_of_hearts.png images/cards/default/front/king_of_spades.png images/cards/default/front/queen_of_clubs.png images/cards/default/front/queen_of_diamonds.png images/cards/default/front/queen_of_hearts.png images/cards/default/front/queen_of_spades.png
        deckchange.h deckchange.cpp deckchange.ui
        images/menu.png

        sounds/background-music.mp3 sounds/carddrop.mp3
        musicplayer.h musicplayer.cpp
        images/stand.png
        images/noSound.png images/sound.png
        sounds/shuffleandbridge.mp3

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Black APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Black SHARED
            ${
            }
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
target_link_libraries(Black PRIVATE Qt6::Multimedia)

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
