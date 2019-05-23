#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        unordered_map<int, vector<int>>
            stationHaveBus;  // 每个站点经过的哪些bus, 战点和对应bus的对应
        for (int i = 0; i < routes.size(); i++) {
            for (auto station : routes[i]) {
                stationHaveBus[station].push_back(i);
            }
        }
        unordered_map<int, bool>
            visitedStation;  // 某个站台是不是访问过，访问过那这个站台就不用再次访问了,因为不知道站台的序号，所以用hash表
        for (auto& station : stationHaveBus) {
            visitedStation[station.first] = false;
        }
        int step = 0;  // 循环的次数，也是经过的多少bus
        vector<bool> visitedBus(routes.size(), false);  // 某个bus是否访问过
        vector<int> stations;  // 存储着下一轮要访问的站台
        stations.push_back(S);  // 第0轮的时候，需要访问的第一个站点
        while (
            stations
                .size()) {  // 广度优先，第一次是需要经过1次bus的车站，第二次是2次bus的车站，以此类推
            vector<int> nextStations;  // 下一轮要访问的车站
            step++;
            for (auto station : stations) {
                for (auto bus : stationHaveBus[station]) {
                    if (!visitedBus[bus]) {
                        visitedBus[bus] = true;
                        for (auto s : routes[bus]) {
                            if (s == T) return step;
                            if (!visitedStation.at(s)) {
                                nextStations.push_back(
                                    s);  // 下一轮访问经过这个站台的车子
                                visitedStation.at(s) =
                                    true;  // 当前的站台被访问果了
                            }
                        }
                    }
                }
            }
            stations.swap(nextStations);
        }
        return -1;
    }
};
