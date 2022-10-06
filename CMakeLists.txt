cmake_minimum_required(VERSION 3.13)

# имя прокета - Backups, язык С++
project(Backups LANGUAGES CXX)

# cmake 17-го стандарта языка С++
set(CMAKE_CXX_STANDARD 17)

# cmake должен быть именно 17-го стандарта в обязательном порядке, иначе ошибка компиляции
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# отключены какие-либо расширения
set(CMAKE_CXX_EXTENSIONS OFF)

# подключить исходники и библиотеки GNU стандарта
include(GNUInstallDirs)

# установить директории cmake'а
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# необходимо подключить анализатор кода Gcov, иначе вывести ошибку
find_program(GCOV_PATH gcov)
if(NOT GCOV_PATH)
  message(FATAL_ERROR "Code coverage analysis requires gcov!")
endif()

# подключить директорию с исходным кодом и заголовочными файлами библиотеки c классами Figures
add_subdirectory(Backup)

# провести тестирование 
enable_testing()

# подключить директорию с тестами для программы лаборатороной работы Tests
add_subdirectory(Tests)
