cmake_minimum_required(VERSION 3.5)

project(Checkers VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(UI_QTWIDGETS ON CACHE INTERNAL BOOL)
if (UI_QTWIDGETS)
    set(QTWIDGETS_PATH "${PROJECT_SOURCE_DIR}/views/qtwidgets/headers" CACHE INTERNAL "")
endif()

set(UI_INTERFACE_PATH "${PROJECT_SOURCE_DIR}/views/Interface" CACHE INTERNAL "")
set(MODEL_UI_PATH "${PROJECT_SOURCE_DIR}/models/ui/headers" CACHE INTERNAL "")
set(MODEL_GAME_PATH "${PROJECT_SOURCE_DIR}/models/game/headers" CACHE INTERNAL "")

include(Dependencies.cmake)
add_subdirectory(views/qtwidgets)
add_subdirectory(models/ui)
add_subdirectory(models/game)

set(PROJECT_SOURCES
        main.cpp
)

if (UI_QTWIDGETS)
    if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
        qt_add_executable(${PROJECT_NAME}
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
        )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET Checkers APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
    else()
        if(ANDROID)
            add_library(${PROJECT_NAME} SHARED
                ${PROJECT_SOURCES}
            )
    # Define properties for Android with Qt 5 after find_package() calls as:
    #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
        else()
            add_executable(${PROJECT_NAME}
                ${PROJECT_SOURCES}
            )
        endif()
    endif()

    target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

    # Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
    # If you are developing for iOS or macOS you should consider setting an
    # explicit, fixed bundle identifier manually though.
    if(${QT_VERSION} VERSION_LESS 6.1.0)
      set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.${PROJECT_NAME})
    endif()
    set_target_properties(${PROJECT_NAME} PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )

    if(QT_VERSION_MAJOR EQUAL 6)
        qt_finalize_executable(${PROJECT_NAME})
    endif()

    target_link_libraries(${PROJECT_NAME} PRIVATE Checkers-views-qtwidgets)
    target_include_directories(${PROJECT_NAME} PRIVATE ${QTWIDGETS_PATH})
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Checkers-models-ui)
target_link_libraries(${PROJECT_NAME} PRIVATE Checkers-models-game)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/models/ui/headers)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/models/game/headers)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
