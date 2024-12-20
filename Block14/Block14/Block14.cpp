#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI 3.141592653589793

//Функция расчета площади поперечного сечения
double calculateCrossSectionArea(double d) {
    return PI * pow(d / 2, 2);
}

int main() {
    double length_pipeline = 100 * 1000;
    int n = 5;
    double d = 1;
    double dx = length_pipeline / (n - 1); // Длина одного участка

    vector<double> densities = { 850, 860, 870 };
    vector<int> time_steps = { 1, 2, 3 };

    double crossSectionArea = calculateCrossSectionArea(d);

    cout << fixed << setprecision(2);
    cout << "dx = " << dx << " m\n";
    cout << "S = " << crossSectionArea << " m^2\n\n";

    cout << " number | p (kg/m^3) | V (m^3) | m (kg)\n";

    for (int i = 0; i < densities.size(); i++) {
        double v = crossSectionArea * dx * time_steps[i];
        double m = v * densities[i];

        cout << (i + 1) << "  " << densities[i] << "  " << v << "  " << m << "\n";
    }

    return 0;
}