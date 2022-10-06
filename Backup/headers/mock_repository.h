#include "repository.h"

class FakeRepository : public Repository
{
    void saveRestorePoint(RestorePoint* restore_point) override;
};
