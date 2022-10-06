#pragma once

#include "storage.h"
#include "job_object.h"

#include <vector>
#include <ostream>


struct File
{
    std::string file_path_;
};

class Storage
{

public:
    Storage();
    void addFile(const File& file);
    void addFiles(std::vector<File> file);
    std::vector<File>* getFiles();
    void serialize(std::ostream &ostream);

private:
    std::vector<File> files;
};
