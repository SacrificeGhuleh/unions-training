#include <iostream>

union NakedUnion {
  int itgr;
  double dbl;
};

struct TaggedUnion {
  enum DataType {
    INTEGER, DOUBLE
  };
  
  DataType dataType;
  
  union {
    int itgr;
    double dbl;
  };
  
  void print() {
    print(dataType);
  }
  
  void print(DataType type) {
    switch (type) {
      case INTEGER: {
        std::cout << itgr;
        break;
      }
      case DOUBLE: {
        std::cout << dbl;
        break;
      }
    };
  }
};

struct RobustTaggedUnion {
  enum DataType {
    INTEGER, DOUBLE
  };
private:
  DataType dataType;
  
  union {
    int itgr;
    double dbl;
  };
public:
  void print() {
    print(dataType);
  }
  
  void print(DataType type) {
    switch (type) {
      case INTEGER: {
        std::cout << itgr;
        break;
      }
      case DOUBLE: {
        std::cout << dbl;
        break;
      }
    };
  }
  
  void set(DataType type) {
    dataType = type;
  }
  
  void set(int i) {
    if (dataType == INTEGER) {
      itgr = i;
    } else {
      throw std::runtime_error("Wrong datatype set to union");
    }
  }
  
  void set(double d) {
    if (dataType == DOUBLE) {
      dbl = d;
    } else {
      throw std::runtime_error("Wrong datatype set to union");
    }
  }
  
  template<class T>
  T get() {
    throw std::runtime_error("Invalid data type");
  }
};

template<>
double RobustTaggedUnion::get() {
  if (dataType == DOUBLE) {
    return dbl;
  }
  throw std::runtime_error("You tried to get invalid datatype");
}

template<>
int RobustTaggedUnion::get() {
  if (dataType == INTEGER) {
    return itgr;
  }
  throw std::runtime_error("You tried to get invalid datatype");
}

template<>
RobustTaggedUnion::DataType RobustTaggedUnion::get() {
  return dataType;
}

int main(int argc, char **argv) {
  // Different possibilities, how to initialize union value
  NakedUnion nu1{10};
  NakedUnion nu2{.dbl = 20.};
  NakedUnion nu3{itgr : 30}; //deprecated
  
  std::cout << "nu1 " << nu1.dbl << "\n";
  std::cout << "nu2 " << nu2.dbl << "\n";
  std::cout << "nu3 " << nu3.itgr << "\n";
  
  std::cout << "Why is the first output incorrect? \n\n\n";
  
  
  TaggedUnion tu1{TaggedUnion::DataType::INTEGER, 10};
  TaggedUnion tu2{.dataType{TaggedUnion::DataType::DOUBLE}, .dbl{20.}};
  TaggedUnion tu3{dataType : TaggedUnion::DataType::INTEGER, dbl:30};
  
  std::cout << "tu1 ";
  tu1.print();
  std::cout << "\n";
  
  std::cout << "tu2 ";
  tu2.print();
  std::cout << "\n";
  
  std::cout << "tu3 ";
  tu3.print();
  std::cout << "\n";
  
  std::cout << "Why is the third output incorrect? \n\n\n";
  
  RobustTaggedUnion rtu;
  rtu.set(RobustTaggedUnion::DOUBLE);
  rtu.set(10.);
  
  try {
    std::cout << rtu.get<int>();
  }
  catch (std::runtime_error ex) {
    std::cout << ex.what() << "\n";
  }
  
  try {
    std::cout << rtu.get<double>();
  }
  catch (std::runtime_error ex) {
    std::cout << ex.what() << "\n";
  }
  
}
