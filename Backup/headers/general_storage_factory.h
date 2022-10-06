#pragma once

#include "storage_factory.h"



class GeneralStorageFactory : public StorageFactory
{
public:
    GeneralStorageFactory();
    std::vector<Storage> putInStorage(std::vector<JobObject> jobObjects) override;
};
