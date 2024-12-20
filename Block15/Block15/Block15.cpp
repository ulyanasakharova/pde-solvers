#include <iostream>
#include <vector>
using namespace std;

// ������� ������� ���� ���������
void calculateLayer(const vector<double>& prev_layer, vector<double>& next_layer, double boundary_condition) {
    for (size_t i = 0; i < prev_layer.size(); i++) {
        if (i == 0) {
            next_layer[i] = boundary_condition; // ��������� �������
        }
        else {
            next_layer[i] = prev_layer[i - 1]; // ������ ���� �� ������ �����������
        }
    }
}

int main() {
    double length_pipeline = 100 * 1000;
    int n = 5;
    double ro_a = 850;
    double ro_b = 860;
    double s_a = 0.5;
    double s_b = 0.8;
    int N = 10;

    vector<double> ro_0(n, ro_a); // ��������� ���� ���������
    vector<double> ro_1(n);       // �������� ���� ���������
    vector<double> s_0(n, s_a);   // ��������� ���� ���������� ����
    vector<double> s_1(n);        // �������� ���� ���������� ����

    // ����� ���������� �������
    cout << "t";
    for (int i = 0; i < n; i++) {
        cout << "\tx" << i << "_density\tx" << i << "_sulfur";
    }
    cout << endl;

    for (int t = 0; t < N; t++) {
        // ������ ���� ���������
        calculateLayer(ro_0, ro_1, ro_b);

        // ������ ���� ���������� ����
        calculateLayer(s_0, s_1, s_b);

        // ����� ����������� ��� �������� ������� �������
        cout << t;
        for (int i = 0; i < n; i++) {
            cout << "\t" << ro_1[i] << "\t" << s_1[i];
        }
        cout << endl;

        // ���������� ����� ��� ���������� ���������� ����
        ro_0 = ro_1;
        s_0 = s_1;
    }

    return 0;
}