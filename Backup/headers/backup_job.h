#pragma once

#include "storage_factory.h"
#include "job_object.h"
#include "restore_point.h"
#include "repository.h"

#include <vector>
#include <algorithm>



class BackupJob
{

public:
    BackupJob(std::string name,
              StorageFactory* storage_factory,
              Repository* repository);


    void addJobObject(const JobObject& job_object);

    void addJobObjects(std::vector<JobObject> job_objects);

    void removeJobObject(const JobObject& job_object);

    std::vector<RestorePoint> getRestorePoints();

    RestorePoint* runJob();

private:
    std::string name_;
    std::vector<JobObject> job_objects_;
    std::vector<RestorePoint> restore_points_;
    Repository* repository_;
    StorageFactory* storage_factory_;
};
