#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int QINZHENG = 1;
const int PUTONG = 2;
const int WU = 0;

struct fan {
  std::string name;
  int room;
  std::tuple<int, int, int> food;
};
struct needed {
  int start;
  int end;
  needed(int x, int y) {
    start = x;
    end = y;
  }
  // [start, end] start 和 end 都包括
};
std::vector<needed> person = {
    needed(301, 307), needed(315, 321), needed(401, 408), needed(409, 417),
    needed(418, 421), needed(517, 521), needed(501, 507), needed(601, 606),
    needed(607, 612), needed(613, 617)};
std::vector<fan> dataa;
void read() {
  ifstream fp("data.csv");
  string line;
  getline(fp, line); // 表头 ignore
  while (getline(fp, line)) {
    fan data_line;
    string number;
    istringstream readstr(line);

    getline(readstr, number, ','); // liu shui ignore

    getline(readstr, number, ','); // name
    data_line.name = number;

    getline(readstr, number, ','); // room
    data_line.room = atoi(number.c_str());

    getline(readstr, number, ','); // is zao
    if (number == "否") {
      std::get<0>(data_line.food) = WU;
    }
    getline(readstr, number, ','); // zao
    if (number == "普餐") {
      std::get<0>(data_line.food) = PUTONG;
    } else if (number == "清真") {
      std::get<0>(data_line.food) = QINZHENG;
    } else {
      std::get<0>(data_line.food) = WU;
    }

    getline(readstr, number, ','); // is zhong
    if (number == "否") {
      std::get<1>(data_line.food) = WU;
    }
    getline(readstr, number, ','); // zhong
    if (number == "普餐") {
      std::get<1>(data_line.food) = PUTONG;
    } else if (number == "清真") {
      std::get<1>(data_line.food) = QINZHENG;
    } else {
      std::get<1>(data_line.food) = WU;
    }

    getline(readstr, number, ','); // is wan
    if (number == "否") {
      std::get<2>(data_line.food) = WU;
    }
    getline(readstr, number, ','); // wan
    if (number == "普餐") {
      std::get<2>(data_line.food) = PUTONG;
    } else if (number == "清真") {
      std::get<2>(data_line.food) = QINZHENG;
    } else {
      std::get<2>(data_line.food) = WU;
    }
    dataa.push_back(data_line);
  }
  return;
}
bool cmp(const fan x1, const fan x2) {
  if (x1.room < x2.room) {
    return true;
  } else {
    if (x1.room == x2.room) {
      return (x1.name < x2.name);
    } else {
      return false;
    }
  }
}
void print() {
  for (auto i : dataa) {
    cout << i.room << " " << i.name << std::get<0>(i.food)
         << std::get<1>(i.food) << std::get<2>(i.food) << endl;
  }
  return;
}
void dsort() { std::sort(dataa.begin(), dataa.end(), cmp); }
void printTotal() {
  int qin1 = 0;
  int pu1 = 0;
  int qin2 = 0;
  int pu2 = 0;
  int qin3 = 0;
  int pu3 = 0;
  for (auto i : dataa) {
    if (std::get<0>(i.food) == QINZHENG) {
      qin1++;
    }
    if (std::get<0>(i.food) == PUTONG) {
      pu1++;
    }

    if (std::get<1>(i.food) == QINZHENG) {
      qin2++;
    }
    if (std::get<1>(i.food) == PUTONG) {
      pu2++;
    }

    if (std::get<2>(i.food) == QINZHENG) {
      qin3++;
    }
    if (std::get<2>(i.food) == PUTONG) {
      pu3++;
    }
  }
  cout << "早普" << pu1 << " 早清" << qin1 << endl
       << "中普" << pu2 << " 中清" << qin2 << endl
       << "晚普" << pu3 << " 晚清" << qin3 << endl;
}
void checkSame1() {
  for (auto i = 1; i < dataa.size(); i++) {
    if ((dataa[i].name == dataa[i - 1].name) &&
        ((dataa[i - 1].room == dataa[i].room))) {
      if (!((dataa[i - 1].food == dataa[i].food))

      ) {
        cout << "out wrong" << endl;
        cout << dataa[i - 1].name << endl;
        int temp;
        cin >> temp;
      }
    }
  }
}
void checkSame2() {
  for (auto i = 1; i < dataa.size(); i++) {
    if (dataa[i].name == dataa[i - 1].name) {
      if (((dataa[i - 1].room == dataa[i].room))

      ) {
        cout << "out wrong" << endl;
        cout << dataa[i - 1].name << endl;
        int temp;
        cin >> temp;
      }
    }
  }
}
void printPerson() {
  for (auto tempp : person) {
    int start = tempp.start;
    int end = tempp.end;
    int qin1 = 0;
    int pu1 = 0;
    int qin2 = 0;
    int pu2 = 0;
    int qin3 = 0;
    int pu3 = 0;
    for (auto i : dataa) {
      if ((i.room >= start) && (i.room <= end)) {
        if (std::get<0>(i.food) == QINZHENG) {
          qin1++;
        }
        if (std::get<0>(i.food) == PUTONG) {
          pu1++;
        }

        if (std::get<1>(i.food) == QINZHENG) {
          qin2++;
        }
        if (std::get<1>(i.food) == PUTONG) {
          pu2++;
        }

        if (std::get<2>(i.food) == QINZHENG) {
          qin3++;
        }
        if (std::get<2>(i.food) == PUTONG) {
          pu3++;
        }
      }
    }
    cout << start << "-" << end << ":" << endl
         << "早普" << pu1 << " 早清" << qin1 << endl
         << "中普" << pu2 << " 中清" << qin2 << endl
         << "晚普" << pu3 << " 晚清" << qin3 << endl;
  }
}
int main() {
  read();
  dsort();
  print();
  printTotal();
  //checkSame1();
  // checkSame2();
  printPerson();

  return 0;
}