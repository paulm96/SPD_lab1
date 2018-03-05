#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

//int Cmax(int **array, int tasks, int mach) {
//    std::vector<int> machines;
//    for (int i = 0; i < mach; i++) {
//        machines.push_back(0);
//    }
//
//    for (int j = 0; j < tasks; j++) {
//        machines[0] += array[j][0];
//        for (int i = 0; i < mach - 1; i++) {
//            if (machines[i] >= machines[i + 1]) {
//                machines[i + 1] = machines[i] + array[j][i + 1];
//            } else {
//                machines[i + 1] = machines[i + 1] + array[j][i + 1];
//            }
//        }
//    }
//    return machines[mach - 1];
//}
//
//
//void perm(int &min, int **result_array, int **array, const int &tasks, const int &machines, int k) {
//    if (k == 1) {
//        int value = Cmax(array, tasks, machines);
//        if (value < min) {
//            min = value;
//            //std::copy(&array[0][0], &array[0][0] + tasks * machines, &result_array[0][0]);
//        }
//
//    } else {
//        for (int i = 0; i < k; ++i) {
//            std::swap(array[i], array[k]);
//            perm(min, result_array, array, tasks, machines, k - 1);
//            std::swap(array[i], array[k]);
//        }
//    }
//}
//



struct Task {
    int task_id;
    int fullTime;

    Task(int task_id, int time)
            : task_id(task_id), fullTime(time) {
    }
};

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

//    int result = std::numeric_limits<int>::max();   //max_int
//    perm(result, result_array, array, tasks, machines, tasks - 1);  //all permutations

    //  std::cout << "Result: " << result << std::endl;
/*   for (int i = 0; i < tasks; ++i) {
       for (int j = 0; j < machines; ++j) {
           std::cout << result_array[i][j] << " ";
        }
        std::cout << std::endl;
    }*/


    return 0;
}