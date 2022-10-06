#include "../headers/split_storage_factory.h"
#include "../headers/job_object.h"

SplitStorageFactory::SplitStorageFactory()
{

}

std::vector<Storage> SplitStorageFactory::putInStorage(std::vector<JobObject> jobObjects)
{

    std::vector<Storage> storages;

    for (auto jobObject: jobObjects)
    {
        File file{jobObject.getFilePath()};

        Storage storage;
        storage.addFile(file);
        storages.push_back(storage);
    }

    return storages;
}
