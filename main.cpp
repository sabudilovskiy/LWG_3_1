#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <stdexcept>
#include "Graph.h"
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int A[12][12] = {
            { 0, 1, 4, 4, 8, 5, 6, 7, 5, 2, 4, 2 },
            { 1, 0, 6, 9, 1, 2, 3, 1, 2, 8, 9, 5 },
            { 4, 6, 0, 7, 4, 8, 9, 6, 2, 6, 7, 6 },
            { 4, 9, 7, 0, 2, 0, 0, 8, 8, 8, 7, 8 },
            { 8, 1, 4, 2, 0, 3, 9, 2, 7, 7, 3, 1 },
            { 5, 2, 8, 0, 3, 0, 0, 6, 4, 4, 5, 3 },
            { 6, 3, 9, 0, 9, 0, 0, 2, 2, 9, 2, 3 },
            { 7, 1, 6, 8, 2, 6, 2, 0, 7, 4, 2, 6 },
            { 5, 2, 2, 8, 7, 4, 2, 7, 0, 3, 4, 6 },
            { 2, 8, 6, 8, 7, 4, 9, 4, 3, 0, 3, 4 },
            { 4, 9, 7, 7, 3, 5, 2, 2, 4, 3, 0, 7 },
            { 2, 5, 6, 8, 1, 3, 3, 6, 6, 4, 7, 0 },
    };
    //�������� ��� ��������� ������
    Graph graph(A, false);
    //������ ������ ������� 3.1
    Tree tree = graph.find_MST();
    std::vector<int> answer;
    //��������� ������������� ����� � ������� ������� 3.2
    tree.left_depth(answer);
    std::cout << "������������� ����� ������:\n";
    for (int i = 0; i < answer.size(); i++){
        std::cout << answer[i] << ' ';
    }
    std::cout << '\n';
    answer.clear();
    //��������� ����� ���������� �� 0 ������� �� ��������� ������� 3.3
    answer = graph.find_shortest_ways(0);
    std::cout << "���������� ��������� �� ������: \n";
    for (int i = 0; i < answer.size(); i++) std::cout << "�� " << i+1 << " �������: " << answer[i] << '\n';
    //������� 3.4
    std::cout << "������� ������� �� ������: " << tree.avg_inc_left_breadth() << '\n';
    //��������� ���������� ������ ��������� ����� ������ ��� �������� ��������� ������
    Graph graph2 = Graph(A, true);
    //������� 4.1
    std::cout << "������������ �����: " << graph2.max_flow_problem(0, 9) << '\n';
    //������� 4.3
    answer = graph.colorized();
    for (int i = 0; i < answer.size(); i++) std::cout  << i+1 << " ������� ���������� � ���� " << answer[i] << '\n';
    //������� 4.4
    std::vector<int> gamiltone_route = graph.find_gamiltione_route();
    if (gamiltone_route.empty()){
        std::cout << "����������� ���� �� ���������� � ���� �����. ";
    }
    else {
        std::cout << "����������� ����: ";
        for (int i = 0; i < gamiltone_route.size(); i++) std::cout << gamiltone_route[i] << ' ';
    }
}
