#include<bits/stdc++.h>
using namespace std;

//better code
bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int flowerbed_size = flowerbed.size();
        if(n == 0)
            return true;
        for (int i=0; i < flowerbed_size; i++)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1]==0) && (i == flowerbed_size - 1 || flowerbed[i + 1] == 0))
            {
                i++;
                n--;
            }
            if(n == 0)
                return true;
        }
        return false;
    }

// //first code
// int main()
// {
//     bool can_place_flower;
//     vector<int> flowerbed = {0, 1, 0};
//     int n = 1;
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < flowerbed.size(); j++)
//         {
//             if (flowerbed.size() > 1)
//             {
//                 if(j == 0 && flowerbed[j] == 0)
//                 {
//                     if(flowerbed[j + 1] == 0)
//                     {
//                         flowerbed[j] = 1;
//                         count++;
//                         break;
//                     }
//                 }
//                 if(j == flowerbed.size() - 1  && flowerbed[j] == 0)
//                 {
//                     if(flowerbed[j - 1] == 0)
//                     {
//                         flowerbed[j] = 1;
//                         count++;
//                         break;
//                     }
//                 }
//                 if (j > 0 && j < flowerbed.size() - 1 && flowerbed[j] == 0 && flowerbed[j + 1] == 0 && flowerbed[j - 1] == 0)
//                 {
//                     flowerbed[j] = 1;
//                     count++;
//                     break;
//                 }
//             }
//             else if(flowerbed.size() == 1)
//             {
//                 if(flowerbed[j] == 0)
//                 count++;
//                 flowerbed[j] = 1;
//                 break;
//             }
//         }
//     }
//     can_place_flower = count == n;
//     cout << count << " " << can_place_flower;
//     return 0;
// }