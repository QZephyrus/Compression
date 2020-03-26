#include "Compression.h"

vector<point> creatTrace()
{
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
vector<point> creatTrace2()
{
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

int main()
{
  vector<point> trace;
  trace = creatTrace2();
  cout << trace.size() << endl;
  for (auto &v : trace)
  {
    // cout << "( " << v.X << " , " << v.Y << " , " << v.time << " )" << endl;
    cout << v.X << "," << v.Y << endl;
  }
  vector<point> rettrace;
  //rettrace = Compression2(trace, 200, 60, 2);
  rettrace = Compression_OW(trace, 200, 2);
  cout << rettrace.size() << endl;
  for (auto &v : rettrace)
  {
    // cout << "( " << v.X << " , " << v.Y << " , " << v.time << " )" << endl;
    cout << v.X << "," << v.Y << endl;
  }
  rettrace = Restore_OW(rettrace, 2);
  cout << rettrace.size() << endl;
  for (auto &v : rettrace)
  {
    // cout << "( " << v.X << " , " << v.Y << " , " << v.time << " )" << endl;
    cout << v.X << "," << v.Y << endl;
  }
  return 0;
}