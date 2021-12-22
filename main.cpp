#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <stdexcept>
#include "Graph.h"
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int A[10][10] = {{0,8,9,9,0,0,0,0,0,18},
                     {8,0,0,9,8,0,7,0,9,10},
                     {9,0,0,3,0,6,0,0,0,0},
                     {9,9,3,0,2,4,0,0,0,0},
                     {0,8,0,2,0,2,9,0,0,0},
                     {0,0,6,4,2,0,9,0,0,0},
                     {0,7,0,0,9,9,0,4,5,0},
                     {0,0,0,0,0,0,4,0,1,4},
                     {0,9,0,0,0,0,5,1,0,3},
                     {18,10,0,0,0,0,0,4,3,0}}; //проверка для остовного дерева
    Graph graph(A, false);
    //строим дерево ЗАДАНИЕ 3.1
    Tree tree = graph.find_MST();
    std::vector<int> answer;
    //запускаем левосторонний обход в глубину ЗАДАНИЕ 3.2
    tree.left_depth(answer);
    std::cout << "Левосторонний обход дерева:\n";
    for (int i = 0; i < answer.size(); i++){
        std::cout << answer[i] << ' ';
    }
    std::cout << '\n';
    answer.clear();
    //запускаем поиск расстояний от 0 вершины до остальных ЗАДАНИЕ 3.3
    answer = graph.find_shortest_ways(0);
    std::cout << "Наименьшее растояние от первой: \n";
    for (int i = 0; i < answer.size(); i++) std::cout << "До " << i+1 << " вершины: " << answer[i] << '\n';
    //задание 3.4
    std::cout << "Средняя степень по дереву: " << tree.avg_inc_left_breadth() << '\n';
    //полностью корректная работа алгоритма будет только при создании фиктивных связей
    Graph graph2 = Graph(A, true);
    //задание 4.1
    std::cout << "Максимальный поток: " << graph2.max_flow_problem(0, 9) << '\n';
    //задание 4.3
    answer = graph.colorized();
    for (int i = 0; i < answer.size(); i++) std::cout  << i+1 << " Вершина раскрашена в цвет " << answer[i] << '\n';
    //задание 4.4
    std::vector<int> gamiltone_route = graph.find_gamiltione_route();
    if (gamiltone_route.empty()){
        std::cout << "Гамильтонов путь не существует в этом графе. ";
    }
    else {
        std::cout << "Гамильтонов путь: ";
        for (int i = 0; i < gamiltone_route.size(); i++) std::cout << gamiltone_route[i] << ' ';
    }
}
