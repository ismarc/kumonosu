/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#include "kumonosu_server_types.h"

namespace kumonosu {

const char* boolArg::ascii_fingerprint = "7D61C9AA00102AB4D8F72A1DA58297DC";
const uint8_t boolArg::binary_fingerprint[16] = {0x7D,0x61,0xC9,0xAA,0x00,0x10,0x2A,0xB4,0xD8,0xF7,0x2A,0x1D,0xA5,0x82,0x97,0xDC};

uint32_t boolArg::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t boolArg::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("boolArg");
  xfer += oprot->writeFieldBegin("name", apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("value", apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool(this->value);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* byteArg::ascii_fingerprint = "EAF0A51FCCA478B8CA6B466F7A29473A";
const uint8_t byteArg::binary_fingerprint[16] = {0xEA,0xF0,0xA5,0x1F,0xCC,0xA4,0x78,0xB8,0xCA,0x6B,0x46,0x6F,0x7A,0x29,0x47,0x3A};

uint32_t byteArg::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t byteArg::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("byteArg");
  xfer += oprot->writeFieldBegin("name", apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("value", apache::thrift::protocol::T_BYTE, 2);
  xfer += oprot->writeByte(this->value);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* i16Arg::ascii_fingerprint = "3628A1EB414F66736E1B2A082E79475F";
const uint8_t i16Arg::binary_fingerprint[16] = {0x36,0x28,0xA1,0xEB,0x41,0x4F,0x66,0x73,0x6E,0x1B,0x2A,0x08,0x2E,0x79,0x47,0x5F};

uint32_t i16Arg::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t i16Arg::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("i16Arg");
  xfer += oprot->writeFieldBegin("name", apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("value", apache::thrift::protocol::T_I16, 2);
  xfer += oprot->writeI16(this->value);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* i32Arg::ascii_fingerprint = "EEBC915CE44901401D881E6091423036";
const uint8_t i32Arg::binary_fingerprint[16] = {0xEE,0xBC,0x91,0x5C,0xE4,0x49,0x01,0x40,0x1D,0x88,0x1E,0x60,0x91,0x42,0x30,0x36};

uint32_t i32Arg::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t i32Arg::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("i32Arg");
  xfer += oprot->writeFieldBegin("name", apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("value", apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->value);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* i64Arg::ascii_fingerprint = "1CCCF6FC31CFD1D61BBBB1BAF3590620";
const uint8_t i64Arg::binary_fingerprint[16] = {0x1C,0xCC,0xF6,0xFC,0x31,0xCF,0xD1,0xD6,0x1B,0xBB,0xB1,0xBA,0xF3,0x59,0x06,0x20};

uint32_t i64Arg::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t i64Arg::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("i64Arg");
  xfer += oprot->writeFieldBegin("name", apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("value", apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->value);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* doubleArg::ascii_fingerprint = "C712EF0DA8599E55DF4D0F13415232EF";
const uint8_t doubleArg::binary_fingerprint[16] = {0xC7,0x12,0xEF,0x0D,0xA8,0x59,0x9E,0x55,0xDF,0x4D,0x0F,0x13,0x41,0x52,0x32,0xEF};

uint32_t doubleArg::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t doubleArg::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("doubleArg");
  xfer += oprot->writeFieldBegin("name", apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("value", apache::thrift::protocol::T_DOUBLE, 2);
  xfer += oprot->writeDouble(this->value);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* stringArg::ascii_fingerprint = "07A9615F837F7D0A952B595DD3020972";
const uint8_t stringArg::binary_fingerprint[16] = {0x07,0xA9,0x61,0x5F,0x83,0x7F,0x7D,0x0A,0x95,0x2B,0x59,0x5D,0xD3,0x02,0x09,0x72};

uint32_t stringArg::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t stringArg::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("stringArg");
  xfer += oprot->writeFieldBegin("name", apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("value", apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* arguments::ascii_fingerprint = "5FE74C86BE910B05C2783D68AB1F95EF";
const uint8_t arguments::binary_fingerprint[16] = {0x5F,0xE7,0x4C,0x86,0xBE,0x91,0x0B,0x05,0xC2,0x78,0x3D,0x68,0xAB,0x1F,0x95,0xEF};

uint32_t arguments::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_LIST) {
          {
            this->boolArgs.clear();
            uint32_t _size0;
            apache::thrift::protocol::TType _etype3;
            iprot->readListBegin(_etype3, _size0);
            this->boolArgs.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += this->boolArgs[_i4].read(iprot);
            }
            iprot->readListEnd();
          }
          this->__isset.boolArgs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == apache::thrift::protocol::T_LIST) {
          {
            this->byteArgs.clear();
            uint32_t _size5;
            apache::thrift::protocol::TType _etype8;
            iprot->readListBegin(_etype8, _size5);
            this->byteArgs.resize(_size5);
            uint32_t _i9;
            for (_i9 = 0; _i9 < _size5; ++_i9)
            {
              xfer += this->byteArgs[_i9].read(iprot);
            }
            iprot->readListEnd();
          }
          this->__isset.byteArgs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == apache::thrift::protocol::T_LIST) {
          {
            this->i16Args.clear();
            uint32_t _size10;
            apache::thrift::protocol::TType _etype13;
            iprot->readListBegin(_etype13, _size10);
            this->i16Args.resize(_size10);
            uint32_t _i14;
            for (_i14 = 0; _i14 < _size10; ++_i14)
            {
              xfer += this->i16Args[_i14].read(iprot);
            }
            iprot->readListEnd();
          }
          this->__isset.i16Args = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == apache::thrift::protocol::T_LIST) {
          {
            this->i32Args.clear();
            uint32_t _size15;
            apache::thrift::protocol::TType _etype18;
            iprot->readListBegin(_etype18, _size15);
            this->i32Args.resize(_size15);
            uint32_t _i19;
            for (_i19 = 0; _i19 < _size15; ++_i19)
            {
              xfer += this->i32Args[_i19].read(iprot);
            }
            iprot->readListEnd();
          }
          this->__isset.i32Args = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == apache::thrift::protocol::T_LIST) {
          {
            this->i64Args.clear();
            uint32_t _size20;
            apache::thrift::protocol::TType _etype23;
            iprot->readListBegin(_etype23, _size20);
            this->i64Args.resize(_size20);
            uint32_t _i24;
            for (_i24 = 0; _i24 < _size20; ++_i24)
            {
              xfer += this->i64Args[_i24].read(iprot);
            }
            iprot->readListEnd();
          }
          this->__isset.i64Args = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == apache::thrift::protocol::T_LIST) {
          {
            this->doubleArgs.clear();
            uint32_t _size25;
            apache::thrift::protocol::TType _etype28;
            iprot->readListBegin(_etype28, _size25);
            this->doubleArgs.resize(_size25);
            uint32_t _i29;
            for (_i29 = 0; _i29 < _size25; ++_i29)
            {
              xfer += this->doubleArgs[_i29].read(iprot);
            }
            iprot->readListEnd();
          }
          this->__isset.doubleArgs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == apache::thrift::protocol::T_LIST) {
          {
            this->stringArgs.clear();
            uint32_t _size30;
            apache::thrift::protocol::TType _etype33;
            iprot->readListBegin(_etype33, _size30);
            this->stringArgs.resize(_size30);
            uint32_t _i34;
            for (_i34 = 0; _i34 < _size30; ++_i34)
            {
              xfer += this->stringArgs[_i34].read(iprot);
            }
            iprot->readListEnd();
          }
          this->__isset.stringArgs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t arguments::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("arguments");
  if (this->__isset.boolArgs) {
    xfer += oprot->writeFieldBegin("boolArgs", apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(apache::thrift::protocol::T_STRUCT, this->boolArgs.size());
      std::vector<boolArg> ::const_iterator _iter35;
      for (_iter35 = this->boolArgs.begin(); _iter35 != this->boolArgs.end(); ++_iter35)
      {
        xfer += (*_iter35).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.byteArgs) {
    xfer += oprot->writeFieldBegin("byteArgs", apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(apache::thrift::protocol::T_STRUCT, this->byteArgs.size());
      std::vector<byteArg> ::const_iterator _iter36;
      for (_iter36 = this->byteArgs.begin(); _iter36 != this->byteArgs.end(); ++_iter36)
      {
        xfer += (*_iter36).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.i16Args) {
    xfer += oprot->writeFieldBegin("i16Args", apache::thrift::protocol::T_LIST, 3);
    {
      xfer += oprot->writeListBegin(apache::thrift::protocol::T_STRUCT, this->i16Args.size());
      std::vector<i16Arg> ::const_iterator _iter37;
      for (_iter37 = this->i16Args.begin(); _iter37 != this->i16Args.end(); ++_iter37)
      {
        xfer += (*_iter37).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("i32Args", apache::thrift::protocol::T_LIST, 4);
  {
    xfer += oprot->writeListBegin(apache::thrift::protocol::T_STRUCT, this->i32Args.size());
    std::vector<i32Arg> ::const_iterator _iter38;
    for (_iter38 = this->i32Args.begin(); _iter38 != this->i32Args.end(); ++_iter38)
    {
      xfer += (*_iter38).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();
  if (this->__isset.i64Args) {
    xfer += oprot->writeFieldBegin("i64Args", apache::thrift::protocol::T_LIST, 5);
    {
      xfer += oprot->writeListBegin(apache::thrift::protocol::T_STRUCT, this->i64Args.size());
      std::vector<i64Arg> ::const_iterator _iter39;
      for (_iter39 = this->i64Args.begin(); _iter39 != this->i64Args.end(); ++_iter39)
      {
        xfer += (*_iter39).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.doubleArgs) {
    xfer += oprot->writeFieldBegin("doubleArgs", apache::thrift::protocol::T_LIST, 6);
    {
      xfer += oprot->writeListBegin(apache::thrift::protocol::T_STRUCT, this->doubleArgs.size());
      std::vector<doubleArg> ::const_iterator _iter40;
      for (_iter40 = this->doubleArgs.begin(); _iter40 != this->doubleArgs.end(); ++_iter40)
      {
        xfer += (*_iter40).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("stringArgs", apache::thrift::protocol::T_LIST, 7);
  {
    xfer += oprot->writeListBegin(apache::thrift::protocol::T_STRUCT, this->stringArgs.size());
    std::vector<stringArg> ::const_iterator _iter41;
    for (_iter41 = this->stringArgs.begin(); _iter41 != this->stringArgs.end(); ++_iter41)
    {
      xfer += (*_iter41).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* serverService::ascii_fingerprint = "AFAFBCDB9822F9D1AA4E44188E720B47";
const uint8_t serverService::binary_fingerprint[16] = {0xAF,0xAF,0xBC,0xDB,0x98,0x22,0xF9,0xD1,0xAA,0x4E,0x44,0x18,0x8E,0x72,0x0B,0x47};

uint32_t serverService::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->serviceType);
          this->__isset.serviceType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->serviceId);
          this->__isset.serviceId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t serverService::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("serverService");
  xfer += oprot->writeFieldBegin("serviceType", apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->serviceType);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("serviceId", apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->serviceId);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* serviceList::ascii_fingerprint = "BCF39F88A624931BC2D417E380B6FE94";
const uint8_t serviceList::binary_fingerprint[16] = {0xBC,0xF3,0x9F,0x88,0xA6,0x24,0x93,0x1B,0xC2,0xD4,0x17,0xE3,0x80,0xB6,0xFE,0x94};

uint32_t serviceList::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_LIST) {
          {
            this->services.clear();
            uint32_t _size42;
            apache::thrift::protocol::TType _etype45;
            iprot->readListBegin(_etype45, _size42);
            this->services.resize(_size42);
            uint32_t _i46;
            for (_i46 = 0; _i46 < _size42; ++_i46)
            {
              xfer += this->services[_i46].read(iprot);
            }
            iprot->readListEnd();
          }
          this->__isset.services = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t serviceList::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("serviceList");
  xfer += oprot->writeFieldBegin("services", apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(apache::thrift::protocol::T_STRUCT, this->services.size());
    std::vector<serverService> ::const_iterator _iter47;
    for (_iter47 = this->services.begin(); _iter47 != this->services.end(); ++_iter47)
    {
      xfer += (*_iter47).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* queueItem::ascii_fingerprint = "423E5C0930758A8A22D51D1BFA50AE4A";
const uint8_t queueItem::binary_fingerprint[16] = {0x42,0x3E,0x5C,0x09,0x30,0x75,0x8A,0x8A,0x22,0xD5,0x1D,0x1B,0xFA,0x50,0xAE,0x4A};

uint32_t queueItem::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->methodId);
          this->__isset.methodId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->serverId);
          this->__isset.serverId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == apache::thrift::protocol::T_STRUCT) {
          xfer += this->argList.read(iprot);
          this->__isset.argList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t queueItem::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("queueItem");
  xfer += oprot->writeFieldBegin("methodId", apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->methodId);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("serverId", apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->serverId);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("argList", apache::thrift::protocol::T_STRUCT, 3);
  xfer += this->argList.write(oprot);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* queueItemList::ascii_fingerprint = "47299E266D53FC38B6A0F5B44E352F87";
const uint8_t queueItemList::binary_fingerprint[16] = {0x47,0x29,0x9E,0x26,0x6D,0x53,0xFC,0x38,0xB6,0xA0,0xF5,0xB4,0x4E,0x35,0x2F,0x87};

uint32_t queueItemList::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == apache::thrift::protocol::T_LIST) {
          {
            this->items.clear();
            uint32_t _size48;
            apache::thrift::protocol::TType _etype51;
            iprot->readListBegin(_etype51, _size48);
            this->items.resize(_size48);
            uint32_t _i52;
            for (_i52 = 0; _i52 < _size48; ++_i52)
            {
              xfer += this->items[_i52].read(iprot);
            }
            iprot->readListEnd();
          }
          this->__isset.items = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t queueItemList::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("queueItemList");
  xfer += oprot->writeFieldBegin("items", apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(apache::thrift::protocol::T_STRUCT, this->items.size());
    std::vector<queueItem> ::const_iterator _iter53;
    for (_iter53 = this->items.begin(); _iter53 != this->items.end(); ++_iter53)
    {
      xfer += (*_iter53).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

} // namespace
