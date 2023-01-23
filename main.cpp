#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

bool test(vector<char> arr);

int main(){
    vector<char> arr = {'[',']'};
    if(!test(arr))
        cout << "wrong";
    else
        cout << "good";
    return 0;
}


bool test(vector<char> arr){
    stack<char> stacking;
    unordered_map<char, char> table;
    table[']'] = '[';
    table[')'] = '(';
    table['}'] = '{';
    for(int i=0;i<arr.size();i++){
        if(!stacking.empty() && stacking.top()==table[arr[i]]){
            stacking.pop();
        }else
            stacking.push(arr[i]);
    }
    return stacking.empty();
}
