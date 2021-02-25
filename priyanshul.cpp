#include <bits/stdc++.h>
using namespace std;

struct st {

    int B;
    int E;
    int L;
};

struct ca {

    int P;
    vector<string> streetName;
};

int main() {

    int D, I, S, V, F;
    cin >> D >> I >> S>> V>> F;

    //cout << "D is: " << D << endl;

    int B, E, L;

    unordered_map<string, st> street;

    unordered_map<int, vector<string>> intersection;

    for (int i = 0; i < S; ++i) {

        string name;
        cin >> B >> E >> name >> L;
        st temp = {B, E, L};
        street[name] = temp;

        intersection[E].push_back(name);
    }

    vector<ca> car(V);

    //int time[V];
    unordered_map<string, int> traffic;

    for (int i = 0; i < V; ++i) {

        //time[i] = 0;

        cin >> car[i].P;

        for (int j = 0; j < car[i].P; ++j)
        {
            string s;
            cin >>s;
            traffic[s]++;
            //time[i] += street[s].L;
        }
    }

    //Start output here
    cout << I << endl;

    for (int i = 0; i < I; ++i) {

        cout << i << endl;
        cout << "1" << endl;

        string maxStreet;
        int maxCars = INT_MIN;

        for (auto it = intersection[i].begin(); it != intersection[i].end(); ++it) {

            if (traffic[*it] > maxCars) {

                maxCars = traffic[*it];
                maxStreet = *it;
            }
        }

        cout << maxStreet << " " << D << endl;
    }

    //sort(time, time + V);

    //cout << "Max time: " << time[V-1] << endl;
}
