#pragma once

#include "storage.h"
#include "job_object.h"

#include <vector>
#include <ctime>


class RestorePoint
{

public:
    RestorePoint(std::string name);
    void addObject(const JobObject& JobObject);
    void addJobObjects(std::vector<JobObject> jobObjects);
    void addStorages(std::vector<Storage> storages);
    void setSaveTime();
    std::vector<JobObject> getJobObjects();
    std::vector<Storage> getStorages();
    std::string getName();
    time_t getTime();
    void serialize(std::ostream &ostream);

private:
    std::string name_;
    time_t save_time_;
    std::vector<JobObject> job_objects_;
    std::vector<Storage> storages_;
};
