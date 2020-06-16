#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Expression {
public:
  virtual double evaluate() = 0;
  virtual string description() = 0;
  virtual int getPriority() { return 5; }
  virtual ~Expression() = default;
};

class Number : public Expression {
public:
  double value;

  Number(double value);

  double evaluate();
  string description();
};

class Variable : public Expression {
private:
  static vector<pair<string, double>> array;

public:
  string name;

  Variable(string name);
  double evaluate();
  string description();

  static void printVec();
  static void assVar(string var_name, double val);
  static double getVar(string var_name);
};

class Constant : public Expression {
protected:
  double value;
};

class Pi : public Constant {
public:
  double evaluate();
  string description();
  Pi();
};

class e : public Constant {
public:
  double evaluate();
  string description();
  e();
};

class Fi : public Constant {
public:
  double evaluate();
  string description();
  Fi();
};

class UnOp : public Expression {
public:
  Expression *arg;

  UnOp(Expression *arg);
};

class Sin : public UnOp {
public:
  string description();
  double evaluate();
  using UnOp::UnOp;
};

class Cos : public UnOp {
public:
  string description();
  double evaluate();
  using UnOp::UnOp;
};

class Exp : public UnOp {
public:
  string description();
  double evaluate();
  using UnOp::UnOp;
};

class Ln : public UnOp {
public:
  string description();
  double evaluate();
  using UnOp::UnOp;
};

class Opposite : public UnOp {
public:
  string description();
  double evaluate();
  using UnOp::UnOp;
};

class Reciprocal : public UnOp {
public:
  string description();
  double evaluate();
  using UnOp::UnOp;
};

class Absolute : public UnOp {
public:
  string description();
  double evaluate();
  using UnOp::UnOp;
};

class BinOp : public UnOp {
public:
  Expression *arg1;
  BinOp(Expression *arg, Expression *arg1);

  int getPriority() override { return 0; }
};

class Add : public BinOp {
public:
  string description();
  double evaluate();
  using BinOp::BinOp;
};

class Subtract : public BinOp {
public:
  string description();
  double evaluate();
  using BinOp::BinOp;
  int getPriority() override { return 1; }
};

class Multiply : public BinOp {
public:
  string description();
  double evaluate();
  using BinOp::BinOp;
  int getPriority() override { return 2; }
};

class Divide : public BinOp {
public:
  string description();
  double evaluate();
  using BinOp::BinOp;
  int getPriority() override { return 3; }
};

class Log : public BinOp {
public:
  string description();
  double evaluate();
  using BinOp::BinOp;
  int getPriority() override { return 4; }
};

class Modulo : public BinOp {
public:
  string description();
  double evaluate();
  using BinOp::BinOp;
  int getPriority() override { return 4; }
};

class Power : public BinOp {
public:
  string description();
  double evaluate();
  using BinOp::BinOp;
  int getPriority() override { return 4; }
};