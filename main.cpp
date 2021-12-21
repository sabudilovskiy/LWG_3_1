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
                     {18,10,0,0,0,0,0,4,3,0}}; //�������� ��� ��������� ������
    Graph graph(A, false);
    //������ ������
    Tree tree = graph.find_MST();
    std::vector<int> answer;
    //��������� ������������� ����� � �������
    tree.left_depth(answer);
    std::cout << "������������� ����� ������:\n";
    for (int i = 0; i < answer.size(); i++){
        std::cout << answer[i] << ' ';
    }
    std::cout << '\n';
    answer.clear();
    //��������� ����� ���������� �� 0 ������� �� ���������
    answer = graph.find_shortest_ways(0);
    std::cout << "���������� ��������� �� ������: \n";
    for (int i = 0; i < answer.size(); i++) std::cout << "�� " << i+1 << " �������: " << answer[i] << '\n';
    std::cout << "������� ������� �� ������: " << tree.avg_inc_left_breadth() << '\n';
    //��������� ���������� ������ ��������� ����� ������ ��� �������� ��������� ������
    Graph graph2 = Graph(A, true);
    std::cout << "������������ �����: " << graph2.max_flow_problem(0, 9) << '\n';
    answer = graph.colorized();
    for (int i = 0; i < answer.size(); i++) std::cout  << i+1 << " ������� ���������� � ���� " << answer[i] << '\n';
}
