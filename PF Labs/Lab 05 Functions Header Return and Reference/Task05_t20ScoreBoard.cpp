#include <iostream>
using namespace std;
 
void ballsToOvers(int balls, int &overs, int &extra);
double runRate(int runs, int balls);
int runsNeeded(int target, int runs);
double requiredRate(int needed, int ballsLeft);
void showScore(int runs, int wickets, int overs, int extra);
int oversToBalls(int overs, int extra);
 
int main() {
    int target, runs, wickets, balls, overs, extra;
 
    cout << "Target: ";
    cin >> target;
    cout << "Runs, wickets and balls bowled: ";
    cin >> runs >> wickets >> balls;
 
    ballsToOvers(balls, overs, extra);
    showScore(runs, wickets, overs, extra);
    cout << "Current run rate: " << runRate(runs, balls) << endl;
    cout << "Need " << runsNeeded(target, runs) << " runs from " << 120 - balls << " balls" << endl;
    cout << "Required run rate: " << requiredRate(runsNeeded(target, runs), 120 - balls) << endl;
    return 0;
}
 
void ballsToOvers(int balls, int &overs, int &extra) {
    overs = balls / 6;
    extra = balls % 6;
}
 
double runRate(int runs, int balls) {
    return runs * 6.0 / balls;
}
 
int runsNeeded(int target, int runs) {
    return target - runs;
}
 
double requiredRate(int needed, int ballsLeft) {
    return needed * 6.0 / ballsLeft;
}
 
void showScore(int runs, int wickets, int overs, int extra) {
    cout << "Score: " << runs << "/" << wickets << " in " << overs << "." << extra << " overs" << endl;
}
 
int oversToBalls(int overs, int extra) {
    return overs * 6 + extra;
}
