#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void push(vector<int>& sequence, vector<int>& stack_s, int input, string& output);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string output;
    int input, n;//입력 / 수열의 수

    cin >> n;
    vector<int> sequence;
    vector<int> stack_s;
    for (int i = n; i >= 1; i--)
    {
        stack_s.push_back(i);
    }


    int stateNum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        
        if (sequence.empty()) stateNum = 0;
        else stateNum = sequence.back();
        
        if (stateNum > input) { cout << "NO"; return 0;} //더 이상 수열 진행 불가능

        //push
        if (stateNum < input)
        {
            push(sequence, stack_s, input, output);
        }

        stateNum = sequence.back();

        //pop
        if(stateNum == input) 
        {
            sequence.pop_back();
            output += "-\n";
        }
        
    }

    cout << output;
    


    return 0;
}

void push(vector<int>& sequence, vector<int>& stack_s, int input, string& output)
{
    while(input >= stack_s.back())
    {
        sequence.push_back(stack_s.back());
        stack_s.pop_back();
        output += "+\n";
        if (stack_s.empty()) {return; }
    }
}


