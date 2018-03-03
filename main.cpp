#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int Cmax(int **array, int tasks, int mach) {
    std::vector<int> machines = {0, 0, 0};

    for (int j = 0; j < tasks; j++) {
        machines[0] += array[j][0];
        for (int i = 0; i < mach - 1; i++) {
            if (machines[i] >= machines[i + 1]) {
                machines[i + 1] = machines[i] + array[j][i + 1];
            } else {
                machines[i + 1] = machines[i + 1] + array[j][i + 1];
            }
        }
    }
    return machines[2];
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


    int **array = new int *[tasks];
    for (auto i = 0; i < tasks; ++i) {
        array[i] = new int[machines];
    }

    for (int i = 0; i < tasks ; ++i) {
        std::getline(in, s);
        std::istringstream converter(s);
        for (int j = 0; j < machines; ++j) {
            converter >> array[i][j];
        }
    }

    auto result = Cmax(array, tasks, machines);
    std::cout << result;

    getchar();

    return 0;
}