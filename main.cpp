#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

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
//                std::cout << machines[i+1] << std::endl;
            }
        }
    }
    return machines[2];
}

bool compare(std::vector<int> & lhs, std::vector<int> &lhs2){
    return lhs[1]<lhs2[1];
}

int main() {
    std::vector<int> vec = {1,3};
    std::vector<int> vec2 = {2,6};
    std::vector<std::vector<int> > xd;
    xd.push_back(vec);
    xd.push_back(vec2);
    std::sort(xd.begin(),xd.end(),compare);
//    std::ifstream in;
//    in.open("./NEH1.DAT", std::ios::in);
//    if(in.good())
//        std::cout << "Opened succesfully";
//
//
//    std::string s;
//    std::getline(in,s);
//    std::istringstream ss(s);
//
//
//    int temp, tasks, machines;
//    ss >> tasks;
//    ss >> machines;
//
//    int **problem = new int*[tasks];
//    for(auto i = 0; i<tasks ; ++i) {
//        problem[i] = new int[machines];
//    }
//
//    std::vector<int> num;
//    while(std::getline(in,s)) {
//        std::istringstream pyk(s);
//        for (int i = 0; i < machines; ++i) {
//            pyk >> temp;
//            num.push_back(temp);
//        }
//    }
//
//    for(auto i:num)
//        std::cout << i;



    //~~~~~~~Z LAB
//
//    for(int i = 0; i<tasks; ++i)
//        for(int j = 0; j<machines; ++machines)
//            in >> problem[i][j];


//    int tab[6][3] = {{1, 5, 7},
//                     {4, 5, 3},
//                     {1, 4, 8},
//                     {7, 3, 9},
//                     {3, 6, 9},
//                     {4, 7, 6}};
//
//    auto result = Cmax(tab);
//    std::cout << result;
//
    getchar();
    return 0;
}