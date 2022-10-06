#pragma once

#include "storage_factory.h"

class SplitStorageFactory : public StorageFactory
{

public:
    SplitStorageFactory();
    std::vector<Storage> putInStorage(std::vector<JobObject> jobObjects) override;
};
