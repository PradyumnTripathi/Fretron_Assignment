#include <bits/stdc++.h>
using namespace std;


// here i am trying to store the values and distribute to the share holders by comparing the values 

class holders {
public:
    string name;
    int contribution;
    int totalWeight;
    vector<int> apples;
    
    holders(string n, int c) : name(n), contribution(c), totalWeight(0) {}
};

bool descendingOrder(int a, int b) {
    return a > b;
}

bool compareParticipants(holders a, holders b) {
    //comparing the values of participants 
    return a.totalWeight < b.totalWeight;
}

void getAppleWeights(vector<int>& appleWeights) {
    // taking all inputs as the weight 
    int weight;
    cout << "Enter apple weight in gram (-1 to stop): ";
    cin >> weight;
    if (weight != -1) {
        //whenever the input is not -1 it will work in a loop to store the values till the end
        appleWeights.push_back(weight);
        getAppleWeights(appleWeights);
    }
}

int main() {
    vector<int> apple;
    getAppleWeights(apple);
    //successfully pushed the weight values into the appleweights

    holders ram("Ram", 50);
    holders sham("Sham", 30);
    holders rahim("Rahim", 20);
    
    vector<holders> participants = {ram, sham, rahim};
    
    sort(apple.begin(), apple.end(), descendingOrder);
    
   
    
    for (const auto& participant : participants) {
        cout << participant.name << " : ";
        for (int apple : participant.apples) {
            cout << apple << " ";
        }
        cout <<endl;
    }
    
    return 0;
}
