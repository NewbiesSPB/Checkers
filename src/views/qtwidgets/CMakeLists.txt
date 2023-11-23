cmake_minimum_required(VERSION 3.5)

project(Checkers-views-qtwidgets VERSION 0.1 LANGUAGES CXX)

set(SOURCES
    source/MainWindowView.cpp
    source/MainMenuView.cpp
    source/MyButtonRect.cpp
    source/MyButtonRound.cpp
    source/GameView.cpp
    source/BoardView.cpp
)

set(HEADERS
    headers/MainWindowView.h
    headers/MainMenuView.h
    headers/MyButtonRect.h
    headers/MyButtonRound.h
    headers/GameView.h
    headers/BoardView.h
    ../interface/IView.h
)

set(PROJECT_SOURCES
    ${SOURCES}
    ${HEADERS}
)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES} )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/headers)

target_link_libraries(${PROJECT_NAME} PRIVATE Checkers-models-ui)
target_include_directories(${PROJECT_NAME} PRIVATE ${MODEL_UI_PATH})
target_include_directories(${PROJECT_NAME} PRIVATE ${UI_INTERFACE_PATH})

