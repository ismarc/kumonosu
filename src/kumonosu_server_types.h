/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef kumonosu_server_TYPES_H
#define kumonosu_server_TYPES_H

#include <Thrift.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>



namespace kumonosu {

class boolArg {
 public:

  static const char* ascii_fingerprint; // = "7D61C9AA00102AB4D8F72A1DA58297DC";
  static const uint8_t binary_fingerprint[16]; // = {0x7D,0x61,0xC9,0xAA,0x00,0x10,0x2A,0xB4,0xD8,0xF7,0x2A,0x1D,0xA5,0x82,0x97,0xDC};

  boolArg() : name(""), value(0) {
  }

  virtual ~boolArg() throw() {}

  std::string name;
  bool value;

  struct __isset {
    __isset() : name(false), value(false) {}
    bool name;
    bool value;
  } __isset;

  bool operator == (const boolArg & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const boolArg &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const boolArg & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class byteArg {
 public:

  static const char* ascii_fingerprint; // = "EAF0A51FCCA478B8CA6B466F7A29473A";
  static const uint8_t binary_fingerprint[16]; // = {0xEA,0xF0,0xA5,0x1F,0xCC,0xA4,0x78,0xB8,0xCA,0x6B,0x46,0x6F,0x7A,0x29,0x47,0x3A};

  byteArg() : name(""), value(0) {
  }

  virtual ~byteArg() throw() {}

  std::string name;
  int8_t value;

  struct __isset {
    __isset() : name(false), value(false) {}
    bool name;
    bool value;
  } __isset;

  bool operator == (const byteArg & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const byteArg &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const byteArg & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class i16Arg {
 public:

  static const char* ascii_fingerprint; // = "3628A1EB414F66736E1B2A082E79475F";
  static const uint8_t binary_fingerprint[16]; // = {0x36,0x28,0xA1,0xEB,0x41,0x4F,0x66,0x73,0x6E,0x1B,0x2A,0x08,0x2E,0x79,0x47,0x5F};

  i16Arg() : name(""), value(0) {
  }

  virtual ~i16Arg() throw() {}

  std::string name;
  int16_t value;

  struct __isset {
    __isset() : name(false), value(false) {}
    bool name;
    bool value;
  } __isset;

  bool operator == (const i16Arg & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const i16Arg &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const i16Arg & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class i32Arg {
 public:

  static const char* ascii_fingerprint; // = "EEBC915CE44901401D881E6091423036";
  static const uint8_t binary_fingerprint[16]; // = {0xEE,0xBC,0x91,0x5C,0xE4,0x49,0x01,0x40,0x1D,0x88,0x1E,0x60,0x91,0x42,0x30,0x36};

  i32Arg() : name(""), value(0) {
  }

  virtual ~i32Arg() throw() {}

  std::string name;
  int32_t value;

  struct __isset {
    __isset() : name(false), value(false) {}
    bool name;
    bool value;
  } __isset;

  bool operator == (const i32Arg & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const i32Arg &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const i32Arg & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class i64Arg {
 public:

  static const char* ascii_fingerprint; // = "1CCCF6FC31CFD1D61BBBB1BAF3590620";
  static const uint8_t binary_fingerprint[16]; // = {0x1C,0xCC,0xF6,0xFC,0x31,0xCF,0xD1,0xD6,0x1B,0xBB,0xB1,0xBA,0xF3,0x59,0x06,0x20};

  i64Arg() : name(""), value(0) {
  }

  virtual ~i64Arg() throw() {}

  std::string name;
  int64_t value;

  struct __isset {
    __isset() : name(false), value(false) {}
    bool name;
    bool value;
  } __isset;

  bool operator == (const i64Arg & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const i64Arg &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const i64Arg & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class doubleArg {
 public:

  static const char* ascii_fingerprint; // = "C712EF0DA8599E55DF4D0F13415232EF";
  static const uint8_t binary_fingerprint[16]; // = {0xC7,0x12,0xEF,0x0D,0xA8,0x59,0x9E,0x55,0xDF,0x4D,0x0F,0x13,0x41,0x52,0x32,0xEF};

  doubleArg() : name(""), value(0) {
  }

  virtual ~doubleArg() throw() {}

  std::string name;
  double value;

  struct __isset {
    __isset() : name(false), value(false) {}
    bool name;
    bool value;
  } __isset;

  bool operator == (const doubleArg & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const doubleArg &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const doubleArg & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class stringArg {
 public:

  static const char* ascii_fingerprint; // = "07A9615F837F7D0A952B595DD3020972";
  static const uint8_t binary_fingerprint[16]; // = {0x07,0xA9,0x61,0x5F,0x83,0x7F,0x7D,0x0A,0x95,0x2B,0x59,0x5D,0xD3,0x02,0x09,0x72};

  stringArg() : name(""), value("") {
  }

  virtual ~stringArg() throw() {}

  std::string name;
  std::string value;

  struct __isset {
    __isset() : name(false), value(false) {}
    bool name;
    bool value;
  } __isset;

  bool operator == (const stringArg & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const stringArg &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const stringArg & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class arguments {
 public:

  static const char* ascii_fingerprint; // = "F3CBDDE3929F8070971B6C66009E4E9E";
  static const uint8_t binary_fingerprint[16]; // = {0xF3,0xCB,0xDD,0xE3,0x92,0x9F,0x80,0x70,0x97,0x1B,0x6C,0x66,0x00,0x9E,0x4E,0x9E};

  arguments() {
  }

  virtual ~arguments() throw() {}

  std::vector<boolArg>  boolArgs;
  std::vector<byteArg>  byteArgs;
  std::vector<i16Arg>  i16Args;
  std::vector<i32Arg>  i32Args;
  std::vector<i64Arg>  i64Args;
  std::vector<doubleArg>  doubleArgs;
  std::vector<stringArg>  stringArgs;

  struct __isset {
    __isset() : boolArgs(false), byteArgs(false), i16Args(false), i32Args(false), i64Args(false), doubleArgs(false), stringArgs(false) {}
    bool boolArgs;
    bool byteArgs;
    bool i16Args;
    bool i32Args;
    bool i64Args;
    bool doubleArgs;
    bool stringArgs;
  } __isset;

  bool operator == (const arguments & rhs) const
  {
    if (__isset.boolArgs != rhs.__isset.boolArgs)
      return false;
    else if (__isset.boolArgs && !(boolArgs == rhs.boolArgs))
      return false;
    if (__isset.byteArgs != rhs.__isset.byteArgs)
      return false;
    else if (__isset.byteArgs && !(byteArgs == rhs.byteArgs))
      return false;
    if (__isset.i16Args != rhs.__isset.i16Args)
      return false;
    else if (__isset.i16Args && !(i16Args == rhs.i16Args))
      return false;
    if (__isset.i32Args != rhs.__isset.i32Args)
      return false;
    else if (__isset.i32Args && !(i32Args == rhs.i32Args))
      return false;
    if (__isset.i64Args != rhs.__isset.i64Args)
      return false;
    else if (__isset.i64Args && !(i64Args == rhs.i64Args))
      return false;
    if (__isset.doubleArgs != rhs.__isset.doubleArgs)
      return false;
    else if (__isset.doubleArgs && !(doubleArgs == rhs.doubleArgs))
      return false;
    if (__isset.stringArgs != rhs.__isset.stringArgs)
      return false;
    else if (__isset.stringArgs && !(stringArgs == rhs.stringArgs))
      return false;
    return true;
  }
  bool operator != (const arguments &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const arguments & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class serverService {
 public:

  static const char* ascii_fingerprint; // = "AFAFBCDB9822F9D1AA4E44188E720B47";
  static const uint8_t binary_fingerprint[16]; // = {0xAF,0xAF,0xBC,0xDB,0x98,0x22,0xF9,0xD1,0xAA,0x4E,0x44,0x18,0x8E,0x72,0x0B,0x47};

  serverService() : serviceType(0), serviceId(0) {
  }

  virtual ~serverService() throw() {}

  int64_t serviceType;
  int32_t serviceId;

  struct __isset {
    __isset() : serviceType(false), serviceId(false) {}
    bool serviceType;
    bool serviceId;
  } __isset;

  bool operator == (const serverService & rhs) const
  {
    if (!(serviceType == rhs.serviceType))
      return false;
    if (!(serviceId == rhs.serviceId))
      return false;
    return true;
  }
  bool operator != (const serverService &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const serverService & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class serviceList {
 public:

  static const char* ascii_fingerprint; // = "BCF39F88A624931BC2D417E380B6FE94";
  static const uint8_t binary_fingerprint[16]; // = {0xBC,0xF3,0x9F,0x88,0xA6,0x24,0x93,0x1B,0xC2,0xD4,0x17,0xE3,0x80,0xB6,0xFE,0x94};

  serviceList() {
  }

  virtual ~serviceList() throw() {}

  std::vector<serverService>  services;

  struct __isset {
    __isset() : services(false) {}
    bool services;
  } __isset;

  bool operator == (const serviceList & rhs) const
  {
    if (!(services == rhs.services))
      return false;
    return true;
  }
  bool operator != (const serviceList &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const serviceList & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class queueItem {
 public:

  static const char* ascii_fingerprint; // = "A104D01649E132F2B265364F05B91078";
  static const uint8_t binary_fingerprint[16]; // = {0xA1,0x04,0xD0,0x16,0x49,0xE1,0x32,0xF2,0xB2,0x65,0x36,0x4F,0x05,0xB9,0x10,0x78};

  queueItem() : methodId(0), serverId(0) {
  }

  virtual ~queueItem() throw() {}

  int64_t methodId;
  int64_t serverId;
  arguments argList;

  struct __isset {
    __isset() : methodId(false), serverId(false), argList(false) {}
    bool methodId;
    bool serverId;
    bool argList;
  } __isset;

  bool operator == (const queueItem & rhs) const
  {
    if (!(methodId == rhs.methodId))
      return false;
    if (__isset.serverId != rhs.__isset.serverId)
      return false;
    else if (__isset.serverId && !(serverId == rhs.serverId))
      return false;
    if (__isset.argList != rhs.__isset.argList)
      return false;
    else if (__isset.argList && !(argList == rhs.argList))
      return false;
    return true;
  }
  bool operator != (const queueItem &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const queueItem & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class queueItemList {
 public:

  static const char* ascii_fingerprint; // = "0F23088D4DE5581F3AE36B250AE0CCC2";
  static const uint8_t binary_fingerprint[16]; // = {0x0F,0x23,0x08,0x8D,0x4D,0xE5,0x58,0x1F,0x3A,0xE3,0x6B,0x25,0x0A,0xE0,0xCC,0xC2};

  queueItemList() {
  }

  virtual ~queueItemList() throw() {}

  std::vector<queueItem>  items;

  struct __isset {
    __isset() : items(false) {}
    bool items;
  } __isset;

  bool operator == (const queueItemList & rhs) const
  {
    if (!(items == rhs.items))
      return false;
    return true;
  }
  bool operator != (const queueItemList &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const queueItemList & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

} // namespace

#endif
