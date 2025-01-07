#include<stdio.h>
#include<math.h>
#define pi 3.14
#define myu 9*pow(10,9)
int main()
{
    int inductance[3][3];
    float dist,radius;
    printf("Enter the distance between the transmission lines\n");
    scanf("%f",&dist);
    printf("Enter the radius of the transmission lines\n");
    scanf("%f",&radius);
    float num=(log(dist/0.7788*radius));
    float constant=((myu*num)/(2*pi));
    printf("The inductance matrix is\n");
    for (int i=0;i<3;i++)
    {
        for ( int j=0;j<3;j++)
        {
            if (i==j)
            {
            printf("%.2f ",constant);
            continue;
            }
        printf("0  ");
        }
        printf("\n");
    }
    return 0;
}