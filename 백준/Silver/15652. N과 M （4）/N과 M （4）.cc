#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
std::vector<int> vec;
void sequnce(int currentIndex ,int count);

int main() 
{
    std::cin>> n >> m;
    sequnce(1, 0);
    return 0;
}

void sequnce(int currentIndex , int count)
{
    if(count == m)
    {
        for(int data : vec)
            std:: cout << data << " ";
        std::cout << "\n";
        return;
    }

    for(int i = currentIndex; i <= n; i++)
    {
        vec.push_back(i);
        sequnce(i, count + 1);
        vec.pop_back();
    }
        
}