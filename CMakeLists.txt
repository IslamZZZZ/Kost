cmake_minimum_required(VERSION 3.16)
project(ExpensesApp)

set(CMAKE_CXX_STANDARD 17)

# Найти модули Qt
find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

# Список UI (если есть)
set(UI_FILES
    ui/MainWindow.ui
)

# Генерация заголовков из .ui (если используешь)
qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# Список C++-файлов
set(SOURCES
    src/main.cpp
    src/Database.cpp     # ← ОБЯЗАТЕЛЬНО добавь
    # src/MainWindow.cpp  # если у тебя есть GUI-класс
)

# Список заголовков (необязательно, но удобно)
set(HEADERS
    src/Database.h
    # src/MainWindow.h
)

add_executable(ExpensesApp
    ${SOURCES}
    ${HEADERS}
    ${UI_HEADERS}
)

# Линкуем Qt и sqlite3
target_link_libraries(ExpensesApp
    Qt5::Widgets
    Qt5::Sql
    sqlite3
)
