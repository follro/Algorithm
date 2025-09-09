#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> vec;

void select(int start, int sum);

int main() 
{
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int sum = 0;

    for(int i = 0; i < 9; i++)
    {
        int a;
        std::cin >> a;
        vec.push_back(a);
        sum += a;
    }

    std::sort(vec.begin(), vec.end());

    std::vector<int>::iterator sit = vec.begin();
    std::vector<int>::iterator eit = vec.end() - 1;

    while(sit !=  vec.end() - 1)
    {
        while(sit != eit)
        {
            if((sum - *sit - *eit) == 100 )
            {
                *sit = 0;
                *eit = 0;
                for(int a : vec)
                {
                    if(a != 0)
                        std::cout << a << "\n";
                }
                return 0;
            }
            --eit;
        }
        eit = vec.end()-1;
        ++sit;
    }

}









