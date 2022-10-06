cmake_minimum_required(VERSION 3.13)

# имя прокета - Backup, язык С++
project(Backup LANGUAGES CXX)

# установить директорию с заголовочными файлами *.h
set(HEADERS_DIR "headers")

# установить директорию с исходными файлами *.cpp
set(SOURCES_DIR "sources")

# установить список заголовочных файлов
set(
    HEADERS
    "${HEADERS_DIR}/backup_job.h"
    "${HEADERS_DIR}/fs_repository.h"
    "${HEADERS_DIR}/job_object.h"
    "${HEADERS_DIR}/mock_repository.h"
    "${HEADERS_DIR}/repository.h"
    "${HEADERS_DIR}/restore_point.h"
    "${HEADERS_DIR}/general_storage_factory.h"
    "${HEADERS_DIR}/split_storage_factory.h"
    "${HEADERS_DIR}/storage.h"
    "${HEADERS_DIR}/storage_factory.h"
    "${HEADERS_DIR}/utils.h"
)

# установить список исходников
set(
    SOURCES
    "${SOURCES_DIR}/backup_job.cpp"
    "${SOURCES_DIR}/fs_repository.cpp"
    "${SOURCES_DIR}/job_object.cpp"
    "${SOURCES_DIR}/mock_repository.cpp"
    "${SOURCES_DIR}/restore_point.cpp"
    "${SOURCES_DIR}/general_storage_factory.cpp"
    "${SOURCES_DIR}/split_storage_factory.cpp"
    "${SOURCES_DIR}/storage.cpp"
    "${SOURCES_DIR}/utils.cpp"
)

# зарегистрировать файлы
add_library(
    ${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)
