#include <iostream>
#include <thread>
#include <chrono>

// Function to simulate a time-consuming task (e.g., downloading a file)
void downloadFile(const std::string& fileName)
{
    std::cout << "Starting to download file: " << fileName << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));  // Simulate time delay
    std::cout << "Finished downloading file: " << fileName << std::endl;
}

// Function to simulate another task (e.g., processing data)
void processData()
{
    std::cout << "Starting to process data..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(6));  // Simulate processing time
    std::cout << "Finished processing data" << std::endl;
}

int main()
{
    // Start asynchronous tasks in separate threads
    std::thread downloadThread(downloadFile, "file1.txt");
    std::thread processThread(processData);

    // Main thread continues execution
    std::cout << "Main thread is free to do other work..." << std::endl;

    // Wait for the threads to finish
    downloadThread.join();
    processThread.join();

    std::cout << "All tasks completed!" << std::endl;
    return 0;
}
