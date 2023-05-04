#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Foo{
    int x;

    public: 
        Foo(int x = 0){
            this->x = x;
        }

        int bar(int y){
            Foo F;
            return y;
        }
};
int main(){
    // std::cerr << "Press Enter to Continue!";
    // std::getchar();

    time_t ttime = time(0);
    cout << "Number of seconds elapsed since January 1, 1990:" << ttime << endl;
    tm *local_time = localtime(&ttime);

    //year
    cout << "Year: "<< 1900 + local_time->tm_year << endl;

    cout << "Month: "<< 1 + local_time->tm_mon<< endl;
    cout << "Day: "<< local_time->tm_mday << endl;

    // cout << "Hour: "<< 1 + local_time->tm_hour << endl;
    // cout << "Minute: "<< 1 + local_time->tm_min << endl;
    // cout << "Second: "<< 1 + local_time->tm_sec << endl;

    cout << "Time: "<< local_time->tm_hour << ":";
    cout << local_time->tm_min << ":";

    cout << 1 + local_time->tm_sec << endl;

    int curr_yr = 1900 + local_time->tm_year;
    int curr_month = 1 + local_time->tm_mon;
    int curr_day = local_time->tm_mday;

    // 2023 
    int travelDate = 15022023;
    int travel_yr = travelDate%10000;
    int travel_month = (travelDate/10000)%100;
    int travel_day = (travelDate/1000000)%100;

    // int travelDateDiff = (travel_yr - curr_yr)*365 + (travel_month - curr_month)*30 + (travel_day - curr_day); 
    // cout << travelDateDiff;

    // vector<int> a;

    // a.push_back(1);
    // a.push_back(2);
    // a.push_back(3);
    // a.push_back(4);
    // a.push_back(5);

    // int x = a[a.size() - 1];
    // a.pop_back();
    // cout << x << endl;

    // for(int i = 0; i < a.size(); i++){
    //     cout << a[i] << " ";
    // }

    // string a = to_string(18032023);
    // string b = to_string(18032023);
    // hash<string> hash_obj;
    // hash<string> ok;
    // // string k = ha/sh_obj(a);

    // auto k = hash_obj(a);
    // auto l = ok(b);
    // cout << k << "\n" << l;

    vector<int*> a;
    int x = 10;

    a.push_back(&x);
    
    *(a[0]) = *(a[0]) + 2;
    cout << x << endl;

    map<int, vector<int>> m;
    m[100000].push_back(20);

    cout << m[100000][0];

    static map<string, double> a1; 
    a1["hello"] = 2;
}