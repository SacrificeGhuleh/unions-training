#include <cstdint>
#include <iostream>
#include <cstddef>

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
      std::cout << "0x" << (int) rawBytes[i] << " ";
    }
    std::cout << "\n";
  }
};

void betterSolution() {
  uint64_t value = 0xDC2525478963AF25ULL;
  uint8_t *buffer;
  buffer = reinterpret_cast<uint8_t *>(&value);
  std::cout << "  Bytes: ";
  for (int i = 0; i < sizeof(uint64_t); i++) {
    std::cout << "0x" << (int) buffer[i] << " ";
  }
  std::cout << "\n";
}

void bestModernSolution() {
  std::byte myByte{0xAF};
//
//  myByte += 10;
//  myByte *= 10;
  myByte <<= 2;
}

int main(int argc, char **argv) {
  TypeConverter<int> tc1{0x1596324};
  tc1.print();
  std::cout << "\n\n";
  
  betterSolution();
  
  
}
