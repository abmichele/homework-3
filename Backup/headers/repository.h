#pragma once

#include "restore_point.h"


struct Repository
{
    virtual void saveRestorePoint(RestorePoint *restorePoint) = 0;
};
