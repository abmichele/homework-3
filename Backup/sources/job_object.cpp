#include "../headers/job_object.h"

#include <fstream>
#include <utility>


// конструктор (параметром принимает имя файла/или его полный путь)
JobObject::JobObject(std::string file_path)
    : file_path_(file_path)
{

}

std::string JobObject::getFilePath()
{
    return this->file_path_;
}

void JobObject::serialize(std::ostream &ostream)
{
    auto path = this->file_path_ + "\n";
    ostream.write(path.c_str(), sizeof(char) * path.length());
}

bool JobObject::operator==(JobObject otherJob)
{
    return this->getFilePath() == otherJob.getFilePath();
}
