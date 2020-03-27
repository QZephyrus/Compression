#include "Compression.h"

vector<point> creatTrace() {
  point begin(-420, -700, "2020-03-20 15:30:00");
  vector<point> ret;
  creatTraces(begin, 2, 0, -50, 2, ret);
  creatTraces(begin, 6, 0, -50, 2, ret);
  creatTraces(begin, 24, -50, 0, 2, ret);
  creatTraces(begin, 15, 0, -50, 2, ret);
  creatTraces(begin, 17, 100, 0, 2, ret);
  creatTraces(begin, 14, 0, 50, 2, ret);
  creatTraces(begin, 5, -100, 0, 2, ret);
  creatTraces(begin, 14, 0, -50, 2, ret);
  creatTraces(begin, 4, -100, 0, 2, ret);
  creatTraces(begin, 14, 0, 50, 2, ret);
  creatTraces(begin, 4, -100, 0, 2, ret);
  creatTraces(begin, 14, 0, -50, 2, ret);
  return ret;
}
vector<point> creatTrace2() {
  point begin(-420, -700, "2020-03-20 15:30:00");
  vector<point> ret;
  creatTraces2(begin, 2, 0, -50, 2, ret);
  creatTraces2(begin, 6, 0, -50, 2, ret);
  creatTraces2(begin, 24, -50, 0, 2, ret);
  creatTraces2(begin, 15, 0, -50, 2, ret);
  creatTraces2(begin, 17, 100, 0, 2, ret);
  creatTraces2(begin, 14, 0, 50, 2, ret);
  creatTraces2(begin, 5, -100, 0, 2, ret);
  creatTraces2(begin, 14, 0, -50, 2, ret);
  creatTraces2(begin, 4, -100, 0, 2, ret);
  creatTraces2(begin, 14, 0, 50, 2, ret);
  creatTraces2(begin, 4, -100, 0, 2, ret);
  creatTraces2(begin, 14, 0, -50, 2, ret);
  return ret;
}
vector<point> creatTrace3() {
  point begin(0, 0, "2020-03-20 15:30:00");
  vector<point> ret;
  creatTraces(begin, 10, 20, 5, 2, ret);
  creatTraces(begin, 8, 20, -10, 2, ret);
  creatTraces(begin, 20, 0, 20, 2, ret);
  creatTraces(begin, 3, 5, 5, 2, ret);
  creatTraces(begin, 2, -2, -5, 2, ret);
  creatTraces(begin, 25, 10, 20, 2, ret);
  creatTraces(begin, 30, 20, -10, 2, ret);
  creatTraces(begin, 30, 20, -7, 2, ret);
  creatTraces(begin, 8, 5, -10, 2, ret);
  creatTraces(begin, 8, 5, -5, 2, ret);
  creatTraces(begin, 8, 10, -5, 2, ret);
  creatTraces(begin, 2, 10, 0, 2, ret);
  creatTraces(begin, 20, -5, -20, 2, ret);
  creatTraces(begin, 15, 20, -8, 2, ret);
  creatTraces(begin, 10, 10, -14, 2, ret);
  creatTraces(begin, 10, 16, -8, 2, ret);
  creatTraces(begin, 3, 5, -5, 2, ret);
  creatTraces(begin, 10, 5, -12, 2, ret);
  creatTraces(begin, 5, 6, -8, 2, ret);
  creatTraces(begin, 8, 6, 8, 2, ret);
  creatTraces(begin, 8, 5, -8, 2, ret);
  creatTraces(begin, 20, 20, 5, 2, ret);
  return ret;
}
vector<point> creatTrace4() {
  point begin(0, 0, "2020-03-20 15:30:00");
  vector<point> ret;
  creatTraces(begin, 10, 20, 5, 2, ret);
  creatTraces(begin, 40, 20, -10, 2, ret);
  creatTraces(begin, 20, 0, 20, 2, ret);
  creatTraces(begin, 30, 5, 5, 2, ret);
  creatTraces(begin, 20, -2, -5, 2, ret);
  creatTraces(begin, 25, 10, 20, 2, ret);
  creatTraces(begin, 30, 20, -10, 2, ret);
  creatTraces(begin, 30, 20, -7, 2, ret);
  creatTraces(begin, 40, 5, -10, 2, ret);
  creatTraces(begin, 40, 5, -5, 2, ret);
  creatTraces(begin, 40, 10, -5, 2, ret);
  creatTraces(begin, 20, 10, 0, 2, ret);
  creatTraces(begin, 20, -5, -20, 2, ret);
  creatTraces(begin, 15, 20, -8, 2, ret);
  creatTraces(begin, 10, 10, -14, 2, ret);
  creatTraces(begin, 10, 16, -8, 2, ret);
  creatTraces(begin, 30, 5, -5, 2, ret);
  creatTraces(begin, 10, 5, -12, 2, ret);
  creatTraces(begin, 25, 6, -8, 2, ret);
  creatTraces(begin, 40, 6, 8, 2, ret);
  creatTraces(begin, 40, 5, -8, 2, ret);
  creatTraces(begin, 20, 20, 5, 2, ret);
  return ret;
}

vector<point> creatCirles() {
  point begin(0, 0, "2020-03-20 15:30:00");
  vector<point> ret;
  creatCirle(begin, 200, 120, 2, ret);
  return ret;
}

int main() {
  vector<point> trace;
  trace = creatTrace4();
  cout << trace.size() << endl;
  for (auto &v : trace) {
    // cout << "( " << v.X << " , " << v.Y << " , " << v.time << " )" << endl;
    cout << v.X << "," << v.Y << endl;
  }
  vector<point> rettrace;
  // rettrace = Compression2(trace, 200, 60, 2);
  rettrace = Compression_OW_Relat(trace, 10, 2);
  cout << rettrace.size() << endl;
  for (auto &v : rettrace) {
    // cout << "( " << v.X << " , " << v.Y << " , " << v.time << " )" << endl;
    cout << v.X << "," << v.Y << endl;
  }
  rettrace = Restore_OW(rettrace, 2);
  cout << rettrace.size() << endl;
  for (auto &v : rettrace) {
    // cout << "( " << v.X << " , " << v.Y << " , " << v.time << " )" << endl;
    cout << v.X << "," << v.Y << endl;
  }
  return 0;
}