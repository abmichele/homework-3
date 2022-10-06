#include "repository.h"



class FSRepository : public Repository
{

public:
    FSRepository(std::string path);

    void saveRestorePoint(RestorePoint* restorePoint) override;

private:
    std::string directory_;
};
