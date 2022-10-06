#include "../headers/restore_point.h"
#include "../headers/utils.h"

#include <utility>
#include <ctime>

using std::vector;

RestorePoint::RestorePoint(std::string name)
    : name_(name),
      save_time_(time(nullptr))
{

}

void RestorePoint::setSaveTime()
{
    this->save_time_ = time(nullptr);
}

time_t RestorePoint::getTime()
{
    return this->save_time_;
}

std::string RestorePoint::getName()
{
    return this->name_;
}

vector<JobObject> RestorePoint::getJobObjects()
{
    return this->job_objects_;
}

vector<Storage> RestorePoint::getStorages()
{
    return this->storages_;
}

void RestorePoint::addObject(const JobObject &jobObject)
{
    this->job_objects_.push_back(jobObject);
}

void RestorePoint::addJobObjects(vector<JobObject> jobs)
{
    this->job_objects_.insert(this->job_objects_.end(), jobs.begin(), jobs.end());
}

void RestorePoint::addStorages(vector<Storage> storages)
{
    this->storages_.insert(this->storages_.end(), storages.begin(), storages.end());
}

void RestorePoint::serialize(std::ostream &ostream)
{
    auto namestr = "name:" + this->name_ + "\n";
    ostream.write(namestr.c_str(), sizeof(char) * namestr.size());

    auto timestr = "time:" + timeToString(this->save_time_) + "\n";
    ostream.write(timestr.c_str(), sizeof(char) * timestr.size());

    std::string jobsstr = "jobs:\n";
    ostream.write(jobsstr.c_str(), sizeof(char) * jobsstr.size());

    for (JobObject job: this->job_objects_)
    {
        job.serialize(ostream);
    }
}
