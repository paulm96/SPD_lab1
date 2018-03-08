#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Task {
    int task_id;
    int fullTime;

    Task(int task_id, int time)
            : task_id(task_id), fullTime(time) {
    }
};

int Cmax(int **array, std::vector<Task> taskMeneger, int tasks, int mach) {
    std::vector<int> machines;
    for (int i = 0; i < mach; i++) {
        machines.push_back(0);
    }
    for (int j = 0; j < tasks; j++) {
        machines[0] += array[taskMeneger[j].task_id][0];
        for (int i = 0; i < mach - 1; i++) {
            if (machines[i] >= machines[i + 1]) {
                machines[i + 1] = machines[i] + array[taskMeneger[j].task_id][i + 1];
            } else {
                machines[i + 1] = machines[i + 1] + array[taskMeneger[j].task_id][i + 1];
            }
        }

    }
    return machines[mach - 1];
}


int perm(int **array, const int &tasks, const int &machines, std::vector<Task> tasksMeneger) {
    std::vector<int> times;
    std::vector<Task> tmpArray;
    tmpArray = tasksMeneger;
    int cMax = std::numeric_limits<int>::max();
    for (int i = 0; i < tasks; i++) {
        times.push_back(std::numeric_limits<int>::max());
    }
    int result = 2;

    for (int j = 0; j < tasks - 1; j++) {
        for (int i = result - 1; i >= 0; i--) {
            times[i] = Cmax(array, tasksMeneger, result, machines);

            if (i > 0) {
                std::swap(tasksMeneger[i], tasksMeneger[i - 1]);

            }
            if (i < result - 1 && times[i] < times[i + 1]) std::swap(tmpArray[i + 1], tmpArray[i]);

        }
        tasksMeneger = tmpArray;
        result++;
    }

    for (int i = 0; i < tasks; i++) {
        if (times[i] < cMax)
            cMax = times[i];
    }
    return cMax;
}


std::vector<int> sum(int **array, const int &tasks, const int &machines) {
    std::vector<int> sums;
    int sum = 0;
    for (int i = 0; i < tasks; ++i) {
        for (int j = 0; j < machines; ++j) {
            sum += array[i][j];
        }
        sums.push_back(sum);
        sum = 0;
    }
    return sums;
}


int main() {
    std::ifstream in;
    in.open("./NEH1.DAT", std::ios::in);
    if (in.good())
        std::cout << "Opened succesfully\n";


    std::string s;
    std::getline(in, s);
    std::istringstream ss(s);

    int tasks, machines;
    ss >> tasks;
    ss >> machines;


    int **array = new int *[tasks];    //main array
    for (auto i = 0; i < tasks; ++i) {
        array[i] = new int[machines];
    }
    int **result_array = new int *[tasks];  //array for the result
    for (auto i = 0; i < tasks; ++i) {
        result_array[i] = new int[machines];
    }

    for (int i = 0; i < tasks; ++i) {   //to fill the main array
        std::getline(in, s);
        std::istringstream converter(s);
        for (int j = 0; j < machines; ++j) {
            converter >> array[i][j];
        }
    }


    std::vector<int> sums;
    sums = sum(array, tasks, machines);

    //  for(auto i:sums)
    //      std::cout << i << " ";

    std::vector<Task> tasksMeneger;
    for (int i = 0; i < tasks; ++i) {
        tasksMeneger.emplace_back(i, sums[i]);
    }
    std::sort(tasksMeneger.begin(), tasksMeneger.end(), [](Task a, Task b) -> int {
        return a.fullTime > b.fullTime;
    });

    for (auto i:tasksMeneger)
        std::cout << i.fullTime << " " << i.task_id << std::endl;

    int cMax = perm(array, tasks, machines, tasksMeneger);
    std::cout << "cMax = " << cMax << std::endl;


/*   for (int i = 0; i < tasks; ++i) {
       for (int j = 0; j < machines; ++j) {
           std::cout << result_array[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    for (auto i = 0; i < tasks; ++i) {
        delete[] array[i];
        delete result_array[i];
    }
    delete[]array;
    delete[]result_array;

    return 0;
}