#include "../headers/fs_repository.h"
#include "../headers/utils.h"

#include <fstream>
#include <filesystem>
#include <utility>

using std::string;

FSRepository::FSRepository(string path)
    : directory_(path)
{

}


void FSRepository::saveRestorePoint(RestorePoint *restorePoint)
{
    auto name = restorePoint->getName();
    auto time = restorePoint->getTime();

    std::ofstream fs;


    if (!std::filesystem::is_directory(this->directory_) || !std::filesystem::exists(this->directory_))
    {
        std::filesystem::create_directory(this->directory_);
    }


    if (!this->directory_.empty() && this->directory_.back() != '\\')
        this->directory_ += '\\';

    string repo_name = name + "_" + timeToString(time) + ".repo";
    fs.open(this->directory_ + repo_name);
    restorePoint->serialize(fs);
    fs.close();


    int storage_index = 0;
    for (auto storage: restorePoint->getStorages())
    {
        string st_name = name + "_" + timeToString(time) + "_" + std::to_string(storage_index) + ".storage";

        std::ofstream storage_fs(this->directory_ + st_name);
        storage.serialize(storage_fs);
        storage_fs.close();
        ++storage_index;
    }
}
