#include "Expression.hpp"

Number::Number(double value) { this->value = value; }

double Number::evaluate() { return value; }

string Number::description() { return to_string(value); }

Variable::Variable(string name) { this->name = name; }

string Variable::description() { return name; }

double Variable::evaluate() {
  for (auto i = array.begin(); i != array.end(); i++) {
    if (i->first == name)
      return i->second;
  }
  throw "Brak zmiennej";
}

vector<pair<string, double>> Variable::array = {};

void Variable::printVec() {
  for (size_t i = 0; i < array.size(); i++)
    cout << Variable::array[i].first << " " << Variable::array[i].second
         << std::endl;
}

void Variable::assVar(std::string var_name, double val) {
  for (size_t i = 0; i < array.size(); i++) {
    if (Variable::array[i].first == var_name) {
      array[i].second = val;
      return;
    }
  }
  Variable::array.push_back(make_pair(var_name, val));
}

double Variable::getVar(string var_name) {
  for (size_t i = 0; i < array.size(); i++) {
    if (Variable::array[i].first == var_name) {
      return array[i].second;
    }
  }
  throw "Nie ma takiej zmiennej";
}

Pi::Pi() { value = 3.14159265359; };
string Pi::description() { return "Pi"; }
double Pi::evaluate() { return value; }

Fi::Fi() { value = 1.61803; };
string Fi::description() { return "Fi"; }
double Fi::evaluate() { return value; }

e::e() { value = 2.718281828; };
string e::description() { return "e"; }
double e::evaluate() { return value; }

UnOp::UnOp(Expression *arg) { this->arg = arg; }

string Sin::description() { return "sin(" + arg->description() + ")"; }
double Sin::evaluate() { return sin(arg->evaluate()); }

string Cos::description() { return "cos(" + arg->description() + ")"; }
double Cos::evaluate() { return cos(arg->evaluate()); }

string Exp::description() { return "exp(" + arg->description() + ")"; }
double Exp::evaluate() { return exp(arg->evaluate()); }

string Ln::description() { return "ln(" + arg->description() + ")"; }
double Ln::evaluate() { return log(arg->evaluate()); }

string Opposite::description() { return "-(" + arg->description() + ")"; }
double Opposite::evaluate() { return (-1) * arg->evaluate(); }

string Reciprocal::description() { return "1/" + arg->description(); }
double Reciprocal::evaluate() { return 1.0 / arg->evaluate(); }

string Absolute::description() { return "|" + arg->description() + "|"; }
double Absolute::evaluate() { return abs(arg->evaluate()); }

BinOp::BinOp(Expression *arg, Expression *arg1) : UnOp(arg) {
  this->arg1 = arg1;
}

string Add::description() {
  return arg->description() + " + " + arg1->description();
}
double Add::evaluate() { return arg->evaluate() + arg1->evaluate(); }

string Subtract::description() {
  string left, right;
  left = arg->description();
  if (arg1->getPriority() < getPriority())
    right = "(" + arg1->description() + ")";
  else
    right = arg1->description();
  return left + " - " + right;
}
double Subtract::evaluate() { return arg->evaluate() - arg1->evaluate(); }

string Multiply::description() {
  string left, right;
  if (arg->getPriority() < getPriority())
    left = "(" + arg->description() + ")";
  else
    left = arg->description();
  if (arg1->getPriority() < getPriority())
    right = "(" + arg1->description() + ")";
  else
    right = arg1->description();
  return left + " * " + right;
}
double Multiply::evaluate() { return arg->evaluate() * arg1->evaluate(); }

string Divide::description() {
  string left, right;
  if (arg->getPriority() < 2)
    left = "(" + arg->description() + ")";
  else
    left = arg->description();
  if (arg1->getPriority() < getPriority())
    right = "(" + arg1->description() + ")";
  else
    right = arg1->description();
  return left + " / " + right;
}
double Divide::evaluate() { return arg->evaluate() / arg1->evaluate(); }

string Log::description() {
  return "log(" + arg->description() + ", " + arg1->description() + ")";
}
double Log::evaluate() { return log(arg->evaluate()) / log(arg1->evaluate()); }

string Modulo::description() {
  return arg->description() + "%" + arg1->description();
}
double Modulo::evaluate() {
  return static_cast<int>(arg->evaluate()) %
         static_cast<int>((int)arg1->evaluate());
}

string Power::description() {
  string left, right;
  if (arg->getPriority() <= getPriority())
    left = "(" + arg->description() + ")";
  else
    left = arg->description();

  if (arg->getPriority() <= getPriority())
    right = "(" + arg1->description() + ")";
  else
    right = arg1->description();

  return left + "^" + right;
}
double Power::evaluate() { return pow(arg->evaluate(), arg1->evaluate()); }