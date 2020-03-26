#pragma once
//#include"DBStruct.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/random.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::string;
using std::vector;
using namespace boost::random;
using namespace boost::posix_time;
using namespace boost::gregorian;

class point
{
public:
  double X;
  double Y;
  string time;
  point(double x, double y, string Time) : X(x), Y(y), time(Time){};
  point(double x, double y) : X(x), Y(y){};
  point(void){};
  // point(DBTrace trace):X(trace.X),Y(trace.Y),time(trace.time){};
  void getPoint(double x, double y, string Time)
  {
    X = x;
    Y = y;
    time = Time;
  };
};

string ptime_to_string(ptime t);

double getDist(const point &A, const point &B);
double getAngle(const point &A, const point &B, const point &C);
double getPointToLineDist(const point &A, const point &B, const point &C);
double getVelocity(double dist, double time);
double getVelocity(const point &A, const point &B);
point getSimulatPoint(const point &A, const point &B, double time);
point getSimulatPoint2(const point &A, const point &B, double time);

vector<point> Compression(const vector<point> &trace, double distance,
                          double angle, double time);
vector<point> Compression2(const vector<point> &trace, double distance,
                           double angle, double time);
vector<point> Compression_OW(const vector<point> &trace, double distance, double time);
vector<point> Compression_OW_Relat(const vector<point> &trace, double distance, double time);

int getPointNum(const point &A, const point &B);

vector<point> Restore(const vector<point> &trace, double time);
vector<point> Restore3(const vector<point> &trace, double time);
vector<point> Restore_OW(const vector<point> &trace, double time);

void creatTraces(point &A, int num, double XF, double YF, double time,
                 vector<point> &ret);

void creatTraces2(point &A, int num, double XF, double YF, double time,
                  vector<point> &ret);
