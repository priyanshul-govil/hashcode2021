#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

#define int long long

struct st {

    int B;
    int E;
    int L;
};

struct ca {

    int P;
    vector<string> streetName;
};

bool comp(pair<int, int> p1, pair<int, int> p2) {

    return p1.second > p2.second;
}

signed main() {

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



    ca car[V];

    int carShortest;
    unordered_map<string, int> traffic;


    vector<pair<int, int>> time(V);

// FINE TILL HERE

    


    for (int i = 0; i < V; ++i) {

        cin >> car[i].P;
        int timeTaken = 0;
        for (int j = 0; j < car[i].P; ++j)
        {
            string s;
            cin >> s;
            traffic[s]++;
            timeTaken += street[s].L;
            car[i].streetName.push_back(s);
        }


        pair<int, int> temp = make_pair(i, timeTaken);
        time[i] = temp;
    }



    int carsInFront[V];

    for (int i = V - 1; i >= 0; --i) {

        carsInFront[i] = 0;

        string streetName = car[i].streetName[0];

        for (int j = i - 1; j >= 0; --j) {

            if (car[j].streetName.size() == 0) {

                continue;
            }

            if (car[j].streetName[0].compare(streetName) == 0) {

                carsInFront[i]++;
            }
        }
    }

    
    for (int i = 0; i < V; ++i) {

        time[i].second += carsInFront[i];
    }


    //sort(time.begin(), time.end(), comp);

    
/*
    for (int i = 0; i < V; ++i) {

        if (time[i].second <= D) {

            carShortest = time[i].first;
            break;
        }
    }*/

    carShortest = abs((int)cos(V)) * V;

    vector<string> STREETS = car[carShortest].streetName;

    unordered_map<int, string> result;

    for (auto& it: STREETS) {

        int node = street[it].E;

        if (result.find(node) == result.end()) {

            result[node] = it;
        }
    }



    for (int i = 0; i < I; ++i) {

        if (result.find(i) != result.end()) {

            continue;
        }

        string maxStreet;
        int maxCars = INT_MAX;

        for (auto it = intersection[i].begin(); it != intersection[i].end(); ++it) {

            if (traffic[*it] <= maxCars) {

                maxCars = traffic[*it];
                maxStreet = *it;
            }
        }

        result[i] = maxStreet;

    }

    // OUTPUT STARTS HERE   

    cout << I << endl;

    for (int i = 0; i < I; ++i) {

        cout << i << endl;
        cout << "1" << endl;
        cout << result[i] << " " << D << endl;
    }

}
