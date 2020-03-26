#include "Compression.h"

string ptime_to_string(ptime t)
{
  string time;
  time = to_iso_extended_string(t);
  time = time.replace(time.find("T"), 1, " ");
  return time;
}

double getDist(const point &A, const point &B)
{
  double dist, x, y;
  x = A.X - B.X;
  y = A.Y - B.Y;
  dist = sqrt(x * x + y * y);
  return dist;
}

// C为中心点
double getAngle(const point &A, const point &B, const point &C)
{
  double angle = atan2(A.X - C.X, A.Y - C.Y) - atan2(B.X - C.X, B.Y - C.Y);
  if (angle > M_PI)
    angle -= 2 * M_PI;
  if (angle < -M_PI)
    angle += 2 * M_PI;
  angle = abs(angle * 180.0 / M_PI);
  return angle;
}

// C到AB直线的距离
double getPointToLineDist(const point &A, const point &B, const point &C)
{
  double dist;
  if (A.X == B.X)
  {
    dist = fabs(A.Y - B.Y);
  }
  else
  {
    double k = -((A.Y - B.Y) / (A.X - B.X));
    double b = (A.Y * B.X - B.Y * A.X) / (B.X - A.X);
    dist = fabs(k * C.X + C.Y + b) / sqrt(1 + k * k);
  }
  return dist;
}
// 将AB直线分成row段，C到第num个点的距离
double getPointToLinePDist(const point &A, const point &B, const point &C, int row, int num)
{
  point temp;
  temp.X = A.X + num * (B.X - A.X) / row;
  temp.Y = A.Y + num * (B.Y - A.Y) / row;
  double dist = getDist(temp, C);
  return dist;
}

double getVelocity(double dist, double time)
{
  double V;
  V = dist / time;
  return V;
}
double getVelocity(const point &A, const point &B)
{
  double dist, V;
  dist = getDist(A, B);
  time_duration time;
  time = time_from_string(B.time) - time_from_string(A.time);
  double t = time.total_seconds();
  V = dist / t;
  return V;
}

point getSimulatPoint(const point &A, const point &B, double time)
{
  double X, Y, S, D, V;
  string Time;
  D = getDist(A, B);
  V = getVelocity(A, B);
  S = V * time;
  X = B.X + (S * (B.X - A.X)) / D;
  Y = B.Y + (S * (B.Y - A.Y)) / D;
  time_duration t = seconds(time);
  ptime ti = time_from_string(B.time);
  ti = ti + t;
  Time = ptime_to_string(ti);
  point retpoint(X, Y, Time);
  return retpoint;
}
point getSimulatPoint2(const point &A, const point &B, double time)
{
  double X, Y, S, D, V;
  string Time;
  D = getDist(A, B);
  V = getVelocity(A, B);
  S = V * time;
  X = A.X + (S * (B.X - A.X)) / D;
  Y = A.Y + (S * (B.Y - A.Y)) / D;
  time_duration t = seconds(time);
  ptime ti = time_from_string(A.time);
  ti = ti + t;
  Time = ptime_to_string(ti);
  point retpoint(X, Y, Time);
  return retpoint;
}

vector<point> Compression(const vector<point> &trace, double distance,
                          double angle, double time)
{
  vector<point> retrace;
  int flag = 0;
  point pt1;
  point pt2;
  point pt3;
  double dist, ang;
  for (auto &t : trace)
  {
    if (flag == 0)
    {
      pt1 = t;
      retrace.push_back(t);
      flag++;
    }
    else if (flag == 1)
    {
      pt2 = t;
      retrace.push_back(t);
      flag++;
    }
    else
    {
      pt3 = getSimulatPoint(pt1, pt2, time);
      dist = getDist(t, pt3);
      ang = getAngle(pt3, t, pt2);
      pt1 = pt2;
      if (dist > distance || ang > angle)
      {
        retrace.push_back(t);
        pt2 = t;
      }
      else
      {
        pt2 = pt3;
      }
    }
  }
  retrace.push_back(trace.back());
  return retrace;
}

vector<point> Compression2(const vector<point> &trace, double distance,
                           double angle, double time)
{
  vector<point> retrace;
  point pt1;
  point pt2;
  point pt3;
  double dist, ang;
  for (unsigned int i = 0; i < trace.size(); i++)
  {
    if (i == 0)
    {
      pt1 = trace[0];
      retrace.push_back(pt1);
    }
    else if (i == 1)
    {
      pt2 = trace[1];
      retrace.push_back(pt2);
    }
    else if (i == trace.size() - 1)
    {
      retrace.push_back(trace[i]);
    }
    else
    {
      pt3 = getSimulatPoint(pt1, pt2, time);
      dist = getDist(trace[i], pt3);
      ang = getAngle(pt3, trace[i], pt2);
      pt1 = pt2;
      if (dist > distance || ang > angle)
      {
        pt1 = trace[i];
        retrace.push_back(trace[i]);
        i++;
        pt2 = trace[i];
        retrace.push_back(trace[i]);
      }
      else
      {
        pt2 = pt3;
      }
    }
  }
  return retrace;
}

