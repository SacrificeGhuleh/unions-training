#include <cstdint>
#include <iostream>

template<class T_DATATYPE>
struct TypeConverter {
  union {
    T_DATATYPE data;
    uint8_t rawBytes[sizeof(T_DATATYPE)];
  };
  
  void print() {
    std::cout << "Type converter\n";
    std::cout << "  Decimal: " << data << "\n";
    std::cout << std::hex << "  Hex: 0x" << data << "\n";
    std::cout << "  Bytes: ";
    for (int i = 0; i < sizeof(T_DATATYPE); i++) {
      std::cout << "0x"<<(int)rawBytes[i] << " ";
    }
    std::cout << "\n";
  }
};

int main(int argc, char **argv) {
  TypeConverter<int> tc1{0x1596324};
  tc1.print();
}
