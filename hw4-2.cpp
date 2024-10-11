#include "env.h"
#include <bitset>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int N;
        vector<pair<int, int>> map;
        std::cin >> N;
        int ljin, rjin;
        vector<pair<int, int>> arr1;
        vector<pair<int, int>> arr2;
        vector<pair<int, int>> brr1;
        vector<pair<int, int>> brr2;
        if (N % 2 == 1) {

            ljin = N - 1;
            for (int i = 0; i < N - 1; i += 2) {
                link_wire(i, i + 1);
                arr1.push_back({ i,i + 1 });
            }
            move_to_opposite();
            bool vs[N] = { 0, };
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    if (check_connectivity(i, j)) {
                        brr1.push_back({ i,j });
                        vs[i] = 1; vs[j] = 1;
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                if (vs[i] == 0) rjin = i;
            }
            brr2.push_back({ rjin,brr1[0].first });
            link_wire(rjin, brr1[0].first);
            for (int i = 0; i < brr1.size() - 1; i++) {
                brr2.push_back({ brr1[i].second,brr1[i + 1].first });
                link_wire(brr1[i].second, brr1[i + 1].first);
            }
            move_to_opposite();
            clean_wires();
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    if (check_connectivity(i, j)) {
                        arr2.push_back({ i,j });
                    }
                }
            }
            map.push_back({ ljin,rjin });
            while (map.size() < N) {
                int ta, tb;
                for (int i = 0; i < N; i++) {
                    if (brr2[i].first == rjin) {
                        tb = brr2[i].second;
                        break;
                    }
                    if (brr2[i].second == rjin) {
                        tb = brr2[i].first;
                        break;
                    }
                }
                for (int i = 0; i < N; i++) {
                    if (arr2[i].first == ljin) {
                        ta = arr2[i].second;
                        break;
                    }
                    if (arr2[i].second == ljin) {
                        ta = arr2[i].first;
                        break;
                    }
                }
                map.push_back({ ta,tb });
                ljin = ta;
                rjin = tb;
                for (int i = 0; i < N; i++) {
                    if (arr1[i].first == ljin) {
                        ta = arr1[i].second;
                        break;
                    }
                    if (arr1[i].second == ljin) {
                        ta = arr1[i].first;
                        break;
                    }
                }
                for (int i = 0; i < N; i++) {
                    if (brr1[i].first == rjin) {
                        tb = brr1[i].second;
                        break;
                    }
                    if (brr1[i].second == rjin) {
                        tb = brr1[i].first;
                        break;
                    }
                }
                map.push_back({ ta,tb });
                ljin = ta;
                rjin = tb;
            }
            answer(map);
        }
        else {//N은 짝수
            for (int i = 0; i < N - 3; i += 2) {//ㅇㅇ
                link_wire(i, i + 1);
                arr1.push_back({ i,i + 1 });
            }

            move_to_opposite();
            clean_wires();
            bool vs[N] = { 0, };
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    if (check_connectivity(i, j)) {
                        brr1.push_back({ i,j });
                        vs[i] = 1; vs[j] = 1;
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                if (vs[i] == 0) {
                    rjin = i;
                    vs[i] = 1;
                    break;
                }
            }
            int realjin;
            for (int i = 0; i < N; i++) {
                if (vs[i] == 0) {
                    realjin = i;
                    break;
                }
            }
            brr2.push_back({ rjin,brr1[0].first });
            link_wire(rjin, brr1[0].first);
            for (int i = 0; i < brr1.size() - 1; i++) {
                brr2.push_back({ brr1[i].second,brr1[i + 1].first });
                link_wire(brr1[i].second, brr1[i + 1].first);
            }

            move_to_opposite();
            clean_wires();
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    if (check_connectivity(i, j)) {
                        arr2.push_back({ i,j });
                    }
                }
            }
            for (int i = 0; i < N; i++) {//아래서두개가찐따임 N-1, N-2
                if (N - 2 != i && check_connectivity(N - 2, i)) {
                    map.push_back({ N - 2,rjin });
                    map.push_back({ N - 1,realjin });
                    ljin = N - 2;
                    break;
                }
                else if (N - 1 != i && check_connectivity(N - 1, i)) {
                    map.push_back({ N - 1,rjin });
                    map.push_back({ N - 2,realjin });
                    ljin = N - 1;
                    break;
                }
            }
            //map.push_back({ljin,rjin});
            while (map.size() < N) {
                int ta, tb;
                for (int i = 0; i < brr2.size(); i++) {
                    if (brr2[i].first == rjin) {
                        tb = brr2[i].second;
                        break;
                    }
                    if (brr2[i].second == rjin) {
                        tb = brr2[i].first;
                        break;
                    }
                }
                for (int i = 0; i < arr2.size(); i++) {
                    if (arr2[i].first == ljin) {
                        ta = arr2[i].second;
                        break;
                    }
                    if (arr2[i].second == ljin) {
                        ta = arr2[i].first;
                        break;
                    }
                }
                map.push_back({ ta,tb });
                ljin = ta;
                rjin = tb;
                for (int i = 0; i < arr1.size(); i++) {
                    if (arr1[i].first == ljin) {
                        ta = arr1[i].second;
                        break;
                    }
                    if (arr1[i].second == ljin) {
                        ta = arr1[i].first;
                        break;
                    }
                }
                for (int i = 0; i < brr1.size(); i++) {
                    if (brr1[i].first == rjin) {
                        tb = brr1[i].second;
                        break;
                    }
                    if (brr1[i].second == rjin) {
                        tb = brr1[i].first;
                        break;
                    }
                }
                map.push_back({ ta,tb });
                ljin = ta;
                rjin = tb;
            }
            answer(map);
        }
    }
    return 0;
}
