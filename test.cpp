#define _USE_MATH_DEFINES
#include "Compression.h"
#include "matplotlibcpp.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost;
namespace plt = matplotlibcpp;

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
vector<point> creatTrace5() {
  point begin(-420, -700, "2020-03-20 15:30:00");
  vector<point> ret;
  creatTraces2(begin, 7, 7, -50, 2, ret);
  creatTraces2(begin, 10, 10, -50, 2, ret);
  creatTraces2(begin, 24, -50, 2, 2, ret);
  creatTraces2(begin, 15, 7, -50, 2, ret);
  creatTraces2(begin, 17, 100, 6, 2, ret);
  creatTraces2(begin, 14, 5, 50, 2, ret);
  creatTraces2(begin, 6, -100, 7, 2, ret);
  creatTraces2(begin, 14, 7, -50, 2, ret);
  creatTraces2(begin, 7, -100, 10, 2, ret);
  creatTraces2(begin, 14, 5, 50, 2, ret);
  creatTraces2(begin, 6, -100, 9, 2, ret);
  creatTraces2(begin, 14, 3, -50, 2, ret);
  return ret;
}
vector<point> creatTrace6() {
  point begin(-420, -700, "2020-03-20 15:30:00");
  vector<point> ret;
  creatTraces(begin, 7, 0, -50, 2, ret);
  creatTraces(begin, 6, 0, -20, 2, ret);
  creatTraces(begin, 24, -50, 0, 2, ret);
  creatTraces(begin, 6, 7, -10, 2, ret);
  creatTraces(begin, 15, 0, -50, 2, ret);
  creatTraces(begin, 6, 5, -10, 2, ret);
  creatTraces(begin, 17, 100, 0, 2, ret);
  creatTraces(begin, 5, 20, 2, 2, ret);
  creatTraces(begin, 14, 0, 50, 2, ret);
  creatTraces(begin, 5, -100, 0, 2, ret);
  creatTraces(begin, 14, 0, -50, 2, ret);
  creatTraces(begin, 4, -100, 0, 2, ret);
  creatTraces(begin, 14, 0, 50, 2, ret);
  creatTraces(begin, 4, -100, 0, 2, ret);
  creatTraces(begin, 14, 0, -50, 2, ret);
  return ret;
}

vector<point> creatCirles7() {
  point begin(0, 0, "2020-03-20 15:30:00");
  vector<point> ret;
  creatCirle(begin, 200, 120, 2, ret);
  return ret;
}
vector<point> creatTracenum(int total) {
  mt19937 gen;
  uniform_real_distribution<double> off(-80.0, 80.0);
  uniform_int<> n(1, 50);
  variate_generator<mt19937 &, uniform_real_distribution<double>> away(gen,
                                                                       off);
  variate_generator<mt19937 &, uniform_int<>> nu(gen, n);
  point begin(0, 0, "2020-03-20 15:30:00");
  vector<point> ret;
  int num = 0;
  while (total > 0) {
    num = nu();
    if (num > total) {
      num = total;
    }
    creatTraces(begin, num, away(), away(), 2, ret);
    total -= num;
  }
  return ret;
}
vector<point> creatTrace8() {
  vector<point> ret = creatTracenum(1000);
  return ret;
}
vector<point> creatTrace9() {
  vector<point> ret = creatTracenum(5000);
  return ret;
}
vector<point> creatTrace10() {
  vector<point> ret = creatTracenum(10000);
  return ret;
}
vector<point> creatTrace11() {
  vector<point> ret = creatTracenum(50000);
  return ret;
}
vector<point> creatTrace12() {
  vector<point> ret = creatTracenum(100000);
  return ret;
}
vector<point> creatTrace13() {
  vector<point> ret = creatTracenum(500000);
  return ret;
}
vector<point> creatTrace14() {
  int total = 1000;
  vector<point> ret;
  mt19937 gen;
  uniform_real_distribution<double> off(-80.0, 80.0);
  uniform_int<> n(1, 50);
  variate_generator<mt19937 &, uniform_real_distribution<double>> away(gen,
                                                                       off);
  variate_generator<mt19937 &, uniform_int<>> nu(gen, n);
  point begin(0, 0, "2020-03-20 15:30:00");
  int num = 0;
  while (total > 0) {
    num = nu();
    if (num > total) {
      num = total;
    }
    creatTraces(begin, num, away(), away(), 2, ret);
    total -= num;
  }
  return ret;
}

