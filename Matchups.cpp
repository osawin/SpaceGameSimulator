#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

int main() {
	int n = 10000;
	std::vector<int> Fighter;
	std::vector<int>  Bomber;
	std::vector<int>  Battleship;
	std::vector<int>  Artillery;
	std::vector<int>  Knight;
	std::vector<int>  Fortress;
	Fighter.push_back(7);
	Fighter.push_back(5);
	Fighter.push_back(20);
	Fighter.push_back(-1);
	Fighter.push_back(2);
	Fighter.push_back(5);
	Bomber.push_back(6);
	Bomber.push_back(6);
	Bomber.push_back(20);
	Bomber.push_back(6);
	Bomber.push_back(1);
	Bomber.push_back(3);
	Battleship.push_back(5);
	Battleship.push_back(10);
	Battleship.push_back(20);
	Battleship.push_back(2);
	Battleship.push_back(3);
	Battleship.push_back(2);
	Artillery.push_back(0);
	Artillery.push_back(3);
	Artillery.push_back(35);
	Artillery.push_back(3);
	Artillery.push_back(2);
	Artillery.push_back(1);
	Knight.push_back(13);
	Knight.push_back(7);
	Knight.push_back(5);
	Knight.push_back(4);
	Knight.push_back(1);
	Knight.push_back(4);
	Fortress.push_back(6);
	Fortress.push_back(12);
	Fortress.push_back(20);
	Fortress.push_back(7);
	Fortress.push_back(2);
	Fortress.push_back(1);
	std::string names[6] = {"fighter", "bomber", "battleship", "artillery", "knight", "fortress"};
	std::vector<std::vector<int> > stats;
	stats.push_back(Fighter);
	stats.push_back(Bomber);
	stats.push_back(Battleship);
	stats.push_back(Artillery);
	stats.push_back(Knight);
	stats.push_back(Fortress);
	int ax = 0;
	while (ax < 6) {
		int bx = 0;
		while (bx < 6) {
			if (bx != ax) {
				std::vector<int> first = stats[ax];
				std::vector<int> sec = stats[bx];
				int k = 0;
				int results[3] = {0, 0, 0};
				while (k < n) {
					int dist = std::max(sec[2], first[2]);
					int A = first[5];
					int B = sec[5];
					while (A > 0 && B > 0)	{
					int i = 0;
						if(dist > first[2]) {
							dist = dist-(first[0]+(rand()%6+1));
						} else {dist = std::min(first[2], dist+first[0]+(rand()%6+1));}
						if (dist <= first[2]) {
							while (i < A*first[4]) {
								int x = rand() % 6 + 1;
								x = x + (rand()%6)+1;
								x = x+first[3];
								if (x >= sec[1]) {
									B--;
								}
								i++;
							}
						}
						if(dist > sec[2]) {
							dist = dist-(sec[0]+(rand()%6+1));
						} else {dist = std::min(sec[2], dist+sec[0]+(rand()%6+1));}
						if (B >= 0 && dist <= sec[2]) {
							i = 0;
							while (i < B*sec[4]) {
								int x = rand() % 6 + 1;
								x = x + (rand()%6)+1;
								x = x + sec[3];
									if (x >= first[1]) {
										A--;
								}
								i++;
							}
						}
					} if (A > 0) {
						results[0]++;
					} else if (B > 0) {
						results[1]++;
					} else { results[2]++;}
					k++;
				}
				std::cout << "when " << names[ax] << " shot " << names[bx] << " first, they won " << results[0] << " times." << std::endl;
			}
			bx++;
		}
		ax++;
	}
	return 0;
}