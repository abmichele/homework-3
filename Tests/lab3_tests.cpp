#include <gtest/gtest.h>

#include "../Backup/headers/backup_job.h"
#include "../Backup/headers/general_storage_factory.h"
#include "../Backup/headers/split_storage_factory.h"
#include "../Backup/headers/fs_repository.h"
#include "../Backup/headers/job_object.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>

TEST(CreateBackups1, TwoRestorePointsAndThreeStoragesCreated)
{


    SplitStorageFactory* split_factory = new SplitStorageFactory();


    FSRepository repo("D:\\Users\\miche\\Desktop\\tmp\\repository_for_split_storage");

    BackupJob job("first_backup", split_factory, &repo);

    const char * name = "D:\\Users\\miche\\Desktop\\tmp\\room_list.txt";
    std::filesystem::path p(name);
    JobObject backup_object_1(p.string());

    const char * name2 = "D:\\Users\\miche\\Desktop\\tmp\\salary_list.txt";
    std::filesystem::path p2(name2);
    JobObject backup_object_2(p2.string());

    job.addJobObject(backup_object_1);
    job.addJobObject(backup_object_2);

    job.runJob();

    job.removeJobObject(backup_object_2);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    job.runJob();

    std::vector<RestorePoint> points = job.getRestorePoints();
    ASSERT_EQ(points.size(), 2);
    ASSERT_EQ((points[0].getStorages()).size(), 2);
    ASSERT_EQ((points[1].getStorages()).size(), 1);
}

TEST(CreateBackups2, OneRestorePointAndOneStorageCreated)
{

    GeneralStorageFactory* general_factory = new GeneralStorageFactory();

    FSRepository repo("D:\\Users\\miche\\Desktop\\tmp\\repository_for_general_storage");

    BackupJob job("second_backup", general_factory, &repo);

    const char * name = "D:\\Users\\miche\\Desktop\\tmp\\room_list.txt";
    std::filesystem::path p(name);
    JobObject backup_object_1(p.string());

    const char * name2 = "D:\\Users\\miche\\Desktop\\tmp\\salary_list.txt";
    std::filesystem::path p2(name2);
    JobObject backup_object_2(p2.string());

    job.addJobObject(backup_object_1);
    job.addJobObject(backup_object_2);

    job.runJob();

    std::vector<RestorePoint> points = job.getRestorePoints();
    ASSERT_EQ(points.size(), 1);
    ASSERT_EQ((points[0].getStorages()).size(), 1);

}

