#include <iostream>
#include <vector>
using namespace std;

int main()
{
    double length_pipeline = 100;
    double step_of_grid = 5;
    double r0_a = 850;
    double r0_b = 860;
    vector<double> r0_0(step_of_grid);
    vector<double> r0_1(step_of_grid);
    vector<double> r0_2(step_of_grid);

    for (int i = 0; i <= (step_of_grid - 1); i++)
    {
        r0_0[i] = r0_a;
    }

    for (int i = 0; i <= (step_of_grid - 1); i++)
    {
        if (i == 0)
        {
            r0_1[i] = r0_b;
        }
        else
        {
            r0_1[i] = r0_0[i - 1];
        }
    }

    for (int i = 0; i <= (step_of_grid - 1); i++)
    {
        if (i == 0)
        {
            r0_2[i] = r0_b;
        }
        else
        {
            r0_2[i] = r0_1[i - 1];
        }
    }

    cout << r0_0[0] << " " << r0_0[1] << " " << r0_0[2] << " " << r0_0[3] << " " << r0_0[4] << endl;
    cout << r0_1[0] << " " << r0_1[1] << " " << r0_1[2] << " " << r0_1[3] << " " << r0_1[4] << endl;
    cout << r0_2[0] << " " << r0_2[1] << " " << r0_2[2] << " " << r0_2[3] << " " << r0_2[4] << endl;
    return 0;
}