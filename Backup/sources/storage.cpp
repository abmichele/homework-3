#include "../headers/storage.h"

#include <filesystem>
#include <fstream>

Storage::Storage()
{

}

void Storage::addFile(const File &file)
{
    this->files.push_back(file);
}

void Storage::addFiles(std::vector<File> files)
{
    this->files.insert(this->files.end(), files.begin(), files.end());
}

std::vector<File>* Storage::getFiles()
{
    return &this->files;
}

void Storage::serialize(std::ostream &ostream)
{
    size_t file_count = files.size();
    ostream.write(reinterpret_cast<const char *>(&file_count), sizeof(file_count));
    for (const auto &file: files)
    {
        size_t file_name_length = file.file_path_.length();
        ostream.write(reinterpret_cast<const char *>(&file_name_length), sizeof(file_name_length));
        ostream.write(file.file_path_.c_str(), file_name_length * sizeof(char));
        size_t file_size = std::filesystem::file_size(file.file_path_);
        ostream.write(reinterpret_cast<const char *>(&file_size), sizeof(file_size));
        std::ifstream backup_file(file.file_path_, std::ios::in | std::ios::binary);
        copy(
                std::istreambuf_iterator<char>(backup_file),
                std::istreambuf_iterator<char>(),
                std::ostreambuf_iterator<char>(ostream));

        // закрыть архив (бэкап)
        backup_file.close();
    }
}