void inserXY(const vector<point> &trace, vector<double> &X, vector<double> &Y) {
  X.clear();
  Y.clear();
  for (auto &v : trace) {
    X.push_back(v.X);
    Y.push_back(v.Y);
  }
}

void statistics(const vector<point> &orgtrace, const vector<point> &comtrace,
                const vector<point> &restrace, CountData &Data) {
  Data.AverDist = 0;
  vector<double> Dist;
  Data.OrgN = orgtrace.size();
  Data.ComN = comtrace.size();
  Data.ResN = restrace.size();
  Data.CR = (double)Data.ComN / (double)Data.OrgN;
  Data.SP = 1 - Data.CR;
  Data.ReSR = (double)Data.ResN / (double)Data.OrgN;
  Data.CS = (double)Data.OrgN / Data.ComTime.total_microseconds();
  for (int i = 0; i < Data.OrgN; i++) {
    double dist = getDist(orgtrace[i], restrace[i]);
    Dist.push_back(dist);
    Data.AverDist += dist;
  }
  Data.AverDist = Data.AverDist / Data.OrgN;
  for (int i = 0; i < Data.OrgN; i++) {
    Data.Variance += (Dist[i] - Data.AverDist) * (Dist[i] - Data.AverDist);
  }
  Data.Variance = Data.Variance / Data.OrgN;
}

int main() {
  /*
  vector<point> trace;
  ptime tick, now;
  time_duration diff;
  tick = microsec_clock::local_time();
  trace = creatTrace2();
  // trace = creatCirles();
  now = microsec_clock::local_time();
  diff = now - tick;
  cout << "Trace number " << trace.size() << " create use "
       << diff.total_nanoseconds() << " ns" << endl;
  for (auto &v : trace) {
    cout << v.X << "," << v.Y << endl;
  }
  vector<point> rettrace;
  // rettrace = Compression2(trace, 200, 60, 2);
  tick = microsec_clock::local_time();
  rettrace = Compression_OW_Relat(trace, 10, 2);
  now = microsec_clock::local_time();
  diff = now - tick;
  cout << "Trace number " << rettrace.size() << "  compression use "
       << diff.total_nanoseconds() << " ns" << endl;
  for (auto &v : rettrace) {
    cout << v.X << "," << v.Y << endl;
  }
  tick = microsec_clock::local_time();
  rettrace = Restore_OW(rettrace, 2);
  now = microsec_clock::local_time();
  diff = now - tick;
  cout << "Trace number " << rettrace.size() << "  restore use "
       << diff.total_nanoseconds() << " ns" << endl;
  for (auto &v : rettrace) {
    cout << v.X << "," << v.Y << endl;
  }
  */
  vector<point> trace, comtrace, restrace;
  trace = creatTrace13();
  // trace = creatCirles7();
  CountData data;
  ptime tick, now;
  tick = microsec_clock::local_time();
  comtrace = Compression_OW_Relat(trace, 10, 2);
  now = microsec_clock::local_time();
  data.ComTime = now - tick;
  tick = microsec_clock::local_time();
  restrace = Restore_OW(comtrace, 2);
  now = microsec_clock::local_time();
  data.ReSTime = now - tick;
  statistics(trace, comtrace, restrace, data);
  cout << "Orgin Point Number:" << data.OrgN << endl;
  cout << "After Compression Point Number:" << data.ComN << endl;
  cout << "Restore Point Number:" << data.ResN << endl;
  cout << "Compression Ratio(CR):" << data.CR << endl;
  cout << "Saving Space(SP):" << data.SP << endl;
  cout << "ReStore Rate:" << data.ReSR << endl;
  cout << "Compression Speed(CS):" << data.CS << endl;
  cout << "Average offset distance:" << data.AverDist << endl;
  cout << "Variance of offset distance:" << data.Variance << endl;
  cout << "Compression use time(us):" << data.ComTime.total_microseconds()
       << endl;
  cout << "Restore use time(us):" << data.ReSTime.total_microseconds() << endl;
  plt::figure_size(2400, 1560);
  vector<double> X, Y;
  inserXY(trace, X, Y);
  plt::named_plot("orgin", X, Y);
  inserXY(comtrace, X, Y);
  plt::named_plot("Compression", X, Y);
  inserXY(restrace, X, Y);
  plt::named_plot("Restore", X, Y, "r--");
  plt::title("test13");
  plt::legend();
  string filename = "./test13.png";
  plt::save(filename);
  cout << "Saving result to " << filename << endl;
  return 0;
}