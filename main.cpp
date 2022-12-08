#include "HFVector.cpp"
using namespace std;
int main() {
    HFVector<int>vec(4); //Default constructor - Initialize capacity of vector
    //Push back function
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout<<vec<<endl;//output stream overloading
    cout<<"------------------"<<endl;
    int arr[] = {6,7,8,9};
    //Initialize vector from array with n elements
    HFVector<int>vec2(arr,3);
    cout<<vec2<<endl;
    cout<<"-------------------"<<endl;
    //Initialize vector from a copy using copy constructor
    HFVector<int>vec3(vec2);
    cout<<vec3<<endl;
    cout<<"-------------------"<<endl;

    //Accessing vector elements
    cout<<vec<<endl;
    cout<<"Element at index 0 : "<<vec[0]<<endl;
    cout<<"Element at index 3 : "<<vec[3]<<endl;
    //Testing exceptions
    cout<<"Element at index 10: "<<vec[10]<<endl;
    cout<<"-------------------"<<endl;

    //Testing pop back
    cout<<"Before pop_back: "<<vec<<endl;
    vec.pop_back();
    cout<<"After pop_back: "<<vec<<endl;
    cout<<"------------------"<<endl;

    //Erasing from vector at certain position
    cout<<"Original vector: "<<vec<<endl;
    vec.erase(vec.begin()+2);
    cout<<"Erasing element at index 2 (val=3): "<<vec<<endl;
    //Testing invalid iterator position
    vec.erase(vec.begin()+99);
    cout<<"------------------------"<<endl;

    //Erasing elements from vector between a range
    vec.insert(vec.begin()+2,3);
    vec.push_back(5);
    cout<<"Original vector: "<<vec<<endl;
    vec.erase(vec.begin()+2,vec.begin()+3);
    cout<<"Erasing from index 2 to index 3 : "<<vec<<endl;
    cout<<"------------------"<<endl;
    //Testing clear of vector
    cout<<"Original: "<<vec<<endl;
    vec.clear();
    cout<<"After erase: "<<vec<<endl;
    cout<<"-------------------"<<endl;
    //Testing insert function
    vec.push_back(1);
    vec.push_back(3);
    cout<<"Original: "<<vec<<endl;
    vec.insert(vec.begin()+1,2);
    cout<<"Inserting a value of 2 in it is order: "<<vec<<endl;
    cout<<"---------------------"<<endl;

    //Testing begin() and end()
    cout<<"First element: "<<*vec.begin()<<endl;
    cout<<"Last element: "<<*(vec.end()-1)<<endl;
    cout<<"----------------------"<<endl;

    //Testing comparison operators
    cout<<"Vector 1 : "<<vec<<endl;
    vec2 = vec;
    cout<<"vector 2 : "<<vec2<<endl;
    cout<<"vector 3 : "<<vec3<<endl;
    cout<<vec<<"  ==  "<<vec2 <<"  "<<(vec==vec2?"True":"False")<<endl;
    cout<<vec<<"  ==  "<<vec3 <<"  "<<(vec==vec3?"True":"False")<<endl;
    cout<<vec<<"  <  "<<vec2 <<"  "<<(vec<vec2?"True":"False")<<endl;
    cout<<vec<<"  <  "<<vec3 <<"  "<<(vec<vec3?"True":"False")<<endl;
    cout<<"---------------------"<<endl;

    //Testing Capacity operations
    cout<<"Vector: "<<vec<<endl;
    cout<<"Size: "<<vec.size()<<endl;
    cout<<"Capacity before resize(original): "<<vec.capacity()<<endl;
    vec.resize();
    cout<<"Capacity after  resize          : "<<vec.capacity()<<endl;
    cout<<"Is vector empty?: "<<(vec.empty()?"True":"False")<<endl;
    vec.clear();
    cout<<"Is vector empty?: "<<(vec.empty()?"True":"False")<<endl;
    cout<<"Empty vector: "<<vec<<endl;
    return 0;
}