vector<point> Compression_OW(const vector<point> &trace, double distance, double time)
{
  point pt1, pt2, pt3;
  int row = trace.size();
  int n;
  vector<point> retrace;
  for (int i = 0; i < row; i++)
  {
    if (i == 0)
    {
      pt1 = trace[i];
      retrace.push_back(pt1);
      n = i;
      i++;
    }
    else
    {
      pt2 = trace[i];
      bool flag = true;
      for (int j = n + 1; j < i; j++)
      {
        double dist = getPointToLineDist(pt1, pt2, trace[j]);
        if (dist > distance)
        {
          flag = false;
          break;
        }
      }
      if (flag == false)
      {
        retrace.push_back(trace[i - 1]);
        pt1 = trace[i - 1];
        n = i - 1;
      }
      else if (i == row - 1)
      {
        retrace.push_back(trace[i]);
      }
    }
  }
  return retrace;
}

vector<point> Compression_OW_Relat(const vector<point> &trace, double distance, double time)
{
  point pt1, pt2;
  int row = trace.size();
  int n;
  vector<point> retrace;
  for (int i = 0; i < row; i++)
  {
    if (i == 0)
    {
      pt1 = trace[i];
      retrace.push_back(pt1);
      n = i;
      i++;
    }
    else
    {
      pt2 = trace[i];
      bool flag = true;
      for (int j = n + 1; j < i; j++)
      {
        double dist = getPointToLinePDist(pt1, pt2, trace[j], i - n, j - n);
        if (dist > distance)
        {
          flag = false;
          break;
        }
      }
      if (flag == false)
      {
        retrace.push_back(trace[i - 1]);
        pt1 = trace[i - 1];
        n = i - 1;
      }
      else if (i == row - 1)
      {
        retrace.push_back(trace[i]);
      }
    }
  }
  return retrace;
}

int getPointNum(const point &A, const point &B, double time)
{
  ptime t1 = time_from_string(A.time);
  ptime t2 = time_from_string(B.time);
  time_duration td = t2 - t1;
  int num = td.total_seconds() / time;
  return num;
}

vector<point> Restore(const vector<point> &trace, double time)
{
  vector<point> retrace;
  int flag = 0;
  int num;
  point pt1, pt2, pt3, pt4;
  for (auto &t : trace)
  {
    if (flag == 0)
    {
      pt1 = t;
      retrace.push_back(t);
      flag++;
    }
    else if (flag == 1)
    {
      pt2 = t;
      retrace.push_back(t);
      flag++;
    }
    else
    {
      pt3 = t;
      num = getPointNum(pt2, pt3, time);
      for (int i = 1; i < num; i++)
      {
        pt4 = getSimulatPoint(pt1, pt2, time);
        retrace.push_back(pt4);
        pt1 = pt2;
        pt2 = pt4;
      }
      retrace.push_back(pt3);
      pt1 = pt2;
      pt2 = pt3;
    }
  }
  return retrace;
}

vector<point> Restore3(const vector<point> &trace, double time)
{
  vector<point> retrace;
  int num;
  point pt1, pt2, pt3;
  for (unsigned int i = 0; i < trace.size(); i++)
  {
    if (i == trace.size() - 1)
    {
      retrace.push_back(trace[i]);
    }
    else
    {
      pt1 = trace[i];
      retrace.push_back(trace[i]);
      i++;
      pt2 = trace[i];
      num = getPointNum(pt1, pt2, time);
      for (int j = 0; j < num; j++)
      {
        pt3 = getSimulatPoint2(pt1, pt2, time);
        retrace.push_back(pt3);
        pt1 = pt3;
      }
      retrace.push_back(pt2);
    }
  }
  return retrace;
}

vector<point> Restore_OW(const vector<point> &trace, double time)
{
  vector<point> retrace;
  int num;
  point pt1, pt2, pt3;
  for (unsigned int i = 0; i < trace.size(); i++)
  {
    if (i == 0)
    {
      pt1 = trace[i];
      retrace.push_back(pt1);
    }
    else
    {
      pt2 = trace[i];
      num = getPointNum(pt1, pt2, time);
      for (int j = 1; j < num; j++)
      {
        pt3 = getSimulatPoint2(pt1, pt2, time);
        retrace.push_back(pt3);
        pt1 = pt3;
      }
      retrace.push_back(pt2);
      pt1 = pt2;
    }
  }
  return retrace;
}

void creatTraces(point &A, int num, double XF, double YF, double time,
                 vector<point> &ret)
{
  mt19937 gen;
  uniform_real_distribution<double> dist(-5.0, 5.0);
  variate_generator<mt19937 &, uniform_real_distribution<double>> die(gen,
                                                                      dist);
  time_duration t = seconds(time);
  for (int i = 0; i < num; i++)
  {
    A.X = A.X + XF + die();
    A.Y = A.Y + YF + die();
    A.time = ptime_to_string(time_from_string(A.time) + t);
    ret.push_back(A);
  }
}

void creatTraces2(point &A, int num, double XF, double YF, double time,
                  vector<point> &ret)
{
  mt19937 gen;
  uniform_real_distribution<double> dist(-15.0, 15.0);
  variate_generator<mt19937 &, uniform_real_distribution<double>> die(gen,
                                                                      dist);
  time_duration t = seconds(time);
  for (int i = 0; i < num; i++)
  {
    A.X = A.X + XF + die();
    A.Y = A.Y + YF + die();
    A.time = ptime_to_string(time_from_string(A.time) + t);
    ret.push_back(A);
  }
}