#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print(const unordered_set<int>& set){
    for (const auto& element: set)
        cout<<element<<" ";
    cout<<endl;
}

void print(const unordered_map<int, int>& map){
    for(const auto& element: map)
        cout<<"["<<element.first<<": "<<element.second<<"] , ";
    cout<<endl;
}

void find(const unordered_set<int>& set, const int& element){
    if(set.find(element) == set.end())
        cout<<element<<" not found"<<endl;
    else
        cout<<element<<" found"<<endl;
}

void find(const unordered_map<int, int>& map, const int& element){
    auto it = map.find(element);
    if (it == map.end())
        cout<<element<<" not found"<<endl;
    else
        cout<<element<<" found with value="<< it->second<<endl;
}

int main() {
    cout<<"Unordered Set example: "<<endl;
    unordered_set<int> set;
    for(int i=1; i<6; i++)
        set.insert(i);

    cout<<"Initial set: ";
    print(set);

    set.insert(6);
    cout<<"After inserting 6: ";
    print(set);

    set.insert(10);
    set.insert(350);
    cout<<"After inserting 10 and 350: ";
    print(set);
    cout<<endl;

    find(set, 4);
    find(set, 100);
    set.erase(2);
    cout<<"Erased 2 from set"<<endl;

    cout<<"Unordered Map example: "<<endl;

    unordered_map<int, int> squareMap;

    squareMap.insert({2, 4});
    squareMap[3]=9;
    cout<<"After inserting squares of 2 and 3 = ";
    print(squareMap);

    squareMap[30]=900;
    squareMap[20]=400;
    cout<<"After inserting squares of 20 and 30 = ";
    print(squareMap);

    find(squareMap, 10);
    find(squareMap, 20);
    cout<<"Value of map[3] = "<<squareMap[3]<<endl;
    cout<<"Value of map[100] = "<<squareMap[100]<<endl;

    return 0;
}
