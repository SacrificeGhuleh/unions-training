#include <iostream>
#include <vector>
#include <array>
#include "utils.h"

template<class T_DATATYPE, size_t T_NUM>
union vec {
  typedef T_DATATYPE type;
  size_t size() {
    return T_NUM;
  }
};

template<class T_DATATYPE>
union vec<T_DATATYPE, 3> {
  struct {
    union {
      T_DATATYPE r;
      T_DATATYPE x;
    };
    union {
      T_DATATYPE g;
      T_DATATYPE y;
    };
    union {
      T_DATATYPE b;
      T_DATATYPE z;
    };
  };
  T_DATATYPE data[3];
  
  size_t size() {
    return 3;
  }
};

template<class T_DATATYPE>
union vec<T_DATATYPE, 4> {
  struct {
    union {
      T_DATATYPE r;
      T_DATATYPE x;
    };
    union {
      T_DATATYPE g;
      T_DATATYPE y;
    };
    union {
      T_DATATYPE b;
      T_DATATYPE z;
    };
    union {
      T_DATATYPE a;
      T_DATATYPE w;
    };
  };
  T_DATATYPE data[4];
  std::array<T_DATATYPE, 4> stdData;
  
  size_t size() {
    return 4;
  }
};


int main(int argc, char **argv) {
  vec<float, 3> vector3{};
  
  for (int i = 0; i < vector3.size(); ++i) {
    vector3.data[i] = random(0, 255);
  }
  
  vec<float, 4> vector4{};
  for (int i = 0; i < vector4.size(); ++i) {
    vector4.data[i] = random(0, 255);
  }
  printf("Vector 4 data\n");
  printf("  %05.1f  %05.1f  %05.1f  %05.1f\n", vector4.data[0], vector4.r, vector4.x, vector4.stdData.at(0));
  printf("  %05.1f  %05.1f  %05.1f  %05.1f\n", vector4.data[1], vector4.g, vector4.y, vector4.stdData.at(1));
  printf("  %05.1f  %05.1f  %05.1f  %05.1f\n", vector4.data[2], vector4.b, vector4.z, vector4.stdData.at(2));
  printf("  %05.1f  %05.1f  %05.1f  %05.1f\n", vector4.data[3], vector4.a, vector4.w, vector4.stdData.at(3));
  
  
}
