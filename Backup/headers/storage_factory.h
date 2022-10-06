#pragma once

#include "storage.h"
#include "job_object.h"

#include <vector>

class StorageFactory
{
public:
    StorageFactory() {}

    virtual std::vector<Storage> putInStorage(std::vector<JobObject> jobObjects) = 0;
};
