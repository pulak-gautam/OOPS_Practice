#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N = 100;
class Foo{
    int x;

    public: 
        static vector<Foo*> list;
        Foo(int x = 0){
            this->x = x;
            list.push_back(this);
        }

        int bar(int y){
            Foo F;
            return y;
        }

        int getX(){
            return this->x;
        }
};
vector<Foo*> Foo::list;
int main(){
    // Foo::list.reserve(N);

    Foo f(2);
    for(int i = 0; i < Foo::list.size(); i++){
        cout << ((Foo::list)[0])->getX() << endl;
    }

    vector<int> a;
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }
}