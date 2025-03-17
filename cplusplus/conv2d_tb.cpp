#include <iostream>
using namespace std;


int conv2d(int *arr1, int row_size, int col_size, int *kernel, int krow_size, int kcol_size, int *output) {
    int orow_size = row_size - krow_size + 1;
    int ocol_size = col_size - kcol_size + 1;

    for (int i = 0; i < orow_size; i++) 
    {
        for (int j = 0; j < ocol_size; j++) 
        {

            output[i * ocol_size + j] = 0;
            cout << "i = " << i << ", j = " << j << endl;
            for (int m = 0; m < krow_size; m++) 
            {
                conv2d_label0:for (int n = 0; n < kcol_size; n++) 
                {
                    int flipped_m = krow_size - 1 - m;
                    int flipped_n = kcol_size - 1 - n;

                    cout << "The array value is " << arr1[(i + m) * col_size + (j + n)] << endl;
                    output[i * ocol_size + j] += arr1[(i + m) * col_size + (j + n)] * kernel[flipped_m * kcol_size + flipped_n];
                }
            }
            cout << endl;
        }
    }
    return 0;
}

// int conv2d(int *,int ,int ,int *,int ,int ,int *);
int main() 
{

    int in[4][4] = 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 1, 2},
        {1, 1, 1, 1}
    };


    int kernel[2][2] = 
    {
        {1, 2},
        {1, 1}
    };


    int row_size = sizeof(in) / sizeof(in[0]);
    int col_size = sizeof(in[0]) / sizeof(in[0][0]);
    int krow_size = sizeof(kernel) / sizeof(kernel[0]);
    int kcol_size = sizeof(kernel[0]) / sizeof(kernel[0][0]);


    int output_rows = row_size - krow_size + 1;
    int output_cols = col_size - kcol_size + 1;
    int output[output_rows][output_cols];

    for(int i = 0; i < 5; i++)
    {
    	cout << in[i] << endl;
    }

    conv2d((int *)in, row_size, col_size, (int *)kernel, krow_size, kcol_size, (int *)output);

    cout << "Output Matrix:" << endl;
    for (int i = 0; i < output_rows; i++) 
    {
        for (int j = 0; j < output_cols; j++) 
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}