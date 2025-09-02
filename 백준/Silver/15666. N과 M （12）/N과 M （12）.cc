#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
std::vector<int> vec;
std::vector<int> vec2;
void sequnce(int currentIndex ,int count);

int main() 
{
    std::cin>> n >> m;
    for(int i = 0; i < n; i++)
    {
        int input;
        std:: cin >> input;
        vec.push_back(input);
    }    

    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    sequnce(0, 0);
    return 0;
}

void sequnce(int currentIndex , int count)
{
    if(count == m)
    {
        for(int data : vec2)
            std:: cout << data << " ";
        std::cout << "\n";
        return;
    }

    for(int i = currentIndex; i < vec.size(); i++)
    {
        vec2.push_back(vec[i]);
        sequnce(i, count + 1);
        vec2.pop_back();
    }
        
}