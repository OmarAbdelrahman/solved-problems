#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define size(A) ((int)A.size())

int numberOfPoints;
double g_max = INT_MAX;
vector<double> g_distances;
vector<pair<int, int> > g_pointsToShow;
vector<double> g_distanceShow;

vector<double> getDistances(vector<pair<int, int> >&);
void backTrack(vector<pair<int, int> >&, vector<pair<int, int> >&, vector<bool>&, int);
void Display(int&);

int main() {
	pair<int, int> Point;
	vector<pair<int, int> > pointsEntered;
	vector<pair<int, int> > combinations;
	vector<bool> taken(8, false);
	for (int networkNumber = 1; cin >> numberOfPoints && numberOfPoints != 0; networkNumber++) {
		g_pointsToShow.resize(numberOfPoints);
		g_distanceShow.resize(numberOfPoints - 1);
		g_distances.resize(numberOfPoints - 1);
		combinations.resize(numberOfPoints);
		pointsEntered.resize(numberOfPoints);
		for (int i = 0; i < size(pointsEntered); i++) {
			cin >> Point.first >> Point.second;
			pointsEntered[i] = Point;
		}
		backTrack(pointsEntered, combinations, taken, 0);
		Display(networkNumber);
	}
	return 0;
}

void backTrack(vector<pair<int, int> >& p_points, vector<pair<int, int> >& p_combinations, vector<bool>& p_taken, int index) {
	if (index == size(p_combinations)) {
		double distanceSum = 0;
		g_distances = getDistances(p_combinations);
		for (int i = 0; i < size(g_distances); i++) 
			distanceSum += g_distances[i];
		if (distanceSum < g_max) {
			g_max = distanceSum;
			g_distanceShow = g_distances;
			g_pointsToShow = p_combinations;
		}
	}
	else for (int i = 0; i < size(p_points); i++) {
		if (!p_taken[i]) {
			p_combinations[index] = p_points[i];
			p_taken[i] = true;
			backTrack(p_points, p_combinations, p_taken, index + 1);
			p_taken[i] = false;
		}
	}
}

vector<double> getDistances(vector<pair<int, int> >& p_combinations) {
	double X, Y;
	for (int i = 0; i < size(p_combinations) - 1; i++) {
		X = (double)p_combinations[i].first - (double)p_combinations[i + 1].first;
		Y = (double)p_combinations[i].second - (double)p_combinations[i + 1].second;
		g_distances[i] = sqrt((X * X) + (Y * Y));
	}
	return g_distances;
}

void Display(int &p_network) {
	cout << "**********************************************************" << endl;
	cout << "Network #" << p_network << endl;
	for (int i = 0; i < size(g_distanceShow); i++) {
		cout << "Cable requirement to connect (" << g_pointsToShow[i].first << "," << g_pointsToShow[i].second << ") to ("
			 << g_pointsToShow[i + 1].first << "," << g_pointsToShow[i + 1].second << ") is " << setiosflags(ios::fixed)
			 << setprecision(2) << g_distanceShow[i] + 16 << " feet." << endl;
	}
	cout << "Number of feet of cable required is " << g_max + (16 * size(g_distances)) << "." << endl;
}