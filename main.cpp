#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int Cmax(int tasks[6][3]) {
    std::vector<int> machines = {0, 0, 0};

    for (int j = 0; j < 6; j++) {
            machines[0] += tasks[j][0];
        for (int i = 0; i < 2; i++) {
            if (machines[i] >= machines[i + 1]) {
                machines[i + 1] = machines[i] + tasks[j][i + 1];
            }
            else {
                machines[i + 1] = machines[i + 1] + tasks[j][i + 1];
                std::cout << machines[i+1] << std::endl;
            }
        }
    }
    return machines[2];
}

int main() {
//    std::ifstream in;
//    in.open("./NEH1.DAT", std::ios::in);
//    if(in.good())
//        std::cout << "git";
//
//    std::string s;
//    std::getline(in,s);
//    std::vector<int> num;
//    std::istringstream ss(s);
//
//    int tasks, machines;
//    ss >> tasks;
//    ss >> machines;
//
//    int **problem = new int*[tasks];
//    for(auto i = 0; i<tasks ; ++i)
//        problem[i] = new int[machines];


//    for(int i = 0; i<tasks; ++i)
//        for(int j = 0; j<machines; ++machines)
//            in >> problem[i][j];
//

    int tab[6][3] = {{1, 5, 7},
                     {4, 5, 3},
                     {1, 4, 8},
                     {7, 3, 9},
                     {3, 6, 9},
                     {4, 7, 6}};

    auto result = Cmax(tab);
    std::cout << result;
    getchar();
    return 0;
}