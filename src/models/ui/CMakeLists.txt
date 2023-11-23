cmake_minimum_required(VERSION 3.5)

project(Checkers-models-ui VERSION 0.1 LANGUAGES CXX)

set(SOURCES
    source/MainWindowModel.cpp
    source/MainMenuModel.cpp
    source/GameModel.cpp
    source/SettingsModel.cpp
    source/StatisticsModel.cpp
)

set (HEADERS
    headers/MainWindowModel.h
    headers/MainMenuModel.h
    headers/GameModel.h
    headers/SettingsModel.h
    headers/StatisticsModel.h
    headers/iuimodel.h
)

set(PROJECT_SOURCES
        ${SOURCES}
        ${HEADERS}
)
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Checkers-models-game)
target_include_directories(${PROJECT_NAME} PRIVATE ${MODEL_GAME_PATH})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/headers)
target_include_directories(${PROJECT_NAME} PRIVATE ${UI_INTERFACE_PATH})

if (${UI_QTWIDGETS})
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
    target_link_libraries(${PROJECT_NAME} PRIVATE Checkers-views-qtwidgets)
    target_include_directories(${PROJECT_NAME} PRIVATE ${QTWIDGETS_PATH})
endif()
