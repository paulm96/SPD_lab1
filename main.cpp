#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Task {
    int task_id;
    int fullTime;
    std::vector<int> tasksOnMachines;   //vector.size is the amount of machines

    Task(int task_id, int time)
            : task_id(task_id), fullTime(time) {
    }
};

std::vector<Task> loadFromFile(const std::string &file) {
    std::ifstream in;
    in.open(file, std::ios::in);
    if (in.good())
        std::cout << "Opened succesfully\n";

    std::string s;
    std::getline(in, s);
    std::istringstream ss(s);

    int tasks, machines;
    ss >> tasks;
    ss >> machines;
    int tmp;

    std::vector<Task> taskVector;
    for (int i = 0; i < tasks; ++i) {   //to fill taskVector
        std::getline(in, s);
        std::istringstream converter(s);
        Task task(i, 0);
        for (int j = 0; j < machines; ++j) {
            converter >> tmp;
            task.fullTime += tmp;
            task.tasksOnMachines.push_back(tmp);
        }
        taskVector.push_back(task);
    }
    return taskVector;
}

int Cmax(const std::vector<Task>& taskVector) {
    std::vector<int> timeOnMachines;
    auto machines = taskVector[0].tasksOnMachines.size();
    for (int i = 0; i < machines; ++i) {
        timeOnMachines.push_back(0);
    }

    for (auto task : taskVector) {
        timeOnMachines[0] += task.tasksOnMachines[0];
        for (int i = 0; i < machines - 1; i++) {
            if (timeOnMachines[i] >= timeOnMachines[i + 1]) {
                timeOnMachines[i + 1] = timeOnMachines[i] + task.tasksOnMachines[i + 1];
            } else {
                timeOnMachines[i + 1] = timeOnMachines[i + 1] + task.tasksOnMachines[i + 1];
            }
        }
    }
    return timeOnMachines[machines - 1];
}

int permutation(const std::vector<Task>& taskVector) {
    std::vector<int> times(taskVector.size());
    std::fill(times.begin(), times.end(), 0);   //to fill the 'times' vector with 0s

    std::vector<Task> tmpArray;
    int index = 0;
    int minTime = std::numeric_limits<int>::max();  //max_int for a large value to compare with

    tmpArray.push_back(taskVector[0]);  //two first tasks
    tmpArray.push_back(taskVector[1]);

    for (int j = 0; j < taskVector.size() - 1; j++) {
        for (auto i = static_cast<int>(tmpArray.size() - 1); i >= 0; i--) {
            times[i] = Cmax(tmpArray);
            if (i > 0) std::swap(tmpArray[i], tmpArray[i - 1]);
        }
        for (int i = 0; i < tmpArray.size(); i++) {
            if (times[i] < minTime) {
                minTime = times[i];
                index = i;
            }
        }
        minTime = std::numeric_limits<int>::max();
        for (int i = 0; i < index; i++)
            std::swap(tmpArray[i], tmpArray[i + 1]);

        if (j < taskVector.size() - 2) tmpArray.push_back(taskVector[tmpArray.size()]);
    }
    return times[index];
}

int main() {
    auto taskVector = loadFromFile("./NEH5.DAT");   //vector with tasks loaded from a file

    std::sort(taskVector.begin(), taskVector.end(),            //sort tasks because of their fulltime
              [](const Task& a, const Task& b) -> bool {
                  return a.fullTime > b.fullTime;
              });

    std::cout << "Cmax = " << permutation(taskVector) << std::endl;
    return 0;
}