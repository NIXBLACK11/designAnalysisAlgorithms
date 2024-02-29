#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
const int MAX_R = 5000;
const int INF = 1e9;

int n, N, c, R;
int distanceMatrix[MAX_N][MAX_N];
vector<int> vehicleLocations;
vector<pair<pair<int, int>, pair<int, int>>> passengerRequests;

struct Vehicle {
    vector<int> schedule;
    int revenue;
};

int calculateDistance(int source, int destination) {
    return distanceMatrix[source][destination];
}

int calculateRevenue(int source, int destination) {
    return calculateDistance(source, destination);
}

bool isValidRequest(int vehicleLocation, int requestPickup, int requestDropoff) {
    int distToPickup = calculateDistance(vehicleLocation, requestPickup);
    int distPickupToDropoff = calculateDistance(requestPickup, requestDropoff);
    int distDropoffToNextLocation = INF;

    for (int i = 0; i < N; i++) {
        if (i != vehicleLocation && find(vehicleLocations.begin(), vehicleLocations.end(), i) == vehicleLocations.end()) {
            distDropoffToNextLocation = min(distDropoffToNextLocation, calculateDistance(requestDropoff, i));
        }
    }

    return (distToPickup + distPickupToDropoff + distDropoffToNextLocation <= c);
}

void findBestSchedule(vector<Vehicle>& vehicles, int requestIdx, int revenueSoFar) {
    if (requestIdx == R) {
        return;
    }

    for (int i = 0; i < N; i++) {
        int vehicleLocation = vehicleLocations[i];
        for (int j = requestIdx; j < R; j++) {
            int requestPickup = passengerRequests[j].first.first;
            int requestDropoff = passengerRequests[j].first.second;
            int requestStart = passengerRequests[j].second.first;
            int requestEnd = passengerRequests[j].second.second;

            if (requestStart >= revenueSoFar && isValidRequest(vehicleLocation, requestPickup, requestDropoff)) {
                vehicleLocations[i] = requestDropoff;
                vehicles[i].schedule.push_back(j);
                vehicles[i].revenue += calculateRevenue(requestPickup, requestDropoff);
                findBestSchedule(vehicles, j + 1, revenueSoFar + vehicles[i].revenue);
                vehicles[i].revenue -= calculateRevenue(requestPickup, requestDropoff);
                vehicleLocations[i] = vehicleLocation;
                vehicles[i].schedule.pop_back();
            }
        }
    }
}

int main() {
    cin >> n >> N >> c >> R;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distanceMatrix[i][j];
        }
    }

    vehicleLocations.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vehicleLocations[i];
        vehicleLocations[i]--;
    }

    passengerRequests.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> passengerRequests[i].first.first >> passengerRequests[i].first.second;
        cin >> passengerRequests[i].second.first >> passengerRequests[i].second.second;
        passengerRequests[i].first.first--;
        passengerRequests[i].first.second--;
    }

    vector<Vehicle> vehicles(N);

    findBestSchedule(vehicles, 0, 0);

    int totalRevenue = 0;
    for (int i = 0; i < N; i++) {
        totalRevenue += vehicles[i].revenue;
    }

    cout << "Vehicle Schedules:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Vehicle " << i + 1 << ": ";
        for (int requestIdx : vehicles[i].schedule) {
            cout << "[" << passengerRequests[requestIdx].first.first + 1 << " -> " << passengerRequests[requestIdx].first.second + 1 << "] ";
        }
        cout << endl;
    }

    cout << "Total Revenue: " << totalRevenue << endl;

    return 0;
}
