cmake_minimum_required(VERSION 3.16)
project(ExpensesApp)

set(CMAKE_CXX_STANDARD 17)

# Ищем модули Qt: Widgets для GUI, Sql для работы с БД
find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

add_executable(ExpensesApp
    src/main.cpp       # пока только один файл
)

# Линкуем с библиотеками Qt5 и sqlite3
target_link_libraries(ExpensesApp
    Qt5::Widgets
    Qt5::Sql
    sqlite3
)

set(UI_FILES
    ui/MainWindow.ui
)
qt5_wrap_ui(UI_HEADERS ${UI_FILES})
target_sources(ExpensesApp PRIVATE ${UI_HEADERS})