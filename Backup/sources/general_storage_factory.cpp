#include "../headers/general_storage_factory.h"
#include "../headers/job_object.h"

GeneralStorageFactory::GeneralStorageFactory()
{

}

std::vector<Storage> GeneralStorageFactory::putInStorage(std::vector<JobObject> jobObjects)
{

    std::vector<Storage> storages;
    Storage storage;

    for (auto& jobObject: jobObjects)
    {
        File file{jobObject.getFilePath()};
        storage.addFile(file);
    }

    storages.push_back(storage);

    return storages;
}
