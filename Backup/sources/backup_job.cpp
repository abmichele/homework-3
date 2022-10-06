#include "../headers/backup_job.h"


BackupJob::BackupJob(std::string name,
                     StorageFactory *storage_factory,
                     Repository *repository)
    : name_(name),
      storage_factory_(storage_factory),
      repository_(repository),
      job_objects_(std::vector<JobObject>()),
      restore_points_(std::vector<RestorePoint>())
{

}


void BackupJob::addJobObject(const JobObject &job)
{
    this->job_objects_.push_back(job);
}


void BackupJob::addJobObjects(std::vector<JobObject> jobs)
{
    this->job_objects_.insert(this->job_objects_.end(), jobs.begin(), jobs.end());
}

void BackupJob::removeJobObject(const JobObject &job)
{
    this->job_objects_.erase(remove(this->job_objects_.begin(), this->job_objects_.end(), job),
                           this->job_objects_.end());
}

std::vector<RestorePoint> BackupJob::getRestorePoints()
{
    return this->restore_points_;
}

RestorePoint* BackupJob::runJob()
{
    auto *point = new RestorePoint(this->name_);
    point->addStorages(this->storage_factory_->putInStorage(this->job_objects_));

    for (const JobObject& job: this->job_objects_)
        point->addObject(job);

    point->setSaveTime();

    this->restore_points_.push_back(*point);

    this->repository_->saveRestorePoint(point);

    return point;
}


