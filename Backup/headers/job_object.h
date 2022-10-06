#pragma once

#include <string>
#include <cstddef>



class JobObject
{

public:
    JobObject(std::string file_path);
    std::string getFilePath();
    void serialize(std::ostream &ostream);
    bool operator==(JobObject other_job_object);

private:
    std::string file_path_;
};
