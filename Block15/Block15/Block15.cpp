#include <iostream>
#include <vector>
using namespace std;

// Функция расчета слоя параметра
void calculateLayer(const vector<double>& prev_layer, vector<double>& next_layer, double boundary_condition) {
    for (size_t i = 0; i < prev_layer.size(); i++) {
        if (i == 0) {
            next_layer[i] = boundary_condition; // Граничное условие
        }
        else {
            next_layer[i] = prev_layer[i - 1]; // Расчет слоя на основе предыдущего
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

    vector<double> ro_0(n, ro_a); // Начальный слой плотности
    vector<double> ro_1(n);       // Конечный слой плотности
    vector<double> s_0(n, s_a);   // Начальный слой содержания серы
    vector<double> s_1(n);        // Конечный слой содержания серы

    // Вывод заголовков таблицы
    cout << "t";
    for (int i = 0; i < n; i++) {
        cout << "\tx" << i << "_density\tx" << i << "_sulfur";
    }
    cout << endl;

    for (int t = 0; t < N; t++) {
        // Расчет слоя плотности
        calculateLayer(ro_0, ro_1, ro_b);

        // Расчет слоя содержания серы
        calculateLayer(s_0, s_1, s_b);

        // Вывод результатов для текущего момента времени
        cout << t;
        for (int i = 0; i < n; i++) {
            cout << "\t" << ro_1[i] << "\t" << s_1[i];
        }
        cout << endl;

        // Обновление слоев для следующего временного шага
        ro_0 = ro_1;
        s_0 = s_1;
    }

    return 0;
}